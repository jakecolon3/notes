$\mathbb{K}$ è un campo
$\mathbb{K}^n$ sono i vettori di $n$ interi (vettori $n$-dimensionali) che appartengono a $\mathbb{K}$
$\mathbb{K}^n=\{\underline{\overline{X}}=(x_1,...,x_n)|x_i\in\mathbb{K}\}$
	$\underline{0}=(0,...,0)$
### Somma
$\mathbb{K}^n\times\mathbb{K}^n\to\mathbb{K}^n$
$v+w=(x_1+y_1,...,x_n+y_n)$
### Prodotto per scalari
$\mathbb{K}\times\mathbb{K}^n\to\mathbb{K}^n$
= $\lambda x_1,...$

## Proprietà
Sono le proprietà dei campi
![[IMG_20260226_092744.jpg]]
1. $\underline{0} + X = X\ \ \ \forall X\in\mathbb{K}^n$
2. $\forall X\in\mathbb{K}^n\ \ \exists Y\in\mathbb{K}^n$ t.c. $X+Y=0$
3. ...
8. $(\lambda\mu) X = \lambda(\mu X)$

# Definizione
Un insieme $V$ con operazioni:
- Somma
	$V\times V\to V$
	$(v,w)\to v+w$
- Prodotto
	$\mathbb{K}\times V\to V$
	$(\lambda,v)\to \lambda v$
Tali che valgano le proprietà 1. -> 8. è uno *spazio vettoriale su $\mathbb{K}$*
	Gli elementi di $\mathbb{K}$ sono gli scalari ($\mathbb{K}$), gli elementi di $V$ sono vettori ($\mathbb{K}^n$)	

## Vettori nel piano
$\mathbb{E}^2$ = piano euclideo
$V(\mathbb{E}^2)=\{\text{vettori di }E^2\}=\{\text{segmenti orientati in }E^2\text{ ma se }P_1Q_1\text{ è equipollente a }P_2Q_2\text{ definisce lo stesso vettore in }E^2\}$ 
Un segmento orientato è una coppia $PQ$ con $P,Q\in\mathbb{E}^2$
I segmenti orientati $P_1Q_1$ e $P_2Q_2$ sono *equipollenti* se sono paralleli e hanno la stessa lunghezza praticamente
	La relazione di equipollenza è una relazione di equivalenza (sono lo stesso vettore (ma segmento orientato diverso))
- Somma vettoriale
	$V(\mathbb{E}^2)\times V(\mathbb{E}^2)\to V(\mathbb{E}^2)$
	$(\vec{PQ},\vec{RS})\to\vec{PT}$
		$\vec{PT}$ è un nuovo vettore che va da $P$ ad un nuovo punto $T$ (ottenuto traslando $\vec{RS}$ a $Q$)
- Prodotto scalare
	$\mathbb{R}\times V(\mathbb{E}^2)\to V(\mathbb{E}^2)$
	$(\lambda,PQ)\to\vec{PR}$
		$\vec{PR}$ è un nuovo vettore che va da $P$ ad un nuovo punto $R$ che si trova sulla retta $\overline{PQ}$
$V(\mathbb{E}^2)$ con queste operazioni è uno spazio vettoriale/$\mathbb{R}$ (su R)
	Se poniamo $0=\overline{PP}$ (segmento lungo 0) vale la proprietà 1.

## Proprietà algebriche elementari
Sia $V$ uno spazio vettoriale/$\mathbb{K}$
 A. Esiste un unico $0\in V$ t.c. $0+v=v\ \ \ \forall v\in V$
	 0 del campo e 0 dello spazio vettoriale sono distinti
	 $\underline{0}\in V, 0\in\mathbb{K}$
 B. Dato $v\in V$ esiste un unico $w\in V$ t.c. $v+w=0$
	 Dimostrabili con le proprietà dei campi

 I. $0\cdot v=\underline{0}\ \ \ \forall v\in V$
	 Dim.
		 $0\cdot v=(0+v)\cdot v=(6.)=0\cdot v+0\cdot v\to$
		 $0\cdot v+(-(0\cdot v))=0\cdot v+0\cdot v+(-(0\cdot v))\to$
		 $\underline{0}=0\cdot v+(0\cdot v +(-(0\cdot v)))\to$
		 $\underline{0}=0\cdot v+\underline{0}\to$
		 $\underline{0}=0\cdot v$
 II. $\lambda \cdot \underline{0}=\underline{0}\ \ \ \forall \lambda \in\mathbb{K}$
 III. $(-1)\cdot v + v=\underline{0}\ \ \ \forall v\in V$
	Dim.
		$(-1)\cdot v + v=(-1)\cdot v+1\cdot v=(6.)=((-1)+1)\cdot v=\underline{0}$

