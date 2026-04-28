Una funzione *ricorsiva* è una funzione che chiama sé stessa
Un problema può essere risolto in maniera ricorsiva se:
- Sappiamo come rimpicciolire la dimensione del problema
- Esiste almeno un problema che ha una soluzione elementare
- È sempre possibile arrivare ad un caso base applicando ripetutamente la riduzione
- Sappiamo come ottenere la soluzione del problema iniziale dalle soluzioni del sottoproblema

Un esempio di problema risolvibile con ricorsione è il fattoriale:
N!
- Riduzione: N-1
- Caso base: $f(1)=1$
- Composizione: $f(N)=f(N-1)\cdot N$
- Riducendo qualsiasi N arrivo sempre ad 1

## Schema generale per risoluzione ricorsiva
```python
def risolvi_ricorsivamente(problema):
	if is_caso_base(problema):
		return soluzione nota
	else:
		sottoproblema  = riduzione(problema)
		sottosoluzione = risolvi_ricorsivamente(sottoproblema)
		soluzione      = composizione(sottosoluzione)
		return soluzione```

### Fun fact
È sempre possibile simulare un ciclo con una ricorsione e viceversa

# Memorization o caching
Per non calcolare lo stesso valore più volte nei problemi ricorsivi (per esempio la sequenza di Fibonacci) si può salvare il valore di ogni esecuzione:
```python
def fibonacci(N, memoria=None):
	if not memoria:
		memoria = {0:0, 1:1}
	if N not in memoria:
		memoria(N) = fibonacci(N - 1, memoria) + fibonacci(N - 2, memoria)
	return memoria(N)
```
Questo riduce il costo in tempo di esecuzione ma aumenta il costo in memoria del programma

# Alberi binari
Gli alberi sono un modo di ordinare (?) i dati:
	Hanno un nodo di base (*radice*)
	Ogni nodo ha $n$ "figli"
Gli alberi i cui nodi hanno 2 figli ognuno si chiamano *alberi binari*
È comodo scriverli in una classe:
```python
class NodoBinario:
	def __init__(self, V : int|str,
					   left : 'NodoBinario'|None = None,
					   right : 'NodoBinario'|None = None):
	
		self._value = V
		self._sx = left
		self._dx = right
		
	def __repr__(self):
		return f'{self._value!r}'
		
	def __str__(self):
		return f'NodoBinario({self._value!r})'
```
Ogni nodo ha come attributo il suo valore, il sottoalbero alla sua sinistra e il sottoalbero alla sua destra
### Profondità di un albero
In modo ricorsivo:
- Caso base: un albero vuoto `None` ha altezza 0
- Passo ricorsivo e composizione: un nodo ha altezza `1 + max(altezza_sx, altezza_dx)`
- Convergenza: ogni volta che scendo in un sottoalbero i nodi da esaminare diminuiscono almeno di 1

# Alberi n-ari
Sono alberi che possono avere un numero di figli != 2
Altezza:
```python
def altezza(self):
"l'altezza è 1 + la massima altezza dei sottoalberi"
# se non ci sono figli si torna 1
return max( [son.altezza()+1 for son in self._sons], default=1 )
```

In generale i metodi sono uguali agli alberi binari ma si devono controllare un numero variabile di figli