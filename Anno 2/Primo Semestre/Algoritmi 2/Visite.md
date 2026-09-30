# DFS

Per memorizzare i vertici visitati usiamo sia un array che uno stack (così possiamo risalire)

Pseudocodice:
```python
def dfs(G, x):
    """
    algoritmo "depth first search" che ritorna la lista di nodi raggiungibili
    da x.
    param G: grafo da visitare
    param x: nodo di partenza
    """
    vis = [0 for n in G]
    s = stack()
    s.push(x); vis[x] = 1
    while not s.empty(): # 2n-1 volte
        y = s.peek()
        if (esiste un vicino z di y con vis[z] = 0): # O(n)
            s.push(z)
            vis[z] = 1
        else:
            s.pop()
    return vis
```

Dimostriamo che l'algoritmo funziona:

**Proposizione**:  
> Se $y$ è raggiungibile da $x \Rightarrow vis[y] = 1$.

Quindi: se $y$ è raggiungibile da $x \Rightarrow \exists\ v_0e_1v_1e_2...v_{k-1}e_kv_k$ con $v_0 = x;\ v_k = y$.

**Dimostrazione**:  
Per assurdo assumiamo che `vis[y] = 0`. Dato che `vis[x] = 1` allora esiste un indice `i` con `vis[v_i]=1` e `vis[v_i+1] = 0`. Poi, dato che `[vis[v_i]=1`, `v_i` è stato visitato e inserito nello stack `s`. L'algoritmo è terminato, quindi `v_i` è stato rimosso da `s`. Ma questo accade solo quando tutti i vicini di `v_i` sono stati visitati. Quindi `vis[z] = 1` per ogni vicino `z` di `v_i` $\Rightarrow$ `vis[v_i+1] = 1`, CVD.

Quest'algoritmo ha complessità $O(n^2)$. Possiamo ottimizzarlo non ripetendo la ricerca dei vertici non visitati ogni volta che torniamo su un nodo:
```python
def dfs(G, x):
    """
    algoritmo "depth first search" che ritorna la lista di nodi raggiungibili
    da x.
    param G: grafo da visitare
    param x: nodo di partenza
    """
    vis = [0 for n in G]
    s = stack()
    s.push(x); vis[x] = 1
    while not s.empty(): # O(n) volte
        y = s.peek()
        while not y.adiacenti.empty(): # O(n) volte (più precisamente O(deg(y)))
            z = y.adiacenti[0]
            y.adiacenti.remove(0)
            if vis[z] == 0:
                vis[z] = 1
                s.push(z)
                break
        if y == s.peek(): # se non ho trovato un'altro vertice allora y è ancora in cima allo stack
            s.pop()
    return vis
```

Dato che, per ogni nodo $y$, facciamo un lavoro pari a $deg(y)$, la complessità di questo algoritmo è $O(\sum_{y\in V(G)} deg(y))$. Ma abbiamo visto che la somma dei gradi di un grafo è pari a $2m$, con $m =$ numero archi. Quindi l'algoritmo ha complessità $O(2m)$.

Gli archi che usiamo per raggiungere un vertice non visitato formano un *albero di ricerca*. Gli alberi di ricerca sono sempre grafi connessi aciclici. In genere l'albero di ricerca è memorizzato tramite un vettore dei padri

Tangent: algoritmo per trovare la distanza dalla radice di un vertice in un vettore dei padri:
```python
def distanza_radice(v, n):
    x = 0
    i = n
    while v[i] != i:
        i = v[i]
        x += 1
    return x
```

Versione ricorsiva del DFS:
```python
def dfs_ric(g, x, v = [None for _ in g]): # v = vettore padri con None -> non visitato
    foreach (y adj x con v[y] == None):
        v[y] = x
        dfs_ric(g, x, v)
    return v
```

## Applicare i grafi

> Problema: con $n$ corsi e $m$ studenti, vogliamo partizionare gli esami in 2 settimane in modo tale che nessuno studente ha 2 esami nella stessa settimana

Cerchiamo di trasformare questo problema in un grafo. Possiamo scartare gli studenti che hanno solo 1 corso o più di 3 corsi, dato che o va bene qualsiasi assegnamento o nessuno.

I nodi del grafo sono *i corsi*, e gli studenti sono *gli archi*. Possiamo partizionare gli esami assegnando un colore ad ogni nodo. Non è detto che una soluzione sia sempre possibile.

