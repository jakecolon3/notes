### Colazione
3 bevande
4 cose da mangaire

Quante colazioni posso fare?
	Prima bisogna precisare la richiesta
	Colazione 1: 1 bevanda + 1 cosa da mangiare
		= 12
			Perché?
			3 \* 4
			Per ogni bevanda posso scegliere un qualunque snack
			“**Principio moltiplicativo**”
			Risolvibile anche con principio additivo
				Dividi in casi per ogni bevanda, conta le scelte e somma
	Colazione 2: al più 1 bevanda + al più 1 snack
		Al più = <= 1
		= 12 + 4 + 3 + 1 = 20
			1 bevanda + 1 snack; solo bevanda; solo snack; né bevanda né snack
			”**Principio additivo**”
			Risolvibile anche con principio moltiplicativo
				Aggiungi “niente” alle bevande e gli snack

# Principio moltiplicativo
Con n, k >= 1
	n = numero di scelte
	ki = numero di scelte scelte in posizione i
Se scelgo un 1° oggetto tra k1, un 2° tra k2, … un n° tra kn:
	Il numero di scelte possibili è k1 \* k2 \* … \* kn
	Es.:
		Targhe: Lettera, Lettera, Cifra, Cifra, Cifra, Lettera, Lettera
			Targhe possibili = 26 \* 26 \* 10 \* 10 \* 10 \* 26 \* 26
			= 26^4 \* 10^3 
	Es.:
		Numero di stringhe binarie lunghe 70:
			= 2 \* 2 \* 2 … = 2^70 
	Es.:
		Panini: 3 tipi di pane, 3 tipi di salume, 4 tipi di salsa
		Quanti panini si possono fare con 1 scelta di pane, 1 scelta di salume ed esattamente 2 scelte di salsa diverse?
		= 3 \* 3 \* 4 \* 3
	Es.:
		Estraggo da un urna con 100 palline con numeri 4 volte senza rimettere:
		# = 100 \* 99\* 98 \* 97
		Rimettendo: # = 100^4 
		Estraendo 100 numeri: # = 100!
	Es.:
		# di parole (sequenze) di 3 lettere che iniziano con una vocale:
		# = 5 \* 26^2 
	Es.:
		Gara di corsa con 8 atleti: # di ordini di arrivo? (arrivano tutti a tempi diversi)
		# = 8!
		# di salite al podio (ordine conta) = 8 \* 7 \* 6
	Es.:
		Alfabeto A-J:
		# stringhe di 5 lettere che non contengono lettere identiche in posizioni continue
		# = 10 \* 9^4 

Questi sono esempi di [[disposizioni]]
Il principio moltiplicativo calcola sempre sequenze ordinate

# Principio additivo
Abbiamo visto che i problemi di tipo “calcola quante scelte puoi fare con questi elementi” rappresentano le disposizioni di una successione ordinata (calcolate con il principio moltiplicativo)
	Es.
	(i, j, k)
	i ∈ {1, 2, 3}
	j ∈ {1, 2}
	k ∈ {1, 2, 3, 4}

Precedentemente li abbiamo calcolati con il principio moltiplicativo, ma è possibile anche usare il **principio additivo**:
	Suddividi il problema in diverse categorie e somma la quantità di soluzioni in ogni categoria
		Es.
		Targhe con 1 sola P:
			Targhe = {Tutte le possibili targhe}
			Targhe con una P ⊂ Targhe
			Possiamo dividere il problema in 4 “tipi”:
			- P in 1° pos.
				Targhe di tipo P \_ \_ \_ \_ \_ \_
				= 25^3 \* 10^3 
			- P in 2° pos.
				Targhe di tipo \_ P \_ \_ \_ \_ \_
				Stessa quantità
			- P in 3° pos.
				Ecc.
			- P in 4° pos.
			.
			La soluzione totale sarà: 1° + 2° + 3° + 4° = 4 \* 25^3 \* 10^3 

Il principio additivo dà soluzioni più “descrittive” del princ. moltiplicativo, che invece produce soluzioni più algoritmiche
	Altro es.
	**Targhe con *almeno* una P**
	Manteniamo la suddivisione in posizioni
	La soluzione 4 \* 26^3 \* 10^3 non funziona perché i tipi si intersecano, quindi conteremmo la stessa targa più volte
