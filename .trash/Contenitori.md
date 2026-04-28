Tengono conto della posizione dei dati contenuti
	È possibile accedere ad un dato in una certa posizione usando `[index]`
		Es. `var = “123” print(var[1])` > `2`
		Sono accettati indici negativi
	Si può accedere ad un blocco di dati usando l’operatore *slice* `:`
		Esclude l’estremo destro
			Es. `print(var[1:3])` > `23`
		Se si tralascia l’indice a destra o sinistra dello *slice* includerà gli elementi fino alla fine o inizio del contenitore
			Es. `print(var[1:])` > `23`
		Non ritorna `IndexError` se si usa uno slice con indice più grande del contenitore
		Ritorna `IndexError` se si 
		Aggiungendo un ulteriore `:` si può specificare la grandezza degli step tra gli elementi
		Si possono assegnare valori ai contenitori modificabili con gli slice: `lista[x:y:incremento] = contenitore`
			Se il contenitore è vuoto gli elementi dello slice saranno eliminati
			Se l’incremento > 1 il contenitore deve avere la stessa quantità di elementi degli elementi da rimpiazzare
			L’assegnamento a slice di tipo `[x:x]` *inserisce* nella posizione `x` senza rimpiazzare alcun elemento
Un contenitore vuoto vale `False`, se invece ha almeno un valore vale `True`
# Metodi
### .index()
Risponde con l’indice dell’elemento inserito nel contenitore
### .pop()
Legge un elemento del contenitore e lo rimuove

### [[str]]
### [[list]]
Indicizzato, modificabile, ordinato
### [[dict]]
Ordinato, modificabile
### [[tuple]]
Indicizzato, non modificabile, ordinato
### [[set]]
Non indicizzato, modificabile, ordine non fisso
Non accettano elementi modificabili (es. liste)

# Packing e unpacking
Sono un tipo di assegnamento multiplo 
### Packing
Quando si utilizza un assegnamento multiplo il numero di variabili da assegnare deve essere lo stesso dei valori assegnati
Per evitare errori si può utilizzare il packing:
`A, B, *C = [1, 2, 3, 4, 5, 6]`
	Così facendo tutti i valori che non “entrano” nelle variabili saranno inserite (packed) nella variabile con `*`
	`A = 1, B = 2, C = [3, 4, 5, 6]`

La variabile ”packed“ può essere in qualsiasi posizione nell’elenco delle variabili da assegnare
	Le variabili normali prenderanno gli elementi corrispondenti alla loro posizione nella lista, la variabile packed prenderà tutto il resto

È permessa **solo una** variabile packed in un’assegnazione.
### Unpacking
È possibile “spacchettare” variabili all’interno di altre espressioni:
	Avviene quando si calcola il valore dell’espressione
`A = 1, 2`
`B = 3, *A, 4`
`print(B): 3, 1, 2, 4`

In generale il packing avviene *a sinistra* di un assegnamento, l’unpacking *a destra* di un assegnamento

# Funzione `sorted()`
Abbiamo visto che possiamo usare `.sort()` per ordinare alcuni tipi di contenitori, ma non funziona per tutti

Possiamo invece usare `sorted(contenitore, argomenti)`
	Genera una nuova lista con gli elementi del contenitore ordinati
	Gli elementi della lista devono essere confrontabili tra di loro
	Ordine in ordine crescente per il tipo di dato dell’elemento
	L’ordinamento è stabile
	*Accetta tuple*, crea una lista in base alla tupla fornita

Se vogliamo un ordinamento più complesso possiamo trasformare gli elementi del contenitore in una coppia
	Es.
	Per ordinare una lista di stringhe di tipo `”uno”, “due”…` per lunghezza delle parole e ordine alfabetico se la lunghezza è uguale possiamo creare una coppia di tipo `(len(elemento), elemento)`, aggiungerle ad una lista e ordinarla
		Questo caso particolare è detto “trasformazione di Schwartz”
	Questo funziona perché le coppie sono ordinate **in base al primo elemento**, il secondo elemento è analizzato solo *in caso di parità*
	Se vogliamo mantenere l’ordine relativo (avere quindi un ordinamento stabile) di oggetti identici (es. “tre”, “tre”), possiamo aggiungere l’indice dell’oggetto alla tupla
### Parametro `key=`
Il parametro `key` (assegnato per nome) accetta una funzione da applicare ad ogni elemento del contenitore prima dell’ordinamento
	Es.
	`def trasforma_elemento(parola)`
		`return len(parola),parola` \# trasforma ogni elemento in una coppia
	`sorted(lista, key=trasforma_elemento)`
	ordinerà gli elementi di `lista` prima per lunghezza della parola e poi per ordine alfabetico
### Ordinamenti contrapposti
Se qualcosa richiede un ordinamento in direzioni opposte si può rovesciare il numero di uno degli elementi della tupla per ordinarli al contrario
	Se non puoi rovesciare l’elemento skill issue

# Funzione `zip(args, strict=False)`
Sintassi: `zip(cont1, cont2,…)`
Torna un generatore di tuple che contengono **l’elemento i-esimo** di ogni contenitore
Si ferma quando 1 contenitore è esaurito (avrà quindi la stessa lunghezza del contenitore più corte)
	Con il parametro `strict=True` lancia un errore se i contenitori non sono della stessa lunghezza

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