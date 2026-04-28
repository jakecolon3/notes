Una serie numerica è **la somma di tutti i componenti di una successione**:
$$\{a_n\}_{n\in\mathbb{N}},\ \ \ 
\sum_{n=0}^{\infty}{a_n}=a_0+a_1+...$$

# Somme parziali
Se si somma solo fino a $k$ elementi di una successione si ha una *somma parziale* $=S_k$
$$\sum_{n=0}^{k}{a_n}=a_0+a_1+...+a_k=S_k$$
Posso chiedermi: esiste $\lim_{k\to+\infty}{S_k}$?
### Serie indeterminate
Def.: se $\not\exists\lim_{k\to+\infty}{S_k}$ una serie si dice *indeterminata* se:
	$\sum_{n=0}^{\infty}{a_n}=\not\exists$

### Serie convergenti
Def.: se $\exists\lim_{k\to+\infty}{S_k}=S\in\mathbb{R}$ una serie si dice *convergente* se:
	$\sum_{n=0}^{\infty}{a_n}=S$

### Serie divergenti
Def.: se $\exists\lim_{k\to+\infty}{S_k}=\pm\infty$ una serie si dice *divergente* se:
	$\sum_{n=0}^{\infty}{a_n}=\pm\infty$

# Serie particolari
$\lim_{n\to+\infty}a_n=l$
$$
\sum_{n=0}^{\infty}{a_n}=\begin{cases} +\infty\ \ \ l>0\\-\infty\ \ \ l<0\\0\ \ \ \ \ \ \ \ l=0\end{cases}
$$
## Proposizioni
Se $\sum_{n=0}^{\infty}{a_n}$ converge allora $\lim_{n\to+\infty}{a_n}=0$
	Dim.:
	$\exists \lim_{k\to+\infty}{S_k}=S$
	$S_{k+1}=\sum_{k=0}^{k+1}a_n=a_0+...+a_{k+1}$
	$S_{k+1}-S_k=a_{k+1}$
	$\lim_{k\to\infty}S_{k+1}-S_k=S-S=0=\lim_{k\to\infty}a_{k+1}$
Se $\lim_{n\to+\infty}{a_n}\not=0$, $\sum_{n=0}^{\infty}{a_n}$ non converge
## Operazioni con serie
- $\sum_{n=0}^{\infty}{a_n}+{b_n}=\sum_{n=0}^{\infty}{a_n}+\sum_{n=0}^{\infty}{b_n}$ se non divergono ad infiniti opposti (?)
- $\sum_{n=0}^{\infty}{\lambda a_n}+{\mu b_n}=\sum_{n=0}^{\infty}{\lambda a_n}+\sum_{n=0}^{\infty}{\mu b_n}$ se al più una diverge

### Serie geometrica
Fisso $x\in\mathbb{R}$
$\sum_{n=0}^{\infty}{x^n}$
	$a_n=x^n$
Il comportamento all'infinito di $a_n$ dipende dalla base:
$$\lim_{n\to\infty}{b^n}=\begin{cases} +\infty\ \ b>1\\ 1\ \ \ \ \ \ \ b=1\\ 0\ \ \ \ \ \ \ -1<b<1\\\not\exists\ \ \ \ \ \ \ b\leq-1\\\end{cases}$$
Con $x\not=1$:
$$S_k=\sum_{n=0}^{k}x^n=1+x+x^2+...+x^k=\frac{1-x^{k+1}}{1-x}$$
Ora facciamo il limite usando cosa abbiamo visto ($b^n$):
$$
\sum_{n=0}^{\infty}{x^n}=\lim_{k\to+\infty}{\frac{1-x^{k+1}}{1-x}}=\begin{cases}+\infty\ \ \ x>1\\\frac{1}{1-x}\ \ -1<x<1\\\not\exists\ \ \ \ \ \ \ \ x\leq-1\end{cases}
$$
Si può anche calcolare partendo da un numero maggiore di 0:
$$
\sum_{n=p}^{\infty}{x^{n}}=\sum_{n=p}^{\infty}{x^{n-p+p}}=\sum_{n=p}^{\infty}{x^px^{n-p}}=(i=n-p)=x^p\sum_{i=0}^{\infty}{x^{i}}=x^p\cdot\ ...
$$

### Serie telescopiche
Le serie telescopiche sono serie dove $a_n$ si può scrivere come $b_{n+1}-b_n$
$S_k=a_0+a_1+a_2+...+a_k$
	$a_0=b_1-b_0$
	$a_1=b_2-b_1$
	...
Quindi:
$S_k=(b_1-b_0)+(b_2-b_1)+...+(b_k-b_{k-1})+(b_{k+1}-b_k)=b_{k+1}-b_0$
In generale:
$\lim_{k\to+\infty}b_{k+1}-b_0$ tende a $\pm\infty$ se $b_k\to\pm\infty$; = $b-b_0$ se $b_k\to b$; è indeterminato se $\not\exists\lim_{k\to+\infty}{b_k}$
Se la serie parte da un numero $p$ è uguale ma se $b_k\to\pm\infty = b-b_p$
Esempi di serie telescopiche:
- $\sum_{n=1}^{\infty}{\ln(1+\frac{1}{n})}$
	$\lim_{n\to+\infty}{\ln(1+\frac{1}{n})}=0$
	$\ln(1+\frac{1}{n})=\ln(\frac{n+1}{n})=\ln(n+1)-\ln(n)\to b_n=\ln(n)$
	$\sum_{n=1}^{\infty}{\ln(1+\frac{1}{n})}=b_{k+1}-b_1=\ln(k+1)-\ln(1)=\ln(k+1)=+\infty$
