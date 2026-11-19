	A computer that cannot save information across reboots is not very useful, so we need *persistence*.

But, how does the OS communicate with I/O devices without wasting CPU time while blocking?

# Physical layout

The CPU is connected to other devices via buses of varying speeds. RAM gets the fastest bus, but there are more buses that connect to more devices (PCIe, USB, SATA):
![Different I/O buses](./images/io-buses.png)

This tiered system is to offset costs: each component gets the cheapest bus that doesn't limit its speed.

# The I/O Interface

Different I/O devices work differently, but the operating system access them all the same way: by running regular memory operations on a specific address range.

The different device buses are mapped to a known address range, and the OS communicates with the devices in the same way it would access main memory. Instead of trying to read or write to the data directly though, it writes commands to control the device (memory-mapped I/O).

The values in these addresses are also never cached, since they are also modified by the I/O devices.

> [!NOTE]
> User code cannot access these device addresses. Only the kernel is allowed to control I/O devices.

## How devices are mapped

At boot, the computer's firmware (BIOS) requests each device's address space size, writing a base address in each device's base address registers. Then the kernel reads the mapping. After that, each device's driver does something idk

# The I/O interface

Every I/O device exposes the same interface to the operating system, consisting of 3 registers:
- The status register
- The command register
- The data register

![The IO interface](./images/io-device-interface.png)

The naive way to work with this interface is for the OS to poll the device's status, writing commands or reading data once it's not busy; this is obviously wasteful.

## Interrupt-driven I/O

With interrupt-driven I/O, we avoid polling the device and wasting CPU time. The device will send an interrput once it's ready, causing a context switch back to the driver code.

![Interrupt-driven I/O](./images/interrupt-driven-io-diagram.png)

Interrupts are good if the device's operations are much slower than the time to execute a context switch. Certain devices, such as network interfaces, work in very fast intervals. For these sorts of operations, it's better for the device to buffer its data and poll it in batches.

![Why polling is good sometimes](./images/polling-over-interrupts.png)

If events are rare, choose interrupts. If events are very frequent, choose polling.

## Direct Memory Access

If we use the `data` register as the only access point to the device's memory (programmed I/O), big reads or writes would take very large amounts of memory transfers between the register and RAM.

![Programmed I/O vs DMA](./images/programmed-io-vs-dma.png)

With DMA, the CPU just tells the device what to read/write and the address to write to/read from. The DMA controller handles the actual data transfers, with the device generating a single interrupt once the full operation is completed.

To handle multiple requests, the OS keeps a ring buffer containing all requests, writing the address to the start of the buffer to the device at boot (?). The driver code will then add requests at the tail, and the device's controller reads the head, marking requests as done as it completes operations.

### DMA and virtual addresses

Since DMA works with physical addresses, if a device tried to write a bunch of data contigously it could violate the page mappings allocated to the program.

This is handled by the driver: it divides the operation by word size and maps each word to its physical address. This is known as *scatter-gather DMA*.

# Device driver operation

Device drivers are kernel code. They have different responsibilities:
- Initialization
    Find the device, map registers, setup buffers and request rings
- Handle requests
    Translate `read`/`write` syscalls to specific device instructions
- Handle interrupts
- Cleanup
    Stop the device and deallocate resources initialized by the driver

# Hard disks

All I/O devices are addressed by *logical block addresses*, with block sizes between 512B and 5KB. These logical addresses function much like virtual memory addresses.

This mean that, despite the physical layout of the device, the OS always seems teh same flat array of blocks.

In the case of hard disks, the cost of reading can vary significantly based on the physical distance between the blocks: let's see why that is.

## Inside hard disks

This is the layout of a hard disk:
![Inside a hard disk](./images/hard-disk-internals.png)

The disk has multiple platters and heads. Each platter has 2 sides, so it gets 1 head per side. The platters are divided in sectors (blocks), and are spun by the spindle. The heads are moved linearly by arms to the correct spot in the disk to read sectors on a particular track. Once the platter spins under the head, the sector can be read. The group of sectors that are vertically aligned on each platter is called a cylinder.

A disk that runs at 7200 RPM makes 120 revolutions per second, meaning 1 revolution takes 8.33 ms. This is the biggest factor in why hard disks are so much slower than RAM/SSDs.

> [!NOTE]
> Because of angular velocity, outer tracks spin faster than inner tracks, meaning they're faster to access. It's the OS's job to choose how to layout data for the best performance.

### Drive cache

Drives have a DRAM cache that can hold data read in advance and allows a write to be marked as completed before the data is actually writte to the platter.

## Calculating performance

For the OS to be able to optimize data accesses to drives, it has to know how long any request will take.

Each HDD request has 3 steps:
- Seek
    The arm moves to the right track. Takes ~1ms for adjacent tracks, ~4-9ms on average. Grows less than linearly with distance (due to accel/decel).
- Rotation
    The correct sector rotates under the head. Takes half a revolution no average
- Transfer
    The data is accessed. Time depends on the drive's bandwidth; negligible compared to the other 2 steps.

So, the total time for a request is $T=T_\text{seek}+T_\text{rotation}+T_\text{transfer}$.

Example calculation:
![Rough HDD request time calculation](./images/hdd-request-time-calc.png)

Clearly most of the time is spent waiting for the drive's components to move to the right spot. This is why optimizing where data is stored is so important: sequential accesses cost much less since we can make use of the platter's rotation.

![Random vs sequential access times](./images/random-vs-sequential-hdd-access.png)

The OS can use this information to reorder request to optimize for sequential accesses.

## HDD request scheduling

The OS needs to schedule I/O requests to optimize for HDD accesses.

Processes send their I/O requests to a queue. The I/O scheduler is responsible for choosing who gets to access the drive from the queue.

The I/O scheduler faces similar challenges the CPU scheduler does.

### Algorithms

We use head track movement as a measure.

- First come first serve
    Simply serve the requests in arrival order. This algorithm is fair but slow.
- Shortest seek time first
    Analogous to CPU SJF. Greedy algorithm: considers only the next closest request, doesn't consider the shortest global path. Can cause starvation.
- SCAN/elevator
    Sweeps the platter, serving incoming requests on the way and reversing once it reaches the last track. Avoids starvation, but requests wait unevenly: requests in the middle of the platter get served more often.
- C-SCAN
    Same as SCAN, but only serves in one direction, resetting quickly once it reaches the end. Moving across the whole platter is fast since the head doesn't have to accelerate and decelerate.
- LOOK
    Same as SCAN but only move between the first and last requests along the tracks.
- C-LOOK
    LOOK with the C-SCAN approach.

Real systems usually use a variant of LOOK/C-LOOK, since it offers even waits with good average travel time.

We only consider track travel time since that's what the OS knows. The device itself has more information, and so will reorder requests sent by the operating system to optimize further.
