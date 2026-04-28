Definizione:
$$\mathbb{C}:= \{z=a+bi\ |\ a,b\in \mathbb{R}\}$$
	$Re(z)=a,\ Im(z)=bi$
Definiamo le operazioni:
- Somma
	$\mathbb{C}\times \mathbb{C}\to \mathbb{C}$
	$(a+bi, c+di)\to (a+c)+(b+d)i$
- Prodotto
	$\mathbb{C}\times \mathbb{C}\to \mathbb{C}$
	$(a+bi, c+di)\to (ac-bd)+(ad+bc)i$
		Uguale ad un prodotto normale ma $i^2=-1$
Il *coniugato* di un numero $z=a+bi$ è $\bar z:=a-bi$
### I numeri complessi sono un campo
- L'elemento neutro per la somma è $0+0i=:0$
- L'elemento neutro per il prodotto è $1+0i=:1$
Verifichiamo che se $a+bi\not=0$ (quindi almeno uno tra $a$ e $b$ è $0$) esiste $c+di\in \mathbb{C}\ t.c.\ (a+bi)\cdot(c+di)=1$ (ogni elemento ha l'inverso moltiplicativo)
Notiamo che un numero moltiplicato per il suo coniugato produce sempre un numero reale strettamente positivo: $(a+bi)\cdot(a-bi)=a^2-abi+abi-b^2i^2=a^2+b^2$; inoltre se $a+bi\not=0$ allora $a^2+b^2>0$
	Sappiamo che ha l'inverso moltiplicativo
Quindi: $(a+bi)\cdot(\frac{a}{a^2+b^2}-\frac{b}{a^2+b^2}i)=1$
Cioè: $\frac{a-bi}{a^2+b^2}=(a+bi)^{-1}$

### Numeri complessi sul piano
Scegliamo un sistema di riferimento cartesiano nel piano: fissiamo un asse reale ed un asse immaginario
La somma di numeri complessi è rappresentabile sul piano come somma di vettori
Per la rappresentazione del prodotto dobbiamo introdurre delle nuove definizioni:
- Modulo
	Dato un $z\in \mathbb{C}$, il suo modulo è: $|z|:=\sqrt{a^2+b^2}=\sqrt{z\cdot\bar z}$
	È uguale alla lunghezza del segmento che unisce l'origine con il punto
- Argomento
	Fissando un $z\not=0$ sul piano, abbiamo che $\theta$ è il suo angolo in radianti rispetto all'asse reale: $\theta=:Arg(z)$
Dato argomento e modulo posso ricavare $a$ e $b$:
	$a=|z|\cos\theta$
	$b=|z|\sin\theta$
Quindi posso scrivere $z$ come: $z=\rho(\cos\theta+i\sin\theta)$ dove $\rho=|z|,\ \theta=Arg(z)$
	Questo modo di scrivere i numeri complessi è detta *rappresentazione polare*
Possiamo ora vedere la rappresentazione della moltiplicazione:
Siano $z_1=\rho_1(\cos\theta_1+i\sin\theta_1),\ z_2=\rho_2(\cos\theta_2+i\sin\theta_2)$:
$$z_1\cdot z_2=\rho_1\cdot\rho_2(\cos\theta_2+i\sin\theta_1)\cdot(\cos\theta_2+i\sin\theta_2)=...=\rho_1\rho_2[(\cos\theta_1\cos\theta_2-\sin\theta_1\sin\theta_2)+i(\cos\theta_1\sin\theta_2+\sin\theta_1\cos\theta_2)]=\rho_1\rho_2(\cos(\theta_1+\theta_2)+i\sin(\theta_1+\theta_2))$$
	Il modulo di $z_1\cdot z_2=|z_1|\cdot|z_2|$
	L'argomento di $z_1\cdot z_2=Arg(z_1)+Arg(z_2)$
Sul piano quindi il prodotto di due numeri complessi ha come modulo il prodotto dei moduli e come angolo la somma degli angoli
Esercizio:
	Quante soluzioni complesse esistono dell'equazione $z^n=1$?
	A quanto pare ha $n$ soluzioni
### Teorema fondamentale dell'algebra
![[IMG_20260223_131619.jpg]]
Dove $\varepsilon_1,...,\varepsilon_n$ sono le radici di $p(z)$