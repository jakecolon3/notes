# Ereditarietà
L'ereditarietà è un concetto fondamentale nella programmazione ad oggetti: permette di estendere la funzionalità di un programma in modo efficiente e facile da interpretare dagli utenti
Un esempio di ereditarietà è una classe `Forma` che rappresenta una forma geometrica, estesa con sottoclassi come `Rettangolo`, `Cerchio` ecc.
    I rettangoli devono avere metodi e campi diversi dai cerchi
    `Forma` può contenere un metodo `disegna()`, ereditato da ogni sottoclasse
Le sottoclassi possono aggiungere nuovi metodi e campi e *ridefinire* i metodi della superclasse (ma non i suoi campi)

## Classi astratte
Spesso è utile creare delle classi generiche per poi estenderle con sottoclassi più specifiche
Le classi per cui non ha senso creare oggetti sono dette *astratte*, dichiarate con la keyword `abstract`
    Una classe `abstract` non permette l'allocazione della classe
Esempio:
```java
// Personaggio.java
public abstract class Personaggio {
    // campi
    abstract void parla(); // i metodi abstract *devono* essere implementati dalla classe ereditaria
    // etc.
}
// Paperino.java
public class Paperino extends Personaggio { // per estendere una classe si usa `extends`
    // campi
    public Paperino() {};
    // etc.
}
```
Possiamo vedere che esistono anche i metodi `abstract`, definibili solo dentro classi `abstract`

## this e super
Esistono le keyword `this` e `super`, che specificano se si sta accedendo ad un metodo o campo della classe ereditaria vs. della superclasse
Questo è particolarmente utile per specificare se si vuole utilizzare il costruttore della classe erediatria o della superclasse

## Costruttori di sottoclassi
Se una sottoclasse estende una superclasse con un costruttore, allocare un oggetto della sottoclasse chiamerà prima il costruttore della *superclasse*
Questo significa che una superclasse può *deve* avere un costruttore *senza parametri*, dato che creare un oggetto di una sua sottoclasse chiamerà il costruttore della superclasse senza parametri, dando se esso non è definito

# Classi wrapper
In Java esistono delle classi che definiscono oggetti analoghi ai tipi primitivi, ma che forniscono ulteriori metodi di accesso e visualizzazione
    Esempio: la classe `Integer` ha come metodo `int parseInt(String)` che prende una stringa contenente un intero e torna l'intero rappresentato dalla stringa

Gli oggetti creati da queste classi però non possono essere confrontati con gli operatori standard, bisogna usare i loro metodi di confronto (es. `.equals()`)
    Un esempio di metodo di confronto è `compareTo()` che torna `0` se i due oggetti sono uguali, `> 0` se il primo è maggiore del secondo e `< 0` per il contrario

## Autoboxing/unboxing
Il compilatore di Java converte automaticamente i tipi primitivi alle loro classi wrapper nelle dichiarazioni di variabili:
```java
Integer k = 3;
Integer k = new Integer(3);
// queste due dichiarazioni compilano allo stesso codice
```

# Classi utili
## util
Va importata con `import java.util.[nome modulo];`

### Arrays
- `copyOf(var[] array, int size)`
    Crea una copia di `array` contenente i primi `size` elementi
    `size` è la grandezza del nuovo array, non l'ultimo indice
- `toString(var[] array)`
    Torna una rappresentazione testuale dell'array (come stampare una lista in Python)

## System
### out
- `println()`
    Come `print()` in Python
- `print()`
    Come `println()` ma non aggiunge un newline alla fine del testo
Non accettano più argomenti: per concatenare si deve usare +

## Math
- `max(x, y)`; `min(x, y)`
    Torna il massimo/minimo tra 2 valori
- `sqrt(x)`
- `abs(x)`
- `pow(x, y)`
    Torna x elevato alla y
- `round(x)`
- `ceil(x)`; `floor(x)`
    Arrotonda all'intero più vicino/in su/in giù
- `random()`
    Torna un double casuale tra 0 incluso e 1 escluso
- `sin(x)`; `cos(x)`
    Torna un double = il seno/coseno dell'argomento
- `E`
    Numero di Nepero
- `PI`
    Pi greco

## Integer
È una classe "wrapper": corrisponde al tipo primitivo `int`, ma è una classe
Ci sono classi wrapper per ogni tipo primitivo
- `parseInt(String)`
    Prende una stringa contenente un numero intero e torna un intero

