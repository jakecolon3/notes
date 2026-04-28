[[Simboli]]
# Numeri naturali
ℕ = \{0, 1, 2, 3…}
- Insieme infinito

Un numero naturale n ∈ ℕ

Rappresentabili su una retta R con origine O = 0 e fissando un’unità di misura

### *Operazioni*
- **Somma** (+)
	Dati due numeri naturali è possibile associare a loro un terzo numero naturale: **l’insieme è chiuso rispetto alla somma**.
	Esiste un’elemento neutro rispetto alla somma: 0.

- **Prodotto** (\*)
	L’insieme è **chiuso** rispetto al prodotto
	*n* \* *m* = {*n* + *n* … + *n*} *m* volte
	Esiste un elemento neutro rispetto al prodotto: 1.

*Proprietà*:
	**Proprietà commutativa**
		*n + m = m + n*
		*n* \* *m* = *m* \* *n*
	**Legge distributiva**
		(*n, m, h*) ∈ ℕ: *h* \* (*n* + *m*) = *h* \* *m* \* *n*

*Rappresentazione decimale*
	Qualsiasi numero ∈ ℕ è rappresentabile con (ℕ, +, \*):
		2794 = 2\*10^3 + 7\*10^2 + 9\*10 + 4 

Nei numeri naturali non è sempre possibile sottrarre, dobbiamo passare a:
# Numeri interi
ℤ = {…, -n, ..., -2, -1, 0, 1, 2, …, n, …}
ℕ ⊂ ℤ


### *Operazioni*
- **Somma**
	Esiste un elemento inverso rispetto alla somma:
		∀ n ∈ ℤ ∃ m ∈ ℤ: n + m = 0
		*Per ogni numero n compreso in ℤ esiste un numero m compreso in ℤ tale che n + m = 0*
			*m = -n*
- **Prodotto**
- **Differenza**

Nei numeri interi non è sempre possibile dividere, dobbiamo passare a:
# Numeri razionali
ℚ = {p/q, p ∈ ℤ, q ∈ ℕ, q != 0}
	Dato che i razionali possono avere più rappresentazioni equivalenti si fissa q ∈ ℕ per semplicità (forse non preciso)
Per costruzione ℕ ⊂ ℤ ⊂ ℚ
	2 = 2/1; -3 = -3/1
1/2 = 2/4 = 100/200

Se p e q non hanno divisori comuni: (p, q) = I

### *Operazioni*
- **Somma**
- **Differenza**
- **Prodotto**
- **Quoziente**
	p/q, r/s, r != 0 -> (p/q)/(r/s) = p/q \* s/r = (p \* s)/(q \* r)

*Proprietà*
	**Inversione elementi**
		Ogni elemento di ℚ non nullo ha un elemento inverso rispetto al prodotto:
			∀ x ∈ ℚ != {0} ∃ y ∈ ℚ: x \* y = 1
				y = 1/x
	**Legge di annullamento del prodotto**
		Se x \* y = 0: 
		x = 0 o y = 0
		Dimostrazione se x != 0:
			Esiste inverso di x come dimostrato prima = x^-1 
			`x * y = 0` -moltiplico entrambi i membri per x^-1-> `x^-1 * x * y = x^-1 * 0` ->
			1 \* y = 0 ->
			y = 0


### I numeri Q si possono rappresentare in modi diversi:
	Rappresentazione decimale:
		1/2 = 0,5
		7/2 = 3,5
		1/3 = 0,333… = 0,3...
		Non sono uniche: 1 = 0,999…
. 
	Dalla divisione di due numeri interi p/q con q != 0 si ottengono solo:
	- Rappresentazioni decimali limitate:
		p/q = ± n, d1 d2 …
.
	- Rappresentazioni decimali illimitate periodiche:
		Dopo la virgola ho un un numero limitato di cifre che si ripetono:
			1/3 = 0,\[3]\[3]…
			1/7 = 0,\[142857]\[142857]… 


