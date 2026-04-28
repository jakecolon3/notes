# Funzioni
Le soluzioni di un problema del tipo “come posso assegnare 8 oggetti distinti a 4 persone?” sono *funzioni* con **dominio** = insieme degli 8 oggetti e **codominio** insieme delle 4 persone
Una funzione assegna ad ogni elemento del dominio *1 solo* oggetto del codominio
	$f:A\to B$
	Associazione t. c. ogni elemento $a\in A$ è associato 1 solo elemento $b\in B$ e che chiamiamo $f(a)$
		$f(a)$ è detta *l’immagine* di $a$ sotto la funzione $f$, o il *valore* di $f$ sull’argomento $a$

## Definizione
Una funzione $f:A\to B$ è un insieme di coppie ordinate $(a,b)$ con $a\in A, b\in B$tale che per ogni $a\in A$ esiste un unico $b\in B$ tale che $(a,b)\in f$
	`funzione = {(a, f(a)) for a in A}`
La funzione è valida anche se non contiene tutti gli elementi del *codominio*, **non è valida** se non contiene tutti gli elementi del *dominio* o se contiene lo stesso elemento del dominio più volte

### Funzioni iniettive
$f:A\to B$ è iniettiva se non esistono $a,a’\in A, a≠a’$ tali che $f(a)=f(a’)$
	Una funzione *iniettiva* è una funzione che assegna **1 solo** elemento del dominio ad ogni elemento del codominio
### Funzioni suriettive
$f:A\to B$ è suriettiva se ogni elemento del codominio $B$ è assunto come valore da *almeno 1* elemento del dominio $A$
	$\forall b\in B\ \exists\ a\in A:f(a)=b
### Funzioni biiettive/biunivoche
Funzioni sia suriettive che iniettive
### .
Come associo un elemento del dominio ad un elemento del codominio?
$f(n)=2n$
$f:\mathbb{N}\to \mathbb{N}$
$\{(0,0),(1,2),…(n,2n)\}$
	`f = {(n, 2n) for n in naturals}`
### Insieme immagine
$f:A\to B$
$X\subseteq A$
$f(X)$ è detta **l’immagine** di $X$ sotto $f$ = $\{b\in B\ |\ \exists\ a\in X:f(a)=b\}$
	`f(X) = {b := f(x) for x in X}` con `X in A`
$f(X)\subseteq B$  **sempre**
Se vale $f(A)=B,\ f$ è suriettiva e viceversa
L’insieme immagine inverso (preimmagine) $f^{-1}(b)=\{a\in A: f(a)=b\}$ è l’insieme di tutti gli elementi del dominio che assumono valore $b$
	L’insieme delle funzioni di tipo $f^{-1}(b)$ è una partizione di A
### Funzioni e insiemistica
Come interagiscono funzioni, insiemi immagine e immagini inverse con gli operatori insiemistici?
$f:A\to B,\ X,Y\subseteq A$
Posso fare $f(X\cup Y)$ oppure $f(X)\cup f(Y)$, ma sono la stessa cosa?
	$f(X\cup Y) = f(X)\cup f(Y)$ se: 
	$f(X\cup Y) \subseteq f(X)\cup f(Y)$ e $f(X)\cup f(Y) \subseteq f(X\cup Y)$
	Per $f:\{1,2,3,4\}\to \{a,b,c\}, X=\{2,3,4\},Y=\{1,3,4\}$ si
	Anche in generale (guarda dimostrazione)
		Dire “esiste x tale che (x soddisfa A o B)” è equivalente a dire “esiste x tale che (x soddisfa A) o esiste x tale che (x soddisfa B)”
