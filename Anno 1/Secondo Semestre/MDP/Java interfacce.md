Le interfacce definiscono una struttura ben definita da implementare
Se un'interfaccia definisce dei metodi, una classe che implementa l'interfaccia *deve* implementare quei metodi
    Differiscono dalle classi astratte perché non possono definire campi non statici
Le interfacce sono definite con la keyword `interface`:
```java
public interface Interfaccia
{
    // si possono definire costanti nelle interfacce
    int VALORE = 1;         // uguale a:  public final static int VALORE = 1;

    // i metodi definiti nelle interfacce sono implicitamente public e abstract
    void metodo();          //            public abstract void metodo();
}
```

Per implementare un interfaccia si usa la keyword `implements`:
```java
public class Implementazione implements Interfaccia { ... }
```

Da Java 8 è anche possibile definire dei metodi nella dichiarazione dell'interfaccia tramite la keyword `default` o dei metodi statici:
```java
public interface Interfaccia
{
    public static void metodo(args) {
        // implementazione
    }

    // da java 9 è anche possibile definire metodi privati:
    private static void metodo2() { ... }

    default void metodoDefault(args) { ... }
}
```
In genere metodi privati e statici sono dei metodi "di supporto" per la classe

## Perché usare interfacce
In Java non è possibile estendere più di una classe per evitare ambiguità con metodi presenti in più superclassi
Una classe può però implementare *un numero qualsiasi di interfacce*

# Interfacce built-in
Java fornisce delle interfacce di default per implementare alcuni tipi di dati

## `Iterable`
Dichiara un solo metodo `iterator()`:
```java
public interface Iterable {
    Iterator<T> iterator();
}
```
Questo metodo ritorna un tipo *generico*: è un tipo "contenitore" di altri tipi (come un array):
### `Iterator`
```java
public class Iterator<E> {
    boolean hasNext();
    E       next();     // E è il tipo generico
    void    remove();
}
```

L'interfaccia `Iterable` è ciò che permette il funzionamento dei loop `for-each`: qualsiasi classe che la implementa può essere usata in un loop for-each

## `Comparable<T>`
Dichara un metodo che torna un valore maggiore, minore o uguale a zero, a seconda della relazione tra l'oggetto chiamante e l'oggetto fornito come argomento:
```java
public interface Comparable {
    int compareTo(T b);
}
```

## `Cloneable`
Permette l'utilizzo del metodo `clone`:
```java
public interface Cloneable {
    T clone();
}
```

## `Serializable`
Permette la serializzazione:
```java
public interface Serializable {
    ...
}
```

# Interfacce funzionali
Da Java 8 esiste un tipo di interfaccia detta *funzionale*, o SAM (Single Abstract Method)
Le interfacce funzionali necessariamente non possono avere più di 1 metodo astratto
    Però possono avere un numero qualsiasi di metodi di default
Un esempio di interfaccia funzionale è l'interfaccia `Runnable`, che crea un nuovo thread
### Sintassi
Basta aggiungere `@FunctionalInterface` prima della dichiarazione di interfaccia:
```java
@FunctionalInterface    // Il compilatore non permetterà di aggiungere più di 1 metodo astratto
public interface Interfaccia {
    ...
}
```
## Interfacce funzionali di default
### `Comparator<T>`
Fornisce un metodo `compare(a, b)` che torna un intero tra -1 e 1 inclusi per determinare l'ordine relativo degli oggetti
Fornisce anche alcuni metodi di default:
- `reversed()`
    Inverte l'ordinamento
    Utilizzo: `myComparator.reversed().compare(...)`
- `comparing(obj -> obj.getField())`
    Basa l'ordinamento sul campo specificato
- `thenComparing(obj -> obj.getField())`
    Può essere usato dopo `comparing()` per definire l'ordinamento in caso di uguaglianza

### `Predicate<T>`
Fornisce un metodo `test(a)` che torna un booleano
Metodi di default:
- `negate()`
- `and(Predicate)`
    Aggiunge un'altro check al test
- `or(Predicate)`
- ecc. guarda doc

### `Function<T,R>`
Fornisce un metodo `apply(T a)` che torna un oggetto di tipo `R`
Ha anche metodi di default

### `Supplier<T>`
Fornisce un metodo `get()` che torna un oggetto di tipo `T`
    Se usate con un costruttore non si possono passare parametri al costruttore

### `Consumer<T>`
Fornisce un metodo `accept(T a)` che prende un argomento ma non ritorna niente
Funziona a "side-effect"

## Utilità
Immaginiamo di avere un metodo `calcola` definito come segue:
```java
public static int calcola(int a, int b, String tipo) {
    switch (tipo) {
        case "somma":
            return a + b;

        case "prodotto":
            return a * b;

        case "max":
            return Math.max(a, b);

        default:
            throw new UnsupportedOperationException();
    }
```
Questo codice funziona ma ha alcuni problemi: bisogna modificare il metodo se si vuole aggiungere una nuova operazione, il codice è poco pulito, non fa controlli a compile-time, non è estensibile ecc.
Le interfacce però ci permettono di passare in input delle *funzioni* con una certa firma
Ma in Java non si possono usare direttamente delle funzioni come argomenti, si possono però usare oggetti che le rappresentano
Qui entrano in gioco le interfacce funzionali:
```java
@FunctionalInterface
public interface Operazione {
    double esegui(double a, double b);
}

public class Somma implements Operazione {
    public double esegui(double a, double b) {
        return a + b;
    }
}

public static double calcola(double a, double b, Operazione op) {
    return op.esegui(a, b);
}

// main
double somma = calcola(10d, 20d, new Somma()); // somma = 30.0
```
Si possono poi definire altre classi che implementano `Operazione` che possono essere utilizzate in `calcola`

## Espressioni lambda
È possibile creare funzioni anonime, dette *funzioni lambda*:
```java
() -> { System.out.println("Hello, world!") }
```
Le funzioni lambda sono compilate come metodi privati
Le espressioni lambda possono essere usate al posto delle interfaccie funzionali se hanno la stessa firma della funzione dell'interfaccia:
```java
double potenza = calcola(2, 3, (a, b) -> { Math.pow(a, b) });
Runnable r = () -> { System.out.println("Hello, multithreading!") }; // Runnable è un interfaccia funzionale
// ^ equivalente a:
Runnable r = new Runnable() {
    @Override
    public void run() { System.out.println("Hello, multithreading!"); }
};
```
### Sintassi
- Il tipo dei parametri è opzionale; il compilatore lo intuisce
- Le parentesi tonde sono opzionali se si ha un solo parametro
- Le parentesi graffe sono opzionali se si ha solo una riga di codice
- Il return è opzionale se l'unico codice è ciò che deve essere tornato
Quindi queste espressioni sono tutte equivalenti:
```java
(int a, int b) -> { return a + b; }
(a, b) -> { return a + b; }
(a, b) -> return a + b;
(a, b) -> a + b;
// Oppure
(String s) -> return s.replace(' ', '_');
s -> s.replace(' ', '_');
```

### Riferimenti a metodi esistenti
Se abbiamo una funzione lambda che si riferisce solamente ad un metodo già esistente, si può invece usare *un riferimento* a quel metodo:
```java
(x, s) -> { return x.equals(s); }
// altrimenti:
String::equals;
```
Il compilatore può inferire automaticamente l'oggetto su cui chiamare la funzione (il primo argomento passato alla chiamata) e gli argomenti (gli argomenti restanti)
    Se il metodo è statico allora tutti gli argomenti sono passati al metodo
In questo modo possiamo anche chiamare il costruttore di una classe:
```java
String::new
```
