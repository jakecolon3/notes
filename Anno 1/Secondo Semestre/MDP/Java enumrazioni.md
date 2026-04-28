# Sintassi
Le enumerazioni in Java sono definite allo stesso modo di una classe:
```java
// Enumerazione.java
public enum Enumerazione
{
    VALORE1(1),   // è possibile associare un intero ad un valore enumerato
    VALORE2,
    VALORE3,
    VALORE4
}
```
I valori delle enumerazioni sono implicitamente `static` e `final`, e non è possibile creare oggetti di una classe enumerata
Le classi enumerate possono anche contenere campi, metodi e costruttori (questi ultimi devono però avere visibilità `private` o `package`)

Il compilatore genera automaticamente il metodo statico `values()` per ogni enumerazione, che torna un array delle costanti dell'enumerazione, e il metodo `valueOf(String enum)` che prende una stringa corrispondente ad uno dei valori enumerati e torna la costante enumerativa
    Es. `valueOf("VALORE1")` torna `Enumerazione.VALORE1`
