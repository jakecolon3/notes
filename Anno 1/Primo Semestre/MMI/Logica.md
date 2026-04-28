# Booleana
### Operatori
- Congiunzione: $E$
- Disgiunzione: o/oppure
- L'implicazione: se ... allora
- Negazione: non

# Ragionamento
Esempio:
1. Se il padre di Gino è simpatico o la madre di Gino è simpatica allora Gino è simpatico
2. Gino è antipatico (non è simpatico)
$\implies$ 3. Né il padre né la madre di Gino sono simpatici
	Sono entrambi antipatici
	Il ragionamento è valido anche se l'ipotesi è falsa empiricamente
Esempio:
1. Se $a=0$ o $b=0$ allora $ab=0$
2. $ab\not=0$
$\implies$ 3. $a\not=0$ o $b\not=0$
Argomento corretto:
	*Se* sono valide le ipotesi *allora* è vera la conseguenza
	Bisogna sapere quindi quando è vera una proposizione
Per fare ragionamenti bisogna isolare i connettivi (costrutti logici/connettivi booleani) nella proposizione:
	Assegna i blocchi tra i connettivi a variabili
	Con l'esempio di prima:
	1. $(A\lor B)\to C$
	2. $(\neg C)$
	$\implies$ 3. $((\neg A)\land(\neg B))$
In questo modo notiamo che il primo e il secondo esempio sono *esattamente* uguali formalmente

Definizione di proposizione:
	Frase che può essere vera o falsa
		Se A e B sono proposizioni allora:
		- "Non A"
		- "A e B"
		- "A o B"
		- "Se A allora B"
		Sono proposizioni
	Quando è vera una proposizione?
		- "Non A" è vera quando A è falsa
		- "A e B" è vera quando A è vera e B è vera
		- "A o B" è vera quando A è vera o B è vera
			È vera anche se sono entrambe vere (disgiunzione inclusiva)
		- "Se A allora B" è vera quando è vero che se A è vera allora è vera B
		Quindi la verità di una proposizione complessa *dipende dalla verità dei suoi componenti*
			È una funzione della verità delle sue componenti
				$\hat v:\text{PROPOSIZIONI}\to\{V,F\}$ (V = 1, F = 0)
						È un estensione dell'insieme $v$ sulle variabili
					$v(non\ A)=\begin{cases}1,\ se\ v(A)=0\\ \\0,\ se\ v(A)=1\end{cases}$
				`P == True if all(componenti) else False`
			Definizione ricorsiva

# Costruzione di un problema di logica
- Fissiamo un insieme di variabili (parti tra i connettivi logici)
	$\{p1, p2, ...\}=\mathcal{L}$
- Definiamo l'insieme $PROP_\mathcal{L}\subseteq\Sigma^*$ dove $\Sigma=\{p1, p2,...\}\cup\{(,)\}\cup\{\neg, \land, \lor, \implies, \iff\}$
	$\Sigma$ è il più piccolo insieme t.c.:
	1. $\{p1, p2,...\}\subseteq PROP_l$
	2. Se $A, B\in PROP_l$ allora $(\neg A), (A\land B), (A\lor B), (A\implies B), (A\iff B)\in PROP_l$
Es.
	$P=((\neg(p_2\land p_8))=A\lor(\neg p_10)=B)$
	Risolvi ricorsivamente
		La verità di P è definita se la verità delle variabili è definita
Un assegnamento (o valutazione) è una funzione $v:\mathcal{L}\to\{0,1\}$
	È una funzione che assegna vero o falso agli elementi dell'insieme delle variabili
	Fissando un $v:\mathcal{L}\to\{0,1\}$ posso assegnare un valore di verità a *tutte* le proposizioni
```python
def logica(p):
	if p in variabili:
		return p.value

	result = True
	for sub_p in p:
		if logica(sub_p) == False:
			result = False

	return result
```

