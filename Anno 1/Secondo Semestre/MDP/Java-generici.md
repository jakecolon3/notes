Abbiamo visto che alcune delle [[Java_interfacce.md|interfacce]] di Java sono definite con parentesi angolari, per es.:
```java
public interface List<E> { ... }
```
Queste sono definizioni di classi con *tipi generici*

# Utilizzo
## Nelle classi
Nella classe si potrà poi usare il tipo generico come *variabile* nei metodi e campi della classe:
```java
public class MyGeneric<T> {
    private T valore;

    public MyGeneric(T val) { this.valore = val; }

    public T getValore()    { return valore; }
```
Inoltre il compilatore può indovinare il tipo corretto quando si istanzia un oggetto di una classe generica:
    (Nota: non si possono usare tipi primitivi per istanziare un oggetto generico)
```java
MyGeneric<Integer> intero = new MyGeneric<>(10);
```
Si possono specificare più tipi nella dichiarazione di una classe:
```java
public class Coppia<K, V> {
    public K primo;
    public V secondo;
    ...
}
```

## Nei metodi
Si possono usare i tipi generici anche *nei metodi*:
```java
// Bisogna specificare l'elenco dei tipi generici prima del tipo di ritorno:
public static <T> void esamina(ArrayList<T> lista) { ... }
```
Anche qua si può usare la notazione `extends`:
    Da notare che l'ereditarietà è ignorata nei tipi generici
```java
// Non accetta ArrayList<Arancia>:
public static void esamina(ArrayList<Frutta> lista) { ... }
// Accetta ArrayList di qualsiasi tipo che estende Frutta
public static <T extends Frutta> void esamina(ArrayList<T> lista) { ... }
```

### Overloading
I metodi generici possono essere sovraccaricati *anche da metodi non generici*:
```java
public static <T extends Comparable<T>> T getMassimo(T a, T b) { ... }
...
@Override
public static Integer getMassimo(Integer a, Integer b) { ... }
```
Il compilatore cerca di usare il metodo più specifico possibile

# Wildcard `?`
Invece di una variabile di tipo, si può usare il simbolo `?`:
```java
public static void max(ArrayList<? extends Comparable>) { ... }
// In questo modo non possiamo usare il tipo come variabile nel corpo del metodo
```
In questo modo si può anche bypassare il checking di tipo nelle variabili:
```java
ArrayList<?> a = new ArrayList<Integer>(10, 20);
a = new ArrayList<Double>(1.5, 15);
```

# Vincoli sui generici
## extends
Si può restringere il gruppo di tipi accettati:
```java
public class MyClass<T extends Comparable<T>> { ... } // accetta solo tipi che estendono Comparable con se stessi
```

## super
Si può anche specificare un gruppo di tipi che sono estesi da una certa classe:
```java
List<? super Integer> l; // accetta tutti i tipi che sono estesi da Integer ricorsivamente
```

### Quando usare wildcard
Ci sono 3 modi di utilizzare `<?>`:
- `Type<?>`
    Non so niente sul tipo, devo assumere `Object`
- `Type<? extends T>`
    Per oggetti che "producono" T
        Se stai leggendo da una lista di T stai "producendo" T
- `Type<? super T>`
    Per oggetti che "consumano" T
        Se stai creando una lista di T stai "consumando" T

Per riassumere questi casi c'è l'acronimo PECS: *Producer Extends, Consumer Supers*