Possiamo applicare il DFS per trovare una soluzione: dopo aver costruito l'albero di ricerca e, iterandolo, dobbiamo assegnare una delle due settimane al primo nodo, e ad ogni passo assegniamo a tutti i figli del nodo attuale la settimana opposta del nodo attuale.

Per costruire il grafo bipartito:
```python
def dfs_part(g, x):
    part = [0 for _ in g]
    part[x] = 1
    s = [x] # stack
    while not s.empty():
        y = s.pop()
        if (esiste z adj y con part[z] == 0):
            part[z] = 3 - part[y] # part[z] = gruppo opposto di part[y]
            s.push(z)
        else s.pop()
    return part
```

Per controllare se la soluzione è valida:
```python
def bipartisci(g):
    x = un nodo di g
    part = dfs_part(g, x)
    for (u, v) in archi(g):
        if part[u] == part[v]: return None
    return part
```

# Grafi diretti

Il DFS si può applicare anche su grafi diretti, basta seguire la direzione degli archi incidenti ai nodi. Gli alberi di visita di grafi diretti sono chiamati *arborescenze*.

> Problema: un processo è diviso in $n$ lavoretti $x_1,x_2,x_3,x_4$ con le dipendenze $x_1$ prima di $x_2$, $x_2$ prima di $x_3$, $x_3$ prima di $x_1$, $x_4$ prima di $x_3$.
>
> Cercare una programmazione dei processi rispettando tutti i vincoli.

Possiamo risolvere questo problema usando il DFS su un grafo diretto: costruiamo un grafo con gli $x_n$ come nodi e i vincoli come archi. Poi se applichiamo il DFS e troviamo un cammino completo allora abbiamo trovato una soluzione.

Se otteniamo una soluzione valida, possiamo rappresentarla come una lista di nodi connessi da archi che vanno da sinistra a destra. Questa rappresentazione è detta *ordine topologico del grafo*.

```
         ┏ - - - < - - - - ┓
         v                 ^
x4 - < - x3 - < - x1 - < - x2
```
*Ordine topologico del grafo del problema.*

**Proposizione**:  
> Se il grafo $\overset{\rightarrow}{G}$ definito dai processi contiene un ciclo diretto $\Rightarrow\ \not \exists$ una soluzione.

**Dimostrazione**:  
Per assurdo assumiamo $x_1,...,x_k$ sono un ciclo ed esiste un ordine topologico. Uno dei vertici $x_i$ viene prima nell'ordine $\Rightarrow\ x_{i+1}$ viene dopo nell'ordine $\Rightarrow$ l'arco $(x_i, x_{i+1})$ non rispetta l'ordine. (?)

**Proposizione**:  
> Se $G$ è un grafo diretto senza cicli $\Rightarrow\ \exists$ un vertice $v$ senza archi uscenti.

Questa proposizione è equivalente a:  
> Se $\forall$ vertice $\exists$ almeno un'arco uscente $\Rightarrow\ G$ contiene un ciclo.

Possiamo scrivere un algoritmo che prende un grafo diretto con vertici con almeno un arco uscente e che ritorna un ciclo
```python
# TODO:
```

## Trovare un ordine topologico

Abbiamo dimostrato che ogni grafo senza cicli ha almeno un arco senza archi uscenti. Usando questo fatto, per trovare l'ordine topologico basta, ad ogni passo, aggiungere l'arco che non ha archi uscenti alla lista ed eliminarlo.
```python
def ord(g): # g = grafo diretto aciclico
    l = []
    while not g.empty(): # n volte
        v = trova_senza_uscenti(g) # O(n)
        l.append(v)
        rimuovi v dal grafo # O(m): bisogna rimuovere v dalla lista di adiacenza di tutti i nodi di v
    return l
```

Dato $P$ il vettore dei padri e i vertici $x,y$, per trovare l'antenato comune più vicino:
```python
def sol1(p, x, y):
    l1, l2 = [] # liste
    do { # antenati di x; il primo elemento è la radice
        l1.insert(x, 0)
        x = p[x]
    } while p[x] != x
    do { # antenati di y
        l2.insert(y, 0)
        y = p[y]
    } while p[y] != y
    current = l1[0]
    while l1[1] == l2[1]:
        current = l1[1]
        l1.remove_first()
        l2.remove_first()
    return current
```
