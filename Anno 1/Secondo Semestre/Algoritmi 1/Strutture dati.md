Fino ad ora abbiamo visto solo 2 strutture dati, entrambe molto semplici: array ordinati e disordinati
Ogni struttura dati ha vantaggi e svantaggi (per esempio l'array ordinato è molto efficiente nella ricerca)

Le strutture dati possono essere:
- Lineari/Non lineari
    Ci si può accedere o no tramite un indice (es. array vs. albero)
- Statiche/Dinamiche
    Possono cambiare dimensione o sono di dimensione fissa (es. String vs. StringBuilder)
- Omogenee/Disomogenee
    Contengono un singolo o più tipi di dati

In genere le strutture dati possono memorizzare qualsiasi tipo di dato, ed è il programmatore che deve scegliere la struttura adatta per ogni algoritmo

# Insiemi dinamici
Un esempio di insieme dinamico è una struttura dati che contiene chiavi legate ad altri dati satellite
    Nelle operazioni sulla struttura come l'ordinamento non importano i dati satellite, solo le chiavi

## Operazioni
### Operazioni di interrogazione
Le operazioni di interrogazione *non modificano* la struttura dati.
Ad esempio la funzione `Search(S, k)` che recupera l'elemento con chiave `k` in `S`
Altri esempi sono `Predecessor(S, k)` e `Successor(S, k)` che tornano la chiave che sarebbe subito dopo `k` *se `S` fosse ordinato*

### Operazioni di modifica
Le operazioni di modificano modificano la struttura dati.
Per esempio `Insert`, `Pop`...

# Array
Gli array possono essere suddivisi in array *ordinati* e *disordinati*, che come abbiamo visto hanno proprietà molto diverse

## Operazioni
### Ricerca
- Array disordinati: costo $O(n)$
- Array ordinati: costo $O\log(n)$

### Minimo/Massimo
- Array disordinati: costo $\Theta(n)$
- Array ordinati: costo $\Theta(1)$

### Predecessor/Successor
- Array disordinati: costo $\Theta(n)$
- Array ordinati: costo $\Theta(1)$

### Inserimento
- Array disordinati: costo $\Theta(1)$
- Array ordinati: costo $O(n)$

### Rimozione
- Array disordinati: costo $\Theta(1)$
- Array ordinati: costo $O(1)$

# Liste puntate semplici
### Puntatori
"Puntate" si riferisce ai *puntatori*
Un puntatore è una variabile che ha come valore un indirizzo di memoria
Quindi, al contrario delle variabili normali, si riferiscono ai valori indirettamente
Quindi mentre `int x = 5` si riferice al valore 5, `int *x = 5` si riferisce all'*indirizzo in memoria* 5 (dove ci deve essere un intero)

## Struttura
Ogni elemento di una lista puntata è un insieme dinamico con una chiave ed un campo `next` che punta al prossimo elemento della lista
Nello pseudocodice useremo `p.key` per indicare il contenuto del campo `key` dell'elemento puntato da `p` e `p.next` per indicare il contenuto del campo `next` puntato da `p`, e `\` per indicare `null`
Una lista puntata semplice ha elementi organizzati in successione
Ci si accede sempre da un'estremità tramite un puntatore alla testa della lista, e l'accesso è necessariamente *sequenziale*
    Quindi *non* ci si può accedere per indice in tempo lineare

## Operazioni
### Ricerca
```python
#@param p  puntatore alla lista
#@param k  valore da cercare
#@return   puntatore all'elemento della lista con valore k
def Search(p, k):
    p_corr = p      # non possiamo usare p perché se lo spostiamo non possiamo più accedere alla lista
    while (p_corr is not None) and (p_corr.key != k):
        p_corr = p_corr.next

    return p_corr   # retituisco il puntatore al valore dato che non si può accedere a liste puntate per indice
```
Vediamo che questo algoritmo ha costo in $O(n)$

### Inserimento in testa
Dato che l'unico modo per trovare l'ultimo elemento di una lista puntata è scorrerla tutta, è molto più efficiente aggiungere l'elemento in testa alla lista:
```python
#@param p  puntatore alla lista
#@param k  valore da aggiungere in forma di lista puntata con 1 elemento
def Insert(p, k):
    if k is not None:
        k.next = p
    p = k
```
Vediamo che questo algoritmo ha costo $\Theta(1)$

**Osservazione**
Mentre per un array basta allocare memoria solo alla creazione dell'array, per le liste puntate bisogna allocare memoria ogni volta che si aggiunge un elemento (per creare l'insieme dinamico con chiave e puntatore), ma non quando è creata

