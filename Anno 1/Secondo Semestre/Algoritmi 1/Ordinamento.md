Il problema dell'ordinamento è un problema ricorrente nell'informatica
È molto importante per la risoluzione di altri problemi dato che è spesso un sotto-problema in algoritmi più complessi
È anche praticamente molto utile dato che è molto più efficiente cercare dentro un array ordinato

# Algoritmi di ordinamento
Un algoritmo di ordinamento è un algoritmo che può ordinare un insieme di elementi in base ad una relazione d'ordine definita sull'insieme
Per semplicità negli esempi vedremo array di numeri interi di elementi con indici da $0$ a $n-1$
    È sufficiente per avere un idea del costo di algoritmi di ordinamento per tipi di dati più complessi dato che spesso altri tipi di dati sono associati a delle chiavi uniche
Iniziamo vedendo degli algoritmi relativamente semplici, detti *naif*, ma arriveremo ad algoritmi più complessi come *mergesort*, *quicksort* e *heapsort*

## Ordinamenti naif
### Insertion sort
L'idea è prendere ogni elemento dell'array e "inserirlo" nel posto giusto
Esempio:
    Per ogni $i=0,...,n-1$:
    - Si estrae l'elemento dalla posizione $i$, liberando quella posizione
    - Si trova la posizione corretta nella parte ordinata dell'array
    - Si spostano gli elementi dell'array per fare spazio per l'elemento
Nota:
    Per dimostrare la correttezza di un'algoritmo è necessario un *invariante*, che per l'insertion sort è il corretto ordinamento dei $i-1$ elementi dell'array

 Pseudocodice:
 ```python
 def Insertion_Sort(A):
     for j in range(1, len(A)): # parte da 1 perché il primo elemento è già ordinato
         x = A[j]
         i = j - 1
         while i >= 0 and A[i]>x:
             A[i+1] = A[i]
             i -= 1
        A[i+1] = x
 ```
 Il costo di questo algoritmo è $\Theta(n)$ nel caso peggiore e $\Theta(n^2)$ e quindi $T(n)=O(n^2)$

### Selection sort
Il selection sort ad ogni iterazione cerca il nuovo minimo dell'array e lo mette dopo l'ultimo minimo
Esempio:
    Ho $i$ elementi ordinati (= invariante)
    - Cerco il minimo tra i restanti $n-i$ elementi
    - Lo scambio con l'elemento in posizione $i+1$
    - Ripeto
Pseudocodice:
```python
def Selectoin_Sort(A):
    for i in range(len(A) - 1): # saltiamo l'ultimo elemento dato che sarà sempre l'elemento più grande
        m = i                   # m: indice del minimo
        for j in range(i + 1, len(A)):
            if A[j] < A[m]:
                m = j
        A[m], A[i] = A[i], A[m]
```
Costo computazionale: $T(n)=O(n^2)$ sempre

### Bubble sort
Il bubble sort ad ogni iterazione controlla l'elemento $i$ e $i-1$ e, se non sono ordinati, li inverte, ripetendo il processo fino a che l'array è ordinato
L'invariante è il fatto che una parte dell'array è sempre già ordinata
Processo:
    - Guarda i primi 2 elementi
    - Se non sono ordinati scambiali
    - Ripeti
Pseudocodice:
```python
def Bubble_Sort(A):
    for i in range(len(A)):
        for j in range(len(A)-1, i, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
```
Costo computazionale: $\Theta(n^2)$ sempre


Tutti questi algoritmi hanno costo in $O(n^2)$, ma si può fare di meglio?
Per rispondere si dobbiamo trovare un algoritmo più efficiente
Ma ad un certo punto possiamo rispondere no con certezza ragionando sulla natura del problema
    Per esempio per trovare il minimo è necessario iterare l'intero array, quindi ha costo minimo in $\Theta(n)$
Per stabilire questo limite inferiore è utile usare un *albero di decisione*
## Albero di decisione
L'albero di decisione rappresenta tutte le possibili scelte che un'algoritmo può fare
Nel caso di algoritmi che fanno confronti, ad ogni step l'algoritmo può fare solo 2 scelte: si o no
Quindi in questo caso abbiamo un'albero binario
Non bisogna costruire l'intero albero, basta trovare delle proprietà per studiare l'algoritmo
Prendendo come esempio un albero di decisione di un algoritmo di confronto, ogni nodo rappresenta un confronto ed ogni foglia rappresenta una soluzione
    Quindi il costo computazionale di un'algoritmo è proporzionale alla lunghezza di un percorso radice -> foglia
    La limitazione inferiore del costo computazionale dell'ordinamento è quindi dato dalla massima lunghezza di un percorso dell'albero di decisione.