# Formalizzazione
## Linguaggi proposizionali
Un linguaggio proposizionale $\mathcal{L}$ è un insieme non vuoto di variabili
Dato un $\mathcal{L}$ proposizionale definiamo $PROP_\mathcal{L}$ come il più piccolo insieme t.c.:
1. $\mathcal{L}\subseteq PROP_\mathcal{L}$
2. Se $A,B\in PROP_\mathcal{L}$ allora $(\neg A), (A\land B), ...\in PROP_\mathcal{L}$
## Valutazioni
Un assegnamento o valutazione di verità per $\mathcal{L}$ è una funzione: $v:\mathcal{L}\to \{0,1\}$
Dato un assegnamento $v$ definisco $\hat v$ ricorsivamente come la funzione di tipo $\hat v: PROP_\mathcal{L}\to \{0,1\}$ tale che:
- Se $A\in \mathcal{L}$ (A è una variabile) allora $\hat v(A)=v(A)$
- Se $A$ è di tipo $(\neg B)$ allora $\hat v=\begin{cases}1 & \text{se } \hat v(B)=0\\0 & \text{se } \hat v(B)= 1\end{cases}$
- Se $A$ è di tipo $(B\land C)$ allora $\hat v(A)=...$
- Se $A$ è di tipo $(B\lor C)$ allora $\hat v(A)=...$
- Se $A$ è di tipo $(B\implies C)$ allora $\hat v(A)=\begin{cases}0 & \text{se } \hat v(B)=1\ e\ \hat v(C)=0\\1 & \text{altrimenti}\end{cases}$
	Falso solo se è vera la premessa ma falsa l'implicazione
- Se $A$ è di tipo $(B\iff C)$ allora $\hat v(A)=\begin{cases}1 & \text{se } \hat v(B)=\hat v(C)\\0 & \text{altrimenti}\end{cases}$
	$(\neg (B\sqcup C))$
- Se $A$ è di tipo $B\sqcup C$ (XOR) allora $\hat v(B)=\begin{cases}0 & \text{se }\hat v(B)=\hat v(C)\\1 & \text{ altrimenti}\end{cases}$
	Usando i connettivi già descritti: $(A\lor B)\land \neg(A\land B)$
		Le loro tavole di verità sono identiche
	Quindi non dobbiamo specificare un nuovo connettivo

Quindi un argomento valido è del tipo:
	Se sono vere le ipotesi allora è vera la proposizione
		Per ogni $v$ t.c. $v(\text{ipotesi})=1$ si ha $v(\text{proposizione})=1$
	$\{A_1, ..., A_n\}\models A$
		Con $\alpha$ = valutazione, $A$ = proposizione:
			$\forall \alpha\text{ se } \alpha(A_1)=...=\alpha(A_n)=1\text{ allora } \alpha(A)=1$
		Conseguenza logica
		Caso particolare: $\emptyset\models A$ è sempre vera
			$\forall\alpha\ \ \alpha(A)=1$
			"Tautologia"
	$A_1, ..., A_n\models A\iff \emptyset\models(A_1, ...A_n)\implies A\iff(A_1, ..., A_n)\land \neg A$ è "UNSAT" ($=0\forall \alpha$)
		Tutte queste definizioni sono equivalenti
		Dimostriamo $(A_1,...,A_n)\models A \iff \emptyset\models (A_1,...,A_n)\implies A$:
			Ipotesi: $(A_1,...,A_n)\models A\ \forall\alpha$
			Per assurdo $\emptyset\not\models (A_1,...,A_n)\implies A$
			Vero se $\exists\alpha:\ \alpha((A_1,...A_n)\implies A)=0$
			Vero s.se $\exists\alpha:\ \alpha(A_1,...,A_n)=1$ e $\alpha(A)=0$
			Vero s.se $\exists\alpha:\ \alpha(A_1),...,\alpha(A_n)=1$ e $\alpha(A)=0$ contraddizione

Per ogni funzione booleana/tavola di verità esiste una proposizione $A$ in $n$ variabili $p_n$ t.c. la tavola di verità di $A$ è con il grafico della funzione (la trovi con induzione credo)
	$\alpha(A)=f(\alpha(p_1),...,\alpha(p_n))$
boh vedi dimostrazione induttiva

# C.N.F. e D.N.F.
## D.N.F.
E' possibile scrivere qualsiasi funzione booleana in "forma normale disgiuntiva" (DNF), cioè come disgiunzione di congiunzioni di letterali (variabili):
	Esempio di proposizione in DNF, dove $A_{i,j}$ sono letterali:
$$
(A_{1,1}\land A_{1,2}\land ...\land A_{1,m_1})\lor(A_{2,1}\land ...)\lor...\lor(A_{n,1}\land ...\land A_{n,m_n})
$$
	Si può scrivere anche:
$$
\bigvee_{i\leq n}\bigwedge_{j\leq m_i}A_{i,j}
$$
## C.N.F.
Alternativamente ogni funzione booleana si può scrivere in "forma normale congiuntiva" (CNF):
$$
\bigwedge_{i\leq n}\bigvee_{j\leq m_i}A_{i,j}
$$

