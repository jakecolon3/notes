# Processes

We already saw that one of the most important abstractions that the OS provides is the process.

More precisely, a process is a collection of:
- Program code
- Value of the PC
- CPU registers
- A private virtual address space
- Open file descriptors
- Unique process ID (a *PID*)

When a process is started, the OS:
1. Reads the binary
2. Loads code into RAM\*
3. Allocates a stack and heap
4. Sets up file descriptors (stdin, stdout, stderr)
5. Jumps to entrypoint
    \*A program can be loaded either *eagerly* or *lazily*:
    - Eager loading loads the entire binary into memory before starting executino
    - Lazy loading only loads the instructions needed at the current point in execution. If the program tries to access an unloaded instruction, a page fault is generated, causing the OS to load the part of the binary that contains the requested instruction.

The state of a newly started process is as follows:
- The stack contains `argc`, `argv[]`, `envp[]`
- The heap is empty
- The PC points to the first instruction of `main`
- I/O file descriptors are open and connected to the terminal

## Process state

A process can be in one of these states:
- Ready
    The process is ready to execute instructions and is waiting for the CPU
- Running
    The process' instructions are being executed by the CPU. Only 1 process per core can be running at once.
- Blocked
    The process is waiting for I/O or for an event

The OS *scheduler* is responsible for managing process' states.

## Process Control Block

We mentioned that a process contains some information. This information is stored in a *process control block*.

![Process control block](./images/proc-control-block.png)
*Simplified PCB.*

When the CPU does a context switch, it saves the current process' information in a PCB and loads a different one.

The OS keeps a table of all processes with their associated PCBs. This table is used by the scheduler.

## Process Hierarchy

On UNIX systems, processes are organized in a *tree*. The tree is rooted at PID 1, with a program known as the *init system* (usually `systemd`). The init system is the first user-space program executed after the kernel, and is responsible for starting all other processes after boot.

If a process is orphaned, it is adopted by the init system.

If the init system dies, the kernel panics as there is nothing left to manage user-space.

# UNIX Process API

Process management is done by the OS, so to create programs that interact with processes we must use system calls.

The main function for spawning processes if `fork()`. This function creates an *exact copy* of the current process. Then this copied process can run `exec()` to *replace* its running program.

![Process API](./images/process-api.png)

The API is designed this way to give more flexibility ("Do one thing, and do it well").

## `fork()`

To spawn a new process (on UNIX), you use `fork()`. `fork()` creates an exact copy of the process, with the only difference being its return value: 0 in the child, and the PID of the child in the parent (or negative for errors).

### Copy-on-Write

Instead of naively copying the entire address space on fork, modern OSes use a technique called *copy on write*: the child and parent processes intially **share** the same address space as read-only, then when one of them tries to write to the shared memory a page fault is generated and a copy of the requested data is created for the process to write to.

## `wait()`

When a child process exits, it becomes a "zombie": its data is freed but its PCB is kept with status `ZOMBIE`. The parent process is responsible for cleaning up its children via `wait()`.

`wait()` blocks (unless there are no children, in which case it returns an error) the current process until a child process exits, then returns that process' PID. This way, we can enforce an execution order between the parent and child.

`waitpid()` lets you wait for a specific child process. It takes 3 arguments, see man for info.

There are some macros to inspect the exit status of a child; see man maybe? are they on there

## `exec()`

The `exec` syscall *replaces* the current process' program with a new program. This means that all code after the `exec` call (if it is successful) is never executed.

One of the few things that is kept after `exec` is the parent process' environment.
