Per interagire con i file salvati su disco bisogna prima aprirli tramite `os.open()` per preparare le strutture dati necessarie
In questo modo il programma prende il primo blocco di dati dal file e lo inserisce nella memoria (buffer)
A mano a mano che si legge il file il programma rilascia e inserisce i diversi blocchi di dati del file
# Funzione `open()`
Sintassi:
	`from os import open`
	`open(filename, mode, encoding)`
### `filename`
Indica il percorso del file da aprire
Come default `open()` cerca nella directory corrente (di esecuzione dello script)
È possibile specificare una directory
	- Su Windows le directory sono separate da `\`
		`<Lettera drive>:\\...` cerca dalla radice del drive
		Python interpreta correttamente anche `/`
		Preferibile perché `\` è un escape character, quindi in Python bisogna scrivere `\\`
	- In altri OS sono separate da `/`
		`/...` parte dalla radice dell’albero delle directory
### `mode`
Specifica la modalità di apertura del file
	Se è un file di testo i dati devono essere preparati in modo diverso da un file contenente dati binari (mp3, png ecc)
La modalità di apertura è una stringa di 1 o due caratteri
Il primo carattere è tra
- `’r’`
	Modalità di lettura (default)
- `’w’`
	Modalità di scrittura
	Se si sta modificando un file di testo **non** aggiunge `\n` automaticamente come fa `print()`
	Un alternativa è `print(str, file=file_aperto)`
- `’a’`
	Aggiunge nuovo contenuto al file
- `’x’`
	Crea un nuovo file e da errore se esiste già
Il secondo carattere è tra
- `’t’`
	Il file è aperto in modalità testo (default)
	Il contenuto è interpretato come caratteri
- `’b’`
	Il file è aperto in modalità binaria
	Il contenuto **non** è interpretato automaticamente
- `’+’`
	Per leggere e modificare il file
### `encoding`
Specifica la codifica del testo del file specificato
Il default è `utf-8` (Unicode)
	È meglio specificarlo in caso di sistemi operativi diversi
Altre codifiche
- `’latin’`
- `’ascii’`
- `’cp1252’`
	Default di Windows
`open(filename)` di default apre il file con l’encoding default del sistema operativo corrente

Dopo aver aperto un file il file *va chiuso* per rilasciare la memoria utilizzata **e finalizzare le operazioni di scrittura** con `oggetto_file.close()`, oppure utilizzare:
# `with... as`
Sintassi:
	`with open(filename...) as variabile:`
		`codice`
Questa funzione apre un file e lo chiude **anche in caso di errore**
	È quindi preferibile ad usare direttamente `open()` e `close()`
# Metodo `.seek()`
Sintassi:
	`file.seek(carattere)`
I file si comportano come un “nastro”: una volta letto un blocco di contenuto non è più possibile leggerlo
Con questo metodo è possibile spostarsi all’interno del file (per esempio all’inizio)
	Nei file di testo è utile solo per tornare all’inizio dato che non è garantito che ogni riga ha lo stesso numero di caratteri
# Lettura file
###### **Nota**: caratteri newline
- Windows: `\r\n`
	Python in lettura converte i newline di Windows in soli `\n` automaticamente
- Altri: `\n`
	Utilizza sempre questo in scrittura

È possibile leggere i file con:
- `file.read()`
	Legge tutto il file (o fino al punto specificato)
- `file.readline()`
	Legge solo la riga corrente
- `file.readlines()`
	Torna una lista di tutte (fino al punto specificato) le righe del file
	Terminano con `\n` apparte forse l’ultima
### File come generatori di righe
Dato che i file sono letti riga per riga possono essere usati come un generatore per risparmiare memoria