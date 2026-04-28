# Funzioni derivabili
Sia $f:\mathbb{R}\to\mathbb{R}$, sia $x_0\in\mathbb{R}. $f(x)$ si dice *derivabile* in $x_0$ se il rapporto incrementale esiste ed è finito in $x_0$:
	$\lim_{h\to 0}{\frac{f(x_0+h)-f(x_0)}{h}}=L\in\mathbb{R}$
	$f'(x)=L$
Che è la definizione di *derivata prima*
Quindi l'equazione della retta tangente al grafico in $(x_0,f(x_0))$ è:
	$y=f(x_0)+f'(x_0)(x-x_0)$
	Per questa retta: $\lim_{h\to 0}{\frac{f(x_0+h)-[f(x_0)+f'(x_0)-h]}{h}}=0$
		L'unica retta con questa proprietà

## Derivate di funzioni comuni
- $f(x)=c$
	La retta secante = $f(x)$, $\lim_{h\to 0}{\frac{f(x_0+h)-f(x_0)}{h}}=\frac{c-c}{h}=0=f'(x_0)$
	Le funzioni costanti sono derivabili ovunque e hanno sempre derivata = 0
- $f(x)=ax+b$
	${\frac{f(x_0+h)-f(x_0)}{h}}=\frac{a(x_0+h)+b-(ax_0+b)}{h}=\frac{ah}{h}=a\ \forall h$
	$\lim_{h\to 0}{\frac{f(x_0+h)-f(x_0)}{h}}=a=f'(x_0)$
	Le rette sono derivabili su $\mathbb{R}$ e $f'(x)=a\ \forall x\in \mathbb{R}$
- $f(x)=x^2$
	${\frac{f(x_0+h)-f(x_0)}{h}}=\frac{(x_0+h)^2-x_0^2}{h}=...=2x_0+h$
	$\lim_{h\to 0}{\frac{f(x_0+h)-f(x_0)}{h}}=2x_0=f'(x)$
	I polinomi di secondo grado sono derivabili su $\mathbb{R}$ e $f'(x)=2x$
- $f(x)=3x^2+6x+8$
	Applichiamo un [teorema]([[#Regole di derivazione]]):
		$=6x+6$
- $[x^\alpha]'=\alpha x^{\alpha-1}$
- $[x^{-\alpha}]'=(\frac{1}{x})'=...=-\alpha x^{-\alpha-1}\ \forall\alpha$
- $[e^x]'=e^x$
- $[\sin(x)]'=\cos(x)$
- $[\cos(x)]'=-\sin(x)$
- $[\log(|x|)]'=\frac{1}{x}, x\not=0$
	$e^{\log(x)}=x\ \forall x>0$
	$[e^{\log(x)}]'=(e')(\log(x))\cdot [\log(x)]'=e^{\log(x)}[log(x)]'=x[log(x)]'$
	$x[\log(x)]'=x => x[\log(x)]'=1 => [\log(|x|)]'=\frac{1}{x}$
- $(\tan(x))'=[\frac{\sin(x)}{cos(x)}]'=\frac{1}{cos^2(x)}$
- Inverse delle trig.:
	Calcolate con la regola di composizione
	$\tan(arctan(x))=x$
		$1=(\tan)'(\arctan(x))\cdot [\arctan(x)]'=\frac{1}{\cos^2(\arctan(x))}\cdot[\arctan(x)]'=>$
		$[\arctan(x)]'=\cos^2(arctan(x))=\frac{\cos^2}{\cos^2+\sin^2}=\frac{1}{1+\frac{\sin^2}{\cos^2}}=\frac{1}{1+[\tan(\arctan(x))]^2}=$
		$=\frac{1}{1+x^2}$
- $\arcsin(x)=\frac{1}{\sqrt{1-x^2}}\ \forall x\not=\pm1$
- $\arccos(x)=-\frac{1}{\sqrt{1-x^2}}\ \forall x\not=\pm1$

# Regole di derivazione
Siano $f,g$ derivabili in $x_0,\ k\in\mathbb{R}$
- $[kf(x_0)]'=k\cdot f'(x_0)$
	La derivata del prodotto tra una costante e una funzione è la derivata della funzione per la costante
- $[f(x_0)\pm g(x_0)]'=f'(x_0)\pm g'(x_0)$
	La derivata della somma di 2 funzioni è la somma delle derivate delle funzioni
- $[f(x)g(x)]'=f'(x)g(x)+f(x)g'(x)$
- $[\frac{f(x)}{g(x)}]'=\frac{f'(x)g(x)-f(x)g'(x)}{g(x)^2}$
- $[f(g(x))]'=f'(g(x))g'(x)$

# Massimi e minimi relativi
Con il teorema di Weierstrass abbiamo visto che ogni funzione continua in un intervallo ha un massimo e un minimo; ora possiamo trovarlo:
Sia $f[a,b]\to\mathbb{R}\ \ x_0\in[a,b]$
$x_0$ è di *massimo relativo* per $f(x)$ se:
	$\exists \delta:f(x)\leq f(x_0)\ \forall x\in(x_0-\delta,x_0+\delta)\cap[a,b]$
		Esiste un valore tale che $f(x)$ è minore o uguale di $f(x_0)$ per ogni $x$ attorno a $x_0$
	Quindi se la derivata vale 0
Analogo per minimo relativo

## Teorema di Fermat
Sia $f:[a,b]\to\mathbb{R},$ sia $x_0\in[a,b]$ di massimo o minimo relativo
Se $f$ è derivabile in $x_0$ allora $f'(x_0)=0$
Questo teorema non si inverte: se $f'(x_0)=0\ \ x_0$ non è necessariamente di massimo o minimo
	Es.: $f(x)=x^3$
		$f'(0)=0$ ma $f(x)>0$ se $x>0$ e $f(x)<0$ se $x<0$
		Questo è un *punto di flesso*

Come faccio a sapere se un punto in cui si annulla la derivata è un massimo, minimo o flesso?
## Teorema di Rolle
Data una $f:[a,b]\to \mathbb{R}$ continua in $[a,b]$, derivabile in $(a,b)$, $f(a)=f(b)$:
$$\exists c \in(a,b): f'(c)=0$$
	Data una funzione continua e derivabile in un intervallo, con lo stesso valore agli estremi dell'intervallo, esiste almeno un punto interno all'intervallo dove la derivata vale 0
Dim.:
	Dato che $f$ è continua, posso applicare il teorema di Weierstrass =>
	$\exists x_m,x_M\in[a,b]:f(x_m)\leq f(x)\leq f(x_M)\ \forall x\in [a,b]$
	4 casi:
		1. Massimo e minimo sono interni all'intervallo
			Per Fermat la derivata nel massimo e nel minimo si annulla
		2. Il minimo è ad un estremo dell'intervallo
			Per Fermat la derivata si annulla nel punto di *massimo*
		3. Il massimo è ad un estremo dell'intervallo
			Per Fermat la derivata si annulla nel punto di *minimo*
		4. Entrambi sono agli estremi dell'intervallo
			Dato che $f(a)=f(b)$ e la funzione ha il massimo e il minimo negli estremi, la funzione è costante -> $f'(x)=0\ \forall x$

## Teorema di Lagrange
Data una $f:[a,b]\to \mathbb{R}$ continua in $[a,b]$, derivabile in $(a,b)$:
$$\exists c \in (a,b):f'(c)=\frac{f(b)-f(a)}{b-a}$$
	La retta che passa per $a,b$ ha coeff. angolare $\frac{f(b)-f(a)}{b-a}$
	Il teorema afferma che esiste una retta parallela a questa retta tangente al grafico
Questo teorema e il teorema di Rolle sono equivalenti: se posso dimostrarne uno posso dimostrare l'altro:
	Dimostrazione di Rolle con Lagrange
		Se ruoto la funzione in modo che $f'(c)=0$ ho Rolle
			$g(x)=f(x)-\frac{f(b)-f(a)}{b-a}(x-a)$
			$g(a)=f(a);g(b)=f(a)$
			$\exists c \in(a,b):g'(c)=0;\ g'(x)=f'(x)-\frac{f(b)-f(a)}{b-a}$
			$f'(c)=\frac{f(b)-f(a)}{b-a}$
![[1764057655112.jpg]]

 Ricordiamo che data una $f:E\to \mathbb{R}$ con $E\not=\emptyset$
	- Si dice *monotona crescente* se $\forall x,y\in E, x\not=y: \frac{f(y)-f(x)}{y-x}\geq0$
	- Si dice *monotona decrescente* se $\forall x,y\in E, x\not=y: \frac{f(y)-f(x)}{y-x}\leq0$
### Segno della derivata e monotonia
Data una $f:[a,b]\to\mathbb{R}$ derivabile:
- Se $f$ è monotona crescente: $f'(x)\geq 0$
- Se $f$ è monotona decrescente: $f'(x)\leq 0$
Questo teorema vale anche al contrario
Dim.:
	Supponiamo $f'(z)\geq0\ \forall z\in[a,b]$
	Prendiamo $x<y$ in $[a,b]$
		$f:[x,y]\to\mathbb{R}$ è continua in $[x,y]$ e derivabile in $(x,y)$
		Soddisfa Lagrange: $\exists c\in (x,y)$
			$f'(c)=\frac{f(y)-f(x)}{y-x}\geq 0$ perché $f'$ è sempre $\geq0$

## Tipi di punti stazionari
Dato un punto stazionario $x_0$:
- Se $f'(x_0^-)<0$ e $f'(x_0^+)>0$ allora $x_0=x_m$
- Se $f'(x_0^-)>0$ e $f'(x_0^+)<0$ allora $x_0=x_M$
- Se $f'(x_0^-)=f'(x_0^+)$ allora $x_0$ è di flesso

## Distinguere massimi e minimi con derivata seconda
Sia $x_0:\ f'(x_0)=0$
	$f''(x_0):$
	- Positiva:
		$x_0$ è di minimo
	- Negativa:
		$x_0$ è di massimo

# Applicazione di Rolle/Lagrange (?)
Sia $f:[a,b]\to\mathbb{R}; x_0\in(a,b)$ continua in $x_0$ e derivabile $\forall x\not=x_0$
Se $\exists \lim_{x\to x_0}{f'(x)}=L\in\mathbb{R}$ allora $f$ è derivabile in $x_0$ e $f'(x_0)=L$
Dim.:
	$f:[x_0,b]\to\mathbb{R}$ continua su $[x_0,b]$ (perché è continua in $x_0$ e derivabile nel resto) e derivabile su $(x_0,b)$
	$0<h<b-x_0 => x>0+h\in[x_0,b]=>$ Lagrange
		$\exists x_0<c_h<x_0+h:\frac{f(x_0+h)-f(x_0)}{h}=f'(c_h)$ => $\lim_{h\to0^+}{\frac{f(x_0+h)-f(x_0)}{h}}=\lim_{x\to x_0}{f'(x)}=L$
		???

## Massimi e minimi assoluti
Data una funzione per cui vale Weierstrass:
	$x_m,x_M\in A\cup B \cup C$
	$A = \{a,b\}$
	$B=\{x\in(a,b):f'(x)=0\}$
	$C=\{x\in(a,b):\not\exists f'(x)\}$
		Il massimo di $f$ sarà il valore più grande tra i valori negli insiemi immagini di $f$ rispetto ad $A,B,C$
		Il minimo di $f$ sarà il valore più piccolo...
Praticamente controlla i punti in cui può esserci un massimo o un minimo (si annulla derivata, estremi, non si può derivare)

# Teorema di de l'Hopital
Si usa per risolvere forme indeterminate del tipo $\frac{\infty}{\infty}$ e $\frac{0}{0}$
$f,g:[a,b]\to\mathbb{R}$ continue e derivabili
$f(x_0)=g(x_0)=0$
$\lim_{x\to x_0}{\frac{f(x)}{g(x)}}=\frac{0}{0}$
Se $\exists \lim_{x\to x_0}{\frac{f'(x_0)}{g'(x_0)}}$ allora $\lim{}{\frac{f(x)}{g(x)}}=\lim{}{\frac{f'(x)}{g'(x)}}$
Analogo per $\frac{\infty}{\infty}$

