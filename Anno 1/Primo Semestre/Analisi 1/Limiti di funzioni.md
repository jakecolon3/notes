Ci servono per definire le [[Funzioni continue]]
### Limite ad infinito
Sia $d:\mathbb{R}\to \mathbb{R}$; è *infinitesima* per $x\to +\infty$ se $\forall \varepsilon >0\ \exists M$ tale che $|d(x)|<\varepsilon\ \ \forall x>M$
	$d$ tende a 0 per x che tende a + infinito se comunque io scelgo epsilon esiste un numero $M$ tale che dopo $M$ $d(x)$ è sempre compreso tra +epsilon e -epsilon
$f:\mathbb{R}\to \mathbb{R}$ ha limite $l$ per $x\to +\infty$ se $f(x)-l$ è infinitesima
	$\forall \varepsilon >0, \exists M: |f(x) -l|<\varepsilon \ \ \forall x>M$
		Come prima ma ora è $f(x)-l$ invece che $d(x)$
	Es.
	$\lim_{x\to\infty}{\frac{x^2}{1+x^2}}=1=l$
	$\forall \varepsilon\ \ |\frac{x^2}{1+x^2}-1|<\varepsilon$
	$|\frac{x^2-1-x^2}{1+x^2}|=$ rivedi

### Limite in un punto
$f:(a,b)\to\mathbb{R},x\in[a,b]$
$f$ è infinitesima per $x\to x_0$ se $\forall\varepsilon>0\ \ \exists \delta>0:\ 0< |x-x_0|<\delta,\ x\in(a,b)$
$|f(x)|<\varepsilon$
$f:(a,b)\to\mathbb{R}, x_0\in[a,b]$
$\lim_{x\to x_0}{f(x)}=l\in\mathbb{R}$ se $f(x)-l$ è infinitesima per $x\to x_0$
	$\forall \varepsilon>0\ \exists\delta>0:\ 0< |x-x_0|<\delta,|f(x)-l|<\varepsilon$
	Es.
	$\lim_{x\to 1}{3x-5}=-2$	$|f(x)-l| =|3x-5+2| =|3x-3| =3|x-1|=\varepsilon$
	$|x-1|<\delta => |f(x)-l| =3|x-1|<\varepsilon<3\delta=3\cdot \frac{\varepsilon}{3}=\varepsilon$
	$\delta=\frac{\varepsilon}{3}$
	Es.2
	$\lim_{x\to x_0}{\sin(x)=\sin(x_0)}$
	Formula di prostaferesi:
	$\sin x-\sin x_0=2\sin (\frac{x-x_0}{2})\cos(\frac{x-x_0}{2})$
	$|\sin x-\sin x_0|\leq$(perché cos<=1)$2\cdot|\sin(\frac{x-x_0}{2})\leq 2\cdot |\frac{x-x_0}{2}=|x-x_0|<\varepsilon,\ \varepsilon>0,\delta =\varepsilon$ rivedi

### Operazioni con i limiti
 $\lim_{x\to x_0}{f(x)}=l,\lim_{x\to x_0}{g(x)}=m$
	$\lim{f(x)\pm g(x)}=l\pm m$
	$\lim{f(x)\cdot g(x)}=l\cdot m$
	$\lim{\frac{f(x)}{g(x)}}=\frac{l}{m}$

### Relazioni tra limiti
 $\exists \lim_{x\to x_0}{f(x)},\ \exists \lim_{x\to x_0}{g(x)}$
	Se $f(x)\leq g(x)$ allora $l\leq m$

### Teorema dei carabinieri
Se $f(x)\to l<g(x)<h(x)\to l$ allora $g(x)\to l$

