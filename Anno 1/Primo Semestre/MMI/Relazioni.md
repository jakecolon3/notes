**Soprainsieme delle funzioni**
	Funzioni $\in$ Relazioni
$f: A \to B$
$f\subseteq A \times B=\{(a,b):a\in A, b\in B\}$
	Prodotto cartesiano A x B
Notazione in fissa: $xRy=(x,y)\in R$

## Definizione
Una relazione binaria (o a 2 posti) $R$ su insiemi $A$ e $B$ è un sottoinsieme di $A\times B$ (prodotto cartesiano)
	$P(A\times B)$ = coppie ordinate degli elementi dell'insieme $A$ con gli elementi dell'insieme $B$
	$(a,\hat a)\in S$ s.se a ha una relazione con $\hat a$
	$R = \{(a,b):a\in A,b\in B$ s.se \<condizione\>$\}$

### Relazioni di ordine
- $<_\mathbb{N}$ su $\mathbb{N}\times \mathbb{N}$
	$=\{(i,j):i,j\in \mathbb{N}, i<j\}$
	$<_\mathbb{N}\subseteq <_\mathbb{R}$
Es.: Stringhe binarie finite
	$R\subseteq B\times B;\  \sigma, \tau\in R$ s.se $\sigma$ è un prefisso di $\tau$
		Stringhe binarie che iniziano per $\sigma$ e terminano per $\tau$

### Osservazione
Possono quasi sempre ridursi a considerare relazioni binarie di tipo $A\times A$
	Posso quasi sempre trovare un insieme che comprende entrambi gli insiemi precedenti
		$A$ = esseri umani
		$B$ = gatti
		$A\times B\supseteq R$
		$(a,b)\in R$ s.se a è padrone di b
		Equivalente a $C\times C$ con $C$: esseri viventi


### Rappresentazione delle relazioni
E' possibile rappresentare le relazioni in modo simile alle funzioni (punti e frecce \[grafo])
	Le frecce possono puntare anche a punti dello stesso insieme
Oppure con una *matrice* con righe e colonne assegnate ad ogni elemento dei 2 insiemi e ogni punto della matrice = 1 se la coppia fa parte della relazione e 0 se non ne fa parte

### Relazioni inverse
$R\subseteq A\times B=\{(a,b):\dots\}$
	$R^{-1}\subseteq B\times A=\{(b,a):(a,b)\in R\}$
	Al contrario delle funzioni è sempre possibile invertire una relazione
	Nella rappresentazione con matrice è equivalente a scambiare righe e colonne (1° riga -> 1° colonna etc.)
		"Trasposizione"

## Composizione di relazioni
 $R,S \subseteq A\times A$
	$(a,b)\in R$ se a è sposato con b
	$(c,d)\in R$ se d è figlio di c
	$(x,y) \in (S\circ R)$ s.se esiste $z\in A: (x,z)\in R, (z,y)\in S$
		Se esiste un punto z in R raggiungibile da x che raggiunge un punto y in S
		Equivalente per $(R\circ S)$
![[IMG_20251106_094412.jpg]]
E' anche possibile comporre una relazione per se stessa:
$R\subseteq A\times A$
	$(R\circ R)=$ Gli elementi di R "distanti 2" dal punto nel grafo
		$(R\circ R) = R^2$
	Es. $R\subseteq \mathbb{N}\times \mathbb{N}$
	$(x,y)\in R$ s.se $y=x+1$
	$(R\circ R)=\{(x,y):y=x+2\}$
	$x<y$ s.se esiste $n$: $y=x+n$ s.se esiste $n:(x,y)\in <=\bigcup_{}{R^n}$

### Transitività
$R\subseteq A\times A$ è transitiva se:
	$\forall x,y,z\in A$ se $(x,y)\in R$ e $(y,z)\in R$ allora $(x,z)\in R$
	$x,y,z$ *non* devono essere distinti
	Se non si verifica $(x,y)\in R, (y,z)\in R$ è comunque transitiva (transitiva a vuoto)
		Dati $x,y$ in relazione e $y,z$ in relazione, $R$ è transitiva se anche $x,z$ sono in relazione
		Es. raggiungibilità
			Da una mappa di raggiungibilità con 1 passo $R$, la mappa di raggiungibilità in $n$ passi è $\bigcup_{i=1}^{n}R^n$
				Questa relazione è sicuramente transitiva con $n\to\max$ (?)

