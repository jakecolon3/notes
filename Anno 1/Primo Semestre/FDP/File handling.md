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
	`with open(filename...) as nome_variabile:`
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
	Legge solo la riga corrente (incluso \n)
- `file.readlines()`
	Torna una lista di tutte (fino al punto specificato) le righe del file
	Terminano con `\n` tranne forse l’ultima
## Scrittura file
E' possibile scrivere in un file con il metodo `.write()`
	Oppure con `print("str", file=file)`
### File come generatori di righe
Dato che i file sono letti riga per riga possono essere usati come un generatore per risparmiare memoria
### Trovare parole in un file di testo
Per trovare le parole all'interno di un file di testo è necessario modificarne il contenuto in modo tale da poter utilizzare i metodi delle stringhe
	Per esempio rimuovere tutti i caratteri non alfabetici o trasformare tutte le parole in minuscole
	Possibili considerazioni sono parole interrotte da newline e apostrofi ("l'albero")
### Trovare il file "più importante"
Una parola che appare spesso *nello stesso file* ma poco in altri file è "interessante"
	Questo tipo di ricerca si chiama "term frequency-inverse document frequency" ([tf-idf](https://en.wikipedia.org/wiki/tf-idf))
## File `JSON`
I file JSON sono file di testo con sintassi semplificata per rappresentare principalmente dizionari e liste
Il modulo `json` semplifica la letture di questi file:
	`json.load(file.json)` legge il file e ne trasforma i contenuti nelle strutture dati di Python
	`json.loads(str)` legge da una *stringa* in formato JSON
	`json.dump(obj[dict, list, ?], file_in_modalità_scrittura` scrive nel file in formato JSON
Nei file JSON:
- Non si possono aggiungere commenti (usare file `jsonc`)
- Non ci sono virgole alla fine delle liste o dizionari
- Le chiavi devono essere semplici (str, int, float, none, bool)
- Si devono usare i doppi apici `"`
- Non si possono usare tuple
## File `YAML`
Un altro formato per rappresentare contenitori nidificati
Ogni elemento è identificato da un trattino `-`
Le stringhe non devono essere racchiuse da apici
Per interagire con questo formato si può usare il modulo `yaml`
	Per leggere si usa `yaml.safe_load(file[file_object])` (funziona su file e str)
	Per scrivere si usa `yaml.dump(obj[dict, list, etc], file[file_object])`
In YAML `True alias on, False alias off, None alias ~, null`
## Richieste dal web
Per interagire con contenuti dal web si può utilizzare (tra altre) la libreria `requests`
Permette di mandare richieste di tipo `GET` e `POST` con parametri
	Torna uno status code e decodifica il testo html o json
`requests.get(url)` torna un oggetto con diversi attributi:
- `.status_code` = codice fornito
- `.text` = testo del sito (se presente)
- `.content` contenuto del file se è un file binari (es. immagine)
C'è anche il metodo `.json()` sugli oggetti forniti da requests che decodifica i file json
E' possibile fornire parametri alle richieste GET di requests con l'argomento `params=dict`
	Per passare parametri ad altre richieste (tipo POST) si deve usare `data=dict`

# Percorsi
Nei sistemi UNIX i percorsi sono del tipo `dir/dir_o_file`
	In Windows si usa `\` invece di `/`

# Errori
- `FileNotFoundError`
- `FileExistsError`
	Se provo a creare un file che già esiste
- `PermissionError`
- `NotADirectoryError`
	Se si usa `os.listdir()` su un file invece che una directory

# [[Immagini]]
