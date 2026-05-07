# Definizione
I dizionari sono una [[Strutture dati|struttura dati]] astratta dinamica con 3 operazioni:
- Inserimento
- Ricerca
- Rimozione
I dizionari sono fondamentali nelle basi di dati

Tra le strutture dati che abbiamo visto, ci sono alcune strutture che potremmo usare per memorizzare i dizionari: array, liste concatenate e liste concatenate doppie
Ma non sono adeguate per questa struttura: negli array ordinati la rimozione e l'inserimento sono in $O(n)$, la ricerca negli array disordinati è in $O(n)$, ecc.
Ci servono delle nuove strutture dati:
- Tabelle and indirizzamento diretto
- Tabelle hash
Queste tabelle sono memorizzate come array, quindi hanno dimensione fissa
### Nomenclatura
- $U$: insieme "universo" dei valori che le chiavi *possono* assumere; sono numeri interi
- $m$: numero di posizioni a disposizione nella struttura dati
- $n$: numero di elementi presenti nel dizionario; gli elementi hanno chiavi diverse tra di loro

## Tabelle a indirizzamento diretto
Molto banalmente una tabella ad indirizzamento diretto è un array dove ogni elemento è posizionato all'indice pari alla sua chiave
Ovviamente in questo modo ognuna delle 3 operazioni necessarie hanno costo in tempo lineare

Però questa struttura ha un problema: l'array dovrà essere grande quanto tutti i possibili valori che le chiavi possono assumere
Ovviamente questo non è pratico, quindi vogliamo trovare una tabella che funziona in modo simile ma che ha un numero di possibili chiavi più vicino al numero di elementi che vogliamo memorizzare

## Tabelle hash
Assumendo che $m > n$, si può definire una funzione detta *funzione hash* che data una chiave calcola l'indice corrispondente alla chiave
Però c'è un problema: dato che l'insieme delle chiavi possibili è molto più grande dell'insieme delle chiavi attuali, potrebbe succedere che la funzione hash assegni lo stesso indice a 2 valori diversi
Una buona funzione hash quindi rendere il più possibile equiprobabili i valori fino a $m - 1$ che produce; deve quindi apparire come una funzione casuale, ma deve essere comunque deterministica in modo tale da poter accedere ai suoi elementi
    L'ipotesi che ogni valore avrà un hash differente è detta *ipotesi di uniformità semplice della funzione hash*
