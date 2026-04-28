I dizionari sono contenitori che accettano *coppie* di valori di tipo:
	chiave unica: valore
Tengono conto dell’ordine di assegnazione dei contenuti
	Se si cambia il valore di una chiave manterrà la stessa posizione relativa agli altri oggetti
Funzionano come liste ma usano le chiavi al posto degli indici

# Accedere ad un dizionario
Per accedere ad un valore di un dizionario si usa:
	`dict[key]`
	La chiave può essere qualsiasi tipo di dato
	È possibile aggiungere valori ad un dizionario in questo modo:
		`dict[key] = [value]`
	Provando ad accedere ad un dizionario con una chiave inesistente produce l’errore `KeyError`
	Si può utilizzare `in` per controllare se una chiave è presente in un dizionario
		Es.
		`key in dict` (Risponde con un boolean)
# Metodi
### .keys()
Crea un oggetto che comprende tutte le chiavi nel dizionario
È un generatore: Python crea i suoi contenuti solo quando glielo chiedo
	Quindi se lo uso in un loop `for` creerà gli oggetti solo quando il `for` li richiede
	Questo risparmia memoria
### .values()
Identico a .keys() ma per i valori del dizionario
### .items()
Crea un oggetto che comprende tutte le coppie `(chiave, valore)` nel dizionario
### .popitem()
Legge l’ultima coppia chiave/valore e la rimuove
### dict1 | dict2
crea un nuovo dizionario con tutte le coppie di `dict1` e `dict2`
### .update(dict)
Modifica il primo dizionario aggiungendo tutte le nuove coppie dal secondo dizionario e aggiornando le chiavi già presenti con i valori del secondo dizionario
### .get(key, default)
Accede al valore associato alla chiave specificata, o torna il valore di default se la chiave non è presente
### .pop(key, default)
Torna il valore della chiave e la rimuove se è presente, altrimenti torna il valore di default
### .fromkeys(keys, value)
Costruisce un dizionario con le chiavi fornite (`keys` è un contenitore), tutte associate allo stesso valore