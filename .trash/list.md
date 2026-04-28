Le liste sono contenitori indicizzati, ordinati e modificabili
Sono accessibili in questo modo:
	`list[index]`
Quando si elimina un elemento di una lista tutti gli elementi successivi devono ”fare un passo a sinistra”; questa operazione può essere molto costosa in base a quale elemento eliminiamo
	Una conseguenza di questo è che se eliminiamo un elemento di una lista mentre la stiamo scandendo per indici:
		1. Saltiamo l’elemento immediatamente successivo all’elemento eliminato
		2. Ora l’indice in ultima posizione sarà `lunghezza lista - 2` invece che `lunghezza lista - 1`
	Per evitare questi problemi possiamo scandire la lista dalla fine, creare una nuova lista escludendo solo gli elementi indesiderati, o scandendo una copia della lista che non modifichiamo
# Metodi
**.insert(indice, elemento)**
	Inserisce un elemento nella lista all’indice fornito
	Se si fornisce un indice troppo grande inserisce l’elemento alla fine della lista
**.pop(i)**
	Legge e rimuove l’elemento con indice fornito, o l’ultimo elemento della lista se non è fornito un indice
	Errore se la lista è vuota o l’indice non esiste
**.remove(elemento)**
	Elimina la *prima occorrenza* dell’elemento
	Errore se non è presente
**.index(elemento)**
	Trova il primo indice in cui c’è l’elemento
	Errore se non è presente
**.append(elemento)**
**.count(elemento)**
	Conta quante volte l’elemento è presente nella lista
**.reverse()**
	Rovescia la lista in modo distruttivo
		Quindi cambia il contenuto della lista
**.sort()**
	Ordina la lista in modo distruttivo
	Si può specificare l’ordinamento
	Gli elementi devono essere confrontabili
		Es. se una lista contiene stringhe e interi risulta errore
