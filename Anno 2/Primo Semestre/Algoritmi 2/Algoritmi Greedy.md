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

# Minimum Spanning Tree

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
    ordina gli archi per peso
    sol = {}
    for i in range(n):
        if sol union g.e[i] non contiene cicli:
            sol.add(g.e[i])
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

Dimostrazione di correttezza di Kruskal:  
Sia $Sol_i$ il valore di $Sol$ dopo l'$i$-esimo passo del `for`. Proposizione ($*$): $\forall i\in 0,...,n\ \exists$ una soluzione ottimale $Sol^*$ con $Sol_i\leq Sol^*$.

Osservazione: $*\Rightarrow Sol_m$ è una soluzione ottimale. Dimostrazione: per $*$, esiste una soluzione ottimale $Sol^*$ che contiene $Sol_m$. ?? $Sol_m$ e $Sol^*$ sono alberi di copertura $\Rightarrow |Sol_m|=n-1, |Sol^*|=n-1\Rightarrow Sol_m=Sol^*$. Per induzione:
- Caso base: $$
Sol_0=\emptyset \Rightarrow Sol_0\subseteq Sol^* \text{ per qualsiasi soluzione ottimale } Sol^*.
$$
- Assumiamo che esiste un $Sol^*$ ottimale che contiene $Sol_i$: $$
Sol_{i+1} = \begin{cases} Sol_i \\ Sol_i \cup \{e_{i+1}\}. \end{cases}\\
\text{Se } Sol_{i+1}= Sol_i \text{ è già }\subseteq Sol^*. \\
\text{Se } e_{i+1}\in Sol^*\Rightarrow Sol_{i+1}\text{ è già }\subseteq Sol^*.
$$  
    Se il nuovo elemento non fa parte di $Sol^*$ significa che l'algoritmo ha aggiunto un'arco che ha creato un ciclo perché esiste un cammino in $Sol^*$ che collega i due vertici dell'arco e il cammino + l'arco è un ciclo (????) boh mi sono perso ([slide](http://wwwusers.di.uniroma1.it/~wollan/Prog_Alg/Appunti/greedy3.pdf))

---

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

Dimostrazione correttezza di Prim:  
L'output è un'albero perché partiamo da un grafo connesso (singolo nodo) e ad ogni passo aggiungiamo un nodo connesso al grafo, quindi rimane connesso; non ha cicli perché ad ogni passo aggiungiamo un nodo che non è già nel grafo.

Dimostriamo che l'albero è minimo. Sia $Sol_i$ la soluzione dopo l'$i$-esima iterazione del `while`. Si ha che $Sol_0=\emptyset$.  
Proposizione ($*$): per ogni $i\in 0,...,n$, esiste una soluzione ottimale $Sol^*$ che contiene $Sol_i$.  
Dimostriamo $*$ per induzione.
- Caso base: $Sol^*\subseteq \emptyset$.
- Ipotesi induttiva: $Sol_i\subseteq Sol^*$.
    Aggiungiamo un arco ad ogni passo quindi $Sol_i \not= Sol_{i+1}$. Se il nuovo arco $e_{i+1}\in Sol^*\Rightarrow Sol_{i+1}\subseteq Sol^*$ e abbiamo fatto. Altrimenti $uv = e_{i+1}\not\in Sol^*$. Dato che $Sol^*$ è già un albero, $Sol^*\cup \{uv\}$ ha un ciclo $C$. $C$ ha un percorso da $v\to u$ che non passa per $uv$. Sia $f$ l'arco lungo il percorso con un termine in $R$ ed uno fuori. Il peso di $f$ è maggiore o uguale del peso di $uv$ dato che abbiamo scelto $uv$ come l'arco di peso minimo uscente da $R\Rightarrow$ il peso di $(Sol^*-f)\cup \{uv\}$ è minore o uguale al peso di $Sol^*\Rightarrow Sol^{**}=(Sol^*-f)\cup\{uv\}$ è una soluzione ottimale che contiene $Sol_{i+1}$. È quindi possibile estendere $Sol_{i+1}$ ad una soluzione ottimale CVD.

---