### Osservazioni
- L'albero delle decisioni contiene *ogni* permutazione di soluzioni, quindi l'albero deve contenere almeno $n!$ foglie.
- Un albero binario di altezza $h$ non può contenere più di $2^h$ foglie, dove $h$ è l'altezza dell'albero.
Quindi:
$$
2^h\geq n! \Rightarrow h\geq \log n!
$$
Calcoliamo $\log n!$.
    Assumiamo che $n$ sia pari per semplicità
    $$
    \begin{gather}
    \log n! =\log (n(n-1)(n-2)(n-2)...\cdot 2\cdot 1)= \\ \\
\sum_{i=1}^{n}\log i=\sum_{i=1}^{\frac{n}{2}}\log i+\sum_{i=\frac{n}{2}+1}^{n}\log i\geq0+\sum_{i=\frac{n}{2}+1}^{n}\log \frac{n}{2}=\frac{n}{2}\log n-\frac{n}{2}=\Theta(n\log n)
    \end{gather}
    $$
Quindi:
# Teorema
Il costo computazionale di qualunque algoritmo di ordinamento basato su confronti è $\Omega(n\log n)$.


Vediamo quindi un algoritmo di ordinamento in tempo $O(n\log n)$:
# Merge sort
Il merge sort utilizza una tecnica algoritmica detta *divide et impera* (divide and conquer):
- Suddividi il problema in sottoproblemi più piccoli (divide)
- Risolvi i sottoproblemi ricorsivamente (conquer)
- Componi le soluzioni dei sottoproblemi (combina)

## Strategia
Nell'implementazione del merge sort:
- La sequenza di $n$ elementi viene divisa in 2 sottosequenze di $n/2$ elementi
- Le due sottosequenze vengono ordinate ricorsivamente
    La ricorsione termina quando le sottosequenze sono composte da un singolo elemento
- Le sottosequenze sono fuse in un'unica sequenza ordinata

## Pseudocodice
```python
def merge_sort(A, indice_primo, indice_secondo):
    if (indice_primo < indice_secondo):
        indice_medio = (indice_primo + indice_secondo) // 2
        merge_sort(A, indice_primo, indice_medio)
        merge_sort(A, indice_medio + 1, indice_secondo)
        fondi(A, indice_primo, indice_medio, indice_ultimo)
```
Questo algoritmo avrà un costo $T(n)=2T(n/2)+S(n)+\Theta(1)$, dove $S$ è il costo della funzione `fondi`

### Fondi
Sfrutta il fatto che le 2 sottosequenze sono ordinate: il minimo ed il massimo di ogni sottosequenza sono rispettivamente il primo e l'ultimo elemento dell'array
Il minimo della sequenza fusa sarà il minimo tra i minimi delle due sottosequenze, e questa proprietà rimane dopo aver eliminato i minimi
Basta quindi trovare ripetutamente il minimo tra le 2 sottosequenze ed inserirlo in un nuovo array
Pseudocodice:
```python
def fondi(A, ind_1, ind_m, ind_2): # le 2 sequenze sono concatenate nello stesso array, separate a ind_m
    i,j = ind_1, ind_m + 1
    B = []
    while i <= ind_m and j <= ind_2:
        if A[i] <= A[j]:
            B.append(A[i])
            i += 1
        else:
            B.append(A[j])
            j += 1
    while i <= ind_m:
        B.append(A[i])
        i += 1
    while j <= ind_m:
        B.append(A[j])
        j += 1
    for i in range(len(B)):
        A[ind_1 + i] = B[i]
```
Costo computazionale: $\Theta(n)$

Quindi il costo del merge sort è: $T(n/2)+\Theta(n);\ T(1)=\Theta(1)\Rightarrow T(n)=\Theta(n\log n)$.
Ma c'è un problema: la fusione non può essere svolta direttamente sull'array principale in tempo $\Theta(n)$.
Questo è un problema perché creare l'array di supporto per `fondi` occupa molta memoria, possibilmente andando oltre lo spazio di memoria principale e quindi ricadendo sulla memoria secondaria, dove non vale la misura di costo uniforme e si perde efficienza.

