`java.lang.String`
È una classe "fondamentale": è un tipo di dato su cui dipende l'implementazione del linguaggio e per cui è ridefinito `+`
Non richiede import perché fa parte del package speciale `java.lang`

# Metodi
- `toLowerCase()`, `toUpperCase()`
	*Ritornano* una stringa uguale ma tutta maiuscola/minuscola
	In Java le stringhe sono immutabili
- `substring(int startIndex, int endIndex)`
	Torna una slice della stringa
- `concat(String s1, String s2)`
	Come +
- `indexOf(char c)`
	Torna l'indice della prima occorrenza del carattere nella stringa
- `startsWith(String s)`, `endsWith(String s)`
	Torna un bool che verifica se la stringa inizia o finisce con la stringa specificata
- `replace(String original, String new)`
	Torna una nuova stringa con i caratteri rimpiazzati
- `split(String sep)`
	Torna un array di stringhe (`String[]`) contenente la stringa spezzata alle posizioni del carattere specificato
- `equals(String s)`
	Torna `true` se le due stringhe hanno lo stesso contenuto, `false` altrimenti
	Bisogna usare questo invece di `==` dato che `==` controlla se 2 oggetti sono lo stesso oggetto
- `trim()`
	Torna una stringa senza whitespace all'inizio e alla finze
## StringBuilder
Esiste la classe `StringBuilder`, che definisce un oggetto *mutabile*: è meglio utilizzare questo se si deve modificare una stringa ripetutamente
	Ha metodi come `append()` e `insert()`