Dobbiamo evitare:
S > 1° + 2° + 3° + 4° (soluzione non esclusiva) 
S < 1° + 2° + 3° + 4° (soluzione non esaustiva)

In termini insiemistici questo processo di suddivisione si chiama “**partizione**”:
	Prendiamo un insieme A che contiene tutte le soluzioni e lo dividiamo in *sottoinsiemi*
		T(A) ⊆ A
		T(2) ⊆ A
		… T(k) ⊆ A
	Abbiamo una partizione dell’insieme A se i sottoinsiemi sono **esaustivi** ed **esclusivi**
		- Esaustivi:
		Ogni elemento di A è in almeno uno dei T(i)
		A ⊆ T(1) ∪ … ∪ T(k)
			Definizione di unione:
			X ∪ Y = {a: a ∈ X oppure a ∈ Y}
		- Esclusivi:
		Nessun elemento è in più di un T(i)
		i ≠ j, T(i) ∩ T(j) = ø (insieme vuoto)
			Definizione di intersezione:
			X ∩ Y = {a: a ∈ X, a ∈ Y}
	Quindi:
		Una **partizione** di un insieme A è una famiglia di sottoinsiemi di A tra loro *esaustivi* ed *esclusivi* (disgiunti)

Con questi principi possiamo definire il principio additivo in questo modo:
	Se T(1), …,T(k) è una partizione di A, allora \#A = \#T(1) + … + \#T(k) = $\sum_{i=1}^k\#T_i$

Per risolvere \#A = “numero di targhe con almeno una P” possiamo anche usare un altro metodo:
	Contiamo tutte le targhe (”insieme ambiente”) e da esse sottraiamo le targhe che **non hanno nessuna** P
	“Passaggio per complemento” (conto gli oggetti che non soddisfano la richiesta):
		\#A = \#T - \#B
		= 26^4 \* 10^3 - 25^4 \* 10^3 
	.
	Questa è comunque un’applicazione del principio additivo:
		\#T - \#B = \#A ->
		> \#T = \#A + \#B
		In questo caso B è il *complemento* di A in T: B = T \ A
			Definizione di complemento:
			Con A ⊆ X:
			X \ A = {a: a ∈ X, a ∉ A}
				Questo processo **produce sempre una partizione** di X

Es.
Gara con 8 atleti
	2 Ita
	3 Fra
	3 Spa
\# di ordini di arrivo t. c. i primi 3/2 hanno nazionalità distinte?
Top 3:
$(2\cdot{3}\cdot{3}+3\cdot 2 \cdot 3+3\cdot 3\cdot 2)\cdot 2=108$
Bottom 5:
Parole {I, F, f, S, s} = $P_5$ = $5\cdot4\cdot3\cdot2 = 120$
Classifica:
$108\cdot 120=12960$

# Principio di inclusione/esclusione a 2 termini ($PIE_{2}$)
Se abbiamo un insieme di soluzioni X divisa in sottoinsiemi che si intersecano non possiamo usare il principio additivo, dobbiamo partizionarlo:
	((M+F) ∩ M ∩ F) ⊆ X
	In questo caso sommare M e F per trovare il numero di studenti (= \#(M ∪ F))sarebbe sbagliato: conteremmo più volte chi si trova nel sottoinsieme (M+F)
		M contiene M e M+F
		F contiene F e M+F
		Sommare M e F sarebbe:
			(Solo M + M+F) + (Solo F + M+F)
		Sommiamo M+F 2 volte
	Per partizionarlo dobbiamo fare:
		#(M ∪ F) = \#M + \#F - \#(M ∩ F)

Per utilizzare questo metodo deve essere facile contare $M, F, M\cup F, M\cap F$


Come contiamo l’unione di 3 insiemi?
### Principio di inclusione/esclusione a 3 elementi ($PIE_{3}$)
$$E = A\cup B\cup C$$
$\#E=(\#A+\#B+\#C)-\#(A\cap B)-\#(A\cap C)-\#(B\cap C)+\#(A\cap B\cap C)$
# Principio di inclusione/esclusione a n elementi
Regola del pastore
[[Combinazioni]]
Gara con 8 atleti
\# qualificazioni = # di salite al podio *ma* non ordinate

### [[Esercizi combinatoria]]