Data una rappresentazione decimale limitata o periodica come individuo il numero razionale p/q?
	0,5 = 5/10 = 1/2
	0,32 = 32/100 = 8/25
	2,3444… = \[234 (tutte le cifre del numero) - 23 (cifre prima del periodo)]/90 (tanti 9 quante sono le cifre del periodo seguiti da tanti 0 quante sono le cifre dell’antiperiodo) = 211/90
		4 = periodo = cifre che si ripetono
		3 = antiperiodo = cifre dopo la , ma prima del periodo
	Es.
		3,151515… = (315 - 3)/99 = 312/99
		0,999… = (9 - 0)/9 = 1

### Ordinamento
**Rappresentazione grafica** (?)
Rappresentando ℚ su una retta orientata possiamo mettere in ordine i numeri razionali


*Q non basta per misurare*:
		Problema: misurare la lunghezza L della diagonale di un quadrato di lato 1 (L è razionale?)
			(quadrato sulla retta numerica)
			Per il teorema di Pitagora L = sqrt(1^2 + 1^2) = sqrt(2)
			Dimostriamo che sqrt(2) ∉ ℚ:
				Per assurdo sia sqrt(2) = p/q con p, q ∈ ℕ
				con q != 0
				con (p, q) = I (non hanno divisori comuni)
					sqrt(2) = p/q -> moltiplica per q entrambi i membri
					sqrt(2) \* q = p -> eleva al quadrato entrambi i membri
					p^2 = 2 \* q^2 *quindi p^2 è pari* -> *anche p è pari* -> se p è pari: p = 2n
					p^2 = 2 \* q^2 = 4 \* n^2 -> divido entrambi i termini per 2
					q^2 = 2 \* n^2 -> q^2 è pari -> q è pari
						Se sia p che q sono pari allora hanno come divisore comune 2: **è contraddittorio con la premessa (p, q) = I**
						Abbiamo dimostrato per assurdo che sqrt(2) != p/q


# Numeri reali
ℝ = {punti della retta R} = ℚ ∪ {numeri irrazionali}
	Ogni punto P della retta R corrisponde ad un unico numero reale x -> x: ascissa del punto P
	I numeri irrazionali sono caratterizzati dall’avere una rappresentazione decimala illimitata **non periodica**
Questa definizione non basta: definiamoli in modo assiomatico:
	ℝ è un insieme dove sono definite certe operazioni che soddisfano certe regole
	Proprietà di ℝ:
		1. ℝ: (+, -, \*, /)
			Proprietà commutativa (+, \*)
			Esiste un elemento neutro rispetto alla somma
			Esiste un elemento neutro rispetto al prodotto
			Esiste l’opposto rispetto alla somma: a + b = 0
			Esiste l’inverso rispetto al prodotto: a \* a^-1 = 1
			Proprietà associativa, distributiva ecc.
		2. ℝ è un insieme ordinato
			x, y ∈ ℝ
			x < y se nella rappresentazione sulla retta R y è a *destra* di x
			x > y se nella rappresentazione sulla retta R y è a *sinistra* di x
			x <= y se x < y o x = y
			x >= y se x > y o x = y
			ℝ è un ordinamento totale:
				x, y ∈ ℝ, x != y allora o x > y o x < y

**Ordinamento**
Proprietà:
- Proprietà transitiva
	Se x <= y e y <= z allora x <= z
- Proprietà di cancellazione
	Se x <= y allora ∀ z ∈ ℝ: x + z <= y + z
- Proprietà di ?
	Se x <= y allora ∀ z ∈ ℝ:
		z >= 0: z \* x <= z \* y
		z < 0: z \* x >= z \* y
- I numeri ℝ sono densi nei ℚ
	Comunque io prendo 2 numeri ℝ tra di loro esistono infiniti numeri ℚ
		Segue che ogni numero ℝ può essere approssimato bene quanto voglio da un numero razionale
- ℝ è **completo**
	”Non ci sono buchi”
	Ogni punto della retta R corrisponde ad un numero reale ed ogni numero reale corrisponde ad un punto della retta

