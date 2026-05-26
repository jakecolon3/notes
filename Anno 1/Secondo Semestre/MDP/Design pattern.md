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

# Behavioural patterns
Questi pattern riguardano le interazioni e le responsabilità tra gli oggetti
