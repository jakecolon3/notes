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

### Ridenominazione

> $$S = \rho_{NuovoNome1,NuovoNome2,...,\leftarrow,Nome1,Nome2...}(R)$$

Questa operazione rinomina gli attributi della tabella.

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

---

Per ora abbiamo visto solo operazioni su tabelle dello stesso tipo. Vediamo ora delle operazioni su tabelle di tipo diverso.

### Prodotto cartesiano

> $$r_1\times r_2$$

Il prodotto cartesiano costruisce una relazione contenente le tuple che consistono delle tuple della prima seguite dalle tuple della seconda. (ogni tupla di una concatenata ad ogni tupla dell'altra)

Quindi $r_1\time r_2$ produce elementi del tipo $(x_1,y_1,...,z_1,x_2,y_2,...)$, dove gli $x_1$ provengono da $r_1$ e gli $x_2$ da $r_2$

Però c'è un problema se entrambe le relazioni hanno attributi con lo stesso nome. Per risolvere si possono rinominare i nomi degli attributi.

### Join Naturale

Il join naturale fa un prodotto cartesiano ma escludendo tutti gli attributi che hanno lo stesso nome e valore. È un operatore derivato:
$$
r_1\bowtie r_2 = \pi_{XY}(\sigma_C(r_1\times r_2))
$$
Dove:
- $C$ è $R_1.A_1=R_2.A_1\land R_1.A_2=R_2.A_2\land...\land R_2.A_k=R_2.A_k$.
- $X$ è l'insieme di attributi di $r_1$
- $Y$ è l'insieme di attributi di $r_2 che non sono attributi di $r_1$

> [!WARNING]
> Ci sono dei casi limite da considerare: se ci sono attributi con lo nome ma non ci sono tuple con lo stesso valore per quell'attributo, si ottiene l'insieme vuoto. Se invece non ci sono attributi con lo stesso nome, la condizione diventa sempre vera e quindi si ottiene il prodotto cartesiano.

### $\theta$-join

> $$r_1\bowtie_{A\theta B}r_2 = \sigma_{A\theta B}(r_1 \times r_2)$$
> (Dove $\theta$ è un'operatore di confronto, e $A, B$ sono attributi dello stesso dominio della prima e seconda relazione rispettivamente.)

Il join naturale non ha senso se gli attributi hanno lo stesso nome ma non lo stesso significato. Il theta-join permette di agiungere una condizione alla selezione delle tuple del prodotto cartesiano.

# Quantificatore Universale

I query che abbiamo visto finora hanno condizioni che (?) implicano il *quantificatore esistenziale* ($\exists$). Queste query controllano la condizione riga per riga.

Query che hanno condizioni che dipendono da più righe (es. "persona con età massima") implicano invece il *quantificatore universale* ($\forall$ o $\not \exists$).

Per fare query con questo tipo di condizione, possiamo eseguire la query con la condizione *negata*, e poi sottrarre il risultato dal totale.

> [!WARNING]
> Bisogna assicurarsi che l'insieme totale non includa tuple inaspettate: per esempio "clienti che hanno fatto solo ordini di almeno 100 pezzi" ha la condizione sottintesa che il risultato non deve contenere clienti che non hanno mai fatto ordini (quindi non compaiono nella tabella `ordini`, e che saranno quindi mantenuti dopo la sottrazione)

# Condizioni ricorsive

Se una relazione ha un'associazione con sè stessa, come facciamo query in base a quella relazione? Possiamo condizioni solo se sono nella stessa riga.

Possiamo fare un $\theta$-join della tabella *con sè stessa*.
