# Approssimazione di un polinomio
Data una funzione $f(x)$, un punto $x_0$ e un naturale $n\geq 0$, quel è il *miglior polinomio* di grado $\leq n$ che approssima $f(x)$ in un intorno di $x_0$?
$$P_n(x)= \sum_{k=0}^{h}a_kx^k=...$$
Il "migliore" è: ...

## "o piccoli"
Una funzione $f(x)$ si dice *infinitesimo* di ordine superiore a $n$ in un punto $x_0$ se:
$$\lim_{x\to x_0}{\frac{Q(x)}{(x-x_0)^n}}=0$$
$Q(x)=0\cdot((x-x_0)^n)$ => "o piccolo di $(x-x_0)^n$"
	Es.
	$x^2$ è $o(x)$, ma non è $o(x^2)$
		$x_0=0,\ \ \lim_{x\to 0}{\frac{x^2}{x}}=\lim_{x\to 0}{x}=0$ (questo limite con $x^2$ sotto = 1$\not=0$)
In generale: $x^m=o(x^n)\ \forall n<m$
#### Alcune proprietà:
- $o(x^m)\pm o(x^n)=o(x^{min(m,n)})$
- $o(kx^n)=o(x^n)$ (costanti non cambiano)
- $x^m\cdot o(x^n)=o(x^{m+n})$ (le potenze "entrano" in $o()$)
- $o(x^m)\cdot o(x^n)=o(x^{m+n})$
- $Q(x)=o(x^m) => Q(x)=o(x^n)\ \forall n<m$
$f(x)= x^2+3x+o(x^3) <=> f(x)-x^2-3x=o(x^3) <=> \lim_{x\to0}{\frac{f(x)-x^2-3x}{x^3}}=0$
$\lim_{x\to x_0}{\frac{f(x)-P_n(x)}{(x-x_0)^n}}=0$ è equivalente a dire ...
Un polinomio $P_n(x)$ di grado $\leq n$ è il "miglior polinomio" approssimante $f(x)$ vicino a $x_0$ se $f(x)=P_n(x)+o((x-x_0)^n)<=>\lim_{x\to x_0}{\frac{f(x)-P_n(x)}{(x-x_0)^n}}=0$
Sappiamo cos'è ma ci rimangono 2 domande:
- Esiste?
	$n=0$    $f(x)=P_0(x)+o((x-x_0)^0)=a_0+o(1)$ (perché un polinomio di grado 0 è costante)
	Esiste $a_0\in\mathbb{R}:\ \ f(x)=a_0+o(1)$?
	Esiste $a_0\in\mathbb{R}:\ \ \lim_{x\to x_0}{f(x)-a_0}=0$? $<=>\lim_{x\to x_0}{f(x)}=a_0$
		Se $f$ è continua in $x_0=>\exists\ \ \lim_{x\to x_0}{f(x)}=f(x_0)\to P_0(x)=f(x_0)$
		Se $n=0$ e $f$ è continua in $x_0$ allora $P_0(x)=f(x_0)$ ed è tale che: $f(x)=f(x_0)+o(1)$
sono molto perso non so di cosa stiamo parlando
- Com'è fatto?
	abbiamo dimostrato che se c'è un polinomio è del tipo $P_1(x)=f(x_0)+a_1(x-x_0)$ ?????
	boh $a_1=f'(x_0)$ se $f'(x_0)\exists$
	se $f$ è derivabile in $x_0$ allora il miglior polinomio di grado $\leq 1$ è $P_1(x)=f(x_0)+f'(x_0)(x-x_0)$ = retta tangente nel punto
	$a_2=\frac{f''(x0)}{2}$ se esiste $f''$
		Il miglior polinomio di grado $\leq 2$ è $P_2(x)=f(x_0)+f'(x_0)(x-x_0)+\frac{f''(x_0)}{2}(x-x_0)^2$
Riassumendo:

# Formula di Taylor
Sia $f$ derivabile (quindi continua) $n$ volte in $x_0$ e sia:
$$T_n(x;x_0)=\sum_{k=0}^{n}\frac{f^{(k)}(x_0)}{k!}(x-x_0)^k$$
Allora:
$$f(x)=T_n(x;x_0)+o((x-x_0)^n)$$
($T_n$ è il miglior polinomio di grado $\leq n$)
$T_n$ è *il polinomio di Taylor di $f(x)$, centrato in $x_0$, di ordine $n$.*
Espansione:
$$T_n(x;x_0)=f(x_0)+f'(x_0)(x-x_0)+\frac{f''(x_0)}{2}(x-x_0)^2+...+\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n$$
![[Pasted image 20251128120135.png]]
![[Pasted image 20251128122228.png]]
	Con $x_0=0$, $T_m(x;0)$ di un polinomio è tutti i termini del polinomio fino al termine $m$-esimo, o tutti i termini se $m\geq n$
Trick per espandere un polinomio di Taylor senza calcolare derivate:
![[Pasted image 20251128123006.png]]![[Pasted image 20251128123037.png]]= espansione (trust me)

