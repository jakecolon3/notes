Dato che in Java ogni linea di codice deve essere dentro un metodo (dentro una classe), i metodi sono analoghi alle funzioni in Python
# Dichiarare un metodo
```java
public class Main {
    static void myMethod(parametri) {
    // codice
    }
}
```
Questo codice crea la classe `Main` e crea un metodo che appartiene alla classe `Main` con la keyword `static` e che non ha valore di ritorno con la keyword `void`

È possibile chiamare un metodo in questo modo:
```java
public class Main {
    static void myMethod(parametri) {
    // codice
    }

    public static void main(String[] args) {
        myMethod();
    }
}
```

## Parametri
Per definire i parametri di un metodo basta specificare i tipi di dati e i nomi dei parametri, separati da virgole:
```java
public class Main {
    static void myMethod(String param1, int param2) {
        // codice
    }
}
```
### Numero di parametri variabile
È possibile definire funzioni che prendono come argomenti *un array* di dimensione qualsiasi:
```java
public static void myMethod(int myVar, double... arrayDouble) {
    //codice
    return arrayDouble[x]
}
```
Questo è analogo ad usare `def function(*args)` in Python

## Valori di ritorno
Se il metodo deve tornare un valore si deve sostituire `void` con un tipo di dato primitivo, ed usare `return` nel metodo:
```java
public class Main {
    static int myMethod(int x) {
        // codice
        return x;
    }
}
```

## Method overloading
È possibile definire metodi diversi con lo stesso nome, a patto che hanno numero o tipo di parametri diversi:
```java
public class Main{
    static int myMethod(int x) {
        // codice
    }
    static double myMethod(double x) {
        // codice
    }
}
```
Il programma sceglierà il metodo da eseguire in base al tipo degli argomenti forniti

# Costruttori
È convenzione usare un metodo che fa da costruttore degli oggetti di una classe:
```java
public class MyClass {
    private int var1;
    private int var2;

   /**
    * costruttore
    * ha lo stesso nome della classe
    * supporta l'overloading
    */
    public MyClass(int valore) {
        var1 = valore;
    }

    // secondo costruttore che prende un double
    public MyClass(double valore) {
        var2 = valore;
    }
}
```

Per creare un oggetto di una classe con un costruttore:
```java
public class Main {
    public static void main(String[] args) {

        MyClass myObject = new MyClass(...) // crea un nuovo oggetto con gli argomenti specificati
    }
}
```

Non è obbligatorio usare un costruttore, Java crea un costruttore vuoto di default
