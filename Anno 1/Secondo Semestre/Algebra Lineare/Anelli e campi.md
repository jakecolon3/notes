Sugli insiemi $\mathbb{Z}, \mathbb{Q}, \mathbb{\mathbb{R}}$ esistono le operazioni di somma e di prodotto, che hanno queste proprietà:
1. $\exists \ 0\in \mathbb{R}\ t.c.\ 0+a=a\ \ \ \forall a$
2. $a+(b+c)=(a+b)+c\ \ \ \ \forall a,b,c$
3. $\forall a\ \ \exists b\ t.c.\ a+b=0$
4. $a+b=b+a\ \ \ \ \forall a,b$
5. $\exists\ 1\in \mathbb{R}\ t.c.\ 1\cdot a=a\ \ \ \ \forall a$
6. $a\cdot(b\cdot c)=(a\cdot b)\cdot c\ \ \ \ \forall a,b,c$
7. $a\cdot b=b\cdot a\ \ \ \ \forall a,b,c$
8. $a\cdot(b+c)=a\cdot + a\cdot c\ \ \ \ \forall a,b,c$
	(immagina $\in \mathbb{R}$ per tutti i per ogni)
Queste non sono solo proprietà, definiscono una classe di insiemi:
## Anelli
Un insieme $\mathbb{R}$ con due operazioni $\mathbb{R}\times \mathbb{R}\to \mathbb{R},\ (a,b)\to a+b$ e $\mathbb{R}\times \mathbb{R}\to \mathbb{R},\ (a,b)\to a\cdot b$ è un *anello commutativo* (per 7.) *con 1 (unità)* (per 5.) se valgono queste proprietà.
Vediamo quindi che $\mathbb{N}$ con $+$ e $\cdot$ *non* è un anello (per 3.)
Osservazioni:
- $\exists !$ (esiste un unico) $0\in \mathbb{R}\ t.c.$ valga 1.
- Dato $a\in \mathbb{R},\ \exists!\ b\in \mathbb{R}\ t.c.\ a+b=0$
- $\exists!\ 1\in \mathbb{R}\ t.c.\ 1\cdot a=a\ \ \forall a\in \mathbb{R}$

### Campi
Un anello $\mathbb{K}$ è un *campo* se $\forall a\not=0$ esiste $b\in \mathbb{K}\ t.c.\ a\cdot b = 1$
Quindi $\mathbb{Z}$ non è un campo, ma $\mathbb{Q}$ e $\mathbb{R}$ sono campi

### Anelli e campi finiti
Gli insiemi che abbiamo visto hanno tutti cardinalità finita, ma esistono anche anelli e campi finiti
$n\in \mathbb{N},\ \ n\geq 2$
$\mathbb{Z}/(n):=\{[0],...,[n-1]\}$
Definiamo operazioni di somma e prodotto su $\mathbb{Z}/(n)$ = l'insieme delle "classi resto modulo n" (i possibili resti dividendo un $z\in \mathbb{Z}$ per $n$)
- Somma:
	$\mathbb{Z}/(n)\times \mathbb{Z}/(n)\to \mathbb{Z}/(n)$
	$([a], [b])\to$ resto della divisione per n della somma "solita" a+b
- Prodotto:
	$\mathbb{Z}/(n)\times \mathbb{Z}/(n)\to \mathbb{Z}/(n)$
	$([a], [b])\to$ resto della divisione per n del prodotto "solita" a+b
(metti immagine)
$\mathbb{Z}/(n)$ con queste operazioni è un anello
È un campo? Si, ma solo s.se $n$ è primo
	Es.: dimostra che se $n$ non è primo allora $\mathbb{Z}/(n)$ non è un campo