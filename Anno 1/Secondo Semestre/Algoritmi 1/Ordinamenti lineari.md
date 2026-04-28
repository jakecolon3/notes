Un ordinamento lineare è un ordinamento che ha tempo in $O(n)$
Non è in contraddizione con il teorema sul costo minimo dato che quello si applica ad ordinamenti per confronti
Per ordinare senza confronti servono alcune ipotesi aggiuntive

# Counting sort
Opera per conteggio

## Ipotesi
Ciascuno degli $n$ elementi da ordinare è un intero di valore compreso in un certo intervallo conosciuto
    Chiamiamo il massimo dell'intervallo $k$

## Strategia
Questo algoritmo ha costo in $\Theta(n+k)$

- Crea un nuovo array `C` con indici $0,1,...,k$
- Scorro l'array iniziale
- Aggiungo 1 all'indice di `C` uguale all'elemento trovato
- Scorro `C` rimpiazzando `C[i]` volte elementi in `A` con `i`
```python
# non l'ho scritto
```

Dato che il costo è in $O(n+k)$, se impongo $k=O(n)$ abbiamo che l'algoritmo avrà costo $\Theta(n)$

### Osservazioni
Questo algoritmo non ordina il loco, dato che serve l'array `C`
Se ci sono dati "satellite" non saranno salvati
    Questo si può risolvere con un terzo array `B` che salva i dati
    Posso trovare in che posizione di `B` salvare i dati contando quanti minori di un certo indice ci sono da `C`: se in posizione $i$ scrivo `C[0] + C[1] + ... + C[i-1]` so che l'elemento `A[j]` deve andare in posizione `C[i] + 1`

# Bucket sort
### Ipotesi
Gli $n$ elementi devono essere distrubuiti in modo uniforme (con probabilità costante) in un intervallo da $1$ a $k$

### Strategia
Divido l'intervallo in $n$ sotto-intervalli di uguali dimensioni $\frac{k}{n}$ detti *bucket* e distribuisco i valori nei bucket senza confrontarli tra di loro

Costo: nel caso medio $T(n)=\Theta(n)$, nel caso peggiore non è lineare
