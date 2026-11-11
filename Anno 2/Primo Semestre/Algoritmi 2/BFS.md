# BFS

Problema:  
Dato un grafo $G$ non diretto, trovare la distanza (lunghezza (numero di archi) minima di un cammino) tra $x$ e $y$. Per risolvere questo problema dobbiamo anche trovare $dist(x,z)\forall z\in G$.
- La distanza tra $x$ e $x$ è 0.
- La distanza tra $x$ ed i suoi vicini è 1.
- I vertici adiacenti ai vicini di $x$ hanno distanza 2.
- ...
Vediamo che in questo modo stiamo facendo una ricerca *in larghezza*. Quest'algoritmo è il *breadth first search* (BFS):
```python
def bfs(g: Grafo, x: Vertice):
"""
distanza da un vertice con breadth first search
param g: grafo
param x: vertice di partenza
return:  array contenente la distanza tra `x` e `y` per ogni indice `y`
complessità: O(n+m)
"""
    dist = [-1] * g.len()
    dist[x] = 0
    q: Queue = [x]
    # non possiamo fare una cosa del genere:
    # for y in x.vicini:
    #    dist[y] = 1
    # dobbiamo usare una coda:
    while not q.empty(): # n volte
        y = q.pop()
        for z in y.vicini: # deg(y) volte
            if dist[z] == -1: # non visitato
                dist[y] + 1
                q.enqueue(z)
    return dist
```

*Proposizione*:  
Sia $G$ un grafo, $x,y$ vertici. Se $dist(x,y)=k\Rightarrow \exists$ un vicino $z$ di $y$ con $dist(x,z)=k-1$.

*Dimostrazione*:  
Sia $P$ un cammino di lunghezza $k$ da $x\to y$. Se $x$ e $y$ sono adiacenti, $k=1$ e il vicino $z$ è $x: dist(x,x) = 0 = k-1$. Altrimenti prendiamo $z$ il vertice subito prima di $y$ lungo $P$.

## Correttezza

Dimostriamo la correttezza del BFS.

Vogliamo dimostrare: `dist[y]`$=dist(x,y)\forall y$.
- Per $x$: `dist[x]`$=0=dist(x,x)$.
- Per $y$ con $dist(x,y)=1$, `dist[y]`$=1$.
- Supponiamo che per ogni $z$ con $dist(x,z)=k-1$ allora `dist[z]`$=k-1$ e $dist(x,y)=k$. Per la proposizione, $\exists z' \text{ adj }y$ con $dist(x,z')=k-1\Rightarrow$`dist[z']`$=k-1\Rightarrow$ quando $z'$ è stato in prima posizione nella coda abbiamo segnato `dist[y] = dist[z']+1 = k-1+1 = k` $\Rightarrow$ ogni vertice $y$ con $dist(x,y)=k$ ha `dist[y]=k`.

## Cammini

Per trovare anche il cammino minimo tra due vertici dobbiamo anche i cammini del BFS.

Da notare che il numero massimo di cammini minimi di un BFS è $2^{n/2-1}$. Quindi non è realistico memorizzarli tutti.

```python
def bfs_completo(g: Grafo, x: Vertice):
"""
bfs con numero di cammini minimi per vertice e albero di visita
param g: grafo
param x: vertice di partenza
return: array contenente i cammini minimi per ogni vertice, array contenente la
    lunghezza dei cammini minimi, e l'albero di visita sotto forma di vettore
    dei padri
"""
    dist = [-1] * g.len()
    count = [0] * g.len() # numero di cammini minimi per ogni vertice
    p = [0] * g.len() # vettore dei padri
    q: Queue = [x]

    dist[x] = 0
    count[x] = 1
    p[x] = x
    while not q.empty():
        y = q.pop()
        for z in y.vicini:
            if dist[z] == -1: # z non visitato
                dist[z] = dist[y] + 1
                q.enqueue(z)
                count[z] = count[y]
                p[z] = y
            elif dist[z] == dist[y] + 1: # z visitato con un nuovo cammino minimo
                count[z] += count[y]
    return count, dist, p
