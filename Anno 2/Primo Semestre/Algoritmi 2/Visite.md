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
x
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

### Con DFS

Dato un DFS, aggiungiamo un contatore che incrementa ogni volta che troviamo un vertice non visitato. Definiamo una funzione $t(v) =$ valore del contatore quando $v$ è stato visitato la prima volta, ed una funzione $T(v) =$ valore del contatore quando $v$ è stato visitato l'ultima volta (nella risalita). Applicando queste funzioni ai nodi del grafo, ad ogni nodo abbiamo associato un intervallo $[t(v), T(v)]$.

Proposizione:
> Per ogni $u,v$:
> $$
\begin{align}
&i)   &&[t(u),T(u)]\subseteq[t(v),T(v)]        &&:\text{ archi all'indietro} \\
&ii)  &&[t(v),T(v)]\subseteq[t(u),T(u)]        &&:\text{ archi in avanti} \\
&iii) &&[t(u),T(u)]\cap[t(v),T(v)] = \emptyset &&:\text{ archi di attraversamento} \\
\end{align}
$$

Dimostrazione:  
Dobbiamo dimostrare che gli intervalli non si sovrappongono, quindi che è impossibile che: $t(u)<t(v)\leq T(u)<T(v)$:
> Se $t(u)<t(v)\Rightarrow v$ è inserito nello stack dopo $v$ e se $t(v)\leq T(u)$ per forza $v$ è stato rimosso dallo stack prima di $u \Rightarrow T(v)\leq T(u)\Rightarrow$ non è possibile che $t(u)<t(v)\leq T(u)<T(v)$.

$t(v)$ e $T(v)$ hanno alcune proprietà:
- Se $t(v)=T(v)$ allora $v$ è una foglia.
- TODO

Possiamo vedere che gli archi di attraversamento sono quelli che *non sono percorsi* dal DFS (e quindi sono fratelli), gli archi all'indietro sono gli archi che vanno da un vertice *al suo antenato*, e gli archi in avanti sono gli archi che vanno da un vertice *ad un suo discendente*.