## Chiusura transitiva
Una relazione $R^*$ è *chiusura transitiva* ($R^* < R$ (??)) di R s.se
1. $R\subseteq R^*$
2. $R^*$ è transitiva
3. $R^*$ è la più piccola relazione con che soddisfa gli altri 2 punti
	Se $S$ estende $R$ ed è transitiva allora $R^*\subseteq S$
Posso ottenere la chiusura transitiva di una relazione $R$ componendo $R$ con sé stessa più volte:
	$R^*=R\circ R\circ R...\circ R=R^n$
	$R^*=\bigcup_{n\in\mathbb{N}}R^n=R^\infty$

### Riflessività
$R\subseteq A\times A$ è riflessiva s.se $\forall a\in A, (a,a)\in R$
	Ogni vertice ha un arco che punta a se stesso

### Simmetria
$R\subseteq A\times A$ è simmetrica s.se $\forall (a,b)\in A$:
	Se $(a,b)\in R$ allora $(b,a)\in R$
		Per ogni freccia esiste la freccia inversa

## Relazione di equivalenza
$R\in A\times A$ è una *relazione di equivalenza* s.se:
1. $R$ è transitiva
2. $R$ è simmetrica
3. $R$ è riflessiva
	Es.
	$R\subseteq A\times A$
	$f:A\to \mathbb{N}$
	$(a,b)\in R$ s.se $f(a)=f(b)$
		In generale, se definisco una $R$ su $A$ come $(a,b)\in R$ s.se hanno certo valore assegnato identico, ottengo una relazione di equivalenza
Questa proprietà è equivalente alla partizione insiemistica
Es.
	$R\subseteq \mathbb{Z}\times \mathbb{Z}$
	$(a,b)\in R$ s.se $a-b$ è pari
	Dimostriamo:
	- Rifl.: $\forall a\in \mathbb{Z}, (a,a)\in R$ s.se $a-a$ è pari ($a-a=0$)
	- Sim.: $\forall a,b\in \mathbb{Z}, (a,b)\in R$ s.se $(a-b)$ è pari => $(b-a)\in R$ s.se $(b-a)$ è pari
	- Trans.: $\forall a,b,c\in\mathbb{Z}, (a,b)\in R$ s.se $(a-b)$ è pari, $(b,c)\in R$ s.se $(b-c)$ è pari
		$(a,c)\in R: (a-c)$ è pari
		$(a-b)+(b-c)=(a-c)$ ed è pari perché $(a-b),(b-c)$ sono pari

### Classe di equivalenza
Data una relazione $R\subseteq A\times A$ con $a,b\in A$, il *vicinato* di $a$ è l'insieme degli elementi $b$ in relazione con $a$: $\{b\in A: aRb\}$
Se $R$ è una relazione di equivalenza, chiamiamo *classe di equivalenza* = $[a]_R$ ("a modulo R") il vicinato di $R$
$\forall [a]_R=\{b\in A:aRb\}$ valgono:
1. $\forall a \in A, [a]_R\not= \emptyset$
	$R$ è riflessiva, quindi $a\in R, \ \forall a\in A$
2. $\forall a,b\in A,$ o $[a]_R\cap[b]_R=\emptyset$ o $[a]_R=[b]_R$
	2 casi:
	- Vale $aRb$
		

$A = \mathbb{N}\times\mathbb{N}$
Considero una $R\subseteq A\times A$
Definita come:
	$((a,b),(c,d))\in R$ s.se:
		$a+d=b+c$
Dimostriamo che è equivalenza:
- Rifl.
	Def:
	$\forall (a,b)\in \mathbb{N}\times\mathbb{N}: ((a,b),(a,b))\in R$
		Applicata: $a+b=b+a$
- Simm.
	Def:
	$\forall ((a,b),(c,d))\in \mathbb{N}\times\mathbb{N}: ((c,d),(a,b))\in R$
		Applicata: $(a+d=b+c)=(c+b=d+a)$
