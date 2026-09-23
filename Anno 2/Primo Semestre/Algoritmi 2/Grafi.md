# Definizione
> Un grafo è una coppia $(V; E)$ dove $V$ è un insieme di nodi (punti), e $V$ è un insieme di archi (lati).

1. Un arco non può condividere il suo punto di partenza e di arrivo
2. Due archi non possono condividere entrambi i nodi
    Nel caso in cui gli archi sono orientati allora possono se puntano in direzioni opposte

Gli archi di un grafo possono essere orientati. In quel caso il grafo si dice *diretto*.

## Terminologia

- Consideriamo un arco $f$ che collega i punti $x$ e $y$. $f$ si dice *incidente* a $x$ e $y$. $x$ e $y$ si dicono *adiacenti*.
- Il *grado* di un vertice $x$ è il numero di archi incidenti a $x$.
- Una *passeggiata* in un grafo è una sequenza $v_0, e_1, v_1, e_2, v_3, e_3, ..., e_n, v_n$, con $v_k, e_k$ rispettivamente nodi e archi del grafo.
- Una passeggiata è *chiusa* se $v_0 = v_k$.
- Un grafo è detto *connesso* se per ogni coppia di vertici esiste una passeggiata $x$ a $y$.
    Quindi un grafo (non connesso) può avere più "gruppi" di nodi separati
- Un *cammino* nel grafo è una passeggiata che non ripete archi o vertici.
    Data una sequenza che rappresenta una passeggiata, si può trasformare la passeggiata in un cammino eliminando tutti gli elementi tra il primo duplicato ed il secondo (escluso)
- Un *ciclo* è un grafo connesso con ogni vertice di grado 2.

# Passeggiate

> Una *passeggiata* in un grafo è una sequenza $v_0, e_1, v_1, e_2, v_3, e_3, ..., e_n, v_n$, con $v_k, e_k$ rispettivamente nodi e archi del grafo.

Una passeggiata che non ripete archi non può essere chiusa se il suo nodo di partenza ha grado dispari.
Un grafo non contiene passeggiate chiuse che non ripetono archi se **qualsiasi** suo nodo ha grado dispari.

### Teorema

> Esiste una passeggiata chiusa che contiene tutti gli archi una sola volta s.se ogni vertice ha grado pari e il grafo è connesso.

# Rappresentazione dei grafi

Consideriamo questo grafo:
```
1   2
*---*
 \ / \
  *---*
  3   4
```

- ### Matrice di adiacenze
($n\times n$ con $n = \# vertici$)

La matrice di adiacenza di questo grafo ha 1 in posizione $(i, j)$ se $i~j$ ($i$ adiacente a $j$), 0 altrimenti:
$$
\begin{bmatrix}
  0 & 1 & 1 & 0 \\
  1 & 0 & 1 & 1 \\
  1 & 1 & 0 & 1 \\
  0 & 1 & 1 & 0
\end{bmatrix}
$$
Questa rappresentazione ha grandezza in $\Theta(n^2)$, e per controllare l'adiacenza di 2 nodi si impiega tempo $O(1)$.

- ### Lista di adiacenze

Array contenente puntatori alle liste dei nodi adiacenti al nodo corrispondente all'indice.
Questa rappresentazione ha grandezza in $O(n^2)$ e si impiega tempo in $O(n^2)$ per controllare l'adiacenza
    Più precisamente, la grandezza è $O(n+\sum_v \deg(v))$ (n + somma gradi)
    La somma dei gradi dei nodi di un grafo è anche uguale a $2\times m$, con $m$ numero di archi (convenzione).

## Cammini

> Un *cammino* nel grafo è una passeggiata che non ripete archi o vertici.

Data una sequenza che rappresenta una passeggiata, si può trasformare la passeggiata in un cammino eliminando tutti gli elementi tra il primo duplicato ed il secondo (escluso)
Segue che esiste una passeggiata da $x\to y \iff$ esiste un cammino da $\x\to y$.

# Esempi

## Problema

Dato un grafo $G$ dove per ogni vertice $x, \deg(x)\geq 2$, trovare un ciclo nel grafo.

Basta scegliere sempre di seguire uno degli archi che non abbiamo già visitato
    Se trovi un nodo già visitato hai trovato il ciclo

### Pseudocodice

```python
def ciclo(G):
    x := vertice del grafo
    L := lista vuota
    L.append(x)
    current = x
    next = x.vicini[0]
    # while next not in L: // O(n*n)!
    #    L.append(next)
    #    current = next
    #    next = current.vicini[0] if current.vicini[0] != current else current.vicini[1]
    visti := Array[G.nodeCount]
    while visti[next] < 1: # O(n)
        L.append(next); visti[next] += 1
        current = next
        # con la matrice trovare i vicini diventa O(n) -> totale O(n^2)
        next = current.vicini[0] if current.vicini[0] != current else current.vicini[1]
    primoTrovato = L.find(next)
    return L[primoTrovato:]
```
