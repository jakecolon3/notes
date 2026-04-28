Data $a_n$ successione e $x_0\in\mathbb{R}$ fissati, una *serie di potenze* è:
$$\sum_{n=0}^{\infty}{a_n(x-x_0)^n}$$
	Nota: $x_0$ è detto il *centro*
Posso chiedermi:
1. Per quali $x$ converge?
2. Per le $x$ in cui converge, cosa fa $S(x)=\sum_{n=0}^{\infty}{a_n(x-x_0)^n}$? (studio la funzione)

### Osservazioni
- Ogni serie di potenze converge nel centro
	Ogni termine oltre il primo si annulla
- Ponendo $y=x-x_0,$ si può scrivere $\sum_{n=0}^{\infty}{a_n(x-x_0)^n}$ come $\sum_{n=0}^{\infty}{a_ny^n}$, con centro $y_0=0$, e studiare per quali $y$ converge
	In questo modo si trovano le $x$ in cui converge la serie, traslate di $x_0$

# Trovare dove converge una serie di potenze
### Raggio di convergenza
Supponiamo $x_0=0$ (vedi oss. 2):

Se una serie converge in un punto $\bar{x}$, allora converge in tutti i punti in $(-\bar{x}, \bar{x})$
$\rho = \sup\{x\geq 0$ t.c. $\sum_{n=0}^{+\infty}a_nx^n$ converge $\}$ = *raggio di convergenza*
Calcolato $\rho$ so sicuramente che:
- La serie converge per $x\in(-\rho,\rho)$
- La serie non converge se $x>\rho$ o $x<-\rho$
- Non sappiamo cosa fa in $x=\pm\rho$

1. Data una serie $\sum_{n=0}^{\infty}{a_nx^n}$ t.c. $\lim_{n\to+\infty}{\sqrt[n]{|a_n|}}=l\in[0,+\infty]$:
- Se $l\in(0,+\infty)$ allora $\rho=\frac{1}{l}$
- Se $l=\infty$ allora $\rho=0$
- Se $l=0$ allora $\rho=+\infty$
2. Data una serie $\sum_{n=0}^{\infty}{a_nx^n}$ t.c. $\lim_{n\to+\infty}{|\frac{a_{n+1}}{a_n}|}=l$:
- Se $l\in(0,+\infty)$ allora $\rho=\frac{1}{l}$
- Se $l=\infty$ allora $\rho=0$
- Se $l=0$ allora $\rho=+\infty$
	Abbiamo quindi che se $\lim_{n\to+\infty}{|\frac{a_n}{a_{n+1}}|}=l$ allora $\rho=l$

Ora invece prendiamo $\sum_{n=0}^{+\infty}a_n(x-x_0)^n$ con $x_0\not=0$
Calcolato $\rho$ so sicuramente che:
- La serie converge in $(x_0-\rho,x_0+\rho)$
- La serie non converge se $x>x_0+\rho$ o $x<X_0-\rho$
- Non sappiamo cosa fa in $x=x_0\pm\rho$
$\rho$ si calcola come prima

## Continuità delle serie di potenze
Se una $S(x)$ converge agli estremi allora $S(x)$ è continua fino all'estremo in cui converge
E quindi *è derivabile* (infinite volte)
La derivata di una serie di potenze è serie delle derivate:
	$S'(x)=\sum_{n=1}^{+\infty}na_n(x-x_0)^{n-1}$
	$S''(x)=\sum_{n=2}^{+\infty}n(n-1)a_n(x-x_0)^{n-2}$
Proprietà:
$S^{(k)}(x_0)=k!a_k$
Quindi:
$a_k=\frac{S^{(k)}(x_0)}{k!}\to S(x)=\sum_{n=0}^\infty{\frac{S^{(k)}(x_0)}{n!}(x-x_0)^n}$
Che è il polinomio di Taylor
q