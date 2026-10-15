> L'algebra relazionale è un linguaggio formale per interrogare una base di dati relazionale. Consiste di un insieme di operatori che si applicano a istanze di relazione e restituiscono una nuova istanza di relazione.

L'algebra relazionale è *procedurale*: l'ordine delle operazioni definite da un'espressione è l'ordine in cui compaiono nell'espressione (tipo).

# Operatori

Operatori fondamentali:
- Selezione
- Proiezione
- Prodotto cartesiano
- Ridenominazione
- Unione
- Differenza

Operatori derivati:
- Join naturale
- Theta join
- Intersezione
- Quoziente/Divisone

## Operatori Unari

### Proiezione

La proiezione crea una nuova tabella contenente un sottoinsieme delle *colonne* di un'altra tabella. Si denota con $\pi$:
$$
s=\pi_{A_1,A_2,...,A_k}(r)
$$
*La tabella $s$ contiene le colonne $A_1,A_2,...,A_k$ di $r$.*

> [!NOTE]
> Dato che nell'algebra relazionale le tabelle sono trattate come insiemi, è possibile che la proiezione "fondi" delle righe. Se si vuole evitare la perdita di informazioni, la proiezione deve contenere una colonna "chiave".

### Selezione

La selezione permette di selezionare tutte le *righe* di una tabella che soddisfano una condizione. Si denota con $\rho$:
$$
s=\sigma_C(r)
$$
*La tabella $s$ contiene tutte le righe di $r$ che soddisfano $C$.*

> [!NOTE]
> Non è il `SELECT` di SQL. `SELECT` corrisponde alla proiezione.

La condizione è un'espressione *booleana composta* (tramite $\land, \lor, \neg$) da termini del tipo:
$$
\begin{align}
&A\theta B \\
&A\theta a
\end{align}
$$

Dove $\theta$ è un'operatore di confronto, $A$ e $B$ sono attributi con lo stesso dominio, e $a$ è un elemento di $\text{dom}(A)$.
