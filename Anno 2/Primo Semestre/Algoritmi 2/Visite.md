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
