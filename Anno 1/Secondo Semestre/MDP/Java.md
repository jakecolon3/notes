# Compilare e eseguire un programma
Java è un linguaggio compilato: per eseguire codice bisogna prima *compilarlo*:
    In un terminale:
    `.../dir/ > javac program.java`
Questo produce un file `.class`, eseguibile con: `.../dir/ > java program`

## Hello World!
Esempio di un semplice `print`:
```java
public class Main {
  public static void main(String[] args) {
    System.out.println("Hello World!");
  }
}
```

Questo codice fa un paio di cose:
- Crea una classe `Main`
    In Java ogni linea di codice *deve* essere inserita in una classe
    Il nome del file che contiene il codice deve essere identico al nome della classe: in questo caso il file è `Main.java` (case sensitive)
        [[Java-style-guide.md|In genere]] le classi hanno nomi che iniziano con la maiuscola
- Crea il [[Java-metodi.md|metodo]] `main()`, *necessario* per ogni programma, che ha come parametro un array di stringhe `args` (input dal terminale)
- Esegue il metodo `println()` con l'argomento `"Hello World!"`
    `System.out` è una [[Java-classi.md|classe]] + sottoclasse default di Java
    `println()` funziona come `print()` in Python: stampa l'argomento su una nuova linea

# Sintassi
In Java, ogni statement deve terminare con `;`
### Commenti:
- Riga singola: `//`
- Più righe: `/* ... */`

## Creare una variabile
Per creare una variabile bisogna specificare il tipo di dato che essa conterrà:
```java
// Esempio:
int variabile = 2; // 'variabile' è l'identificatore della variabile; '2' è il letterale della variabile
```
### Alcuni [[Java-tipi-di-dati.md|tipi di dati]]:
- String
    Usano virgolette *doppie*: ""
- char
    Singoli caratteri (`'A'`)
    Usano virgolette *singole*: ''
- int
- float
- boolean
    `true` e `false` iniziano con lettere minuscole

Non è necessario assegnare un valore ad una variabile:
```java
boolean variabile;  // codice valido
```

Si possono creare costanti con la keyword `final`:
```java
final int costante = 20;
costante = 21;  // Errore
```
Queste variabili non possono essere modificate dopo la loro creazione

Si può usare la keyword `var` per creare una variabile:
```java
var x = 5;  // questa keyword dice al compiler di identificare il tipo della variabile automaticamente (int)
```
In questo caso bisogna assegnare subito un valore alla variabile
Il tipo della variabile rimarrà fisso al tipo che il compiler ha scelto originariamente
In genere per tipi semplici è meglio specificare la keyword, `var` si usa per tipi più complessi
    Esempio: `var myVar = new myClass();`
`var` si può usare solo per variabili locali, non per campi o parametri

## [[Java-operatori.md|Operatore]] +
Come in Python, in Java si può usare l'operatore + per concatenare variabili:
```Java
String stringa1 = "Hello ";
String stringa2 = "World";
System.out.println(stringa1 + stringa2);  // "Hello World"
```
### Concatenazione di `int` e `String`
Si può usare l'operatore + con tipi di dati diversi, ma bisogna fare attenzione all'ordine:
```java
int numero1 = 1;
int numero2 = 2;
String testo = "Somma: ";
System.out.println(testo + numero1 + numero2);    // stampa "Somma: 12"
System.out.println(testo + (numero1 + numero2));  // stampa "Somma: 3"
System.out.println(numero1 + testo + numero2);    // stampa "1Somma: 2"
System.out.println(numero1 + numero2 + testo);    // stampa "3Somma: "
```
In pratica tratta ogni numero dopo una stringa come se fosse una stringa

### Dichiarare più variabili dello stesso tipo
Si possono dichiarare più variabili dello stesso tipo su una singola riga:
```java
int x = 2, y = 1, z = 3;
```
E si può assegnare lo stesso valore a più variabili diverse:
```java
x = y = z = 10;
```

### Keyword
**Visibilità:**
- `public`
    Rende l'argomento (variabile, metodo ecc.) visibile al di fuori della classe
- `private`
    Rende la variabile/metodo/... visibile solo all'interno dell'oggetto/classe in cui è creata 
- `protected`
    Visibile da tutte le classi all'interno del pacchetto e dalle sottoclassi
**Altri:**
- `final`
    Specifica una costante
- `static`
    Specifica un campo o metodo della classe e non dell'oggetto; è quindi condiviso da tutti gli oggetti della classe
    Si può accedere a campi e metodi statici senza creare oggetti della classe
    I campi statici esistono in un solo luogo in memoria detto *MetaSpace*, allocato prima di qualsiasi oggetto della classe
    I metodi statici *non possono* accedere ai campi degli oggetti, possono accedere solo ai campi della classe (quindi statici)

# Incapsulamento
Abbiamo visto che è possibile controllare come si accede agli oggetti di una classe con le keyword `public` e `private`
Questo è utile per controllare le informazioni disponibili all'utente
Usare campi privati e creare getter e setter per interagire con gli oggetti è detto *incapsulamento*
Lo scopo dell'incapsulamento è creare un *interfaccia* utilizzabile dagli utenti senza che loro conoscano i dettagli di implementazione
Spesso è comodo far tornare ai setter un bool per indicare se l'operazione è stata completata con successo

## Object oriented analysis
Per decidere come strutturare il codice, si crea un "modello UML", cioè una grafica che definisce ad alto livello i campi ed i metodi delle classi
    Da presentare nel report del progetto
    Per creare il modello UML esiste un tool online chiamato [draw.io](https://draw.io)
Schema di progettazione di una classe:
1. Definire la classe
2. Definire metodi
3. Scrivere la documentazione per l'interfaccia pubblica
    Con commenti *javadoc* (`/** ... **/`)
        Hanno tag
4. Definire i campi
5. Implementare i metodi
6. Testare la classe

### Modello UML
Nel diagramma di una classe si inseriscono sia i campi (nome, tipo, visibilità) che i metodi (nome, tipo di ritorno, parametri, visibilità)
La visibilità si indica con:
- `+` per `public` 
- `-` per `private`
- `#` per `protected`
    Accessibili solo dalle implementazioni che estendono una classe
- `~` per visibilità solo nel package (non una vera dichiarazione di visibilità)

Le classi astratte si indicano con il tag `<abstract>` e/o scrivendo il nome in corsivo
L'ereditarietà si indica con una freccia grande che va dalla classe che estende alla classe estesa
    Per le classi annidate si usa una freccia con testa a forma di XOR (⊕)
Le enumerazioni si indicano con il tag `<enumeration>` e una lista dei valosi possibili
