# Successioni
$a:\mathbb{N}\rightarrow \mathbb{R}$
 $\lim_{n\to +∞}{a_n}=l$
	Se una successione soddisfa questa condizione **si stabilizza** a $l$ per $n\to +∞$
		Es.
		$a_n=\frac{1}{n+1}$
		$\lim_{n\to +∞}{a_n}=0$
		Vero, questa successione si stabilizza a 0
In generale:
$a_n$ tende a $l$ se
$\forall \varepsilon >0, \exists \text{ un indice } n_\varepsilon \text{ dipendente da }\varepsilon:|a_n-l|<\varepsilon,\ \forall n>n_\varepsilon$
	Cioè $-\varepsilon<a_n-l<\varepsilon,\ \forall n>n_\varepsilon$
	Cioè $l-\varepsilon<a_n<l+\varepsilon,\ \forall n>n_\varepsilon$

### Successioni divergenti
La successione $(a_n)_n$ **diverge** a $\pm∞$ se comunque si scelga $M>0$, tutti i valori di $a_n$ sono *maggiori/minori* di M tranne al più un numero finito
	Cioè $\forall M >0\ \exists\ n_M:a_n≥/≤M\ \forall n>n_M$
		$\lim_{n\to+∞}{a_n}=\pm ∞$
		Quindi comunque fisso M esiste un punto $n_M$ per cui ogni punto dopo di esso sarà sopra M

**Teorema del confronto**
Date due successioni $a_n, b_n$ con $a_n≥b_n\ \forall n≥n_0$
Se $\lim_{n\to+∞}{b_n}=+∞$ allora $\lim_{n\to+∞}{a_n}=+∞$

**Principio di induzione??**
Data un’affermazione $P(n): \text{es. }2^n≥ n$:
- Se $P(n)$ è vera
- Se $P(n)$ implica $P(n+1)$ (?)
Allora $P(n)\text{è vera }\forall n≥0$

**Disuguaglianza di Bernoulli**
Fisso $h>0$
$(1+h)^n≥1+n*h,\forall n ≥0$
	Dimostro con induzione
	$P(0): (1+h)^0=1≥1+0=1$ si
	$P(n+1):(1+h)^{n+1}≥1+(n+1)*h$ Teorema del confronto
		$=(1+h)(1+h)^n\geq (1+h)(1+nh)=$
		$=1+h+nh+nh^2=1+(n+1)h+nh^2\geq 1+(n+1)h$ C.V.D

