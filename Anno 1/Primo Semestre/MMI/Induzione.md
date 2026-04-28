# Schema
Voglio dimostrare che $\forall n\geq 1$ vale $P(n)$
1. Caso base: $P(1)$
	Dimostro che P vale per 1
2. Passo induttivo
	Sia $n\geq 1$
	$P(n)\to P(n+1)$
3. Concludo $\forall n\geq1$ vale $P(n)$
	Quindi se 1. e 2. allora 3.
Dim.
	Sia $n^*$ il più piccolo naturale $\geq 1$ per cui non vale P
	Non è $1$ perché 1.
	Deve essere $>1$ 
	$n^*-1>1$ vale $P$ perché $n^*$ è il più piccolo per cui non vale
	Ma per 2. vale $n^*-1+1$ quindi vale $P(n^*)$

### Conteggi combinatori
\# sottoinsiemi di un insieme di $n$ elementi $= 2^n$
Dimostriamolo per induzione:
	Base:
		$n=1$
		Sia $A$ un insieme con 1 elt.
		$A$ ha $2^1$ sottoinsiemi ($\{A\},\{0\}$)
	Passo induttivo:
		Sia $A$ un insieme con $n+1$ elt.
		$A = \{a_1,a_2,...,a_n,a_{n+1}\}$
		Fissiamo $a_1$
			I sottoinsiemi $S$ di $A$ sono di 2 tipi:
			1. $a_1\in S$
				$\{a_1\}\cup S^*\subseteq A/\{a_1\}$
				Sono i sott. di $S^*$ che è un insieme di $n$ ($n+1-1$) elementi = $2^n$
			2. $a_2\not\in S$
				Sono i sott. di $A/\{a_1\}$ che è un insieme di $n$ ($n+1-1$) elementi = $2^n$
			Quindi i sott. di $A$ sono $2^n+2^n=2\cdot2^n=2^{n+1}$

\# di 2-sottoinsiemi di un insieme di $n$ elementi è $(^n_2)=\frac{n(n-1)}{2}$
Per induzione:
	Base:
		$n=2$
		Sia $A$ un insieme con 2 elementi
		$A=\{a,b\}$
		$\{a,b\}$ è l'unico 2-sottoinsieme
		$\frac{2(2-1)}{2}=1$
	Passo induttivo:
		Sia $A$ un insieme con n+1 elementi
		Fissiamo $a_1$
			I 2-sottoinsiemi di $A$ sono di 2 tipi:
			1. $a_1\in S$
				Sono i 2-sott. di tipo $\{a_1,a_2\},...,\{a_1,a_n\},\{a_1,a_n+1\}$ che sono $n$ (da 2 a n+1)
			2. $a_2\not\in S$
				Sono tutti e soli i 2-sott. di $A/\{a_1\}$
				$=\frac{n(n-1)}{2}$
			Quindi i 2-sott. di A sono $n+\frac{n(n-1)}{2}=\frac{(n+1)n}{2}$

$\forall n\geq 1$, se $A$ e $B$ hanno entrambi $n$ elementi allora il numero di biiezioni tra $A$ e $B$ è $n!$
Dimostralo per induzione

# Rinforzare l'ipotesi induttiva
...

# Errori di induzione
Bisogna assicurarsi che l'implicazione $P(n)\to P(n+1)$ vale per il caso base (esempio credenti)

### Es.
1. $\forall n\geq 12$ posso scrivere $n$ con pezzi da 4 e da 5
2. Per ogni $k, l\ \exists\ b:\ \forall n\geq b$ posso scrivere $n$ come $n=kx + ly$ per qualche $x, y\geq 0$

# Teorema
Ogni numero naturale $\geq 2$ si può scrivere come prodotto di numeri primi
Dim.
	$n=2$
	Passo: Preso $n\geq 2$, se $n$ si può scrivere come prodotto di primi allora $n+1$ si può scrivere ecc.
		Quindi esistono $(p_1, ..., p_k)$ primi t.c. $n=p_1\cdot...\cdot p_k$ (stesso per n+1)
		1. $n$ primo: fatto
		2. $n$ non primo:
			$n=a\cdot b$
			$z\leq a,b < n$ (?)
			Assumo che a, b sono fattorizzabili per primi (tesi induzione)
			Ripeti per a e b (?)
				Se sono primi hai finito
				Se non sono primi ripeti
					Induzione su un albero qualcosa
					Va formalizzato

# Principio di induzione forte
"$\forall n\geq b\ \ \ P(n)$"
Base: $P(0)$
Passo: Sia $n\geq b$, dimostriamo $P(n+1)$ assumendo $P(b), P(b+1), ..., P(n)$
	Ora assumiamo anche tutte le proposizioni da $P(b)$ a $P(n)$ invece che solo $P(n)$

