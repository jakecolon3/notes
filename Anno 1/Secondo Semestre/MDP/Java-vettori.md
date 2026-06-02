# Dichiarare un array
Gli array sono l'equivalente delle liste/tuple/set di Python, dichiarate in questo modo:
```java
type[] variabile = {valore1, valore2, ..., valorex};
```
Questo crea un array di x elementi di tipo `type`
Da notare che tutti gli elementi di un array devono essere dello stesso tipo

Si può anche creare un array specificandone la dimensione con la keyword `new`:
```java
String[] myArray = new String[2]
```
Questo crea un array di dimensione specificata contenente il valore di default per il tipo (`0, false, null`)
Questo è utile se non si ha l'esatta lista di elementi che il array può contenere
Nota che `var myArray = new var[x] {valore1,  valore2, ...}` non è codice valido: questi 2 modi di dichiarare un array sono esclusivi tra di loro

## Vettori multi-dimensionali
Si può dichiarare un array multi-dimensionale (per esempio una matrice) in questo modo:
```java
var[][] myMatrix = { {valoreX, ...}, {valoreY, ...} };
```

## Accedere agli elementi di un array
Si può accedere all'i-esimo elemento di un array:
```java
int[] myArray = {0, 3, 1};
System.out.println(myArray[2]);  // 1
myArray[1] = 4;,  // myArray[1] diventa 4
```

# Metodi
- `.length()`

Dal package `java.utils.Arrays`:
    Sono metodi statici, ci si accede con `Arrays.metodo()`
- `copyOf(var[] array, int size)`
    Torna una copia dell'array contenente i primi `size` elementi
- `toString()`
    Torna una rappresenazione testuale dell'array (come stampare una lista in Python)