# Quicksort
Anche il quicksort fa uso della strategia *divide and conquer*

## Costo
Il quicksort ha costo in $O(n^2)$, ma in pratica è spesso più veloce degli altri algoritmi
Il costo medio è in $\Theta(n\log n)$
Ordina *in loco*, quindi non ha il problema della memoria del mergesort

## Strategia
Anche il quicksort è ricorsivo e fa uso della strategia *divide et impera*:
- Divide
    Si seleziona un "pivot" nella sequenza di $n$ elementi e si divide l'array in 2 sottosequenze, una maggiore (messa a destra) del pivot e una minore (messa a sinistra) del pivot
- Base
    Procede ricorsivamente fino a che non si arriva a sequenze di 1 elemento
- Impera
    Le due sottosequenze sono ordinate ricorsivamente
- Combina
    Il quicksort non deve combinare le sottosequenze, sono già ordinate

Osservando l'albero di esecuzione del quicksort notiamo che, al contrario del mergesort, i sotto-array sono di dimensioni differenti e quindi i casi base non sono tutti allo stesso livello

## Pseudocodice
```python
def quicksort(A, i_primo, i_ult)
    if (i_primo < i_ult):
        
        # Partiziona divide in 2 sottoarray (resitituisce l'indice della divisione)
        i_medio = Partiziona(A, i_primo, i_ult) 
        # i_medio deve essere tale che sia il sotto-array di destra 
        # che il sotto-array di sinistra abbia almeno 1 elemento
        # quindi può avere valori da 1 a n-1
        
        quicksort(A, i_primo, i_medio)
        quicksort(A, i_medio + 1, i_ult)
```
### Equazione di ricorrenza
$$
T(n)=
\begin{cases}
T(k) + T(n-k) + S(n) + \Theta(1) \\
T(1) = \Theta(1)
\end{cases}
$$
Dove $S$ è il costo di `Partiziona()`

## `Partiziona()`
Idea:
- Prendo 2 indici, 1 arbitrario (?) ed uno alla fine dell'array
- Li faccio scorrere uno verso destra, uno verso sinistra
    Così facendo possono saltare elementi che sono già dal lato giusto del pivot
- Quando un indice trova un elemento dal lato sbagliato della soglia si ferma e aspetta l'altro indice
- Quando entrambi gli indici hanno trovato un elemento in posizione sbagliata scambiano gli elementi

### Pseudocodice
```python
def partiziona(A, i_primo, i_ult):
    pivot = A[i_primo] # scelto arbitrariamente
    i = i_primo - 1
    j = i_ult   + 1
    while true:
        while A[j] <= pivot:
            j -= 1
        while A[i] >= pivot:
            i += 1
        if (i < j):
            A[i], A[j] = A[j], A[i]
        else:
            return j
```

### Costo
$$
S(n) = \Theta(n)
$$

## Costo totale
$$
T(n)=
\begin{cases}
T(k) + T(n-k) + \Theta(n) \\
T(1) = \Theta(1)
\end{cases}
$$
Possiamo risolvere questa equazione solo con il metodo di sostituzione
Vedi calcoli su slide
Otteniamo che nel caso medio $T(n)=\Theta(n\log n)$

Se vale l'ipotesi di equiprobabilità per il valore del pivot, il quicksort è l'algoritmo più veloce per input di grandi dimensioni
Sono quindi state ideate alcune tecniche per l'ipotesi valida per qualsiasi input
Per esempio:
- Randomizzare l'ordine dell'array prima di ordinarlo
- Prendere un elemento casuale come pivot invece del primo


# Esercizi
### Esercizio quicksort 1
L'algoritmo scorre l'array e conta le occorrenze di 0 e di 2 (forse anche solo 1 dei due)
Poi scorre nuovamente l'array rimpiazzando i primi (occorrenze di 0) elementi con 0 e i restanti con 2
Codice:
```python
def ordina_array_02(A):
    c0 = 0
    for i in A:
        if i == 0: c0 += 1

    for i in A:
        if c0 > 0:
            A[i] = 0
            c0 -= 1
        else:
            A[i] = 2
```

### 2
