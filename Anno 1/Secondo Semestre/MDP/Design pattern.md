Esistono delle tecniche di programmazione "approvate" per risolvere determinati problemi

Possiamo dividere i design pattern in 3 categorie:
    Sono ordinati per livello di astrazione
- [[#Creational patterns|Creational patterns]]
- [[#Structural patterns|Structural patterns]]
- [[#Behavioural patterns|Behavioural patterns]]

# Creational patterns
Questi pattern riguardano la creazione degli oggetti
Lo scopo è astrarre il processo di creazione degli oggetti di una classe
Creando buone astrazioni il codice diventa più facile da mantenere ed estendere

## Singleton
Questo pattern consiste nel limitare le classi ad una singola istanza
La classe poi fornisce un punto di accesso globale alla sua istanza

### In pratica
La classe ha un campo privato statico `instance` contenente l'istanza ed un metodo `getInstance()` per accederci
Il costruttore della classe è *privato*, per garantire l'unicità dell'istanza

## Factory method
Il factory method prevede una classe `Factory` con un metodo che torna un 'prodotto'
Alternativamente si può usare un metodo che torna un oggetto `Factory` che può generare diversi tipi di oggetti

## Abstract factory
Questo pattern facilita la costruzione di diverse 'famiglie' di oggetti correlati

### In pratica
Si crea un interfaccia `AbstractFactory` che può essere implementata da diverse classi factory

## Builder pattern
Questo pattern semplifica la costruzione di oggetti complessi, senza dover specificare diversi costruttori con molti parametri

### In pratica
Si definisce una classe `Builder` interna con diversi metodi del tipo `public Builder <campo>(<params>)` che funzionano come setter
In questo modo si possono concatenare diversi metodi per settare i campi desiderati
Si definisce inoltre un metodo `build()` che ritorna l'oggetto finale
    Il costruttore della classe contenente è privato


# Structural patterns
Questi pattern riguardano le relazioni tra i componenti di un programma
    Quindi sulla struttura delle classi e come esse potranno interagire

## Façade pattern
Il facade pattern consiste nel fornire un interfaccia ad alto livello per gestire un sistema complesso
Permette un utilizzo semplificato di un sistema complesso, ma non permette di utilizzarlo al di fuori di come specificato nell'interfaccia

## Decorator (Wrapper) pattern
Permette di diversificare il comportamento di un oggetto senza dover creare sottoclassi
Un oggetto `Wrapper` o `Decorator` è un oggetto collegato ad un `target`

### In pratica
Si crea un interfaccia per l'oggetto principale (il target)
Poi si definiscono diverse classi che implementano l'interfaccia
Si definisce diverse classi `Decorator` che aggiungono qualcosa all'oggetto
    Per esempio se ci sono 2 oggetti che differiscono solo per il valore di un campo si può definire un decorator il cui getter aggiunge un valore fisso al return del campo
In questo modo si possono annidare diversi decorator per avere oggetti sempre più specifici

## Model-View-Controller
    Per il progetto: crea 3 pacchetti per model/view/controller
Lo scopo è il più possibile dividere i comportamenti tra le classi
Prevede 3 elementi:
- Model
Gestisce la logica
- View
Si occupa della visualizzazione del model e dell'input
- Controller
Processa gli input e li manda al model/view

Il model deve essere completamente separato da view e controller
Spesso il controller necessita un minimo di dipendenza con la view

# Behavioural patterns
Questi pattern riguardano le interazioni e le responsabilità tra gli oggetti

## Observer pattern
Questo pattern aiuta la gestione di eventi asincroni (eg. premere un tasto di un interfaccia)
Questo pattern consiste nel definire un oggetto 'osservato' e degli oggetti 'osservatori'
Quando l'oggetto osservato cambia di stato, tutti gli oggetti osservatori ricevono una notifica e possono reagire

### In pratica
Si definisce una classe `Observable` ed un interfaccia `Observer`
    Presenti in `java.util` ma deprecati
    L'alternativa è `java.util.ReactiveStream` ma è più complicato
La classe `Observable` continene delle reference a tutti gli oggetti sottoscritti ad esso, e chiama in metodo `update()` dell'interfaccia `Observer` quando una condizione è verificata
    `Observable` ha un metodo per aggiungere osservatori
    `Observable` ha 2 metodi per gestire i cambiamenti: `setChanged()` e `notifyObservers()`
        Questi metodi vanno chiamati rispettivamenti ogni volta che cambia un campo e ogni volta che si vuole mandare una notifica agli iscritti

### Reactive Stream
Definita nel pacchetto `java.concurrent.Flow`
Definisce un sistema `Publisher`/`Subscriber` che è in grado di gestire le informazioni in modo asincrono
I `Subscriber` inviano quanti dati sono in grado di gestire al `Publisher`
`Publisher`:
- Per aggiungere osservatori si usa `subscribe()`
- Ha un metodo `close()`
    Indica che non saranno mandati ulteriori dati
- Per mandare la notifica si usa `submit()`
`Subscriber`:
- Ha un campo `subscription`
    Contiene una reference astratta ai publisher
    `subscription` ha un metodo `request(int)` che indica quanti dati può ricevere il subscriber
- Ha un metodo `onSubscribe(Flow.Subscription)`
    Chiamato quando l'oggetto si iscrive
- Ha un metodo `onNext(arg)`
    Chiamato ogni volta che il publisher cambia stato
        Ricorda di chiamare `request()` dopo per essere pronti a ricevere altri dati
- `onError()`
- `onComplete()`

Potrebbe essere necessario processare i dati prima di mandarli agli iscritti, e per questo la libreria fornisce la classe `Processor`
Si mette in mezzo tra il publisher ed i subscriber
    Si iscrive al publisher e i subscriber si iscrivono ad esso
- `onComplete()`
    Chiamato quando il publisher chiama `close()`
    Qua deve chiamare `close()` per noticare gli iscritti