### Esempi con la sequenza di Fibonacci:
	$F_0=0,\ \ F_1=1,\ \ F_n=F_{n-1}+F_{n-2}$
	Dimostriamo: $\forall n\geq 1, F_n\leq 2^n$
		Base: $n=1$
			$F_1=1,\ \ 1\leq 2^1=2$
		Passo: sia $n\geq 1$
			Tesi: $F_{n+1}\leq2^{n+1}$, supponendo $F_n\leq 2^n$
			$F_{n+1}=F_n+F_{n-1}$
				Per ip. ind.: $F_n\leq 2^n$
				Per ip. ind. forte: $F_{n-1}\leq 2^{n-1}$
					Quindi mettendoli insieme: $F_{n+1}=F_n+F_{n-1}\leq 2^n+2^{n-1}\leq 2^{n+1}$ C.V.D.
	Dimostriamo: $\forall n\geq2,\ F_n\geq(\frac{3}{2})^{n-2}$
		Base: $n=2$
			$F_2=F_1+F_0=1+0=1\geq(\frac{3}{2})^0$
			Base 2 (servono perché fib è definito per 2 casi precedenti): $n=3$
				$F_3=F_2+F_1=2\geq (\frac{3}{2})^{3-2}=\frac{3}{2}$
		Passo: sia $n\geq 2$
			Tesi: $F_{n+1}=F_n+F_{n-1}\geq (\frac{3}{2})^{(n+1)-2}=(\frac{3}{2})^{n-1}$
			$F_{n+1}=F_n+F_{n-1}\geq (\frac{3}{2})^{n-2}+(\frac{3}{2})^{n-3}\geq (\frac{3}{2})^{n-1}$ C.V.D.
	Dimostriamo: $\sum_{i=0}^{n}F_{2i}=F_{2n+1}-1$
		Base: $n=1$
			$F_0+F_2=1=F_3-1$
		Passo: $n\geq 1$
			$\sum_{i=0}^{n+1}F_{2i}=(\sum_{i=0}^nF_{2i})+F_{2(n+1)}=F_{2n+1}-1+F_{2n+2}$
			Tesi: $\sum_{i=0}^{n+1}F_{2i}=F_{(2(n+1)+1)}-1=$
				$=F_{2n+1}-1+F_{2n+2}=F_{2n+3}-1$ C.V.D.

## Doppia induzione
$\forall a\geq 1\ \ \forall b\geq 1:$
	$(a+1)^b>a\cdot b$
Del tipo: $\forall a\geq 1: P(a)$, ma $P(a)$ a sua volta è: $\forall b\geq 1: P(b)$
Base: $n=1$
	$P(1)=\forall b\geq 1: (1+b)^b>1\cdot b=Q(b)$
Passo: $a\geq 1$
	$P(a)\to P(a+1)=$
		$\forall b\geq 1: (a+1)^b\to ((a+1)+1)^b>(a+1)\cdot b$
		(si può anche prendere prima $P(b)$)
	Vediamo ora $Q(b)$:
		Base: $b=1$
			$(1+1)^b>1\cdot 1$
		Passo: $b\geq 1$
			$2^b>b\to 2^{b+1}>b+1$
		Poi si dimostra normalmente
		In pratica è un'induzione dentro un'induzione
boh ma continua come una dimostrazione normale credo
Riassumendo:
$F(a,b)$
Base: $F(1, 1)$, abbiamo $a=1,b=1$
	$(1+1)^1>1\cdot 1$
Passo: sia $a\geq 1$, fisso $b=1$
	$F(a,1)=>F(a+1,1)$
	$((a+1)+1)^1>(a+1)\cdot 1$
	$a+2>a+1$
boh guarda dispense

# Induzione strutturale
$\mathbb{N}=$ minimo insieme $S$ che ha queste proprietà:
1. $0\in S$
2. Se $s\in S$ allora $s+1\in S$
Preso $X$ definito come minimo $S$:
1. $B\subseteq S$ con $B$= elementi di base
2. $S$ è chiuso sotto gli operatori della famiglia $F$
Per dimostrare che $\forall x\in X$ vale $P(x)$:
1. Vale per ogni $b\in B$
2. P è ? da tutti gli operatori
$f$ operatore:
	Siano $x_1,...,x_n\in X$: $P(x_1)\ e...\ e\ P(x_n)$ allora:
		$P(f(x_1,...,x_n))$
