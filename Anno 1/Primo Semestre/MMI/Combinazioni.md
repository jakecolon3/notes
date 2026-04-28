Gara con 8 atleti
\# qualificazioni = # salite al podio *ma* non ordinate
Se stiamo contando le salite al podio $(a,b,c)≠(b,a,c)$

Le qualificazioni sono una parte di una partizione delle salite al podio
Per contare una qualificazione degli atleti $a,b,c$ dobbiamo dividere le possibili salite al podio con loro al podio per i possibili modi in cui possono essere al podio: $\frac{D_{8,3}}{6}=\frac{D_{8,3}}{3!}$

# Definizione
Sia A un insieme
Sia $n≥0\inℕ$
Un “$n$-sottoinsieme” di A è un sottoinsieme di A con esattamente $n$ elementi
Denotiamo con $[A]^n$ l’insieme di tutti e soli gli $n$-sottoinsiemi di A
	$A = \{a,b,c\}$
	$n=2$
	$[A]^2=\{\{a,b\},\{a,c\},\{b,c\}\}$
	$[A]^3=\{\{a,b,c\}\}$

I k-sottoinsiemi di un insieme di $n$ elementi sono le ***combinazioni*** di ordine k tra $n$ =$$
\frac{D_{n,k}}{k!}=\#[A]^k=C_{n,k}=\frac{n!}{(n-k)!\cdot{}k!}=\binom{n}{k}
$$
Esempio:
	Elezione di 4 rappresentanti tra 80 studenti
	$=C_{80,4}$
Esempio
	80 persone
	- 50 cristiani
	- 20 induisti
	- 10 buddisti
	Gruppi di 5 persone con almeno 1 rappresentante di ogni confessione
	$\text{Delegazioni\ totali}=C_{80,5}$
	Passiamo per complemento: troviamo i gruppi in cui manca almeno un rappresentante di una confessione
	$\text{Delegazioni\ senza}=\{\text{5 senza cristiani}\}\cup \text{\{5 senza ind.\}}\cup \text{\{5 senza budd.\}}$
	$A+B+C-A\cap B-A\cap C-B\cap C+A\cap B\cap C$

Tornando al $PIE_{3}$, possiamo vedere che gli elementi da sottrarre/aggiungere all’iniziale $A+B+C$ sono i $2$-sottoinsiemi di $\{A,B,C\}$ e i $3$-sottoinsiemi dello stesso insieme, calcolabili con le combinazioni
Quindi il $PIE_{n}$=
$$
PIE_{n}=A_{1+}+\dots+A_{n}
$$

### Contare i sottoinsiemi di un insieme
$A=\{a_{1},\dots,a_{n}\}$
\# sottoinsiemi di A (calcolato con principio additivo) = $C_{n,1}+C_{n,2}+\dots+C_{n,n}=2^n=D’_{2,n}$
Insieme dei sottoinsiemi di A = $P(A)=\{S: S\subseteq A\}$
$\#P(A)=\sum_{i=0}^nC_{n,i}=2^n$
Perché $2^n$ conta sia il numero di sottoinsiemi che le stringhe binarie lunghe $n$?
	Suggerimento: la stringa binaria indica se un elemento è presente o no nel sottoinsieme

$C_{80,4}\cdot C_{4,1}=C_{80,1}\cdot C_{79,3}$
$\frac{80!}{76!4!}\cdot 4=80\cdot \frac{79!}{76!3!}$
Delegazione di m studenti tra n e in essa una sottodelegazione di k studenti
Due soluzioni:
- $C_{n,m}\cdot C_{m,k}$
- $C_{n,k}\cdot C_{(n-k),(m-k)}$

Altro modo di contare i k-sottoinsiemi di un insieme:
I k-sottoinsiemi di un insieme di $n$ elementi sono **tanti quanti** i loro complementi
Cos’è il complemento di un k-sottoinsieme?
$S$ è un k-sottoinsieme
$\#A\text{\\} S=\#A-k$
$\#A-k$ è un $(n-k)$-sottoinsieme di A
	Ad ogni S è associato un’altro sottoinsieme con tutti gli elementi non in S

Quindi:
$$
C_{n,k}=C_{n,(n-k)}
$$
$C_{100,3}=C_{100,97}$
	$\frac{100!}{97!3!}=\frac{100!}{3!97!}$

