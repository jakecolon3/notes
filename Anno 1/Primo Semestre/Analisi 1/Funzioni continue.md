Sia $I$ un intervallo:
	$f:I\to \mathbb{R}$
	$x_0\in I$
	$f$ è continua in $x_0$ se $\lim_{x\to x_0}{f(x)}=f(x_0)$
		$f$ è continua in un punto se esiste il limite in quel punto ed è uguale alla funzione in quel punto
Da questo abbiamo che:
- I polinomi sono funzioni continue
- Le funzioni razionali sono funzioni continue
	Tranne se $x_0$ è uno zero per il denominatore
- Il seno è una funzione continua
Se $f$ è continua in ogni $x_0\in I$ allora diciamo che $f$ è continua in $I$

## Punti di discontinuità
I punti in cui una funzione $f$ non è continua sono detti punti di discontinuità, ce ne sono di 3 specie: 
1. $\exists\lim_{x\to x_0^+}{f(x)}=l_+$
	$\exists\lim_{x\to x_0^-}{f(x)}=l_-$
	$l_+\not=l_-$
		Limite destro e limite sinistro non coincidono
2. Almeno uno dei due limiti laterali o non esiste o è $\pm\infty$
	$\lim_{x\to x_0^\pm}{f(x)}=\not\exists$
	$\lim_{x\to x_0^\pm}{f(x)}=\pm\infty$
3. $\lim_{x\to x_0^+}{f(x)}=\lim_{x\to x_0^-}{f(x)}=l$
	Con $f(x_0)=\not\exists$ o $f(x_0)\not=l$
	Detta eliminabile perché possiamo costruire una nuova funzione $\tilde f$ uguale ad $f$ ma con $\tilde f(x_0)=l$
		Detta estensione per continuità di $f$ in $x_0$

### Continuità del coseno
$\forall x\in\mathbb{R}$
$\lim_{x\to x_0}{\cos(x)}=\cos(x_0)$
$|\cos(x)-\cos(x_0)|=|2\sin(\frac{x-x_0}{2})\sin(\frac{x+x_+}{2})|$
$|\cos(x)-\cos(x_0)|\leq2- |\sin(\frac{x-x_0}{2})|$ perché $|\sin(y)|\leq1$?
$\leq2=|\frac{x-x_0}{2}=|x-x_0|$

## Teorema di esistenza degli zeri (rivedi)
Con:
	$f:[a,b]\to\mathbb{R}$ continua
	$f(a)f(b)<0$
		La funzione ha segni opposti negli estremi
$\exists\ c\in(a,b):f(c)=0$
Dim.:
	$f(a)<0, f(b)>0$
	$\{a_n\},\{b_n\}$
	$a_0=a, b_0=b$
	$c=\frac{a+b}{2}$ (media)
	3 casi:
	1. $f(c)>0$
		$a_1=a$
		$b_1=c$
			In questo modo creiamo un nuovo intervallo con gli stessi criteri del primo
			Ripetendo il procedimento ad un certo punto troviamo lo 0
	2. $f(c)<0$
		$a_1=c$
		$b_1=b$
	3. $f(c)=0$
		Hai trovato lo 0
?
$|a_n-b_n|\to0$
$a_n$ crescente e $\to d$
$b_n$ decrescente e $\to d$
Dim.: ??
	$f(b_n)>0\to f(d)<0$
	$f(a_n)\geq0\to f(d)\leq0$

## Teorema del valore intermedio
$f:[a,b]\to\mathbb{R}$ continua e con $[a,b]=$ intervallo
$\forall\ \eta\in[f(a),f(b)]\ \ \exists\ x_0\in[a,b]:f(x_0)=\eta$
	$f$ assume *tutti* i valori compresi tra $f(a)$ e $f(b)$
	$[f(a),f(b)], [f(b),f(a)]\subseteq f([a,b])=\{f(x),x\in[a,b]\}$
Dim.:
	$f(x)-\eta :=\ g(x), g:[a,b]\to\mathbb{R}$ continua
	$\eta\in[f(a),f(b)]$
	$g(a)=f(a)-\eta<0$
	$g(b)=f(b)-\eta>0$
	Ora possiamo applicare il teorema di esistenza degli zeri a $g$
		$\exists x_0\in(a,b):g(x_0)=0$
		$g(x_0)=f(x_0)-\eta$
			$f(x_0)=\eta$ C.V.D.

## Teorema di Weierstrass
$f:[a,b]\to\mathbb{R}$ continua
	Data una $f$ continua su un intervallo chiuso e limitato:
Esistono 2 punti $x_m,\ x_M:f(x_m)\leq f(x)\leq f(x_M),\forall x\in[a,b]$
	Esistono almeno 1 massimo ($x_M$) e 1 minimo ($x_m$)
		$x_M\in E$ si dice un punto di *massimo* se: $f(x)\leq f(x_M)\ \forall x\in E$
		$x_m\in E$ si dice un punto di *minimo* se: $f(x)\geq f(x_m)\ \forall x\in E$
Quindi le funzioni continue in un intervallo chiuso e limitato sono racchiuse in un rettangolo $a,b,x_M,x_m$

