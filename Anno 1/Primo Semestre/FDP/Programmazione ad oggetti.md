# Oggetti
Abbiamo visto che in Python i tipi di dati sono *oggetti*, vediamo ora cosa significa:
Un oggetto è una fusione di:
- Attributi
	Caratteristiche
- Metodi
	Funzionalità, sono funzioni che "appartengono" all'oggetto

# Classi
Gli oggetti sono creati a partire dalle *classi*, che definiscono gli attributi (ma non necessariamente i loro valori) e i metodi che un oggetto può avere

# Sintassi
Per creare una classe:
	`class NomeDellaClasse (EstendendoLaClasse):`
		`# I metodi e gli attributi di una classe devono essere indentati nello statement class`
		`attributo_di_classe = valore`
		`...`
		`# È sempre necessario: (inizializza gli attributi dell'istanza)`
		`def __init__(self, args):`
			`# Si possono assegnare attributi individuali all'istanza (usando gli argomenti di __init__)`
			`self.attributo_individuale = valore1`
		`def metodo(self, args):`
			`codice`
Per creare un istanza di una classe:
	`nome_istanza = Classe(__init__args)`
	Solo dopo aver completato lo statement `class`
Per eseguire il metodo di un istanza:
	`nome_istanza.metodo(args)`

### Metodi speciali
Per convenzione i metodi e attributi che iniziano per `_` o `__` sono privati
	In Python si possono leggere comunque, ma i linguaggi compilati non lo permettono
	Si utilizza comunque questa convenzione per indicare metodi e attributi che non devono essere utilizzati (per esempio potrebbero cambiare con aggiornamento)
In Python ci sono alcuni metodi speciali, che sono interpretati in modo particolare:
- `__add__` viene chiamato quando si usa l'oggetto in operazioni di addizione
- `__sub__` viene chiamato quando si usa l'oggetto in operazioni di sottrazione
- `__repr__` viene chiamato quando si stampa l'oggetto
- ecc. (vedi slide)
- Statement `@classmethod`
	Informo Python che il metodo definito sotto è un metodo della classe e non dell'istanza
	Il metodo prenderà `cls` come argomento al posto di `self`

## Come programmare con classi e oggetti
- Individua i tipi di dati necessari (classi)
- Individua gli attributi delle classi
	Individua se sono necessari attributi di classe (costanti a tutte le istanze)
- Definisci l'inizializzazione della classe
- Definire i metodi fondamentali

# Ereditarietà
Se ci sono diverse classi che hanno funzionalità simili si può creare una *superclasse* e estenderla con diverse sottoclassi
Queste sottoclassi "ereditano" i metodi e gli attributi della superclasse:
	Per chiamare i metodi della superclasse:
	`Oggetto.super().metodo(argomenti)`