Le collisioni sono però inevitabili, quindi bisogna risolverle in qualche modo
### Liste di trabocco
Risolve le collisioni inserendo tutti gli elementi che hanno lo stesso hash in una [[Strutture dati#Liste puntate semplici|lista concatenata]]
In media le liste avranno lunghezza 1, ma è tecnicamente possibile che ogni elemento finisca nella stessa lista
Quindi in media il costo di ricerca è costante, ma nel caso peggiore è in $\Theta(n)$
Il costo di inserimento è sempre costante
Il costo di cancellazione è relativo al costo di rimozione delle liste puntate/doppiamente puntate

### Indirizzamento aperto
Sono usate nei dizionari di Python
Le liste di trabocco allocano nuova memoria per ogni dato duplicato, ma se la tabella è dimensionata bene allora ogni elemento entrerà nella tabella, che abbiamo già allocato
    Inoltre se dobbiamo accedere a memoria secondaria il costo computazionale aumenta di molto
Quindi invece di usare liste in ogni posizione dell'array si calcolano le posizioni da controllare
Per questo si usa una *funzione hash a 2 parametri*: il primo parametro è la chiave e, se si genera una collisione, si aumenta il secondo parametro
    Il processo si ripete fino a che non si trova uno spazio libero

Un problema ovvio è che potrebbe succedere che non si trova uno spazio libero fino a che non si è iterato tutto l'array, quindi nel caso peggiore il costo è $O(n)$. Nel caso medio il costo è $1/(1-\alpha)$ (dove $\alpha$ è il fattore di carico; generalmente è vicino a 1)
**Operazioni**:
- Ricerca
    Nel caso peggiore (l'elemento non è presente) il costo è in $O(n)$; nel caso medio $\Theta(1/1-\alpha)$
    Se l'elemento è presente il costo è $\frac{1}{\alpha}\ln\frac{1}{1-\alpha}+\frac{1}{\alpha}$
        Il costo medio è indipendente dal numero di elementi nella tabella
- Cancellazione
    Non si può semplicemente cancellare un elemento: la ricerca di un oggetto si ferma quando trova uno spazio vuoto, ma potrebbero esserci altri elementi con valori del secondo parametro della funzione hash più grande
    Bisogna quindi usare un valore speciale per indicare che un elemento è stato cancellato
        Così facendo però l'elenco di posizioni di un certo hash cresce sempre di più
        mi sono perso la soluzione
Tutte le operazioni hanno costo nel caso peggiore di $O(n)$
    Quindi nel caso peggiore creare un nuovo dizionario a partire di un array si ha costo di $\sum_{i=1}^{n}O(i)=O(n^2)$

#### Hashing doppio
Invece di usare una funzione hash a due parametri, si possono usare 2 funzioni hash
    Guarda slide per esempio
È favorevole perché è molto improbabile che 2 elementi generino collisioni su 2 funzioni hash

# Alberi binari di ricerca
Un ABR è un albero in cui vengono mantenute le seguenti proprietà:
- Ogni nodo contiene una chiave
- Il valore di ogni nodo è maggiore del valore del figlio sinistro
- Il valore di ogni nodo è minore del valore del figlio destro
Una proprietà di questa struttura è che "proiettando" le foglie orizzontalmente si ottiene un array ordinato
    Per creare questo elenco ordinato basta eseguire una visita in-ordine
Questo permette di effettuare ricerche usando l'algoritmo di ricerca binaria
    La radice è il centro dell'array
Sono memorizzati con record e puntatori con inoltre un puntatore al padre

## Operazioni
- `Search(T, k)`
    Restituisce un puntatore all'elemento con chiave `k` in `T`
- `Min(T), Max(T)`
    Basta percorrere l'albero andando sempre a destra o sempre a sinistra
    I risultati non sono necessariamente foglie: potrebbero avere figli destri/sinistri
    Costo: $O(h)$
        $h$ non è $\log(n)$ perché non è un albero completo o quasi completo
        $h = \begin{cases} \Omega(\log n) \\ \Theta(n) \end{cases}$
- `Predecessor(T, p), Successor(T, p)`
    Restituisce un puntatore all'elemento in `T` che sarebbe prima/dopo la chiave di `*p`
- `Insert(T, k)`
- `Delete(T, p)`

### Ricerca
Simile alla ricerca binaria:
```python
def ABR_searchRec(p, k):
    if p is None or p.key = k:
        return ;
    if k < p.key: return ABR_searchRec(p.left, k)
    else return ABR_searchRec(p.right, k)
```
Costo: $\begin{cases} T(h) = T(h-1) + \Theta(1) \\ T(1) = \Theta(1) \end{cases}$
    Nel caso peggiore sarà $O(n)$ ma nel caso medio è $O(\log n)$

### Inserimento
```python

def ABR_insert(p, k):
    '''
    :param p: puntatore all'albero
    :param k: chiave da inserire
    '''
    y, x = None, p
    z = NodoABR(k)
    while x is not None:
        y = x
        if z.key < x.key:
            x = x.left
        else:
            x = x.right
    if y is None:
        p = z
    else:
        if x.key < y.key:
            y.left = z
        else:
            y.right = z
    z.parent = y
    return p
```

# Alberi AVL
Abbiamo visto che il problema degli ABR è che non è garantito che l'altezza sia bilanciata
    Hanno operazioni in $O(h)$ ma $h$ potrebbe essere uguale a $n$
Gli alberi AVL sono ABR bilanciati tramite delle tecniche di bilanciamento, quindi risolvono questo problema mantenendo le proprietà degli ABR
    Le tecniche di bilanciamento sono basate sull'idea di riorganizzare l'albero dopo ogni inserimento o eliminazione
Lo scopo è mantenere il costo delle operazioni in $O(h)$, ma garantendo $h = O(\log n)$

## Bilanciamento
Il metodo che vedremo si basa sul controllare che, per ciascun nodo dell'albero, la differenza di altezza dei suoi sottoalberi non sia troppo "differente"

### Fattore di bilanciamento
In un albero binario, il *fattore di bilanciamento* (fdb) è definito come la differenza tra l'altezza del suo sottoalbero destro e l'altezza del sottoalbero destro: `fdb = node.left.height - node.right.height`

## Definzione
**Un albero AVL è un albero binario di ricerca in cui *il fdb di ogni nodo è compreso tra -1 e 1***
Vedremo che questa condizione basta per garantire $h = O(\log n)$, cioè:

Teorema: **Gli alberi AVL sono bilanciati.**
### Dimostrazione
Sia $N(h)$ il *numero minimo di nodi che può avere un albero AVL di altezza $h$.*
    Vediamo alcuni $N(h)$: (guarda slide per disegni)
    $N(1) = 1$
    $N(2) = 2$
Per $h \geq 2$, i due sottoalberi della radice dell'albero di altezza $h$ con il numero minimo di nodi non possono avere la stessa altezza, altrimenti si potrebbe ridurre il numero di nodi
Quindi (ecc.)
Possiamo esprimere $N(h)$ in modo ricorsivo:
$$
\begin{gather}
    N(h) = N(h-1) + N(h-2) + 1 \text{ per } h \geq 2 \\
    N(1) = 1 \\
    N(2) = 2
\end{gather}
$$
Risolvendo come un eq. di ricorrenza ottineniamo $N(h) = 2^{h/2 + 1} - 1$
Poiché $n \geq N(h)$:
    $\log(n+1) \geq \frac{h}{2} + 1$
    $h \leq 2\log(n+1) - 2 \Rightarrow h = O(\log n)$ per tutti gli AVL. (CVD)


Questo teorema garantisce che le operazioni di ricerca sugli AVL hanno costo logaritmico, ma questo non è vero per inserimento e rimozione come definiti per gli ABL
Infatti dopo una modifica sull'albero si potrebbe perdere la condizione di bilanciamento; bisogna quindi ribilanciare l'albero dopo ogni modifica

## Rotazioni
Per risolvere questo problema dobbiamo introdurre le rotazioni
Le rotazioni permettono di ripristinare la forma di AVL dopo le modifiche in tempo logaritmico
Possono essere destre o sinistre
    Guarda slide per disegno
Le rotazioni hanno costo costante: si modificano sempre solo 6 puntatori
```python
def AVL_rotazione_sinistra(p, a):
    '''
    :param p:  puntatore alla radice dell'albero
    :param a:  puntatore al nodo su cui si ruota
    '''
    b = a.right
    a.right = b.left
    if a.right is not None:
        a.right.parent = a
    b.left = a
    b.parent = a.parent
    if a.parent is None:
        p = b
    else:   # se a è un sottoalbero
        if a == a.parent.left:
            a.parent.left = b
        else:
            a.parent.right = b
    a.parent = b
    return p
```
**Osservazione**: le visite in-ordine non cambiano dopo una rotazione.

## Operazioni
### Inserimento
Dato che gli AVL sono ABR, il primo passo è inserire come in un ABR
Poi mentre si risale si ribilancia l'albero
    Solo sul cammino tra radice e nodo modificato, gli altri nodi non possono essere stati modificati
    Quindi il numero di nodi disturbati è massimo $h$ quindi logaritmico

Quindi per ribilanciare:
- Si cerca il nodo più profondo che è stato sbilanciato
- Si esegue una rotazione su quel nodo
    Possibilmente 3 rotazioni
    Guarda slide per spiegazione

In totale il costo sarà:
- Inserimento: $O(h) = \log n$
- Calcolo fdb: $O(h)$
- Ribilanciamento: $O(1)$
Quindi in totale $O(\log n)$.

### Cancellazione
Quasi stesso procedimento dell'inserimento:
- Cancella come in ABR
- Ricalcola fdb
- Ribilancia se si è sbilanciato
- Propagazione del ribilanciamento
    Lo sbilanciamento potrebbe propagarsi quindi bisogna ribilanciare più volte
    Il sottoalbero potrebbe diventare più corto dopo il ribilanciamento e quindi sbilanciare un albero più in alto
Il costo totale rimane $O(\log n)$