## Taylor di non polinomi
$f(x)=e^x\ \ x_0=0$
$f(x)=e^0=1$ (poi anche tutte le derivate = 1)
$T_n(x;0)=\sum_{k=0}^{n}\frac{f^{(k)}(0)}{x!}(x)^n$
$$T_n(e^x;0)=\sum_{k=0}^{n}\frac{x^k}{k!}=1+x+\frac{x^2}{2}+\frac{x^3}{6}+...+\frac{x^k}{k!}$$
![[Pasted image 20251128123659.png]]
![[Pasted image 20251128124305.png]]
(È anche il polinomio di Taylor di $2n+2$ perché la derivata in $2n+2=0$)
![[Pasted image 20251128124424.png]]
(È anche il polinomio di Taylor di $2n+1$ perché la derivata in $2n+1=0$)
Somiglianza tra Taylor dell'esponenziale e delle goniometriche:
![[Pasted image 20251128125034.png]]
![[Pasted image 20251128125755.png]]
![[IMG_20251202_094802.jpg]]

## Taylor di funzioni di $\alpha x$
$f(x)=e^{2x}$
$f(0)=1$
$f'(x)=2e^{2x}\to f'(0)=2$
$f''(x)=4e^{2x}\to f''(0)=2^2$
$f'''(x)=8e^{2x}\to f'''(0)=2^3$
$f^{(n)}(0)=2^n$
$T_n(f(e^x);x_0)=2^0+2^1\cdot x+\frac{2^2}{2}x^2+\frac{2^3}{6}x^3+...+\frac{2^nx^n}{n!}=\frac{(2x)^n}{n!}$
Quindi:
$$
T_n(f(e^x);x_0)=\sum_{k=0}^{n}\frac{x^k}{k!}
$$
$$
T_n(f(e^{2x});x_0)=\sum_{k=0}^{n}\frac{(2x)^k}{k!}
$$
Il 2 rimane nella formula del polinomio di Taylor
Questa è una proprietà generale:
Dato un $g(x)=f(Ax)$:
	$g(x)=f(Ax)\ \ g(0)=f(0), g'(x)=Af'(Ax)...$
	$g^{(n)}(0)=A^nf^{(n)}(0)$
	Quindi:
$$T_n(g(x);0)=\sum_{k=0}^n \frac{A^kf^{(n)}(0)}{k!}x^k=\sum_{k=0}^n \frac{f^{(n)}(0)}{k!}(Ax)^k$$
Formula generale:
$$T_n(f(Ax);0)=T_n(f(x);0)[Ax]$$

## Taylor di funzioni di $x^\alpha$
$f(x)=e^{x^2}$
$e^t=1+t+\frac{t^2}{2}+...+\frac{t^n}{n!}+o(t^n)$
$e^{x^2}=1+x^2+\frac{x^4}{2}+...+\frac{x^{2n}}{n!}o(x^{2n})=P_{2n}(x)$
In generale:
$$T_{2n}(e^{x^2};0)=\sum_{k=0}^n\frac{x^{2k}}{k!}$$
Questo vale per tutte le funzioni, non solo l'esponenziale
Se $f(x)=T_n(x;0)+o(x^n)=>f(Ax^k)=T_n(f(Ax^k);x_0)+o(x^{nk})$
Es.: $T_4(x^2\sin{(3x^3)};0)$
	$\sin(t)=t-\frac{t^3}{6}+o(t^3)$
	$\sin(3x^3)=3x^3-\frac{9}{2}x^9+o(x^9)$
	$x^2\sin(3x^3)=x^2[3x^3-\frac{9}{2}x^9+o(x^9)]=3x^5-\frac{9}{2}x^11+o(x^11)$
	I termini $\leq$ 4 non ci sono quindi $T_4=0$

$\frac{1}{1-x}=\sum_{k=0}^nx^k+o(x^n)=>\frac{1}{1+x}$ boh
$\frac{1}{1+x}=\sum_{k=0}^n(-1)^kx^k+o(x^n)=1-x+x^2+...+(-1^nx^n)+o(x^n)$
$\frac{1}{1+x^2}=\sum_{k=0}^n(-1)^kx^{2k}+o(x^{2n})=1-x^2+x^4+...+(-1)^nx^{2n}+9(x^{2n})$

### Derivata in 0 da Taylor
Se $f(x)=1+3x^2+5x^3-6x^5+o(x^6)$
Cos'è $f^{(4)}(0)$ e $f^{(5)}(0)$?
$T_6(f(x);0)=1+3x^2+5x^3-6x^5$ perché $o(x^6)$
$=f(0)+f'(0)x+\frac{f''(0)}{2}x^2+...+\frac{f^{(6)}(0)}{720}x^6$
	Se sono uguali hanno tutti i coefficienti uguali quindi per trovare la $n$-esima derivata in 0 sostituisci il coefficiente al termine $n$-esimo nel polinomio di Taylor
		$f^{(4)}=0$ perché non c'è il termine di quarto grado
		$f^{(5)}=-\frac{6}{720}$: coefficiente di quinto grado sostituito alla derivata del coefficiente del quinto grado nel polinomio di Taylor
Guarda altre funzioni su dispense

## Taylor di $f(x)g(x)$
$=T_n(f(x)g(x);0)=T_n(f(x);0)\cdot T_n(g(x);0)$

# Teorema del resto in forma di Lagrange (?)
Data una $f(x)=\sum_{k=0}^n\frac{f^{(k)}(x_0)}{k!}(x-x_0)^k$ non ho finito di scrivere
$\exists c$ compreso tra $x_0$ e $x$:
	$f(x)=\sum_{k=0}^n\frac{f^{(k)}(x_0)}{k!}(x-x_0)^k+\frac{f^{(n+1)}(c)}{(n+1)!}(x-x_0)^{n+1}$
	Esiste un c tale che la funzione è uguale a quello
mi sono perso