E invece $f(X\cap Y) = f(X) \cap f(Y)$?
	Per $f:\{1,2,3,4\}\to \{a,b,c\}, X=\{1,2,3\},Y=\{3,4\}$ si
	Ma non sempre: se i due sottoinsiemi non hanno elementi in comune ma le loro immagini ne hanno allora $f(X)\cap f(Y) \subseteq f(X\cap Y)$ è falso
		Succede solo con funzioni non iniettive
	Però $f(X\cap Y)\subseteq f(X) \cap f(Y)$ è vero
		”Esiste un x tale che (x soddisfa A e B)” sottointende “esiste un x tale che (x soddisfa A) ed esiste un x tale che (x soddisfa B)” ma non il contrario
	Questo vale per una $f$ iniettiva?
		Si?
		Per ogni $f:X\to Y$ *iniettiva*, **per ogni** $A,B\subseteq X’$: $f(A)\cap f(B)\subseteq f(A\cap B)$
		L’inverso è vero?
		Per ogni $f:X\to Y$ *non iniettiva*, **per ogni** $A,B\subseteq X$: $f(A)\cap f(B)\not\subseteq f(A\cap B)$ (forma forte)
			Falso
		Per ogni $f:X\to Y$ *non iniettiva*, **esistono** $A,B\subseteq X$: $f(A)\cap f(B)\not\subseteq f(A\cap B)$ (forma debole)
			Vero per definizione di non iniettività
				Esistono $x,x’\in X, x≠x’:f(x)=f(x’)$ -> $A=\{x\},B=\{x’\},f(A)=f(B)=y,A\cap B=\emptyset$
	E per $f^{-1}$?
$f\cup g$ e $f\cap g$ son sicuramente insiemi ma non necessariamente funzioni
	Unione:
		Se sono dello stesso tipo (stesso dominio e codominio) $f\cup g$ è una funzione?
			No se esiste $x\in X: f(x)≠g(x)$ perché $f\cup g$ avrebbe almeno un punto del dominio con 2 valori nel codominio
		Se non sono dello stesso tipo: $f:X\to Y,g:W\to Z$ quindi $X\cap W=\emptyset$
			Si
	Intersezione:
		È possibile che $f\cap g$ non sia una funzione su tutto $X$

Data una funzione $f:A\to B$:
	- Se $f$ è in. allora $\#A≤\#B$
		Quindi se $\#A>\#B$ non ci sono funzioni iniettive da A a B, quindi ogni $f:A\to B$ non sarà iniettiva
			“Principio dei cassetti”
	- Se $f$ è sur. allora $\#A≥\#B$
	- Se $f$ è bi. allora $\#A=\#B$
