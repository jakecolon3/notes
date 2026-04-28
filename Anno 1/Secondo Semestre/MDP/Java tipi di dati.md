In Java ci sono 2 gruppi di tipi di dati:
# Tipi di dati "primitivi"
### Interi
- `byte`
	Può contenere valori *interi* da -128 a 127 (± 2^7)
- `short`
	Può contenere valori *interi* da -32768 a 32767 (± 2^15)
- `int`
	Può contenere valori *interi* da -2147483648 a 2147483647 (± 2^31)
- `long`
	Può contenere valori *interi* da -2^63 a +(2^63 - 1)
		Si deve aggiungere una `l` o `L` alla fine del numero quando si assegna il valore alla variabile
Si può aggiungere il prefisso `0b` per definire un intero dalla sua rappresentazione binaria (ex.: `0b101 // = 5`)
Si può aggiungere il prefisso `0` per definire un intero dalla sua rappresentazione in ottale (base 8)
### Fratti
- `float`
	Può contenere valori *fratti* con 6-7 cifre decimali di precisione
		Si deve aggiungere una `f` o `F` alla fine del numero quando si assegna il valore alla variabile
		Si può usare la notazione scientifica (ex.: `12e2f`)
- `double`
	Può contenere valori *fratti* con ~16 cifre decimali di precisione
		Si deve aggiungere una `d` alla fine del numero quando si assegna il valore alla variabile
		Si può usare la notazione scientifica (ex.: `21E5d`)
### Altri
- `boolean`
- `char`
	Accettano anche valori interi, interpretati come codici ASCII

# Tipi di dati "non-primitivi"
- [[Java stringhe|Stringhe]]
- Liste
- Classi
Detti "tipi di riferimento" perché si riferiscono a *oggetti*
Più o meno equivalenti alle classi in Python: sono tipi di dati creati dal programmatore
Al contrario dei primitivi, hanno metodi che possono essere chiamati
Contengono sempre un valore, non possono essere nulli
### Le variabili hanno tipi fissi
Una volta dichiarata una variabile, non è possibile cambiarne il tipo\*
### \*Type casting
Per convertire un tipo di dato in un'altro si usa il "type casting":
- Widening casting
	Converte un tipo più piccolo ad un tipo più grande
	È automatico
		Esempio:
		`int myInt = 2;`
		`double myDouble = myInt;  // myDouble è un double`
- Narrowing casting
	Converte un tipo più ampio ad un tipo più piccolo
	Specificato manualmente
		Esempio:
		`double myDouble = 9.78d;`
		`int myInt = (int) myDouble;  // myInt è un intero (prende solo la parte intera di myDouble)`

## Oggetti
### Campi
Quando un oggetto viene creato, i suoi campi sono inizializzati automaticamente a valori di default (di solito la rappresentazione di 0 per il tipo di dato del campo)
	Questo non accade per variabili definite nel `main`