Abbiamo già incontrato gli alberi come struttura dati quando abbiamo parlato dell'heap

Gli alberi sono molto versatili: sono applicabili in molte situazioni e permettono di risolvere con facilità problemi non ovvi

# Grafi
Formalmente gli alberi sono un tipo di *grafo*, che sono oggetti matematici formati da una coppia di insiemi: un insieme di nodi $V$ ed un insieme di archi $E\subset V\times V$
### Definizioni
- Cammino
    Un *cammino* in un grafo è una sequenza di nodi distinti connessi a due a due
    Se il primo ed ultimo nodo di un cammino coincidono si dice che è un **ciclo**
- Grafo connesso
    Un grafo G è connesso se, per ogni coppia di nodi $u, v$ esiste un cammino tra $u$ e $v$.
- Grafo aciclico
    Un grafo è aciclico se non contiene cicli.

# Definizione
Un albero può essere definito come un *grafo connesso e aciclico*.

## Lemma
Sia $G=(V, E)$ un grafo connesso aciclico. Eliminando da $G$ un arco qualsiasi, G si disconnette in *due* grafi connessi e aciclici.
    Si dimostra per assurdo: se fosse ancora connesso dopo aver eliminato un arco sarebbe ciclico

## Teorema (caratterizzazione per gli alberi)
Sia $G=(V,E)$ un grafo. Le seguenti affermazioni sono equivalenti ($1\iff 2$):
    1. $G$ è connesso e aciclico.
    2. $G$ è connesso e $|E| = |V| - 1$ (il numero di archi è uguali an numero di nodi - 1).

$1.\to 2.$ Si dimostra per induzione usando il lemma; $2.\to 1.$ si dimostra per assurdo assumendo che l'albero contenga un ciclo

# Alberi radicati
Gli alberi radicati sono un tipo di albero in cui si distingue un nodo detto *radice*
Questi alberi possono essere rappresentati in modo tale che i cammini da ogni nodo alla radice seguano un percorso dal basso verso l'alto
    Quindi si ha la radice come primo nodo, ogni altro nodo sta sotto di essa

In un albero radicato:
- I nodi sono organizzati in livelli
- L'altezza è la lunghezza del cammino più lungo dalla radice ad una foglia
- I nodi che hanno lo stesso padre sono detti *fratelli*
- I ogni nodo nel cammino tra la radice ed un nodo $v$ escluso è detto *antenato* di v

## Alberi radicati ordinati
Un albero radicato è detto ordinato se i figli di ciascun nodo hanno un ordine

### Alberi radicati ordinati binari
Un albero radicato ordinato è binario se ogni nodo ha solo al più 2 figli
Se ogni nodo di un albero binario ha 2 figli si dice *completo*
Se un albero binario è completo tranne per le foglie, dove possono mancare le foglie "su una metà", si dice *quasi completo*

Numero nodi: $n=2^{h-1}-1$, quindi: $h=\log(n+1)-1=\log(\frac{(n+1)}{2})$

# Rappresentazione in memoria
Gli alberi sono una struttura dati astratta; ci sono 3 modi per implementarli:

### Record e puntatori
Questo è il metodo più diffuso
Come nelle [[Strutture Dati#Liste puntate semplici|liste puntate]], ogni nodo è rappresentato da un record contenente:
- key
    Informazioni sul nodo
- left
    Puntatore al figlio sinistro oppure None
- right
    Puntatore al figlio destro oppure None
Un problema di questa rappresentazione è che non si conosce il percorso necessario per raggiungere un qualsiasi nodo

### Rappresentazione posizionale
È lo stesso tipo di rappresentazione dell'[[Heap|heap]]:
I nodi sono memorizzati in un array dove la radice è ad indice $0$ ed i figli sono in posizione $2i+1$ e $2i+2$
Uno svantaggio di questa rappresentazione è che dato che gli array sono statici, bisogna conoscere il numero di nodi che sarà contenuto
    Dato che l'array deve contenere tutti i nodi, la sua dimensione cresce in modo esponenziale rispetto all'altezza dell'albero
Inoltre dato che per rappresentare un nodo senza un figlio bisogna usare un None, si spreca molta memoria se l'albero non è denso

### Vettore dei padri
Si usa un array in cui ogni elemento è associato ad un nodo dell'albero
    Quindi non ci saranno spazi come nella rappresentazione posizionale
Ogni elemento dell'array contiene un record che memorizza la chiave e l'indice del padre del nodo
Il problema di questa memorizzazione è che è difficile trovare i figli di un nodo

## Confronto tra le memorizzazioni
### Trovare il padre
- Record e puntatori
    Per ora non sappiamo come farlo
- Posizionale
    Tempo costante: il padre è sempre ad indice $\frac{i - 1}{2}$
- Vettore dei padri
    Tempo costante: il padre è il valore nell'array dei padri

### Trovare numero di figli
- Record e puntatori
    Tempo costante: guarda i due puntatori e controlla se sono None
- Posizionale
    Tempo costante: guarda gli indici $2i+1$ e $2i+2$
- Vettore dei padri
    Tempo in $O(n)$: bisogna scorrere l'array dei padri e contare quanti nodi hanno $i$ come padre

### Distanza di un nodo dalla radice (livello di un nodo)
- Record e puntatori
    Non sappiamo come farlo
- Posizionale
    Tempo costante: basta prendere il logaritmo dell'indice
- Vettore dei padri
    Tempo in $O(\log n): bisogna trovare il padre fino alla radice

# Visite di alberi
Una visita su un albero è un operazione che consiste nell'accedere a tutti i suoi nodi ed effettuare un operazione su ciascuno di essi
    Su un array una visita è equivalente ad iterare tutti gli elementi dell'array, ma è più complicato sugli alberi

Sugli alberi binari ci sono tre tipi di visite:
- Visita in pre-ordine
    Il nodo è visitato prima di proseguire la visita nei sottoalberi
        N -> L -> R
- Visita in in-ordine
    Il nodo è visitato tra la visita al sottoalbero sinisto e al sottoalbero destro
        L -> N -> R
- Visita in post-ordine
    Il nodo è visitato dopo le visite ai sottoalberi
        L -> R -> N

Quest'ordine è importante perché in base al tipo di operazione potrebbero servire informazioni sul padre per i figli o viceversa
Il calcolo del costo di un algoritmo di visita non è banalissimo da calcolare (vedi slide)
Costo: $\Theta(n)$

## Visita per livelli
Spesso è utile visitare un albero scorrendo i suoi livelli
Questo è banale se memorizzato posizionalmente ma non è possibile con le visite che abbiamo visto finora
Una soluzione per gli alberi record e puntatori è usare una [[Strutture dati#Coda|coda]] di appoggio: la coda memorizza i puntatori ai figli di ogni nodo e l'algoritmo segue l'ordine FIFO della coda
### Con coda
```python
def visita_per_livelli(r, head, tail):
    '''
    :param r:     radice dell'albero
    :param head:  puntatore alla testa della coda
    :param tail:  puntatore alla coda della coda
    '''
    if r is None: return
    enqueue(head, tail, r)
    while not coda_vuota(head):
        p = dequeue(head, tail)
        print(p.key)
        if p.left  is not None: enqueue(p.left)
        if p.right is not None: enqueue(p.right)
```
L'algoritmo scorre tutti gli elementi dell'albero, e le operazioni della coda sono in $\Theta(1)$, quindi il costo è $\Theta(n)$
### Con albero vettore dei padri
Il costo di una visita per livelli è $\Theta(n^2)$ dato che per trovare i figli di un nodo in un vettore dei padri richiede scorrere tutto l'array

