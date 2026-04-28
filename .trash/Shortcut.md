# List comprehension
Modo di creare liste con i loop `for`
Shortcut per creare una lista vuota e aggiungerci valori con `for`
### Sintassi
`[espressione(elemento) for elemento in contenitore]`
	$lista =\{espressione\  \forall \ elemento\in\ contenitore\}$
	Funziona anche per insiemi
		`{espressione(elemento) for elemento in contenitore}`
	E per dizionari
		`{espressione(elemento): espressione2(elemento) for elemento in contenitore}`
	E anche per le tuple
		`tuple(espressione(elemento) for elemento in contenitore)`
È possibile anche **aggiungere condizioni**
	`[espressione(elemento) for elemento in contenitore if condizione]`
	Aggiungerà l’elemento trasformato solo se la condizione è soddisfatta
È anche possibile **costruire `for` nidificati**
	`[espressione(elemento1, elemento2) for elemento in contenitore1 for elemento in contenitore2]`
		Se si aggiunge una condizione dopo il secondo `for` sarà calcolato dopo entrambi, se è inserito tra i `for` il secondo `for` sarà eseguito solo se la condizione è soddisfatta
E **contenitori nidificati**
	`[[espressione(elemento) for elemento1 in contenitore1] for elemento2 in contenitore2]`
		Crea liste con un numero di elementi basato su `contenitore1` **per ogni elemento** di contenitore 2, tutto racchiuso in una lista
# Operatore walrus `:=`
È possibile eseguire un’espressione e assegnare il suo risultato ad una variabile allo stesso tempo con l’operatore `:=` (walrus)
	Esempio: `A = (espressione := 2*3) * 4`
# Espressioni condizionate
Sono espressioni che hanno 2 valori diversi a seconda della condizione
Sintassi:
	`A = x if condizione1 else y`