### Inserimento per puntatore
```python
#@param p  puntatore alla lista
#@param k  elemento da inserire
#@param d  puntatore all'elemento dopo il quale aggiungere k
def InsertAfterD(p, k, d):
    if d is not None:
        k.next = d.next
        d.next = k
```

### Rimozione
```python
#@param p  puntatore alla lista
#@param k  puntatore all'elemento da rimuovere
def Remove(p, k):
    if k is not None:
        if k = p:               # se k è il primo elemento
            p = p.next          # bisogna anche liberare la memoria ma nei linguaggi moderni è automatico
        p_corr = p
        while p_corr.next != k: # dato che non conosco l'elemento precedente devo scorerr la lista
            p_corr = p_corr.next
        p_corr.next = k.next
```
Costo: $O(n)$

**Osservazione**
Le liste puntate sono strutture inerentemente ricorsive: è quindi possibile implementare queste operazioni con algoritmi ricorsivi
    Infatti ogni elemento di una lista puntata punta ad una lista puntata

## Liste doppiamente puntate
Abbiamo visto che con le liste puntate ci sono alcuni problemi generati dal fatto che conosciamo solo l'elemento successivo
Possiamo quindi creare una lista che punta sia all'elemento successivo *che all'elemento precedente*
Questo permette di rimuovere elementi in tempo costante, dato che non bisogna scorrere l'intera lista

# Python List
Le `List` di Python sono simili ad array, ma sono dinamiche e disomogenee
Questo è possibile perché le `List` contengono sia un array che una lista puntata: ogni elemento della lista punta ad un elemento dell'array, e quando l'array si riempe si aggiunge in coda alla lista un puntatore ad un *secondo array*

## Operazioni
- `append`
    Costo: $\Theta(1)$
- `insert`
    Costo: $O(n)$, perché deve scorrere tutto l'array
- `pop`/`del`
    Costo: $O(n)$, stesso motivo
- `concatenate`
    Costo: $\Theta(k)$, dove `k` è la lunghezza della seconda lista

# Pila
La pila è una struttura dati con comportamento "Last In First Out" (LIFO): gli elementi vengono estratti nell'ordine inverso di come sono stati inseriti
Un esempio di una pila è la pila di sistema, lo "stack", che traccia le chiamate di funzioni

## Operazioni
- `push` (inserimento)
- `pop` (estrazione)

**Osservazione**
Entrambe queste operazioni lavorano sullo stesso elemento: la cima della pila (puntatore `top`)

## Implementazione
Dobbiamo usare una struttura dati lineare, quindi abbiamo come opzioni liste (puntate) e array

Con liste:
```python
# @param top  puntatore alla testa della lista
# @param e    puntatore all'elemento da inserire
# @return     puntatore alla nuova testa
def Push(top, e):
    e.next = top
    return e

def Pop(top):
    if top is None:
        throw NullPointerException
    e = top
    top = top.next
    e.next = None
    return e
```
Entrambe queste operazioni hanno costo in $\Theta(1)$

Con array:
    Uguale ma inserisci/rimuovi in coda, costo lineare

# Coda
La coda invece ha comportamento "First In First Out" (FIFO)
Deve quindi avere due puntatori: la coda e la testa

## Operazioni
- `enqueue` (inserimento)
- `dequeue` (estrazione)

## Implementazione
Con liste:
```python
# @param head  puntatore alla testa della coda
# @param tail  puntatore alla coda della coda
# @param e     puntatore all'elemento da inserire
# @return  puntatori alla nuova coda e testa
def Enqueue(head, tail, e):
    if tail is None:
        tail = e
        head = e
    tail.next = e
    tail = e
    return head, tail


# @return  puntatori a testa, coda e elemento
def Dequeue(head, tail):
    if head is None: throw NullPointerException

    e = head
    head = e.next
    e.next = None
    if head is None: tail = None

    return head, tail, e
```

Con gli array:
    Ci conviene mettere tail all'ultimo elemento dato che inserire elementi dall'ultimo indice ha tempo costante
    Possiamo mettere head come primo elemento dato che non è necessario spostare gli elementi a sinistra quando estraiamo
    C'è però un problema: gli elementi si sposteranno man mano verso destra nell'array finché non si avrà un array pieno di None
    Soluzione: code circolari
```python
def Enqueue():
    
```

# Code con priorità
Sono una variante delle code, ma invece di avere come criterio di estrazione quanto "tempo" un oggetto è stato nella coda, si estrae in base ad un'ulteriore attributo degli oggetti, detto *priorità*
Per la priorità si può usare per esempio la chiave dell'oggetto
    In questo caso un array ordinato diventa una coda con priorità
    Anche l'heap è una coda con priorità
Le code "normali" sono una sorta di coda con priorità, dove la priorità è l'ordine di inserimento degli oggetti
