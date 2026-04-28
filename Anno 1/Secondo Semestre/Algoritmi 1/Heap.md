Esiste un algoritmo detto *heapsort* che ha vantaggi sul quicksort, ma per capirla dobbiamo introdurre la struttura dati detta *heap*

Questa struttura dati è stata inventata per eseguire in modo efficiente una sequenza di operazioni di:
- Estrazione del massimo
- Inserimento e cancellazioni
Ripristinando la struttura in modo da poter eseguire nuovamente le operazioni
Questo su un'array è costoso: infatti dopo aver eliminato un elemento di un array ordinato, per mantenere l'ordine bisogna spostare tutti gli elementi dopo l'elemento eliminato per riempire il buco
    Stessa cosa per l'ordinamento
L'heap invece è molto efficiente: impiega tempo in $O(\log n)$ per estrazione del massimo/minimo, inserimento e cancellazione di un elemento

## Definizione
L'heap è un albero binario completo (ogni nodo ha 2 figli) o quasi completo (mancano sul lato destro), inoltre con proprietà dell'ordinamento verticale: la chiave di ogni nodo è maggiore o uguale delle chiavi di qualsiasi dei suoi 2 sotto-alberi

### Implementazione
La definizione che abbiamo visto è "astratta", non ci spiega come è memorizzato l'heap
Vediamo ora come funzione nella pratica:
Per memorizzare un heap si usa un array $A$, con indici che vanno da 0 al numero di nodi dell'heap (`heap_size`) - 1; questi indici sono messi in corrispondenza con gli elementi dell'albero:
$A$ è un array disordinato con la radice dell'albero in prima posizione
I figli di ogni nodo saranno in posizione `2i + 1` e `2i + 2`, con `i` indice del nodo

## Funzioni
Per utilizzare correttamente l'heap bisogna definire delle funzioni ausiliarie:
- Heapify
    Riorganizza l'heap
- Buildheap
    Crea un nuovo heap
- Heapify_bottom_up

### Heapify
Supponiamo di avere un heap che è stato disturbato solo alla radice
Data vera questa ipotesi, `Heapify` può ripristinare le proprietà dell'heap
Ecco come funziona:
- Confronta la radice con i suoi figli e la scambia con il più grande
- Procede ricorsivamente sul sotto-albero la cui radice è stata modificata

Pseudocodice:
```python
def heapify(A, i, heap_size):
    # i è l'indice del nodo disturbato, quindi inizalmente i = 0
    L, R = left(i), right(i)
    i_max = i
    if L < heap_size and A[L] > A[i]:
        i_max = L
    elif R <= heap_size and A[R] > A[i_max]:
        i_max = R

    if i_max != i:
        A[i], A[i_max] = A[i_max], A[i]
        Heapify(A, i_max, heap_size)
```

### Buildheap
`Buildheap` prende un qualsiasi array disordinato e lo trasforma in un heap
Dato che ogni foglia è un heap, si può usare la funzione `Heapify` partendo dal basso:
```python
def build_heap(A):
    for i in range(len(A)//2, -1): # scorre l'array al conrario, partendo dall'ultimo elemento
    # partiamo dalla metà dell'array dato che le foglie sono già heap; il nodo medio è il primo che non è una foglia
        heapify(A, i, heap_size)

```
Il costo di questa funzione sarà $T(n)=O(n\log n)$, dato che chiama la funzione `heapify` $\frac{n}{2}$ volte
Però effettivamente possiamo vedere che il costo effettivo di questa funzione è in $\Theta(n)$, dato che la maggior parte dei sottoalberi è piccolo

## Operazioni
### Inserimento
Per essere utile, una struttura dati deve mantenere la sua forma dopo inserimenti e rimozioni
Quindi se vogliamo inserire un elemento dobbiamo farlo in modo da non disturbare l'heap:
- Inseriamo il nuovo elemento $k$ come nuova foglia
- Creiamo una funzione `heapify_bottom_up` simile a `heapify` ma che funziona dal basso verso l'alto
```python
def heapify_bottom_up(A, heap_size):
    padre = ceil(heap_size/2 - 1)
    if A[padre] < A[heap_size - 1]:
        A[padre], A[heap_size - 1] = A[heap_size - 1], A[padre]
        if padre > 0
            heapify_bottom_up(A, padre)
    return
```
Questa funzione avrà costo in $O(\log n)$ dato che fa operazioni al massimo una volta per livello dell'albero
Per avere una stima più precisa dobbiamo considerare 2 casi:
- Caso completo
    L'albero binario è completo, $T(n)=T(\frac{n}{2}) + \Theta(1)$
- Caso sbilanciato
    L'albero binario non è completo, $T(n)=T(\frac{2}{3}n) + \Theta(1)$
        Il numero di foglie di un albero binario è circa uguale ai nodi del sottoalbero al livello h-1, quindi se mancano le foglie di metà dell'albero ci sono 2/3 dei nodi tipo

Vediamo ora la funzione di inserimento:
```python
def inserisci_in_heap(A, heap_size, k):
    if heap_size = len(A):
        throw ArrayFullException
    A[heap_size] = k
    heap_size += 1
    if heap_size > 0
        heapify_bottom_up(A, heap_size)
    return
```
Costo: $O(\log n)$

### Rimozione
Se vogliamo rimuovere un elemento "tappando il buco", non ci basta chiamare heapify sull'indice rimosso: il buco si sposterà all'ultimo livello, ma potrebbe finire tra altre foglie e non alla fine dell'array come previsto
Possiamo quindi prendere l'ultima foglia e tappare il buco e poi:
- Se è più grande del padre chiamo `heapify_bottom_up`
- Se è più piccolo dei figli chiano `heapify`

### Estrazione minimo
Basta scorrere la metà destra dell'array
Costo: $\Theta(n)$

## Heapsort
### Strategia
Fase 1:
- Trasforma array in heap
    `build_heap` ha costo $\Theta(n)$
- Scambio il massimo (la radice) con l'ultimo elemento, ripristino la forma dell'heap e riduco `heap_size`
    Mettendolo in ultima posizione è già in posizione corretta
    Riducendo heap_size non sarà considerato da `heapify`

Fase 2:
- 

```python
def heapsort(A):
    build_heap(A)
    for x in range(1, len(A), -1):
        A[0], A[x] = A[x], A[0]
    ... completa
```
Costo: $O(n\log n)$
Vediamo che l'heapsort è l'algoritmo più efficiente tra quelli che abbiamo visto dato che impiega tempo $n\log n$ anche nel caso peggiore