Esempi:
- Stringhe finite su un alfabeto $\Sigma$
	Sia $\Sigma^*$ il minimo insieme (relativamente all'ordine $\subseteq$) $S$ tale che:
	1. $\varepsilon \in S$ ($\varepsilon=$stringa vuota)
	2. Se $a\in\Sigma$ e $\sigma\in S$ allora $\sigma a\in S$
	Definiamo la funzione $L:\Sigma^*\to\mathbb{N}$ per ricorsione su $\Sigma^*$
		$L(\varepsilon)=0$
		$L(\sigma a)=L(\sigma) + 1$
			Come una funzione ricorsiva in Python
	Definiamo la concatenazione $\circ:\Sigma^*\to\Sigma^*$
		Base: $\tau\circ\varepsilon = \tau$
		$\tau\circ(\sigma a)=(\tau\circ\sigma)a$
	Definiamo le occorrenze $NUM_x:\Sigma^*\to\mathbb{N},x\in\Sigma$
		$NUM_x(\varepsilon) = 0$
		$NUM_x(\sigma a)=\{^{NUM_x(\sigma): x\not=a}_{NUM_x(\sigma)+1:x=a}$
			Le occorrenze di una lettera $x$ in una parola $\sigma a$ è $NUM_x(\sigma)$ se $x\not=a$, $NUM(\sigma) + 1$ se $x=a$
	Definiamo l'inversione $INV:\Sigma^*\to\Sigma^*$
		$INV(\varepsilon)=\varepsilon$
		$INV(\sigma a)= a\ INV(\sigma)$
	Proprietà: Per ogni $\sigma,\tau\in\Sigma^*$:
		$L(\tau\circ\sigma)=L(\tau)+L(\sigma)$
		Dimostriamo con induzione:
			Visto che ci sono 2 variabili è una doppia induzione
			Proprietà: $P(\sigma):$ per ogni $\tau\in\Sigma^*$ vale $L(\tau\circ\sigma) = L(\tau) + L(\sigma)$
				Induzione strutturale su $\sigma$:
					Base: $\sigma = \varepsilon$
					Tesi: $\forall\tau\in \Sigma^*: L(\tau\circ\varepsilon)=L(\tau)+L(\varepsilon)$
						$\tau\circ\varepsilon = \tau, L(\varepsilon)=0$
						$L(\tau)=L(\tau)+0$ vero
					Passo: considero un elemento generico $\sigma a$ (non vuota perché $a\not=\varepsilon$)
						Tesi: $\forall\tau\in\Sigma^*$ vale $L(\tau\circ\sigma)=L(\tau)+L(\sigma a)$
							$L(\tau\circ\sigma a) = L((\tau\circ\sigma) a)$ per definizione di concatenazione
							$L((\tau\circ\sigma) a)=L(\tau\circ\sigma)+1$ per definizione di $L$
							$=L(\tau)+L(\sigma)+1$ per ipotesi induttiva
								$L(\sigma)+1=L(\sigma a)$ per definizione di L
							$=L(\tau)+L(\sigma a)$ C.V.D. (abbiamo dimostrato $P(\sigma)\to P(\sigma a)$)
Esercizi:
1. Dimostra:
	Per ogni $\sigma,\tau \in \Sigma^*$,
	Per ogni $x\in\Sigma$: $NUM_x(\sigma\circ\tau)=NUM_x(\sigma)+NUM_x(\tau)$
2. Dimostra:
	Per ogni $\sigma,\tau\in \Sigma^*$,
	$INV(\sigma\circ\tau)=INV(\tau)\circ
3. Dato M:
	$\varepsilon\in M\subseteq \{<,>\}^*$
	Se $\sigma,\tau\in M$ allora $<\sigma>\tau\in M$
	Dimostra
		$\forall \sigma\in M:$ il numero di simboli $<$ in $\sigma=$ il numero di simboli $>$ in $\sigma$
		$\forall\sigma\ \ NUM_<(\sigma)=NUM_>(\sigma)$
4. Alberi, alberi binari, alberi binari pieni sono definiti induttivamente
	Alberi bin pieni:
		Ogni nodo ha o 0 o 2 figli
		Def. $B$:
			Dato $\cdot\in B$
			se $S,D\in B$ allora $(\cdot, S, D)\in B$
	1. Dimostra che il numero di foglie è $\leq 2^{\text{altezza albero}}$
		- Definire ricorsivamente numero foglie $F: B\to\mathbb{N}$
			$F(\cdot)=$
			$F((\cdot, S, B))=F(S)+F(B)$
	2. Definire altezza $A:B\to \mathbb{N}$
	3. Definire $N(B)=$ numero di nodi in $B$
	4. Definire $E(B)=$ numero di archi in $B$
	5. Dimostrare che $N(B)=E(B)+1$

L'induzione strutturale è usata per dimostrare le proposizioni nella [[Logica]]