### input()
Ferma il programma e richiede un input da tastiera
Ritorna sempre una stringa

### Funzioni tipo
**int(), str(), float()** ecc.
Ritornano `TypeError` con input incompatibili

### len()
Accetta contenitori (`str`, `list`, `dict`, `tuple`)

### help()
Ritorna informazioni sull’input
Se è un oggetto base di Python ritorna i metodi disponibili per quell’oggetto

### enumerate()
Accetta contenitori
È un generatore
Genera diverse tuple `(indice, valore)` per ogni coppia (indice, valore) in un contenitore
	Più precisamente incrementa il valore dell’indice per ogni call che riceve; per questo è possibile utilizzarlo anche per gli insiemi