```

*Problema*:  
Trovare la distanza $dist(X, Y)$ tra due insiemi di vertici: $dist(X,Y)=\min_{x\in X,\ y\in Y} dist(x,y)$.

Potremmo fare un BFS per ogni vertice di $X$ e, per ogni BFS, controllare quale vertice di $Y$ ha il cammino più corto, ma questo ha complessità altissima.

Un'altra soluzione è aggiungere un nuovo vertice $x'$ adiacente ad ogni vertice in $X$ e fare un BFS partendo da $x'$. Il risultato sarà il vertice in $Y$ con il valore minimo nel risultato del BFS - 1.

Altrimenti possiamo fare una specie di BFS che parte da ogni vertice di $X$ allo stesso tempo:
```python
def bfs_set(g: Grafo, xs: Set<Vertice>, ys: Set<Vertice>):
    dist = [-1] * g.len()
    q: Queue
    for x in xs:
        dist[x] = 0
        q.enqueue(x)
    bfs normale...
    # poi scorri ys e vedi quale dist[y] è il minore
```

Proposizione:  
Sia `dist` l'array di distanze da $x$ dato dal BFS. Allora per ogni $y,z$ con $y \text{ adj } z: |$`dist[z]`$-$`dist[y]`$|\leq 1$.

Dimostrazione:  
Possiamo assumere che `dist[z]`$\leq$`dist[y]`. Allora `dist[y]`$\leq$`dist[z]`$+1$. Allora `dist[z]`$\leq$`dist[y]`$\leq$`dist[z]`$+1$.

> [!NOTE]
> Gli archi del BFS vanno solo verso "strati più profondi".

Proposizione:  
Sia $G$ un grafo connesso non diretto, $x\in V(G), T_1$ un albero BFS con radice $x, T_2$ un albero DFS con radice $x$. $T_1 = T_2 \iff G$ è già un albero.

Dimostrazione:  
- $G$ albero $\Rightarrow T_1 = T_2$ è banale
- $T_1 = T_2 \Rightarrow G$ è un albero:
Uguale all'implicazione $G$ non è un albero $\Rightarrow T_1\not= T_2$. Supponiamo per assurdo che $G$ non è un albero ma $T_1 = T_2$. Allora $G$ contiene un ciclo $\Rightarrow$ esiste un arco all'indietro $yz$ in $T_2$ (DFS) $\Rightarrow\ dist_T(z, y)\geq 2$ che è in contraddizione con il fatto che $T_1$ è un albero BFS ($y$ e $z$ sono adiacenti).

> Un grafo pesato è un grafo con una funzione $w: E(G)\to \mathbb{R}^+$ che assegna un peso ad ogni arco.
> Con $P$ un cammino da $x\to y$, $dist_w(x,y)=\min w(P)=\sum_{e\in E(P)} w(e)$ (la distanza tra due nodi in un grafo pesato è il cammino con somma dei pesi dei suoi archi minima).
> Se il grafo è diretto $dist_w(x,y)$ è il peso minimo di un cammino diretto da $x\to y$.

Osservazioni:  
- $dist_w(x,x)=0$
- $dist_w(x,y)\geq 0$ (i pesi sono parte di $\mathbb{R}^+$)
- $dist_w(x,y)\leq dist_w(x,z) + dist_w(z,y)$

# Algoritmo di Dijkstra

*Problema*:  
Trovare la $dist_w(x,y)$ in un grafo non diretto.

Se $w(e)=1\ \ \forall e\in E(g)$ basta usare il BFS.

Sia $u$ il vertice di $N(x)$ (vicini di $x$) che minimizza $w(x,u)$. Allora $dist_w(x,u)=w(x,u)$ (ogni altro cammino passa per un arco con peso maggiore dato che abbiamo scelto l'arco con peso minimo).

Proposizione:  
Supponiamo di aver trovato un insieme $Z$ di vertici per cui sappiamo $dist_w(x,z)\forall z\in Z$. Se $v$ è il vertice con arco $u'v$ t.c. $v\not\in Z, u'\in Z$ e $w(u'v)+dist_w(x,u')$ è minima, allora $dist_w(x,v)=w(u'v)+dist_w(x,u')$.

Dimostrazione:  
non ho voglia guarda [slide](http://wwwusers.di.uniroma1.it/~wollan/Prog_Alg/Appunti/grafi_greedy.pdf)

Con questa proposizione abbiamo un algoritmo per trovare la distanza minima di ogni vertice.
```python
def dijkstra(G: Grafo, x: Nodo, w: Pesi):
    dist = [inf] * len(G)
    T: Tree = [0] # i cammini da x ai nodi nell'albero sono i cammini con peso minimo in G
    dist[x] = 0
    R = {x} # insieme
    while R != nodi(G): # O(n)
        min = -1
        arco = None
        for uv in archi(G): # O(m)
            if u in R and v not in R: # arco uscente da R
                if arco and dist[u] + w(uv) < min: # aggiorna il minimo
                    min = dist[u] + w(uv)
                    arco = uv
        R.add(v) # aggiungi il nodo di uv che è fuori da R a R
        dist[v] = min
        T.add(arco)
    return dist, T