# Colorabilità di mappe/grafi
$G=(V, E); E\subseteq V\times V$
Una mappa/grafo è "*k-colorabile*" s.se $\exists c: V \to \{1,...,k\}$ (colori) tale che: se $(v,w)\in E$ allora $c(v)\not= c(w)$
	Ho una struttura (grafo) e voglio sapere se ha una certa proprietà (colorabilità)
	Si può tradurre in un problema di soddisfacibilità: un insieme di formule che può essere SAT o no:
		$G=(v, E)\to$ insieme di formule: ogni vertice ha almeno 1 colore
		Variabile $p_{i,j}$ con $1\leq i\leq n,\ \ \ i\leq j\leq k$ che dice "il vertice $v_i$ ha il colore $j$"
		Dire che ogni vertice ha almeno un colore:
			$(p_{1,1}\lor p_{1,2}\lor ...\lor p_{1,k})\land...\land (p_{n,1}\lor...\lor p_{n,k})$
$$\bigvee_{1\leq i\leq n}{\bigwedge_{1\leq j\leq k}{p_{i,j}}}$$
		Dire che ogni vertice ha al più un colore:
$$
\neg \bigvee_{1\leq i\leq n}\ \ \ \ {\bigvee_{1\leq j=j'\leq k}{(p_{i,j}\land p_{i,j'})}}
$$
			Ha altre formalizzazioni equivalenti
		Per ogni coppia di vertici in arco i colori dei due vertici sono diversi:
			Per ogni colore, quei due vertici non hanno lo stesso colore:
$$
(i, i')\in E\ \ \ \ \bigwedge_{1\leq i, i'\leq n}\ \ \ \bigwedge_{1\leq j\leq k}\neg(p_{i,j}\land p_{i',j})
$$

## Verificare soddisfascibilità
Ogni formula si può scrivere come C.N.F.:
$$
\bigwedge_i \bigvee_j L_{i,j}
$$
Con $L_{i, j}=$ letterali
Es:
	$(p\lor q\lor s)\land (\neg p\lor q)\land (\neg s\land t)$
	Si può scrivere come: $\{\{p,q,s\},\{\neg p, q\},\{\neg s, t\}\}$ = insieme di clausole = disgiunzione di letterali
		Un insieme di clausole si può scrivere con operatori logici:
			$p\land(\neg p\lor s)\land (s\lor \neg t\lor \neg r)$
		Se 2 clausole sono tali che esiste un letterale L che appare in positivo in una e in negativo in un'altra allora possiamo scriverle come (risoluzione):
$$C_1/\{L\}\cup C_2/\{\neg L\}$$
		Questo nuovo insieme si chiama "risolvente di $C_1, C_2$ relativamente ad $L$" = $RES_L(C_1, C_2)$
			$C_1,C_2 \models RES_L(C_1,C_2)$
			Es:
				$C_1=\{p\},\ \ C_2=\{\neg p, s\}$
				$RES_p(C_1,C_2) = \{s\}$
				Quindi: $p, \neg p\lor s \models s$
			Dimostriamo $C_1,C_2 \models RES_L(C_1,C_2)$:
				Sia $\alpha(C_1)=\alpha(C_2)=1$
				Tesi: $\alpha(C_1/\{L\}\cup C_2/\{L\})=1$
				Per assurdo assumo che non sia vero:
					$C_1$ è una disgiunzione di letterali $\implies$ esiste (almeno) un letterale $Q\in C_1:\alpha(Q)=1$
					Caso 1: $Q=L$
						$\alpha(Q)=1\implies \alpha(\neg Q)=\alpha(\neg L)$ ma $\alpha(C_2)=1\implies$ esiste letterale $p\in C_2:\alpha(p)=1, p\ne \neg L\implies \alpha(RES_L(C_1, C_2))=1$: contraddizione
					Caso 2: $Q\ne L$
						$Q\in C_1/\{L\}\implies\alpha(RES_L(C_1, C_2))=1$: contraddizione
Sia le clausole che le formule sono insiemi:
	Clausole: insiemi di letterali
		Clausola vuota = $\square$
		Non soddisfacibile (UNSAT)
			$\square$ è SAT vorrebbe dire: esiste $\alpha$ t.c. esiste un letterale $L\in\square$ t.c. $\alpha(L)=1$ ma non esiste L quindi è falso
			Ogni formula che contiene la clausola vuota è *insoddisfacibile*
	Formule: insiemi di clausole
		Formula vuota = $\emptyset$
		Soddisfacibile (SAT)

Data una formula, se applicando ripetutamente la regola di risoluzione a F e ai risolventi ottengo $\square$, allora *F è UNSAT*
Se applicando la risoluzione ad una $F$ ottengo $\square$ allora $F$ è UNSAT
	"Correttezza" del sistema
	È anche "completo": se $F$ è UNSAT allora esiste un modo di ottenere $\square$ a partire da $F$ applicando risoluzione