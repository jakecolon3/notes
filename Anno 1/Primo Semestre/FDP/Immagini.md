Le immagini (per la maggior parte) sono *griglie rettangolari di pixel*
	Ogni pixel ha una coordinata (x,y) e un valore che ne rappresenta il colore
		Il formato di colore più comune è RGB: 3 valori da 0 a 255 che indicano la luminosità di ogni colore
			Un'altro formato comune è RGBa per i png con trasparenza
Ogni pixel codificato in RGB occupa 1 byte = 8 bit
Noi lavoreremo su immagini di formato `png` senza trasparenza

# Immagini in Python
In Python possiamo rappresentare le immagini come **matrici**, cioè *liste di liste*
	La lista esterna è l'immagine, che contiene liste di *righe* di pixel
	Tutte le righe devono avere la stessa lunghezza
E' possibile accedere alle matrici con `matrice[y][x]` con y = riga, x = colonna

#### Nota: shallow copy
Provare a creare un immagine monocolore con 
	`riga = [colore] * lunghezza`
	`img = riga * colonna`
Non funziona, dato che in questo modo ogni riga *non è* una lista unica, ma un riferimento alla stessa lista
	Il modo corretto di farlo è utilizzare un `for` nidificato o una comprehension

## Modificare file immagini
Per salvare/caricare immagini su disco useremo la libreria `images`, che trasforma i file di immagini in matrici
Utilizzo:
- `images.save(list[list[Pixel]], filename: str)` per salvare immagini
- `images.load(filename: str)` per aprire immagini