**Gerarchia degli infiniti**
Date $a_n\to +∞, b_n\to+∞$, se $\lim_{n\to+∞}{\frac{b_n}{a_n}}=+∞$ allora $b_n$ ha ordine di infinito *superiore* di $a_n$: $a_n<<b_n$
$$(\log_Bn)^\beta<<n^\alpha<<A^n<<n!<<n^n,\ A,B>1,\ \alpha,\beta>0$$
N.B. $A^n\to\{+∞\ |\ A>1, 1\ |\ A=1,\ 0\ |\ 0<A<1$
$n^\alpha A^n<<n!$

Data $a_n$, se $|a_n|\to +∞$ allora $\frac{1}{a_n}\to0$: $\lim_{n\to +∞}{\frac{1}{a_n}}=0,\ |a_n|\to+∞$
	Se una successione tende all’infinito, il suo reciproco tende a 0

### Operazioni con i limiti
$\lim a_n +\lim b_n=l+m$
$\lim a_n -\lim b_n=l-m$
$\lim a_n *\lim b_n=l*m$
$\frac{\lim a_n}{\lim b_n}=\frac{l}{m}, m≠0, b_n≠0$

## Teoremi
1. Una successione convergente non può avere 2 limiti diversi
	guarda dim.
2. Date 2 successioni $a_n$ e $b_n$, se $a_n\to 0$ e $b_n$ è limitata, allora $a_n*b_n\to 0$
3. Una successione convergente è limitata
	Se $a_n\to l\ \exists M>0: |a_n|≤M\ \forall n\in \mathbb{N}$
	Non vale il viceversa
		Dim:
		Ip: $a_n\to l$ cioè $\forall \varepsilon >0 \exists n_\varepsilon\in\mathbb{N}:|a_n-l|<\varepsilon\ \forall n≥n_\varepsilon$
		Assumiamo $\varepsilon=1: |a_n-l|<1, \forall n≥n_1$
		$|a_n|=|a_n-l+l|≤_\text{disuguaglianza triangolare}|a_n-l|+|l|<1+|l|\ \forall n≥n_1$
		boh
4. Monotonia del limite
	$a_n\to l\in\mathbb{R},\ b_n\to m\in\mathbb{R}$
	- se $a_n≤b_n,\ \forall n\in\mathbb{N}$ allora $l≤m$
	- se $a_n<b_n,\ \forall n\in\mathbb{N}$ allora $l≤m$
5. Teorema dei carabinieri
	Date 3 successioni $a_n,b_n,c_n:$
	- $a_n≤b_n≤c_n\ \forall n\in\mathbb{N}$
	- $\lim_{n\to+∞}{a_n}=\lim_{n\to+∞}{c_n}=l\in\mathbb{R}$
	allora $\lim_{n\to+∞}{b_n}=l$
	Dim.
		$a_n\to l:\ l-\varepsilon<a_n<l+\varepsilon$
		$c_n\to l:\ l-\varepsilon<c_n<l+\varepsilon$
			$l-\varepsilon<a_n≤b_n≤c_n<l+\varepsilon$
			$l-\varepsilon<b_n<l+\varepsilon\ \forall n≥n_\varepsilon$
	Usiamolo per dimostrare $A>0:\lim_{n\to∞}{\sqrt[n]{A}}=1$
		Sia $A>1$
		$\sqrt[n]{A}>1$
		$\sqrt[n]{A}=1+h_n,\ h_n>0$
		$h_n=\sqrt[n]{A}-1$
		Dis. di Bernoulli: $(1+h)^n≥1+nh,\ h>0$
		$h\to h_n$
		$(1+h)^n≥1+nh_n$
		$(\sqrt[n]{A})^n≥1+nh_n$
		$A≥1+nh_n$
		$A-1≥nh_n\ \ n≥1$
		$\frac{A-1}{n}≥h_n$
		$0≤h_n≤\frac{A-1}{n}$
		Per il teorema dei carabinieri $h_n\to0$
	Dimostra anche che $\lim_{n\to∞}{\sqrt[n]{n}=1}$
## Forme indeterminate
$a_n\to+∞,b_n\to-∞$
$a_n+b_n=\ ?$
### $+∞-∞$
Può convergere, può divergere, può essere limitata ecc.
- Differenza tra radici $\lim_{n\to+∞}{\sqrt{n+2}-\sqrt{n-1}}$
	Per risolvere ”razionalizza”: moltiplica e dividi per le radici, possibilmente cambiando segno
		$(a+b)(a-b)=a^2-b^2$
### $∞\cdot 0$
### $\frac{0}{0}$
### $\frac{∞}{∞}$
Individua e raccogli il termine che cresce di più al num. e denom.
Se al numeratore o al denominatore ci sono termini di cui non sono sicuro dell’ordine posso moltiplicare e dividere per un numero dello stesso ordine del termine maggiore
## Successioni monotone
Una successione $a_n$ è
- Strettamente crescente se $a_n<a_{n+1}\ \forall n$
- Strettamente decrescente se $a_n>a_{n+1}\ \forall n$
- Crescente (non decrescente) se $a≤a_{n+1}\ \forall n$
- Decrescente (non crescente) se $a_n≥a_{n+1}\ \forall n$
Per verificare la monotonia di una successione imposta la disuguaglianza con $a_n$ e $a_{n+1}$
### Proprietà
- Se $a_n, b_n$ sono crescenti, allora anche $a_n+b_n$ sarà crescente
	$a_{n+1}+b_{n+1}>a_{n+1}+b_n>a_n+b_n$
- Una successione monotona moltiplicata per una costante positiva mantiene la sua monotonia
- Una successione moltiplicata per una costante negativa inverte la sua monotonia
- Data una $a_n>0$ crescente, $\frac{1}{a_n}$ è decrescente
### Teorema
Le successioni monotone sono *regolari* (convergono o divergono)
Se $a_n$ è crescente, $\lim_{n\to∞}{a_n}=\sup{(a_n)}$
Se $a_n$ è decrescente, $\lim_{n\to∞}{a_n}=\inf{(a_n)}$
	Dimostriamo il primo caso per $\sup(a_n)\in\mathbb{R}$:
	$A\subseteq\mathbb{R}, s=\sup(A), s≥x\ \forall x\in A,\ \forall r<s\ \exists x\in A: r<x<s$ definizione di sup????
	$\sup(a_n)=l\in\mathbb{R}$
	$\forall \varepsilon >0\ \exists n_\varepsilon\in \mathbb{N}:l-\varepsilon<a_{n_\varepsilon}<l$
	$\forall n≥n_\varepsilon,\ l-\varepsilon<a_{n_\varepsilon}<a_n<l<l+\varepsilon$ = definizione di succ. limitata???
	Per $\sup(a_n)=+∞$
	$\forall A>0\ \exists n_A\in\mathbb{N}:a_{n_A}>A$
	$A<a_{n_A}<a_n\ \forall n>n_A$
### Successione di Nepero
$n≥1,\ a_n=(1+\frac{1}{n})^n\to e$
Dimostriamo
1. Dimostriamo che $a_n$ è crescente per induzione
	Supponiamo $n=1$
	$a_2>a_1=(1+\frac{1}{2})^2>(1+1)$
	$9/4>2$
	Verifichiamo $a_n≥a_{n-1}$
	$( 1+\frac{1}{n})^n\geq (1+\frac{1}{n-1})^{n-1}$
	$(\frac{n+1}{n})^n≥(\frac{n-1+1}{n-1})^{n-1}=(\frac{n}{n-1})^n\cdot(\frac{n-1}{n})$, sarebbe $x^{n-1}=\frac{x^n}{x}$
	$(\frac{n+1}{n})^n\cdot(\frac{n-1}{n})^n≥(\frac{n-1}{n})$ diviso per $(\frac{n}{n-1})^n$
	$(\frac{n^2-1}{n^2})^n>(\frac{n-1}{n})$
	$(1-\frac{1}{n^2})^n≥(1-\frac{1}{n})$
	Dis. bernoulli: $(1+x)^n≥1+nx,\ \forall n≥1\ \forall x≥-1$
	$x=-\frac{1}{n^2}, \left( 1-\frac{1}{n^2} \right)^n≥1+nx=1+n(-\frac{1}{n^2})=1-\frac{1}{n}$ 
	$(1-\frac{1}{n^2})^n≥1-\frac{1}{n}$ C.V.D.
2. Dimostriamo che $a_n$ è limitata
	Prendiamo una succ maggiore di $a_n:b_n=(1+\frac{1}{n})^{n+1}$ decrescente
	$b_1≥b_n\ \forall n$
	$b_n=(1+\frac{1}{n})^{n+1}>a_n=(1+\frac{1}{n})^n$
	(Foto)
	$b_2≥a_n$
	$4≥e≥a_1=2$
	Dimostriamo $b_n$ decr.
	$b_{n-1}≥b_n$
	$(1+\frac{1}{n-1})^n≥(1+\frac{1}{n})^{n+1}$
	$(\frac{n-1+1}{n-1})^n≥(\frac{n+1}{n})^{n+1}$
	$\left( \frac{n}{n-1} \right)^n≥\left( \frac{n+1}{n} \right)^{n+1}=\left( \frac{n+1}{n} \right)^n\cdot(\frac{n+1}{n})$
	$(\frac{n}{n-1})^n\cdot(\frac{n+1}{n})^{-n}≥\frac{n+1}{n}$
	$(\frac{n}{n-1})^n(\frac{n}{n+1})^n≥\frac{n+1}{n}$
	$[(\frac{n}{n-1})(\frac{n}{n+1})]^n≥\frac{n+1}{n}$
	$(\frac{n^2}{n^2-1})^n≥\frac{n+1}{n}=1+\frac{1}{n}$
	Riduciamo ad un caso simile a bernoulli
	$(\frac{(n^2-1)+1}{n^2-1})^n=(1+\frac{1}{n^2-1})^n≥1+\frac{1}{n}$
	Bernoulli
	$x=\frac{1}{n^2-1}$
	$(1+\frac{1}{n^2-1})^n≥1+\frac{n}{n^2-1}≥1+\frac{1}{n}$
	$\frac{n}{n^2-1}>\frac{1}{n}$
	$n^2>n^2-1$ moltiplicato per denom.i

$b_n\to∞$ allora $(1+\frac{1}{b_n})^{b_n}\to e$
$b_n\to∞$ allora $(1+\frac{A}{b_n})^{b_n}\to e^A$
Utile per risolvere esercizi tipo $\lim_{n\to+∞}{(1+\frac{1}{n!})^{4^n}}$
	Riduci a succ. di Nepero moltiplicando e dividendo

## Limiti notevoli
Li dimostreremo più tardi
### $a_n\to0,n\to+∞$
$\lim_{n\to+∞}{\frac{e^{a_n}-1}{a_n}}=1$
$\lim_{n\to+∞}{\frac{\sin(a_n)}{a_n}}=1$
$\lim_{n\to+∞}{\frac{\tan(a_n)}{a_n}}=1$ da def. di tangente
$\lim_{n\to+∞}{\frac{1-\cos(a_n)}{(a_n)^2}}=\frac{1}{2}$
$\lim_{n\to+∞}{\frac{1-\cos(a_n)}{a_n}}=0$
	$=\frac{1-\cos(a_n)}{(a_n)^2}\cdot a_n=\frac{1}{2}\cdot 0$
$\lim_{n\to+∞}{\frac{\arcsin(a_n)}{a_n}}=\lim_{n\to+∞}{\frac{\arctan(a_n)}{a_n}}=1$
###### Formula di Stirling
 $\lim_{n\to+∞}{\frac{n!}{n^n\cdot e^{-n}\sqrt{2\pi n}}}=1$
	 es. $\lim_{n\to +∞}{\frac{n!3^n}{n^n}}$
	 $=\lim{\frac{n!}{n^ne^{-n}\sqrt{2\pi n}}\cdot e^{-n}\sqrt{2\pi n}\cdot 3^n}$
	 $=\lim{1\cdot (\frac{3}{e})^n\cdot\sqrt{2\pi n}}=+∞\cdot +∞$
$\lim_{n\to∞}{\sqrt[n]{x}}=1,\ \forall x>0$
	**Dimostrazione**
	Dis. Bernoulli: $(1+h)^n≥1+hn,\ h≥1,\ n≥1$
	$a_n=\sqrt[n]{x}$
	- $x>1$
		$a_n>1\ \forall x$
		$a_n = 1+h_n,\ h_n=0(?)$
		$x=(a_n)^n=(1+h_n)^n≥1+h_n\cdot n$
		$x-1≥h_n\cdot n≥0$
		$\frac{x-1}{n}\to 0≥h_n≥0$
	- $x=1$
		$\sqrt[n]{1}=1$
	- $0<x<1$
		$\sqrt[n]{x}=\frac{1}{\sqrt[n]{\frac{1}{x}>1}\to1}$
		$\frac{1}{x}>1$ perché è l’inverso di $0<x<1$
