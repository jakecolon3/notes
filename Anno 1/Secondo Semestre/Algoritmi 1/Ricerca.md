La ricerca è uno dei problemi più rilevanti dell'informatica
# Definizione formale
Input:
- Un array `A` di `n` valori
- Un valore `v`
Output:
- Un indice `i` tale che `A[i]=v`, o un valore `None` se `v` non è presente nell'array

## Algoritmi di ricerca
### Ricerca sequenziale
Scorre l'array e confronta ciascun elemento con `v`, restituendo l'indice dell'elemento attuale se è l'elemento corretto
```
def ricerca_sequenziale (A, v):
	i = 0
	while((i < len(A)) and (A[i] != v))
		i += 1
	if (i < len(A)):
		return i
	else:
		return -1
```

Questo algoritmo ha costo $T(n)=\Theta(n)$ nel caso peggiore e $T(n)=\Theta(1)$ nel caso migliore, e costo medio $T(n)=\Theta(n)$
L'operatore `in` in Python usa la ricerca sequenziale quando usato su tipi di dati ordinati

### Ricerca binaria
Funziona *solo* su sequenze ordinate (sorted)
Guarda l'elemento centrale dell'array e se trova l'elemento ritorna, se non lo trova e l'elemento centrale è più piccolo scarta la metà superiore dell'array e ripete la ricerca nell'altra metà o il contrario se l'elemento centrale è più grande
```python
def ricerca_binaria(A, v):
	a,b = 0, len(A) - 1
	m = (a+b)//2
	while (A[m] != v):
		if (A[m] > v):
			b = m - 1
		else:
			a = m + 1
		if a > b:
			return -1
		m = (a + b)//2
	return m
```

Costo computazionale:
Vediamo che all'i-esima iterazione la dimensione dell'input è $\frac{n}{2^i}$, quindi l'ultima $i$ è $\log n$
Quindi il ciclo while è eseguito al più $\log n$ volte e quindi il costo è $T(n)=\Theta(n)$ nel caso peggiore, $T(n)=\Theta(1)$ nel caso migliore e $T(n)=O(\log n)$

### Ricerca costante
Non esiste un algoritmo di ricerca in tempo costante che funziona per dati generali con il modello computazionale corrente