- Trans.
	Def.
	$\forall ((a,b),(c,d),(e,f))\in \mathbb{N}\times\mathbb{N}$:
		Se $((a,b),(c,d))\in R$ e $((c,d),(e,f))\in$ allora $((a,b),(e,f))\in R$
		Applicata: Se $(a+d=b+c)=(c+f=d+e)$ allora $a+f=b+c$
			$a-b=c-d$
			$c-d=e-f$
			$a-b=e-f$

### Rel. equivalenza e partizioni
$R\subseteq A\times A$ è equivalenza
$a\in A$
$[a]_R=\{a'\in A:(a,a')\in R\}$ = vicinato di $a$ = classe di equivalenza di $a$ = punti distanti uguali
$S=(V,R\subseteq V\times V))$ (??)
Cosa posso dire di $[a]_R$ se $R$ è di equivalenza?
- Non vuota
	$a\in[a]_R$ perché $R$ è rifl.
- $\forall a,a'\in A$:
	$[a]_R=[a']_R$ oppure
	$[a]_R\cap[a']_R=\emptyset$ (sono disgiunti)

Se $[a]_R\cap[a']_R\not=\emptyset$:
- $b\in[a]_R$ s.se $(a,b)\in R$
- $b\in[a']_R$ s.se $(a',b)\in R$
Tesi: $[a]_R=[a']_R$
	$\forall c$:
		$(a,c)\in R <=> (a',c)\in R$ ????????

Si può definire una rel. di equivalenza partendo da una partizione

Se $R$ è simm., trans. e $(a,b)\in R$:
	$(a,a)\in R$
	$(b,b)\in R$
$R$ è sempre rifl.?
	No
		Controesempio: aggiungo un punto isolato

## Applicazione delle classi di equivalenza
Dato $\mathbb{N}$ definisco $\mathbb{Z}$ come $\{[(a,b)]_R\ |\ (a,b)\in \mathbb{N}\times\mathbb{N}\}$
$R\subseteq A\times A$ = classe di equivalenza
$A \to \{[a]_R\ |\ a\in A\}$ = è il quoziente di $A$ modulo $R$, cioè *l'insieme delle classi di equivalenza di R*
Così posso definire delle operazioni su diverse classi di equivalenza:
	Es.
	$[(a,b)]_R+[(\hat a,\hat b)]_R=[(a+\hat a,b+\hat b)]$
Però devo dimostrare che questa definizione non dipende dai rappresentanti ($a,b,\hat a,\hat b)$

Generalizzazione di $a\leq b$:
(E' un ordine totale)
$\leq \subseteq \mathbb{N}\times \mathbb{N}$
Proprietà:
- Rifl.: $\forall a\ (a\leq a)$
- Trans.
- Antisimmetrica
	Simmetrica per $a,b$ solo se $a=b$
		$\forall a,b\in \mathbb{N}$ se $a\leq b$ e $b\leq a$ allora $a=b$
- Totalità
	$\forall a,b\in \mathbb{N}\ (a\leq b\ o\ b\leq a)$
Quindi $R\subseteq A\times A$ è un ordine totale s.se ha queste proprietà
Se tolgo la totalità definisco un ordine parziale: $\subseteq$
	- $S\subseteq S$
	- $S\subseteq T \subseteq Q => S\subseteq Q$
	- $S\subseteq T$ e $T\subseteq S=>S = T$

Es. Ordine del dizionario:
	$R$ (ordine) $\subseteq A\times A$ (stringhe finite di lettere nell'alfabeto)
	$\sigma = s_1... s_k$
	$\tau = t_1...t_l$
	$\sigma \leq_\text{lex}\tau$
		E' un ordine totale

Cercare lungo un ordine lineare/totale è molto efficiente
Non per gli ordini parziali
E' possibile passare da un ordine parziale ad un ordine totale che lo include:
Ogni ordine parziale ammette una estensione totale
	$\forall R\subseteq A\times A$ di ordine parziale $\exists \hat R\subseteq A\times A: R\subseteq\hat R, \text{ e }\hat R$ è totale
Lemma: $R\subseteq A\times A$ ordine parziale
	Siano $a,b\in A$ incomparabili
		$[(a,b)\not\in R, (b,a)\not\in R]$
	$\exists R'\subseteq A\times A$ ordine parziale:
	1. $R\subseteq R'$
	2. $(a,b)\in R'$
		Guarda dim.