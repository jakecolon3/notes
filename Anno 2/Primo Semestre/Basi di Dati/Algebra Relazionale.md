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

## Operatori Binari

### Unione

> $$r_1\cup r_2$$

Crea una tabella contenente gli elementi di entrambe le tabelle. Le tabelle devono avere lo stesso tipo: stesso numero e tipo di attributi. Due tabelle "dello stesso tipo" sono dette *union compatibili*.

Gli attributi non devono avere lo stesso nome, ma per ottenere un risultato sensato dovrebbero avere lo stesso "significato".

Bisogna far attenzione a mantenere l'unicità delle chiavi quando si applica l'unione a delle relazioni.

### Differenza

> $$r_1-r_2$$

Si applica a relazioni union compatibili, e crea una relazione contenente tutte le tuple appartenenti ad $r_1$ e non $r_2$.

### Intersezione

> $$r_1\cap r_2$$

Si applica a relazioni union compatibili, crea una tabella contenente solo le tuple contenute in entrambi gli operandi.
