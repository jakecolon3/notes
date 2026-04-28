Gli insiemi sono contenitori non ordinati e modificabili

Check di tipo “quest’elemento è in questo contenitore?” sono molto veloci se si utilizza un insieme

Accettano assegnazioni aumentate
	`|=, &=` ecc.
# Metodi
### .pop()
Legge e distrugge un elemento casuale dell’insieme
	Errore se vuoto
### .union(set)
Unione insiemistica di 2 insiemi
	Alias: `set1 | set2`
### .intersection(set)
Intersezione di 2 insiemi
	Alias: `set1 & set2`
### .difference(set)
Insieme degli elementi del primo insieme che non sono nel secondo insieme
	Alias: `set1 - set2`
### .symmetric_difference(set)
Insieme degli elementi non in comune tra i due insiemi
	Alias: `set1 ^ set2`
### .add(elemento)
Aggiunge un elemento all’insieme
### .remove(elemento)
Rimuove un elemento dall’insieme
	Errore se non è presente
### .update(set)
Unione distruttiva del primo set con il secondo