## Composizione di funzioni
$x\to f(x)$
Se abbiamo una funzione $f$ che ha come insieme immagine elementi che sono validi come input di una funzione $g$ è possibile fare $g(f(x))$
Questo è possibile se il codominio di $f$ è uguale al dominio di $g$
### Definizione
Siano $f:X \to Y, g:Y\to Z$: chiamiamo **funzione composta** di $f$ e $g$ denotata $(g \circ f)$ la funzione $X\to Z$ che associa a $x\in X$ il valore $g(f(x))$
$(g\circ f)$ è un insieme di coppie $(x\in X, z\in Z), z=g(f(x))$ 
$(x,z)\in (g\circ f)$ s.se esiste $y\in Y:(x,y)\in f$ e $(y,z)\in g$
	Dimostriamo $(g\circ f):X\to Z$:
	Per ogni $x\in X$ esiste un unico $z\in Z$ blah
	Dimostriamo che esiste solo 1 z:
		Prendiamo $(x,z),(x,\bar z)\in (g\circ f)$
		$(x,\bar z)\in (g\circ f$ se esiste $\bar y\in Y:(x,\bar y)\in f$ e $(\bar y, \bar z)\in g$
		Dato che f è una funzione $(x,\bar y)=(x,y)$ quindi $(y,\bar z) = (\bar y, \bar z)$ ma dato che anche g è una funzione allora $(y, \bar z)=(y,z)$ quindi $z=\bar z$
### Proprietà
La composizione **non è** commutativa
	Non sempre $(g\circ f)=(f\circ g)$
La composizione **è** associativa
	$h\circ(g\circ g) = (h\circ g)\circ f$
La composizione preserva iniettività/suriettività?
	- Se $f:X\to Y, g:Y\to Z,\ f,g$ iniettive, allora $(g\circ f)$ è iniettiva?
		Lo è se esistono $x≠ x’, (g\circ f)(x)≠(g\circ f)(x’)$
		Proviamo a dimostrare il contrario
			Supponiamo che esistono $x≠x’, (g\circ f)(x)=(g\circ f)(x’)$
			$g(f(x))=g(f(x’))$
			Dato che $g$ è iniettiva per ipotesi allora $f(x)=f(x’)$
			Dato che $f$ è iniettiva per ipotesi allora $x=x’$
			Contraddice l’ipotesi **quindi $(g\circ f)$ è iniettiva** C.V.D.
	- Se $f, g$ suriettive, allora $(g\circ f)$ è suriettiva?
		Per assurdo: se esiste $z\in Z:$ per ogni $x\in X, (g\circ f)(x)≠z$
			dato un $z$ esiste un $y\in Y: g(y)=z$ per suriettività di $g$
			per suriettività di $f$ dato un $y$ esiste un $x\in X: f(x)=y$
			Dato che $f$ e $g$ sono funzioni $g(f(x)) = z$
			Contraddice l’ipotesi **quindi** $(g\circ f)$ **è suriettiva** C.V.D
# Definizione di iniettività e suriettività con le funzioni composte
## Iniettività
### Prima oss.
Per ogni $f:X\to  Y$ iniettiva, $\exists g:Y\to X$ tale che $(g\circ f):X\to X$ è l’**identità** su X : $x\in X\to (g\circ f)(x)=x$, cioè la funzione che associa ogni x a se stesso
	$g:Y\to X$
	$y\in f(X), g(y)=$ l’unico (perché $f$ è iniettiva per ipotesi) $x\in X: f(x)=y$
	$y\not\in f(X), g(y)=$ irrilevante
### Seconda oss.
Data una $f:X\to Y: \exists g:Y\to X: (g\circ f):X\to Y$ allora **$f$ è iniettiva**
	Tesi: $\forall x_1,x_2:x_1≠x_2,\ x_1,x_2\in X=>f(x_1)≠f(x_2)$ (f è iniettiva)
	Dimostriamo per assurdo
		Dati 2 valori diversi, per ipotesi $g(f(x_1))=x_1,\ g(f(x_2))=x_2$
		Supponiamo che esistano 2 valori tali che $f(x_1)=f(x_2)$ (f non iniettiva)
		$g(f(x_1))=g(f(x_2))$ dato che $g$ è una funzione questo è possibile solo se $x_1=x_2$, che contraddice l’ipotesi
Quindi:
	$f:X\to Y$ è iniettiva s.se $\exists g:Y\to X$ tale che $(g\circ f):X\to X=id_x$ (funzione identità)
## Suriettività
### Prima oss.
Data una $f:X\to Y$ suriettiva esiste $g:Y\to X$ tale che $(f\circ g):Y\to Y$ è identità su $y$
	???
### Seconda oss.
Sia $f:X\to Y$, se esiste $g:Y\to X$ tale che $(f\circ g)=id_y$ allora **$f$ è suriettiva**
Tesi: $\forall y\in Y,\ \exists x\in X$ tale che $f(x)=y$
Dimostrazione: per ipotesi per ogni elemento nel codominio di $f$, $f(g(y))=y$, e per ipotesi il codominio di $g$ è il dominio di $f$ quindi ??????????
## Biiettività
data una $f$ biiettiva, se $(f\circ g)=id_y$ allora $(g\circ f)=id_x$
Possiamo dimostrare che se $g(f(x))≠id_x$ allora $f(g(x))≠id_y$, quindi è vero