- $\sum_{n=1}^{\infty}{\frac{1}{n(n+1)}}$
	$\frac{1}{n(n+1)}=\frac{1}{n}-\frac{1}{n+1}\to b_n=-\frac{1}{n};\ b_1=-1$
	$\sum_{n=1}^{\infty}{\frac{1}{n(n+1)}}=\lim_{k\to+\infty}{-\frac{1}{n+1}+1}=1$

## Serie a termini positivi
$a_n\geq 0$
Prop.: le serie a termini positivi non possono essere indeterminate
	Utile perché sappiamo che se una successione non tende a 0 allora la sua serie diverge
	Riduce le possibilità da 3 a 2

### Teoremi
- Siano $a_n,b_n$ successioni $\geq0$ t.c. $a_n\leq b_n$ (anche $\forall n\geq\bar n$)
	$\sum_{n=0}^{\infty}{b_n}$ converge => $\sum_{n=0}^{\infty}{a_n}$ converge
		Es.
		$\sum_{n=0}^{\infty}{\frac{1}{n^2}}=?$
		Usiamo il fatto che $\frac{1}{n^2}\leq \frac{2}{n(n+1)}$ e quella converge
		Converge
	$\sum_{n=0}^{\infty}{a_n}$ diverge => $\sum_{n=0}^{\infty}{b_n}$ diverge
		Es.
		$\sum_{n=0}^{\infty}{\frac{1}{n}}=?$
		Usiamo il fatto che $\sum_{n=1}^{\infty}{\ln(1+\frac{1}{n})}$ diverge ed è più piccola (dimostra con studio di funzione)
		Diverge
- Confronto asintotico
	Siano $a_n\geq 0,\ \ b_n>0$
	- Se $\lim_{n\to+\infty}{\frac{a_n}{b_n}=l\in(0,+\infty)}$ allora $\sum_{n=0}^{\infty}{a_n}$ converge s.se $\sum_{n=0}^{\infty}{b_n}$ converge
	- Se $\lim_{n\to+\infty}{\frac{a_n}{b_n}=+\infty}$ allora se $\sum_{n=0}^{\infty}{b_n}=+\infty$ allora $\sum_{n=0}^{\infty}{a_n}=+\infty$ (?)
- Criterio della radice
	Sia $a_n\geq 0$ t.c. $\exists\lim_{n\to+\infty}{\sqrt[n]{a_n}}=l$
	- $l<1$  $\sum_{n=0}^{\infty}{a_n}$ converge
	- $l>1$  $\sum_{n=0}^{\infty}{a_n}$ diverge
	- $l=1\ \ \ \sum_{n=0}^{\infty}{a_n}$ ?
- Criterio del rapporto
	Sia $a_n\geq 0$ t.c. $\exists\lim_{n\to+\infty}\frac{a_{n+1}}{a_n}= l$
	- $l<1\ \ \ \sum_{n=0}^{\infty}{a_n}$ converge
	- $l>1\ \ \ \sum_{n=0}^{\infty}{a_n}$ diverge
	- $l=1\ \ \ \sum_{n=0}^{\infty}{a_n}$ ?

### Serie armoniche generalizzate
$\sum_{n=0}^{\infty}{\frac{1}{n^\alpha}}\ \ \forall \alpha >0$
- $\alpha\leq1$ 
	Diverge
- $\alpha \geq 2$ 
	Converge
- $1 <\alpha<2$ 
	Converge (dimostrato con integrali)

## Serie a segno qualsiasi
Abbiamo di nuovo 3 casi:
$$
\sum_{n=0}^{\infty}{a_n}=\begin{cases} \text{Converge}\\\text{Diverge}\\\text{Indeterminata}\end{cases}
$$

### Convergenza assoluta
Definizione:
	Una serie $\sum_{n=0}^{\infty}{a_n}$ converge *assolutamente* s.se $\sum_{n=0}^{\infty}{|a_n|}$ converge
Proposizione:
	Se $a_n$ converge assolutamente allora $a_n$ converge
Questa proprietà è utile dato applicando il modulo ad una successione otteniamo una serie a termini positivi, e possiamo quindi utilizzare i criteri delle serie a termini positivi

### Teoremi
- Criterio di Leibnitz
	Sia $\sum_{n=0}^{\infty}{(-1)^na_n}$ una serie con queste proprietà:
		1. $a_n\geq 0$
		2. $a_n$ monotona decrescente
		3. $\lim_{n\to+\infty}{a_n}=0$
	$\sum_{n=0}^{\infty}{(-1)^na_n}$ converge

# Serie di potenze
Data $a_n$ successione e $x_0\in\mathbb{R}$ fissati, una *serie di potenze* è:
$$\sum_{n=0}^{\infty}{a_n(x-x_0)^n}$$
Posso chiedermi: per quali $x$ converge?