## Teorema del valore intermedio 2 (con Weierstrass)
$f[a,b]\to\mathbb{R}$ continua
Per Weierstrass $\exists m,M$
$f([a,b])=[m,M]$
	Possiamo descrivere l'immagine della funzione come un intervallo chiuso che va dal minimo della funzione al massimo
		$\forall t\in[m,M]\ \exists x_t\in[a,b]:f(x_t)=t$
	Quindi $f([a,b])$ assume tutti e soli i valori compresi tra $m$ e $M$
In pratica: l'immagine delle funzioni continue è sempre un intervallo
Cosa succede con intervalli non chiusi?
	- $(a,b)$
	- $(a,+\infty)$
	- $(-\infty,b)$
In alcuni casi posso comunque applicare i teoremi visti studiando la funzione agli estremi:

## Generalizzazione di Weierstrass e valori intermedi
$f:(a,b)\to\mathbb{R}$ continua
$\lim_{x\to a^+}{f(x)}=\pm\infty=l_a$
$\lim_{x\to b^-}{f(x)}=\pm\infty=l_b$
4 casi:
- $l_a=l_b=+\infty$
	Se la funzione tende a +infinito ad entrambi gli estremi esiste almeno un minimo:
	$\exists\min f(x)=m$
	$f((a,b))=[m,+\infty)$
- $l_a=l_b=-\infty$
	Se la funzione tende a -infinito ad entrambi gli estremi esiste almeno un massimo:
	$\exists\max f(x)=M$
	$f((a,b))=(-\infty,M]$
- $l_a=-l_b=\pm\infty$
	Se la funzione tende ad infiniti opposti negli estremi la sua immagine è $\mathbb{R}$
	$f((a,b))=\mathbb{R}$
Quindi anche se Weierstrass non è applicabile posso comunque ottenere delle informazioni
Con questo posso anche applicare il teorema dei valori intermedi

### Calcolare immagini
Data una funzione con dominio $\not=\mathbb{R}$, per calcolare la sua immagine bisogna analizzare il limite destro e sinistro di ogni punto di discontinuità
	$f(x)=\frac{x^3}{x^2-4}$
	Devo studiare $\lim_{x\to\pm 2^{\pm}}{f(x)}$
	Posso studiare il segno per velocizzare il processo

# Rapporto incrementale
$f:\mathbb{R}\to\mathbb{R},\ x_0\in\mathbb{R},\ h\not=0\ (h?0)$
Il rapporto incrementale di $f(x)$ tra $x_0$ e $x_0+h$:
	$\frac{f(x_o+h)-f(x_0)}{h=(x_0+h)-x_0}$
	La retta che passa per $x_0$ e $x_0+h$ è:
		Passa per $x_0$: $y=f(x)+m(x-x_0)$
		Impongo $f(x_0+h)...$
		$m=\frac{f(x_0+h)-f(x_0)}{h}$ = il rapporto incrementale
Quindi il rapporto incrementale è *il coefficiente angolare della retta secante al grafico passante per* $(x_0,f(x_0)),(x_0+h,f(x_0+h))$
Abbiamo quindi una funzione che ci definisce il coefficiente angolare della retta secante al grafico al variare di $h$
Retta tangente al grafico:
	$y=f(x_0)+f'(x_0)(x-x_0)$
Possiamo quindi chiederci cos'è $\lim_{h\to 0}{\frac{f(x_0+h)-f(x_0)}{h}}$
	Per sapere se esiste e se è finito dobbiamo vedere $f(x)$
[[Derivate]]

### Funzioni monotone
$f:E\to \mathbb{R}$ si dice crescente se:
	$x>y=>f(x)\geq f(y)$
Strettamente crescente se:
	$x>y=>f(x)> f(y)$
(equivalente per decrescenti)
Alternativamente:
	$f:E\to\mathbb{R}$ è crescente <=> $\forall x,y\in E\ \ x\not=y: \frac{f(x)-f(y)}{x-y}>(=) 0$
		Studiare il segno di quella funzione ci fa capire la crescenza/decrescenza di $f$
Data una funzione definita in parti non è detto che se entrambe le parti sono crescenti allora la funzione è crescente globalmente (salti)
	Se è continua allora è sempre vero

### Suriettività di una retta continua
Data una $f:\mathbb{R}\to\mathbb{R}$ continua, come dimostro che è suriettiva ($f(\mathbb{R})=\mathbb{R}$)?
Teorema del valore intermedio: $\forall \eta, +\infty>\eta, -\infty < \eta$
$f:\mathbb{R}\to\mathbb{R}$ continua: $\lim_{x\to+\infty}{f(x)}=\pm\infty=-\lim_{x\to-\infty}{f(x)}$
	$\forall t\in\mathbb{R}\ \exists x_t\in\mathbb{R}: f(x_t)=t$

### Serie geometrica finita
Fissato $q\in \mathbb{R}/\{0\}$
$\sum_{i=0}^{n}q^i=1+q+\dots+q^n=\frac{1-q^{m-1}}{1-q}$
	Dim.:
	$n=1$
	$\sum_{i}=1+q$
	
$a_n=\sum_{i=0}{n}

# Derivabilità delle funzioni