# complessità O(nm)
```

Quest'algoritmo ha complessità alta, visto che controlliamo sempre ogni arco per trovare un arco uscente da $R$. Vogliamo trovare un modo per ottimizzare questa ricerca.

Ogni volta che aggiungiamo un arco ad $R$, per trovare il nuovo arco minimo dobbiamo considerare gli archi uscenti dal nuovo $R$, che sono gli archi uscenti dal vecchio $R$ + gli archi uscenti dal vertice appena aggiunto. Vanno inoltre aggiornati i "valori" (distanza minima fino a quel nodo) dei nodi subito fuori $R$. (?? credo)

Dato che ad ogni passo dobbiamo estrarre l'arco con peso minimo, possiamo memorizzare gli archi candidati in un heap minimo.

```python
def dijkstra(G: Grafo, x: Nodo, w: Pesi):
    dist = [inf] * len(G)
    dist[x] = 0
    P: VettorePadri = [-1] * len(G)
    P[x] = x
    H: Heap = min_heap()
    for xv in x.archi: # O(n*log(n)), al massimo n archi escono dalla radice a quanto pare
        H.add(xv, chiave = w(xv))
    for i in range(1, n): # già aggiunto x quind n-1 volte
        uv = H.pop() # O(log(m))
        if P[u] == -1: # il vertice uscente è quello non in P
            new = u
            old = v
        else:
            new = v
            old = u
        P[new] = old
        dist[new] = dist[old] + w(uv)
        for y ~ new: # y adiacente new; O(deg(new) * log(n)) -> O(m*log(n)) totale (fuori dal primo for)
            if P[y] == -1: # y fuori da R
                H.add(new,y, chiave = dist[new] + w(new,y)) # nuovo candidato
            else:
                H.remove(new,y) # non era il minimo quindi non ci interessa
    return P
# totale: O(n*log(n) + n + m*log(n)) = O((n + m)log(n))
```

---

Dato $P$ vettore dell'albero di cammini minimi di un grafo $G$ radicato in $x$ con pesi $w$, definiamo:
- $w_1: E(G)\to \mathbb{R}^+; w_1(e)=w(e)+1$
- $w_2: E(G)\to \mathbb{R}^+; w_2(e)=2w(e)$

$P$ è il vettore dell'albero di cammini di peso minimo per $w_1$? Per $w_2$?

Per $w_1$ è falso: pensa quadrato con lato 4 e altri 1.

Per $w_2$ è vero perché moltiplicare il peso dei singoli archi è equivalente a moltiplicare il peso totale del cammino, quindi le relazioni tra pesi non cambiano.