Ne grafi non diretti, il caso $iii)$ non è possibile: è impossibile che due foglie connesse abbiano intervalli disgiunti (se una è raggiunta dal DFS è impossibile che venga rimossa dallo stack prima che venga visitata l'altra). (??) -> Tutti gli archi $(u,v)$ che non fanno parte dell'albero di visita del DFS sono archi all'indietro.

Proposizione:  
> Un grafo $G$ non diretto connesso ha un ciclo $\iff$ ogni DFS ha un arco all'indietro.

Dimostriamo "Se $G$ è non diretto connesso con ciclo $\Rightarrow$ ogni DFS ha un arco all'indietro".

Prendiamo un grafo contenente un ciclo $C$. $C$ non può essere contenuto interamente nell'albero di ricerca (gli alberi di ricerca non hanno cicli) $\Rightarrow\ \exists\ e\in E(C)$ che non fa parte dell'albero $\Rightarrow\ e$ è un arco all'indietro.

Per l'altro lato, prendiamo $u, v$ arco all'indietro con $u$ discendente di $v$. Nell'albero di visita $\exists$ un cammino $P$ da $u\to v$ e $P + u,v$ è un ciclo (??? i guess).

Proposizione:  
Sia $G$ un grafo diretto. $\exists$ ciclo in $G\ \iff\ \exists$ un arco all'indietro per qualsiasi DFS nel grafo.

Prima parte:  
Se $\exists$ arco $u,v$ da $u$ un discendente di $v$, nell'albero di visita $\exists$ un cammino diretto da $v\to u$. Il cammino + l'arco $u,v$ è un ciclo diretto.

boh leggi le slide sono più chiare:
> Se il grafo non è diretto (e connesso), la presenza di un qualsiasi arco all'indietro indica l'esistenza di un ciclo. E se non ci sono archi all'indietro il grafo è aciclico perchè coincide con l'albero della DFS.
> Lo stesso vale per grafi diretti, cioè il grafo ha un ciclo se e solo se c'è almeno un arco all'indietro. Per vederlo supponiamo che u0, u1,…,uk sia un ciclo (orientato e semplice) di G, quindi u0 = uk. Supponiamo, senza perdita di generalità, che u0 sia il primo nodo del ciclo ad essere visitato dalla DFS. Siccome tutti gli altri nodi del ciclo saranno visitati durante la DFS da u0, l'arco (uk - 1, u0) è necessariamente un arco all'indietro. Dobbiamo ora far vedere che se c'è un arco all'indietro, c'è un ciclo. Sia (w, v) un arco all'indietro. Siccome v è un antenato di w, nell'albero della DFS c'è un cammino (orientato e semplice) che va da v a w e quindi l'arco (w, v) chiude tale cammino in un ciclo.

non ho seguito bene tbh

# Esercizi

---

In un grafo diretto, un *pozzo universale* è un vertice $x$ che ha archi entranti da ogni altro nodo e nessun arco uscente.

---

In un grafo connesso e non diretto, un $e\in\ E(G)$ è un *ponte* se $\not\exists$ un ciclo $C$ che contiene $e$. Un algoritmo per controllare se un arco è un ponte consiste nel cancellare l'arco che si vuole controllare e vedere se esiste ancora un cammino tra i due nodi con un DFS. Per controllare se esiste un ponte in un grafo, si può applicare il DFS sul grafo e, per ogni arco $xy$ nell'albero del DFS, applicare il primo algoritmo per stabilire se $xy$ è un ponte (più efficiente di applicare il primo algoritmo su ogni arco del grafo).

Proposizione:
> Se $G$ è un grafo connesso, $T$ un albero DFS e $xy\in E(T)$ con $y$ discendente di $x$: $xy$ non è un ponte $\iff\ \exists$ un arco $uv\in E(G)\not \in T$ all'indietro con $u\in T_y$ e $v$ antenato di $x$ con $uv\not=xy$.

Algoritmo per trovare tutti i ponti in un grafo:
```python
dfs_ponti(G, u: Node, z: Node, tt[], c, ponti):
"""
param u: vertice appena visitato
param z: padre di u
param ponti: out param
return: il nodo "più all'indietro"
"""
    c++
    tt[u] = c # tt contiene il "tempo di visita"
    back = tt[u] # il "più all'indietro" all'inizio è il nodo appena visitato
    for v in adj(u):
        if tt[v] == 0:
            b = dfs_ponti(G, v, u, tt, c, ponti) # ritorna `back`
            if b >= tt[v]:
                ponti.append(uv)
            if b < back:
                back = b
        else:
            if tt[v] < back and tt[v] != tt[z]:
                back = tt[v]
    return back
```

---

> Sia $G$ un grafo diretto. $G$ è fortemente connesso se $\forall\ x,y\in V(G)\ \exists$ un cammino diretto $x\to y$ e un cammino $y\to x$ (ogni nodo è raggiungibile da qualsiasi altro nodo).

Osservazione:
> Per qualsiasi grafo diretto e $x\in V(G),\ \exists$ un sottografo fortemente connesso che contiene $x$ (il grafo contenente solo $x$ è fortemente connesso).

> Un *componente* fortemente connesso è un sottografo $H$ fortemente connesso **massimale**: per qualsiasi sottografo $H'\supset H$ (strettamente) allora $H'$ non è fortemente connesso.

Da notare che se $x,y$ fanno parte dello stesso componente fortemente connesso $\not\Rightarrow\ x,y$ fanno parte di un ciclo: i cicli non possono avere nodi ripetuti, mentre un componente fortemente connesso si

Dato che i componenti fortemente connessi non possono avere nodi in comune (sarebbe un unico componente), ed ogni nodo fa parte di un componente fortemente connesso (un componente può avere solo 1 nodo), l'insieme dei componenti fortemente connessi di un grafo lo partiziona.

Per trovare le componenti fortemente connesse in un grafo, possiamo trovare e contrarre i cicli, riducendo il grafo a singoli nodi, e poi nella risalita ricorsiva ricostruire la lista di componenti "spacchettando" ogni componente contratto.

Questo algoritmo ha complessità $O(n(n+m))$. Vogliamo quindi trovare un algoritmo che utilzza il DFS per rimanere in $O(n+m)$.

Proposizione:  
> Sia $T$ un albero DFS di un grafo diretto $G$, $u\in V(G)$ e $xy$ un arco di attraversamento con $x\in tree(u)$ ($tree(u)$ sono i discendenti di $u$). Allora $\exists\ z$ antenato comune più vicino di $x,y$ e $z$ è un antenato di $u$ ed $\exists$ figli $u_1,u_2$ di $z$ con $x\in tree(u_1),y\in tree(u_2)$, e $\forall x'\in tree(u_1),y'\in tree(u_2): t(x')>t(y')$. (vedi dimostrazione??)

Definizione:  
> Sia $C$ comp. fortemente connessa, $T$ un'arborescenza di visita di un DFS. Si dice *C-radice* il primo vertice di $C$ visitato nel DFS.

Proposizione:  
> Se $u$ è una C-radice allora:
> 1. $C(u)\subseteq tree(u)$ ($C(u)$ = comp. fort. connessa contenente $u$)
> 2. Se $u_1,...,u_k$ sono tutte le C-radici in $tree(u)$, allora $V(tree(u))=C(u_1)\cup C(u_2)\cup...\cup C(u_k)$.
> (vedi dimostrazione)

---

Dato un modo per riconoscere le C-radici, abbiamo un DFS per trovare componenti fortemente connesse:
```python
def dfs_scc(G, u, open, output, vis):
"""
param G: grafo diretto
param u: nodo di G
param open: stack
param output: out param
param vis: nodi visitati
"""
    vis[u] = 1
    open.push(u)
    for v ~ u: # v adj u
        if vis[v] == 0:
            dfs_scc(G, v, open, output, vis)
    c = [] # lista
    if is_c_radice(u):
        do:
            w = open.pop()
            c.append(w)
        while w != u
    output.append(c)
```
Parte iniziale:
```python
def scc(G):
"""
param G: grafo diretto
"""
    open = [] # stack
    output = {} # set
    vis = [0 for _ in G.nodi()]
    for v in G.nodi():
        if vis[v] == 0:
            dfs_scc(G, v, open, output, vis)
    return output
```

Vediamo ora come trovare le C-radici.

Proposizione:  
> Un nodo $u$ non è una C-radice $\iff$ nelle chiamate ricorsive del `dfs_scc` con radice $u$ viene attraversato un arco $(v,w)$ t.c. $w$ è stato già visitato ($t(w) < t(u)$) ma il componente di $w$ non è stato stabilito ($w\in$ `open`).
> (vedi dimostrazione)

boh dobbiamo aggiungere un'altra variabile per stabilire se un nodo è una C-radice

l'algoritmo completo è [sulle slide](http://wwwusers.di.uniroma1.it/~wollan/Prog_Alg/Appunti/grafi_6.pdf)