## Sottospazi vettoriali
Sia $V$ uno spazio vettoriale/$\mathbb{K}$
Un sottoinsieme $W\subset V$ è un *sottospazio vettoriale* se è non vuoto e:
1. Se ho $v_1,v_2\in W$ allora $(v_1+v_2)\in W$
2. Se ho $\lambda\in\mathbb{K}$ e $v\in W$ allora $(\lambda v)\in W$
### Osservazione
Sia $W\subset V$ un sottospazio vettoriale
Allora:
 A. $\underline{0}\in W$
 B. Se $v\in W$ allora $-v\in W$
 C. Ha le operazioni di somma e prodotto scalare
	 $W\times W\to W; (w_1,w_2)\to w_1+w_2$
	 $\mathbb{K}\times W \to W; (\lambda, w)\to \lambda w$
	 È quindi uno spazio vettoriale
Se $\{W_i\}_{i\in I}$ è una collezione di sottospazi vettoriali di $V$ allora $\bigcap_{i\in I}W_i\subset V$ è un sottospazio vettoriale di $V$

# Combinazioni lineari
$\mathbb{K}$ campo
$U,V,W$ spazi vettoriali su $\mathbb{K}$
## Definizione
Siano $v_1,...,v_n\in V$
Un vettore $v\in V$ è *combinazione lineare* di $v_1,..,v_2$ se esistono $\lambda_1,...\lambda_n\in \mathbb{K}$ t.c. $v=\lambda_1 v_1+\lambda_2 v_2+...+\lambda_n v_n$
	Quindi $v$ è parallelo a $w$ se è parallelo alla retta su cui giace $w$
	Se prendiamo invece 2 vettori $v$ e $v'$, le loro combinazioni lineari sono *tutti* i vettori "paralleli" al piano da loro generato (se $v$ e $v'$ non sono combinazioni lineare di loro stessi)

### Notazione
- $\underline{e}_1,...,\underline{e}_n\in \mathbb{K}^n$ sono dati da $\underline{e}_1=(1,0,...,0), \underline{e}_2=(0,1,...,0),...,\underline{e}_n=(0,0,...,1)$
- $\underline{0}\in V$ è combinazione lineare della lista vuota ($n=0$) di vettori
- $S=\{v_1,...,v_n\}\subset V$
	$<v_1,...,v_n>=<\{v_1,...,v_n\}>$ (si scrive senza graffe per fare prima)

## Lemma
Un sottoinsieme non vuoto $W\subset V$ è un sottospazio s.se vale:
	Se $v_1,...,v_n\in W$ allora ogni combinazione lineare di $v_1,...,v_n$ è in $W$