## Random
- `nextInt(int x)`
    Torna un numero casuale tra 0 incluso e 6 escluso
- 

# Polimorfismo
Dato che Java è un linguaggio fortemente tipato, in genere non si può cambiare il tipo di una variabile
L'eccezione è se si usano 2 tipi che estendono la stessa classe:
```java
public class Animale {...}
public class Gatto extends Animale {...}
public class Chihuahua extends Animale {...}

Animale a = new Gatto();
a = new Chihuahua();        // questo è possibile perché Gatto e Chihuahua condividono una superclasse
```
Questo si chiama *poilmorfismo*
Se la superclasse comune definisce un metodo, allora la variabile avrà quel metodo a prescindere dal suo tipo specifico
    Però se le sottoclassi sovrascrivono il metodo verrà usato il metodo della sottoclasse
    È quindi coerente con il "vero" tipo dell'oggetto

Un'applicazione del polimorfismo è creare un array che può contenere oggetti di tipi differenti

## Binding
Il problema di scegliere il tipo di dato corretto è detto *binding*
In Java ci sono due tipi di binding:
- Statico
    È effettuato dal compilatore
- Dinamico
    È effettuato a runtime (`var`?)

## Classe `Object`
In Java ogni oggetto estende implicitamente la classe `Object`, che ha alcuni metodi utili:
- `Object clone()`
    Torna una copia dell'oggetto
- `boolean equals(Object o)`
    Torna `true` se gli oggetti sono uguali
- `Class<? extends Object> getClass()`
    Torna un oggetto `Class` che rappresenta la classe dell'oggetto
    Esiste il metodo della classe `Class` `String getSimpleClassName()` che torna il nome della classe in forma di stringa
- `int hashCode()`
    Torna un intero associato all'oggetto
- `String toString()`
    Torna una rappresentazione in forma di stringa dell'oggetto, di default è in forma `<tipo>@<codice hash>`

### Sovrascrivere `equals`
Dato che il metodo `equals` è usato da Java per alcune operazioni, se lo si sovrascrive bisogna implementare alcune cose specifiche:
```java
@Override
public boolean equals(Object o) {
    if (o == null) return false;
    if (getClass() != o.getClass()) return false;
    // if (!(o instanceof <Classe>)) return false;     // va bene anche così ma questo non funziona con sottoclassi
    ...
```

# Classi e metodi `final`
È possibile definire metodi e classi che non possono essere sovrascritti o estesi usando la keyword `final`:
```java
public final class Classe // non può essere estesa
{
    public final String toString() {} // non può essere sovrascritto da una sottoclasse
}
```

# Classi annidate
Per ora abbiamo visto solo classi *top-level*, cioè definite in un file .java dedicato
Ma spesso è utile definire classi che hanno senso solo all'interno di un'altra classe
È possibile definire classi annidate:
```java
public class Tastiera {
    // campi e metodi
    public class Tasto { ... }
```
Le classi annidate potranno accedere a tutti i campi e metodi della classe top-level, anche se privati
Se poi si vuole creare un oggetto di una sotto-classe al di fuori della sua classe top-level, bisogna prima creare un oggetto della classe top-level:
```java
import Tastiera;
public class Main {
    public static void main(String[] args) {
        Tastiera tastiera = new Tastiera();
        tastiera.Tasto = new tastiera.Tasto();
    }
}
```
Però si possono anche definire classi annidate *statiche* se non si vuole dover creare un oggetto della classe top-level
    Così facendo però la classe non avrà accesso ai campi e metodi non-statici della classe top-level

# Classi anonime
È possibile creare classi anonime, utile se serve creare una classe che deve essere istanziata solo 1 volta
Le classi anonime possono anche estendere altre classi e implementare interfacce; in questo caso l'oggetto viene creato con il nome della classe/interfaccia da estendere/implementare:
### Sintassi
```java
Interfaccia classeAnonima = new Interfaccia()
{
    public Interfaccia() { ... }
    // metodi dell'interfaccia da implementare
}
```

Esempio:
```java
// Formula.java
public interface Formula {
    double calculate(int a);
    default double sqrt(int a) { return Math.sqrt(a); }
}

// Main.java
public static void main(String[] args) {
    ...
    Formula myFormula = new Formula() {
    // implicitamente:
    //  public class <no name> implements Formula

        @Override
        public double calculate(int a) {
            return a * 2;
        }
    };  // è un singolo statement quindi serve il punto e virgola
}
```
