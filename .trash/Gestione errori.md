# try
Per gestire errori nel codice si può usare try:
Sintassi:
	`try:`
		`codice che potrebbe dare errore`
	`except NomeDellaClasseDellErrore as E:`
		`codice da eseguire se è presente quell’errore`
	`finally:` (opzionale)
		`codice da eseguire dopo tutti gli except`
			`finally` esegue anche se c’è un errore non catturato
# Lanciare errori
Per **creare** un errore si possono usare:
- `raise`
	Sintassi: `raise ClasseDellErrore(messaggio_di_errore)`
- `assert`
	Sintassi: `assert condizione, messaggio_di_errore`
		Può dare solo `AssertionError`
			Lancia errore solo se la condizione è falsa