Ogni k-sottoinsieme può essere associato ad un $(n-k)$-sottoinsieme in modo tale che ogni oggetto del k-sottoinsieme è associato ad 1 solo oggetto del complemento, ed ogni oggetto del complemento è associato ad un oggetto del primo sottoinsieme
	Biiettività o buona traduzione
	$X-\tau\rightarrow Y:$
		Ogni elemento $x\in X$ viene tradotto in esattamente 1 elemento di $Y$
		Ogni elemento $y\in Y$ si ottiene come traduzione di almeno un elemento di X
		Elementi distinti in $X$ hanno traduzioni diverse: $x≠x’\rightarrow \tau(x)≠\tau(x’)$


Contiamo i k-sottoinsiemi con il principio additivo
C’è un elemento particolare
Partizioniamo $[A]^k$ in 2 tipi
- Inclusivi
	Contengono l’elemento particolare
- Esclusivi
Quindi $[A]^k=T_1\cup T_2$ e $T_1\cap T_2=ø$
$\#[A]^k$
$\#T_2$ è più facile da contare = $C_{(n-1),k}$
$\#T_1 = C_{(n-1),(k-1)}$
	Tutti gli insiemi di tipo:$\text{elemento particolare}\cup (k-1)\text{-sottoinsiemi scelti da n-1}$
$\#[A]^k=C_{(n-1),k}+C_{(n-1),(k-1)}=C_{n,k}$
Generalizzando:
	$A = \{a_1,…,a_n\}$
	Partiziono $[A]^k$ come segue:
	Fisso un elemento $a\in A$
	Dichiaro:
		$X=\{S\subseteq A:S\text{ ha k elt. e } a\in S\}$
		$Y=\{S\subseteq A:S\text{ ha k elt. e }a\notin S\}$

Buona traduzione
$X-\tau\rightarrow Y:$
	Ogni elemento $x\in X$ viene tradotto in esattamente 1 elemento di $Y$
	Ogni elemento $y\in Y$ si ottiene come traduzione di almeno un elemento di X
	Elementi distinti in $X$ hanno traduzioni diverse: $x≠x’\rightarrow \tau(x)≠\tau(x’)$

### Problemi di scrittura additiva
3 pasticche
2 ragazzi
	Si possono scrivere le soluzioni come sequenze ordinate di 3 pallini e una barra
	In un problema simile con n elementi e k “cassetti” il numero di barre saranno k-1
	Quindi il problema è equivalente a chiedere # sequenze di n elementi e k-1 barre
	Per descrivere una soluzione però basta descrivere le posizioni degli elementi in una stringa di n+k-1 elementi
		È equivalente a contare gli n-sottoinsiemi dell’insieme di n+k-1 posizioni possibili = $C_{12,7}=C_{12,5}$
			Insiemi con gli indici delle posizioni in cui è presente un elemento
			È inoltre equivalente a contare le posizioni delle barrette
	Metodo “*stars and bars*”
	Formalmente il problema è “quante sono le soluzioni intere ≥ 0 della seguente equazione?”
		$x_1+x_2+x_3+x_4+x_5=10$
			$\# = C_{(10+5-1),10}$
			Ogni x è un “contenitore”, il numero dopo l’uguale è il numero di elementi da distribuire
		Questo è un problema di “**scrittura additiva**”
		Se invece cerchiamo soluzioni > 0?
			- Aggiungi 1 elemento ad ogni contenitore
			- Risolvi il problema come prima con i restanti elementi
			Quindi la soluzione sarà $\# = C_{(5+5-1),5}$
				Generalizzando $\#=C_{((n-k)+k-1),k}=C_{(n-1),k}$
		Se invece cerchiamo soluzioni t.c. ogni variabile ≤ i?
		Es. # soluz. di $x+y+z=11$
			- Passaggio al complemento
				Cerchiamo soluzioni t.c. almeno 1 variabile > i
				Sarebbe $x>4 ||y>4||z>4$
				Con $PIE_3$:
				Dividiamo in 3 casi
					- x > 4
						$A=\{C_{11-5+2,2}\}$
					- y > 4
						$B = //$
					- z > 4
						$C = //$
					Totale:
						 $A+B+C-(A\cap B)-(A\cap C)-(B\cap C)+(A\cap B\cap C)$

Con questi esempi abbiamo visto come risolvere problemi del tipo:
	Calcola il numero di soluzioni dell’equazione $\sum _{i=1}^{r}x_i=p$
# Combinazioni con ripetizione
 $A = \{a_1,\dots,a_k\}$
	Elementi che posso scegliere
Le combinazioni *con ripetizione* di ordine $n=C’_{n,k}$ sono: 
$$
\binom{n+k-1}{k}=\frac{(n+k-1)!}{k!(n-1)!}
$$