# If else
La sintassi per gli `if` statement in Java è:
```java
if (condizione) {
    codice;
}
```
Per gli else/if else:
```java
if (condizione) {
    codice;
} else if (condizione2) {
    altroCodice;
} else {
    codiceFinale;
}
```
Le graffe non sono obbligatorie per singole istruzioni
L'`else` si riferisce sempre all'`if` subito precedente
### Operatore ternario
Shorthand per uno statement if else:
```java
var condizione = valore;
var variabile = (condizione) ? valoreSeVero : valoreSeFalso;
```
È anche possibile utilizzare l'operatore ternario senza assegnare il risultato ad una variabile (per esempio dentro `println()`)

## Switch statements
Come in Python, si può usare uno switch statement invece di una catena di if/else:
```java
var condizione = valore,
switch(condizione) {
    case x:
        codice;
        break;  // non è necessario ma salta i check con gli altri casi
    case y:
        altroCodice;
        break;
    ...
        break;
    default:
        codiceDefault;  // se falliscono tutti i check
}
```
### Operatore ->
Esiste l'operatore `->` in Java >= 13 che permette di scrivere gli switch in modo meno verboso:
```java
switch(var) {
    case 1 -> func1();
    case 2 -> func2();
    // ecc.
    default -> defFunc();
}
```
Così non serve usare i due punti o i `break` dopo ogni caso
### `yield`
Altrimenti esiste anche la keyword `yield` che fa la stessa cosa
```java
switch(var) {
    case 1: yield func1();
    case 2: yield func2();
    // ecc.
    default: yield defFunc();
}
```

# Loops
## While
```java
var condizione = valore;
while (condizione) {
    codice;
}
```
### Do... while
Una variante dei while loop che esegue il codice una volta *prima* di controllare la condizione, e poi funziona come un while:
```java
var condizione = valore;
do {
    codice;
}
while (condizione);
```
## For
```java
for (assegnamento; condizione; incremento) {
    codice;
}
```
I for loop prendono 3 statement:
- Il primo è eseguito *una* volta *prima* del codice dentro il loop
- Il secondo è la condizione
- Il terzo è eseguito *ogni* volta *dopo* il codice dentro il loop
    Si possono creare ed aumentare più variabili in questi statement, basta separarli con una virgola
Esempio:
```java
for (int i = 0; i <= 5; ++i) {
    System.out.println(i);  // stampa gli interi tra 0 e 5 inclusi
}
```

Si possono *etichettare* i cicli scrivendo il nome dell'etichetta e due punti prima del `for`:
```java
myLoop:
for (/* etc */) {
    // code
}
```
Questo è utile perché in questo modo si può specificare su che ciclo agiranno `break` e `continue`:
```java
outer:
for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 5; ++j) {
        // codice
        if (condizione) break outer; //esce da entrambi i loop
    }
}
```

### For-each
Esistono anche i loop for-each, che iterano su gli [[Java vettori|array]]:
```java
for (var variabile : lista) {
    codice;
}
```
(Equivalente al seguente codice in Python):
```python
for variabile in lista:
    codice
```
Esistono anche le keyword `break` e `continue`, con funzionamento analogo a Python