## Span(S)
### Definizione
Se $S\subset V$ è un sottoinsieme $<S>$(oppure $span(S)$)(oppure "sottospazio vettoriale di $V$ generato da $S$)$:=\{\lambda_1 v_1+...+\lambda_n v_n\ |\ v_1,...,v_n\in S\}$
### Proprietà
 a. $S\subset <S>$
 b. $<S>$ è un sottospazio di $V$
 c. Se $W\subset V$ è un sottospazio che contiene $S$ allora $<S>\subset W$
	 Cioè: $<S>$ è il più piccolo sottospazio di $V$ contenente $S$
[[WA_1772452908844.jpeg|Dimostrazione proprietà]]:
 a. Se $v\in S\ \ \ v=1\cdot v$
 b. $\underline{0}\in <S>$ perché è combinazione lineare della lista vuota
 ?. Siano $v,w\in <S>$. Dimostriamo che $(v+w)\in <S>$
	 ecc.
 c. Sia $v\in<S>$, cioè $v=\lambda_1 v_2+\lambda_2 v_2+...+\lambda_n v_n$ dove $\lambda_i\in\mathbb{K}$ e $v_i\in S\subset W$
	 Quindi $v_i\in W$, e perciò $v\in W$ per il lemma

### Somma di sottospazi
Se $U,W\subset V$ sono sottospazi, $U+W:=<U\cup W> =\{u+v\ |\ u\in U, w\in W\}$

### Osservazione
$<S>\supset S$ sempre e $<S> =S$ solo se $S$ è un sottospazio

## Spazi finitamente generati
### Definizione
- Uno spazio vettoriale $V$ è *finitamente generato* se esiste un solo insieme finito $S\subset V$ t.c. $V=<S>$
	$\mathbb{K}^n$ è finitamente generato perché $\mathbb{K}^n=<\underline{e}_1,...,\underline{e}_n>$
	$V(\mathbb{E}^3)$ e $V(\mathbb{E}^2)$ sono finitamente generati
	$\mathbb{K}[x]$ non è finitamente generato perché la combinazione lineare di una lista finita di polinomi avrà grado uguale al massimo grado nella lista (e quindi non può generare lo spazio di tutti i polinomi)

### Proprietà
Sia $V$ uno spazio vettoriale finitamente generato
Se $W\subset V$ è un sottospazio, allora $W$ è finitamente generato
	Non è ovvio
	Ipotesi: $V$ è generato da $n$ vettori
	Tesi: Se $W\subset V$ è un sottospazio vettoriale, $W$ è generato da una lista con al più $n$ vettori
	Dimostrazione per induzione su $n$:
		$n=0$
			$V = \{\underline{0}\}$
			$W=V=\{\underline{0}\}$
				Un sottospazio vettoriale non può essere vuoto quindi $W$ deve essere uguale a $V$
		Ipotesi: vero fino ad $n$
		Passo: $n+1$
			$V=<v_1,...,v_{n+1}>$
			Sia $W\subset V$ sottospazio vettoriale
			Sia $U:=<v_1,...,v_n>\subset V$
			$U$ è un sottospazio vettoriale generato da una lista con $n$ vettori
			$W\cap U\subset U$ è un sottospazio vettoriale di $U$. Per Ip. esistono $w_1,...,w_n\in W\cap U$ t.c. $W\cap U=<w_1,...w_n>$
			Se $W\subset U$ allora $W=W\cap U$ e abbiamo fatto
			Se $W\not\subset U$, sia $w_{n+1}\in(W\backslash U)$
			Dimostriamo che $W=<w_1,...,w_n,w_{n+1}>$
				$w_{n+1}=\lambda_1 v_1+...+\lambda_n v_n+\lambda_{n+1}v_{n+1}$
				???

## Relazioni lineari
### Definizioni
- Una relazione lineare tra i vettori $v_1,...,v_n\in V$ è una uguaglianza $\lambda_1 v_1,... \lambda_n v_n=\underline{0}$, con $\lambda_1,...,\lambda_n\in \mathbb{K}$, ed è *non banale* se almeno uno degli scalari non è nullo
- I vettori $v_1,...,v_n\in V$ sono linearmente dipendenti se esiste una relazione lineare non banale tra $v_1,...,v_n$
	Quindi s.se un vettore è multiplo di un'altro o almeno 1 vettore è il vettore nullo
- I vettori $v_1,...,v_n\in V$ sono linearmente indipendenti se non sono linearmente dipendenti
- Una lista $\{v_i\}_{i\in I}$ di vettori di $V$ è una lista di vettori linearmente dipendenti se esiste $i_1,..., i_n \in I$ distinti t.c. $v_1,...,v_n$ sono linearmente dipendenti
- Una lista $\{v_i\}_{i\in I}$ di vettori di $V$ è una lista di vettori linearmente indipendenti se non è una lista di vettori linearmente dipendenti

### Proprietà
- $v_1,...,v_n \in V$ sono linearmente dipendenti s.se esiste $i\in\{1,...,n\}$ t.c. $v_i\in<v_1,...,v_{i-1},v_{i+1}>$ ($v_i$ è combinazione lineare degli altri vettori)
	Dimostrazione:
		Assumiamo che valga $v_i\in<v_1,...,v_{i-1},v_{i+1}>$ (\*) e dimostriamo che $v_1,...,v_n$ sono linearmente dipendenti
			Per (\*) $\exists \mu_1,...,\mu_{i-1},\mu_{i+1},...,\mu_{n}\in \mathbb{K}$ t.c........
		guarda pdf

### Proposizione
Sia $V$ uno spazio vettoriale su $\mathbb{K}$
Supponiamo che $V=<v_1,...,v_m>$
1. Se $w_1,...,w_n\in V$ sono linearmente *indipendenti* allora $n\leq m$
	Se $n\geq m$ allora vale 2. e quindi sarebbero dipendenti
2. Se $w_1,...,w_n\in V$ e $n>m$, allora $v_1,...,v_n$ sono linearmente *dipendenti*
	Se $n<m$ allora vale 1. e quindi sarebbero indipendenti
Esempio per vedere che non è banale:
$$
\begin{align}
(*)=\begin{cases}
    a_{1,1}x_1&+&...&+&a_{i,n}x_n=0 \\
    \vdots &&\vdots && \vdots \\
	a_{i,1}x_1&+&a_{i,j}x_j&+...+&a_{i,n}x_n=0 \\
    \vdots &&\vdots && \vdots \\
    a_{m,1}x_1&+&...&+&a_{m,n}x_n=0
\end{cases}
\end{align}
	$$
	n equazioni
	n incognite
	Dalla prop. segue che se $n>m$, allora esiste una soluzione non banale di quel sistema
	Perché?
		Siano $A_1,...,A_n\in \mathbb{K}^n$ dati da $A_j=(a_{i,j},a_{2,j},...,a_{m,j})$
		Vale $(*)$ s.se $x_1A_1+x_2A_2+...+x_nA_n=0$
		continua in immagine

### Teorema
Sia $V$ uno spazio vettoriale su $\mathbb{K}$ finitamente generato
Se $\mathcal{B}=\{v_1,...,v_m\}$ e $\mathcal{C}=\{w_1,...,w_n\}$ sono basi di $V$, allora $m=n$.
Dim.
	Siccome $\mathcal{B}$ è una base di $V$, $V=<v_1,...,v_n>$
	Siccome $\mathcal{C}$ è una base di $V$, $w_1,...,w_n$ sono linearmente indipendenti e quindi $n\leq m$ per 1. della Proposizione. Per lo stesso ragionamento con $\mathcal{B}$ e $\mathcal{C}$ scambiati, $m\leq n$. Quindi $m=n$

### Definizione
Sia $V$ uno spazio vettoriale su $\mathbb{K}$ finitamente generato
La *dimensione di $V$* è la *cardinalità* di una sua qualsiasi base.
Esempi:
	- La dimensione di $\{\underline{0}\}$ è 0 (la lista vuota è una base di $V$)
	- $\dim\mathbb{K}^n=n$
	- $\dim\mathbb{K}[x]_{\leq d}=\dim\{p\in\mathbb{K}|\deg p\leq d\}=?=...=d+1$ 
	- Sia $V\subset \mathbb{K}^n$ dato da $V=\{\overline{\underline{X}}\in \mathbb{K}^n|\sum_{i=1}^{n}a_ix_i=0\}$
		$\dim V=\begin{cases}0 &\text{ se } (a_1,...,a_n)=(0,...,0) \\ n-1 &\text{ se } (a_1,...,a_n)\not= (0,...,0) \\ \end{cases}$
mi sono completamente perso

### Proposizione
Sia $V$ uno spazio vettoriale su $\mathbb{K}$ di dimensione $n$.
Se $W\subset V$ è un sottospazio allora
$$
\dim W\leq n
$$
e sia ha eguaglianza solo se $W=V$
Dim.
	$W$ è finitamente generato ($\dim \not = 0$), quindi ha una base $\mathcal{B}=\{w_1,...,w_n\}$. Siccome $w_1,...,w_n$ sono linearmente indipendenti possono essere completati a una base $\{w_1,...,w_n,u_1,...,u_a\}$ di $V$
	Quindi
	$$
	n=\dim V=m+a
	$$
	C.V.D.

### Formula di Grassman
$V$ spazio vettoriale su $\mathbb{K}$
$U,W\subset V$ sottospazi finitamente generati
Allora:
$$
\dim(U+W=\{u+w|u\in U,w\in W\})+\dim(U\cap W)=\dim U + \dim W
$$
Osservazione:
Supponiamo $V$ finitamente generato. Allora $\dim(U+W)\leq \dim V$. Quindi Grassman dà che $\dim(U\cap W)=\dim U+ \dim W-\dim (U+W)\geq \dim U + \dim W - dimV$ e perciò se $\dim U + \dim W>\dim V$ l'intersezione $U\cap W$ contiene vettori non nulli
