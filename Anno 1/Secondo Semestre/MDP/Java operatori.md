Gli operatori in Java sono divisi in gruppi:
# Operatori aritmetici
- `+`
	Addizione tra numeri e variabili
	Concatenazione di stringhe
		Non funziona tra `char`: li tratta come l'intero corrispondente al loro codice ASCII
- `-`
- `*`
- `/`
	Divisione
	Dividere 2 interi torna un intero, non c'è l'operatore di divisione intera
- `%`
- `++`
- `--`
	Incrementa/diminuisce una variabile di 1
	Utilizzabili sia prima che dopo la variabile: `i++ == ++i`*
		* Hanno funzionamento leggermente diverso:
		- Pre-incremento:
			Incrementa la variabile *prima* di usarla
		- Post-incremento:
			Incrementa la variabile *dopo* averla usata
Sintassi:
	`myVar = 1;`
	`++myVar;  // 2`
	`--myVar;  // 1`
Non c'è un operatore per esponenziare

# Operatori di assegnamento
- `=`
- `+=`
- `-=`
- Ecc.
	Funzionano come in Python
	Esistono anche per operatori logici e bitwise

# Operatori di comparazione
- `==`
- `!=`
- `>`
- Ecc.
Stessi di Python

# Operatori logici
- `&&`
	And
- `||`
	Or
- `!`
	Not

# Operatori bitwise