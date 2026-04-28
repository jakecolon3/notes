È possibile usare le funzioni come oggetti, come abbiamo visto per il parametro `key=`
Sintassi (basta usare l’argomento funzione come funzione da applicare):
	`def applica_funzione(funzione, valore):`
		`return funzione(valore)`
### Funzione `map()`
Sintassi:
	`map(funzione, cont1, cont2...)`
Applica la funzione fornita ad ogni contenitore fornito e torna una lista con i valori trasformati
### Funzione `filter()`
Sintassi:
	`filter(selettore: func, contenitore)`
Applica una funzione che torna `True` o `False` ad ogni elemento del contenitore e torna un generatore di elementi che tornano `True` quando inseriti nella funzione `selettore`
	Alternativa a 
	`risultato: list = []`
	`for elemento in contenitore:`
		`if selettore(elemento):`
			`risultato.append(elemento)`
### Funzione `all()`
Sintassi:
	`all(contenitore_di_bool)`
Torna `contenitore_di_bool[0] and contenitore_di_bool[1]...`
	Non si ferma quando incontra un `False`
	Un modo di utilizzarlo e fornire come argomento una `map(func, cont)` con una funzione che torna un `bool`
### Funzione `any()`
Sintassi:
	`any(contenitore_di_bool)`
Torna `contenitore_di_bool[0] or contenitore_di_bool[1]...`
	Non si ferma quando incontra un `True`
	