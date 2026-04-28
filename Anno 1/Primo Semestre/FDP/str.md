In Python (e Java) *non sono modificabili* per motivi di ottimizzazione dell’interprete
Quindi per modificare testo Python crea un nuovo oggetto; fortunatamente Python ottimizza l’utilizzo della memoria eliminando le str non utilizzate tramite la *garbage collection*
Le `str` sono codificate in **UNICODE**
	Precedentemente lo standard di codifica per il testo era *ASCII*, in 7 bit
	UNICODE ha più bit: le `str` in Python accettano qualsiasi carattere
Le `str` vanno racchiuse tra “ o ‘ (doppi o singoli apici)
	Devono essere chiuse dallo stesso carattere che le ha aperte
	Se si vuole usare “ o ‘ nelle `str` bisogna inserire \ prima del carattere desiderato
Le `str`, essendo successioni di caratteri, tengono conto della posizione dei caratteri
	Il primo elemento è posizione `0`
	Per accedere al carattere di una `str` “string” in una posizione specifica si usa: `string[numero]`
	Usando `list(stringa)` si ottiene una lista con tutti i singoli caratteri della stringa
	Usando `set(stringa)` si ottiene un insieme con tutti i caratteri unici della stringa
Si può accedere al codice UNICODE di una `str` usando la funzione `ord()`
	La funzione inversa di `ord()` è `chr()`
È possibile concatenare `str` con l’operatore `+`
È possibile moltiplicare `str` per un `int`
	Es. `“ciao” * 2` = `“ciaociao”`
Si possono scrivere `str` a più righe usando tre volte l’apice o doppio apice
	Es. `“””testo
		   `qua”””`

**Caratteri particolari**
	`\n`: nuova linea
	`\t`: tab
	`\`: override
		Es. `print(“a\\b”)` > `a\b`

# Metodi
**.split(separatore)**
	Senza specificare parametri la `str` si spezza agli spazi, accapo e tab
**.upper() e .lower()**
	Ritorna una `str` identica all’input ma con tutti caratteri maiuscoli o minuscoli
**.join(lista_di_stringhe)**
	Crea una stringa che contiene le stringhe nell’argomento separate dalla stringa a cui applico il metodo
**.islower(), .isupper(), .isalpha(), .isnumeric()**
	Rispondono con `True` se la condizione è soddisfatta
**.find(sequenza)**
	Risponde con la posizione della sequenza di caratteri fornita nell’argomento
	Se la sequenza non è presente risponde con `-1`
`.translate(dict)`
	Prende un dizionario di tipo `char_code: stringa` e trasforma ogni carattere contenuto nelle chiavi del dizionario nella stringa corrispondente alla chiave
`.maketrans(dict[str, str])`
	Crea un dizionario utilizzabile in `.translate()`
	Prende in input un dizionario con stringhe come chiavi e valori e torna un dizionario uguale ma con il codice del carattere al posto del carattere per ogni chiave
# String interpolation
È possibile inserire variabili nelle `str` se si aggiunge una `f` prima dell’apice
	Es. `var = 1 | str = f”numero {var}” | print(str) => ”numero 1”` 
	È possibile aggiungere formatting alle `fstring` aggiungendo `:<formatting>` all’interno delle graffe
	
