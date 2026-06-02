Le eccezioni permettono di prevenire e gestire gli errori
In Java le eccezioni sono stampate in questo modo:
```
<file, linea di codice> Exception in thread "<metodo>" <nome eccezione>: <informazioni eccezione>
```

Ci sono 2 tipi di errori:
- Sincroni, suddivisi in:
    - Non critici
        Derivano da condizioni anomale, si possono gestire
            Divisione per 0, errore di I/O...
    - Critici
        Errori interni alla JVM, irrecuperabili
            Cast illegale, null dereference...

# `try-catch`
La sintassi per `try-catch` in Java è:
```java
try {
    // codice
} catch (TipoEccezione eccezione) {
    // codice per gestire eccezione
} catch (TipoEccezione2 eccezione2) {
    // ecc
}
```
Le eccezioni seguono le regole del polimorfismo: se un'eccezione estende un'altra allora sarà compatibile con i `catch` della seconda
C'è anche il blocco `finally`, che viene eseguito sempre, anche se un eccezione non è stata catturata

## Ordine
L'ordine nei `try-catch` è importante: viene eseguito il *primo* blocco compatibile con l'eccezione

# `throws`
Invece di gestire un eccezione, possiamo anche semplicemente ignorarla e passarla al metodo chiamante
In questo modo dovremmo aggiungere una dichiarazione `throws` al metodo
La dichiarazione `throws` impone al metodo chiamante di gestire l'eccezione

# Oggetti eccezione
Le istanze delle eccezioni hanno 2 metodi:
- `String getMessage()`
    Torna una descrizione dell'errore (come riportata dalla JVM in un eccezione non gestita)
- `void printStackTrace()`
    Stampa lo stack trace delle chiamate che hanno portato all'eccezione

# Creare eccezioni
Possiamo creare eccezioni personalizzate nello stesso modo in cui creiamo una classe:
```java
public class MyException extends Exception {
    public MyException() {
        super("<messaggio eccezione>");
    }
}
```

# Gerarchia delle eccezioni
- `Throwable`
    - `Error`
        Errori non gestibili
    - `Exception`
        Errori gestibili
        - `RuntimeException`
        - `IOException`
        - ecc...

# Checked/Unchecked
Le eccezioni "checked" sono eccezioni che devono essere gestite (impone `throws`/`try-catch`)
    Quindi eccezioni che non estendono `RuntimeException`
Le eccezioni "unchecked" sono eccezioni che non devono essere necessariamente gestite
    `Error` e eccezioni che estendono `RuntimeException`
