L'[algoritmo di Dijkstra](<./BFS.md#Algoritmo di Dijkstra>) che abbiamo visto è un esempio di algoritmo *greedy*.

Gli algoritmi greedy sono utilizzati nei problemi di ottimizzazione per trovare la soluzione migliore ad un certo problema.

boh esempio invervalli

Lo schema di un algoritmo greedy è:
- Trova una soluzione parziale

# Correttezza di un algoritmo greedy

Dato un algoritmo greedy con output $Sol$, vogliamo, con $Sol_i$ la soluzione parziale all'$i$-esimo passo dell'algoritmo:
$$
\forall i=0,...,n, \exists \text{ una soluzione ottimale } Sol^* | Sol_i\subseteq Sol^*
$$

Da questa segue che $\exists$ una soluzione ottimale $Sol^*$ con $Sol_n\subseteq Sol^*$. Per essere ottimale, vogliamo che $Sol^*=Sol_n$.

Dimostrazione:  
Assumiamo per assurdo che $Sol_n\not = Sol^*$. Ci deve essere un elemento $I_i$ che fa parte di $Sol^*$ ma non di $Sol_n$. Questo significa che l'algoritmo non è stato eseguito correttamente. Quindi all'$i$-esimo passo c'era un oggetto che non abbiamo inserito nella soluzione. Sappiamo che al passo precedente è stato aggiunto l'elemento $I_{i-1}$; $Sol_{i-1}\subseteq Sol_n\Rightarrow I_i$ è disgiunto (algoritmo per trovare intervalli disgiunti) da tutti gli elementi di $Sol_{i-1}\Rightarrow$ per l'algoritmo $I_i\in Sol_i$ ma abbiamo scelto $I_i\in Sol_n\supseteq Sol_i$, che è una contraddizione.

Si ha quindi che $Sol_n=Sol^*$. L'algoritmo trova la soluzione ottimale.

puoi anche dimostrare per induzione credo? l'idea è che l'insieme di elementi scelti di un'algoritmo greedy cresce sempre quindi puoi fare una dimostrazione induttiva

guarda p.3 [slide](http://wwwusers.di.uniroma1.it/~wollan/Prog_Alg/Appunti/greedy.pdf)

---

Dato un grafo $G$ non diretto con pesi $w: E(G) \to R^+$ vogliamo trovare un sottografo connesso che:
- contiene tutti i vertici
- minimizza $\sum_{e\in E(H)}w(e)$.

È facile trovare un sottografo qualsiasi connesso che contiene tutti i vertici usando un DFS o BFS. Però è più complicato trovare una soluzione ottimale.

Osservazione: ogni soluzione è sempre un albero, dato che se una soluzione contiene tutti i vertici ed un ciclo basta rimuovere un arco dal ciclo per migliorarla.

Il problema si può riscrivere in questo modo: dato $G$ non diretto con pesi sugli archi, trovare l'albero di copertura di peso minimo (MST; minimum spanning tree).

Cerchiamo di formulare un algoritmo greedy per risolvere questo problema.

Un'idea è ordinare gli archi per peso e, ad ogni passo, scegliere l'arco minimo che connette due vertici non ancora connessi:
```
def kruskal(g: Grafo):
    # ordina gli archi per peso
    sol = {}
    for i in range(n):
        if sol union g.e[i] non contiene cicli:
            sol.add(e[i])
    return sol
```

Altrimenti si può fare un ragionamento simile a Dijkstra: ad ogni passo scelgo l'arco minimo con un vertice già scelto e l'altro non ancora scelto:
```
def prim(g: Grafo, v: Vertice):
    sol = {}
    r = {v}
    while r != g.vertici:
        uv = arco con peso minimo t.c. u in r, v not in r
        sol.add(uv)
        r.add(v)
    return sol
```

L'algoritmo di Kruskal crea sempre un albero come output. Dimostrato dal fatto che l'output non contiene mai cicli (non aggiungiamo mai l'arco che crea un ciclo). È sempre connesso perché se non lo fosse allora l'algoritmo avrebbe mancato un arco che connette due nodi componenti e non crea un ciclo.
