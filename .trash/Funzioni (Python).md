### Sintassi:
`def nome_funzione(argomenti):`
`’’’docstring che genera help(nome_funzione)’’’`
	`istruzioni che calcolano il risultato`
	`return risultato`
Usare sempre nomi descrittivi per le funzioni

Se una funzione non contiene un `return`, darà come risultato `None`
	Funzioni di questo tipo sono dette anche **procedure**
### Argomenti di una funzione
Gli argomenti che scrivo nella **definizione** della funzione sono detti **parametri formali**, e contengono i dati che la funzione riceve
Gli argomenti che si utilizzano quando la funzione è eseguita sono detti **parametri attuali**
	Per evitare confusione è meglio usare nomi diversi per i parametri attuali e formali

Gli argomenti formali possono essere:
- Obbligatori, posizionali
	Riconosciuti dalla posizione nell’elenco degli argomenti
		Possibile anche assegnarli per nome
	**Devono** essere tutti presenti quando si chiama la funzione
	Sintassi: `def funzione(nome_argomento)`
	Esecuzione: `funzione(parametro_attuale)`
- Opzionali
	Hanno un valore di default
		Creati al ***momento della definizione*** della funzione
			Se il valore di default è un oggetto mutabile potrebbero esserci *comportamenti inaspettati* con chiamate consecutive della funzione se lo si modifica
				Quindi è consigliato usare un valore immutabile (come `None`) per valori di default
	Riconosciuti per nome e per posizione
	Sintassi: `def funzione(nome_argomento = valore_di_default)`
	Esecuzione: `funzione()` oppure `funzione(parametro_attuale)` oppure `funzione(nome_argomento = parametro_attuale)` (ignora posizione)
	

### Variabili locali
Ogni esecuzione della funzione genera *un nuovo namespace* contenente le **variabili locali della funzione**, create quando la funzione è eseguita, non quando è definita
	Le funzioni possono quindi anche chiamare se stesse
Le variabili locali sono rilasciate quando la funzione termina la sua esecuzione, ma è possibile mantenere i loro valori tramite `return`
	Solo le associazioni `nome_variabile_locale = valore` sono eliminate dal garbage collector

### Scrivere una funzione efficiente
Per capire come risolvere un problema:
	Dividilo in problemi più piccoli
	Considera i possibili modi di risolverlo
	Scegli quello più efficiente
		Evita creazione di tanti oggetti
		Evita tanti 

# Namespace
Il namespace di Python è suddiviso in “livelli”:
- Built-in
	Contiene tutte le variabili e funzioni base dell’interprete Python
- Globale
	Oggetti definiti nel programma principale
	Moduli importati
- Modulo
	Oggetti definiti nel modulo importato
- Locale
	Oggetti definiti all’interno della funzione in esecuzione
	Parametri formali
	Questo namespace è disallocato al termine dell’esecuzione della funzione

Python cerca dal basso verso l’altro
	Quindi se esiste una variabile locale con lo stesso nome di una variabile globale, nell’esecuzione della funzione Python utilizzerà la variabile locale
	Ordine *LEGB*
		Local, Enclosing, Global, Builtin

È possibile modificare variabili globali all’interno di una funzione con la keyword `global`
	Ha utilizzi ma spesso è meglio evitare, crea effetti collaterali non ovvi

Se un’argomento di una funzione è un oggetto modificato dalla funzione, il contenuto dell’oggetto sarà modificato anche **nel programma principale**
Questo tipo di effetto collaterale è sconsigliato dato che ha effetti *non ovvi* sul programma
Per tornare informazioni al programma principale è meglio usare `return`
### `return`

# Espressioni `lambda`
Dette anche “*funzioni anonime*”, sono funzioni calcolate una sola volta
Sono comode ma rendono il codice meno leggibile
### Sintassi
`lambda argomenti: espressione`
	Equivalente a `def funzione(argomenti): return(espressione)`
	Meglio `(espressione)` se usata in `sorted()`
		Se `espressione` torna una tupla `sorted` potrebbe interpretare gli elementi della tupla come parametri
Possono essere assegnate a variabili
# Funzioni locali
In Python è possibile definire una funzione all’interno di un’altra funzione
	Questo perché le funzioni sono semplicemente oggetti assegnate alla variabile che il nome inserito nella definizione della funzione
Queste funzioni possono utilizzare sia i propri parametri che *i parametri della funzione esterna*, ma sono utilizzabili **solo** all’interno della funzione esterna
# [[Programmazione funzionale]]
