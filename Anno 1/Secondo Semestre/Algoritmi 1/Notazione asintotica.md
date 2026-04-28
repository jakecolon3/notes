La notazione asintotica permette di confrontare il tasso di crescita di una funziona rispetto ad un'altra
Ci sono 3 notazioni asintotiche:
- O (o grande)
	Limite asintotico superiore
	Più grande del tempo effettivo
- $\Omega$
	Limite asintotico superiore
	Più piccolo del tempo effettivo
- $\Theta$
	Limite asintotico stretto
	Il tempo esatto dell'algoritmo

# Notazione O
### Definizione
Date due funzioni $f(n), g(n)\geq 0$ si dice che $f(n)$ è in $O(g(n))$ se esistono due costanti $c$ ed $n_0$ tali che:
$$0\leq f(n)\leq cg(n)\ \forall n\geq n_0$$
Quindi una funzione $f(n)$ è in $O(g(n))$ se esiste una $c$ tale che per ogni $n$ maggiore di un certo $n_0$, $g(n)$ è sempre maggiore di $cf(n)$
Esistono infinite funzioni che dominano $f(n)$, ma ci interessa trovare la più piccola tra di esse

## O di funzioni base
- $f(n)=\log{n}$
	$f(n)=O(\sqrt{n})$
	In generale: $\log^a{n}=O(\sqrt[b]n)\ \forall a,b\geq 1$
		Gerarchia degli infiniti
- $f(n)=\sqrt[a]{n}$
	$f(n)=O(n)$
	In generale: $\sqrt[a]{n}=O(n^b)\ \forall a,b\geq 1$
- $f(n)=n^a$
	$f(n)=O(2^n)\ \forall a\geq 1$
	In generale: $n^a=O(b^n)\ \forall a\geq 1, b\geq 2$

# Notazione $\Omega$
Date due funzioni $f(n), g(n)\geq 0$ si dice che $f(n)=\Omega(g(n))$ se esistono due costanti $c$ e $n_0$ tali che $f(n) \geq cg(n)\ \forall n\geq n_0$
	Uguale all'o piccolo ma può anche essere uguale

# Notazione $\Theta$
Date due funzioni $f(n), g(n)\geq 0$ si dice che $f(n)=\Theta(g(n))$ se esistono tre costanti $c_1, c_2, n_0$ tali che:
$$c_1g(n)\leq f(n)\leq c_2g(n)\ \forall n\geq n_0$$
Quindi se è "schiacciata" da $g(n)$ con costanti diverse
	Es.
	$f(n)=\log_a n$
	$f(n)=\Theta(\log_b n)\ \ \forall a,b>0$
		Cambio di base: $\log_a n=log_b n\log_a n=c\log_b n$
	Es.
	$f(n)$ è un polinomio di grado $m$
	$f(n)=\sum^m_{i=0}a_in^i,\ a_m>0$
	Abbiamo visto che $f(n)$ è sia in $O(n^m)$ che in $\Omega(n^m)$

## Calcolo della notazione asintotica con i limiti
Se $\lim_{n\to\infty}{\frac{f(n)}{g(n)}}=k>0$ allora $f(n)=\Theta(g(n))$
	Se il limite del rapporto tra le funzioni è una costante le funzioni hanno lo stesso tasso di crescita
Se $\lim_{n\to\infty}{\frac{f(n)}{g(n)}}=+\infty$ allora $f(n)=\Omega(g(n))$ ma $f(n)\not=(\Theta(g(n)))$
Se $\lim_{n\to\infty}{\frac{f(n)}{g(n)}}=0$ allora $f(n)=O(g(n))$ ma $f(n)\not=(\Theta(g(n)))$

# Algebra della notazione asintotica
1. Regola sulle costanti moltiplicative
	$\forall k>0,\ \forall f(n)\geq0$, se $f(n)=O(g(n))$ allora $kf(n)=O(g(n))$
	Vale anche per omega e theta
2. Regola sulla commutatività con la somma
	Se $f(n)=O(g(n))$ e $d(n)=O(h(n))$ allora $f(n)+d(n)=O(g(n)+h(n))=O(\max(g(n),h(n)))$
		$\max=$ la funzione che cresce più velocemente
	Vale anche per omega e theta
3. Regola sulla commutatività con il prodotto
	Se $f(n)=O(g(n))$ e $d(n)=O(h(n))$ allora $f(n)d(n)=O(g(n)h(n))$
	Vale anche per omega e theta

### Sommatorie notevoli
- $\sum_{i=0}^n i=\frac{n(n+1)}{2}=\Theta(n^2)$
	$\sum_{i=0}^n i^c=\Theta(n^{c+1})\ \ \forall c\in\mathbb{Z}$
- $\sum_{i=0}^n 2^i=2^{n+1}-1=\Theta(2^n)$
	$\sum_{i=0}^n c^i=\frac{c^{n+1}-1}{c-1}\ \ \forall c\not=1$
	Se $c>1$ vale $\Theta(c^n)$; se $c<1$ vale $\Theta(1)$
- $\sum_{i=0}^n i2^i = \Theta(n2^n)$
	$\sum_{i=0}^n ic^i = \Theta(nc^n)\ \ \forall c>1$
- $\sum_{i=0}^n \log i=\Theta(n\log n)$
	$\sum_{i=0}^n \log^c i=\Theta(n\log^c n)\ \ \forall c>1$
- $\sum_{i=1}^n \frac{1}{i}=\Theta(\log n)$
	