## Limiti notevoli
 $\lim_{x\to 0}{\frac{\sin(x)}{x}}=1$
	 Dimostrato con teorema dei carabinieri
	 Valido anche per x<0 perché $\frac{\sin x}{x}$ è pari
 $\lim_{x\to 0}{\frac{\tan(x)}{x}}=1$
  $\lim_{x\to 0}{\frac{\sin(x)}{x}\cdot\frac{1}{\cos(x)}}=1$
	Perché $\cos(x)\to1$
 $\lim_{x\to x_0}{\cos(x)}=\cos(x_0)$
	$=\lim_{x\to 0}{\frac{1-\cos(x)}{x^2}}=\frac{1}{2}$
	$=\lim_{x\to 0}{\frac{1-\cos(x)}{x^2}}\frac{1+\cos(x)}{1+\cos(x)}$
	$=\lim_{x\to 0}{\frac{1-\cos(x)^2}{x^2}}\frac{1}{1+\cos(x)}=$
	$=\lim_{x\to 0}{\frac{\sin(x)}{x}}\frac{\sin(x)}{x}\frac{1}{1+\cos(x)}=\frac{1}{2}$
 $\lim_{x\to0}\frac{1-\cos(x)}{x}=0$
 $\lim_{x\to0}{\frac{e^x-1}{x}}=1$
 $\lim_{x\to0}{\frac{\ln(1+x)}{x}}=1$
 $\lim_{x\to\infty}{(1+\frac{A}{x})^{x}\to e^A}$
 $\lim_{t\to0}{1-\cos(t)}\approx\frac{t^2}{2}$
 $\lim_{x\to\infty}{x^{\frac{1}{x}}}=e^{\frac{\ln(x)}{x}}=1$
 $\lim_{x\to\infty}{P(x)^{\frac{1}{x}}}=1$
 
### Limite destro e sinistro
 $\lim_{x\to x_0^+}{f(x)}=l$ se $\forall\varepsilon>0\ \exists\delta >0:\ x_0<x<x_0+\delta$
	 Consideriamo la funzione solo a destra di $x_0$
 $\lim_{x\to x_0^-}{f(x)}=l$ se $\forall \varepsilon\ \exists\delta>0:\ x_0-\delta<x<x_0$
	 Consideriamo la funzione solo a sinistra di $x_0$

### Teorema ponte
 $f:(a,b)\to\mathbb{R},\ \lim_{x\to x_0}{f(x)}=l\in\mathbb{R}\cup {\pm\infty}<=>\ \forall$ successione $\{a_n\}\subset[a,b]/\{x_0\}$
  $\lim_{n\to \infty}{a_n}=x_0$ si ha $\lim_{n\to\infty}{f(a_n)}=l$
	  Se f tende a l, comunque prendo una $a_n$ che tende a $x_0$ $\lim_{x\to x_0}{f(a_n)}=l$
	  dim.
	  Sia $\varepsilon>0\ \ \ f(x)\to l$ per $x\to x_0,\ \exists\delta>0\ \ 0< |x-x_0|<\delta,\ |f(x)-l|< \varepsilon$
	  Prendiamo $a_n\to x_0$
	  $\exists \bar n: |a_n-x_0| <\varepsilon\ \ n>\bar n$ che soddisfa $0< |x-x_0|<\delta$
	  $|f(a_n)-l| <\varepsilon$
	  Altro verso:
	  $f(x)\not\to l$ per $x\to x_0$
	  $\exists\varepsilon>0\ \forall\delta >0\ \ \exists x: 0< |x-x_0| <\delta$
	  $|f(x)-l| >\varepsilon$
	  $\delta=\frac{1}{n}\ \ \exists |a_n-x_0|<\frac{1}{n}$
	  $|f(a_n)-l| >\varepsilon$
Questo teorema dimostra che molti limiti notevoli delle successioni sono validi anche per le funzioni

### Funzioni che non ammettono limite
 $f(a_n)\to l$
	$\{a_n\}\subset (a,b)/\{x_0\}$
	$\{b_n\}\subset (a,b)/\{x_0\}$
	$\lim_{n\to\infty}{f(a_n)}\not=\lim_{n\to\infty}{f(b_n)}$
Funzione segno:
$\text{sgn}(x)=$
	- $+1:x>0$
	- $0:x=0$
	- $-1:x<0$
$\lim_{x\to0}{\text{sgn}(x)}$
	$a_n=\frac{1}{n},b_n=\frac{-1}{n}$
		$\lim_{x\to0}{\text{sgn}(a_n)}=1$
		$\lim_{x\to0}{\text{sgn}(b_n)}=-1$
			Per mostrare che una funzione non ammette limite? (violerebbe teorema ponte?)

# [[Funzioni continue]]