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
Questo permette di effettuare ricerche l'algoritmo di ricerca binaria
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
