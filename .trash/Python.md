Creato da Guido Van Rossum
Nome viene da Monty Python

La sintassi è particolare rispetto ad altri linguaggi: funziona per indentazione invece che per parentesi

# Tipi di dati
L’istruzione type() indica il tipo di dato della keyword indicata
**int**
	Ignorano gli _
	Numeri interi
	A differenza di altri linguaggi in Python sono codificati in memoria a precisione ”infinita”: non sono limitati dal numero di bit del processore
	Codificati in binario
		Un modo per codificare i numeri relativi usa il bit più a sinistra (più significativo) come negativo
**float**
	Numeri con la virgola
	Codificati con un numero di bit fisso, di solito 1 o 2 word
	(In sistemi a 1 word = 64 bit) Codificati con 1 bit per il segno, 11 per l’esponente e 52 di “mantissa”, o dati effettivi del numero
		Numero = (-1)^*segno* \* 2^(*esponente+offset*) \* 1.*mantissa* 
			Esempio: 1 010 1011 = 
				-1 \^ 1 \* 2^(2+0) \* 1.1011
[[str]]

[[bool]]

**[[Contenitori]]**
# Variabili
In Python i nomi delle variabili si riferiscono ad un indice nel *namespace* che punta al blocco di memoria associato all’oggetto rappresentato dalla variabile
	Questo perché in Python le variabili possono cambiare tipo
	In un linguaggio a variabili con tipo fisso come C le variabili puntano direttamente allo spazio nella memoria che rappresenta l’oggetto
Per cambiare il tipo di una variabile si usa l’operazione di assegnazione `=`
	Così facendo però l’oggetto assegnato precedentemente viene eliminato dalla *garbage collection*
È possibile accedere all’indirizzo nella memoria di un oggetto tramite la funzione `id()`
	Utile per verificare se due variabili si riferiscono allo stesso oggetto
		Altrimenti si può utilizzare l’operatore `is`
			Es. `print(A is B)` > `True` oppure `False`
Per verificare se due variabili contengono le stesse informazioni si utilizza l’operatore `==`
Per convertire una variabile da un tipo ad un’altro si usano le funzioni con nome del tipo
	Es. `int(var), str(var), float(var)` ecc.
	Provare a convertire una variabile ad un tipo incompatibile risulta in un `ValueError`
	La funzione `int()` accetta la base della variabile inserita come parametro
		Es. `print(int(“101”, 2))` > `5`		
È possibile eseguire un’espressione e assegnare il suo risultato ad una variabile allo stesso tempo con l’operatore `:=` (walrus)
	Esempio: `A = (espressione := 2*3) * 4`
### Tipi
In Python il tipo di una variabile è la classe che sarà poi utilizzata nella creazione dell’oggetto assegnato alla variabile
	`list, tuple, str...`
In Python quando si assegna una variabile **non è** necessario specificare il tipo di dato della variabile
	Questo rende il codice meno ottimizzato, dato che la macchina non sa esattamente quanta memoria allocare per ogni variabile
È però anche possibile assegnare il tipo di un oggetto **manualmente**:
	Per le variabili:`var : tipo = valore`
		Oppure `var = valore # type : tipo`
		Con i contenitori è possibile specificare il tipo dei contenuti:
			`list[tipo_contenuto]`
			`dict[tipo_chiave, tipo_valore]`
			`set[tipo_contenuto]`
			`tuple[tipo_indice0, tipo_indice1,...]`
			`tuple[tipo_contenuto,...]` per specificare il tipo di ogni oggetto della tupla
	Per le funzioni: `def funzione(arg1 : tipo1,...) -> return_type:`
		Oppure `def funzione(arg1,...):`
				`type:(tipo1,...) -> return_type`
		I tipi sono salvati nell’attributo `__annotations__` della funzione
	Questo renderà il codice più veloce e ci permette di identificare molti errori ad assegnamento che altrimenti sarebbero stati identificati solo a runtime
Il modulo [`typing`](Moduli) contiene tipi aggiuntivi

**Come scegliere i nomi delle variabili**
- Usa nomi descrittivi
- Usa nomi facili da ricordare

### [[Errori]]
### [[Funzioni base]]

### [[Operatori di confronto]]

### [[Operatori logici]]
# Operazioni matematiche
<sub>Presenti ulteriori operazioni nella libreria *math*</sub>

**//**:
	Divisione intera (solo parte intera del risultato)
**/**:
	Divisione normale (produce sempre un float)
**%**:
	Resto della divisione intera
\*\*:
	Potenza

# Oggetti
In Python tutti i dati sono oggetti
Gli oggetti sono **gruppi di informazioni coerenti** (attributi) *e* **tutte le operazioni che si possono eseguire su di esso** (metodi)
	Es.
	Le stringhe:
	- Hanno lunghezza, contenuti ecc.
	- Hanno operazioni utilizzabili su di esse (es. `.split()`)	
### Metodi
Sintassi: `oggetto.metodo(argomenti)`

# [[Moduli]]
Per caricare in un programma funzionalità da un’altro file si usa `import modulo`
	Per utilizzare una funzione o una variabile da un modulo si usa
		`import modulo`
		`modulo.funzione(argomenti)`
		`modulo.variabile`
	Oppure
		`from modulo import funzione`
		`funzione(argomenti)`
		In questo modo la funzione può essere utilizzata come una funzione definita nel file stesso
			Se una funzione importata ha lo stesso nome di una funzione già esistente la funzione definita prima sarà sovrascritta
		Si può usare `from modulo import *` per importare tutte le funzioni di un modulo, ma non è consigliato per evitare collisioni

# [[Funzioni (Python)]]
### Funzioni default
- `min()`
	Accetta parametro `key=`
		Calcolato *prima* di tornare il risultato
- `max()`
	Accetta parametro `key=`
		Calcolato *prima* di tornare il risultato
- `sum()`
- `isinstance(variabile, tipo)`
	Torna `True` se `type(variabile) == tipo`
# [[Gestione errori]]

# [[Risoluzione dei problemi]]
# [[Tempo di esecuzione]]
# [[Shortcut]]
# [[File handling]]