**Valore assoluto di un numero reale**
x ∈ ℝ
	|x| =
		- x se x >= 0
		- -x se x <= 0
	Rappresenta *la distanza di x dall’origine*
		Risolvi |x| = 3
			x = ± 3
		Risolvi |x| = -1 
			x ∄
	|x| = |-x|
Proprietà del modulo:
- |x| >= 0, |x| = 0 solo se x = 0
- |x \* y| = |x| \* |y|
- Disuguaglianza triangolare
	V x, y € ℝ
	|x + y| <= |x| + |y|
	Dim.:
		- x + y >= 0
			|x + y| = x + y
			Dalla def. di modulo x <= |x| ->
			|x + y| = x + y <= |x| + |y|
		- x + y < 0
			|x + y| = -(x + y) = -x - y
			-x <= |-x| = |x| ->
			-x - y <= |x| + |y|

Dati x, y ∈ ℝ, qual è la distanza d tra x e y?
	d(x, 0) = |x|
	d(y, 0) = |y|
	d(x, y) =
		1. y - x se y >= x
		2. x - y se y < x
			1. y - x se y - x >= 0
			2. -(y - x) se y - x < 0
				Definizione di modulo:
				d(x, y) = |y - x|
		


## Sottoinsiemi di ℝ:
Intervalli:
	Limitati:
		Dati a, b ∈ ℝ, a < b, chiamiamo:
			- Intervallo chiuso \[a, b] = {x ∈ ℝ: a <= x <= b}
			- Intervallo aperto (a, b) = {x ∈ ℝ: a < x < b}
			- Intervalli semiaperti \[a, b) o (a, b] = {x ∈ ℝ: a <= x < b} o {x ∈ ℝ: a < x <= b}
				Questi sono intervalli limitati
				Questi intervalli sono continui
				Questi intervalli hanno la stessa lunghezza *L* = b - a
	Illimitati:
		Sono definiti da una sola disuguaglianza
		Dato a ∈ ℝ:
			- \[a, +inf) = {x ∈ ℝ: x >= a}
			- (a, +inf) = {x ∈ ℝ: x > a}
				Illimitati superiormente
			- (-inf, a] = {x ∈ ℝ: x <= a}
			- (-inf, a) = {x ∈ ℝ: x < a}
				Illimitati inferiormente

### Estremi di un intervallo
Un insieme E ⊆ ℝ è:
	*Limitato* *superiormente* se ∃ Λ ∈ ℝ: x <= Λ ∀ x ∈ ℝ
	*Limitato inferiormente* se se ∃ λ ∈ ℝ: x >= λ ∀ x ∈ ℝ
	*Limitato* se è limitato superiormente e inferiormente
	‎ 
	E' equivalente dire che E è limitato se è contenuto in un intervallo limitato

Avendo due valori λ e Λ di un insieme E è possibile stabilire che E è un sottoinsieme dell'intervallo \[λ, Λ]

**Massimi e minimi**
Massimi:
	Il valore M € R è il massimo di E (M = max E) se:
		M è un maggiorante di E
		M € E
Minimi:
	Il valore m € R è il minimo di E (m = min E) se:
		m è un minorante di E
		m € E

**Estremi superiori ed inferiori**
Sup:
	Il valore Λ è l'estremo superiore di E (Λ = sup E) se:
		Λ è un maggiorante di E
		Ogni maggiorante L di E verifica Λ <= L
Min:
	Il valore λ è l'estremo inferiore di E (λ = inf E) se:
		λ è un minorante di E
		Ogni minorante *l* di E verifica λ >= *l*

Se esiste un maggiorante o minorante dell'insieme E ⊂ ℝ allora esiste *sempre* l'estremo superiore o inferiore; lo stesso **non vale** per i numeri razionali
	Es.
	E = {x € ℚ: x^2 <= 2}
	Dato che sqrt(2) ∉ ℚ, Λ e λ ∄