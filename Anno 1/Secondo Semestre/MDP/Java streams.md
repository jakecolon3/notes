Gli `stream` permettono di manipolare i dati senza modificare la struttura dati da cui sono costruiti
    Hanno un approccio più funzionale
Inoltre sono molto efficienti quando usati con la parallelizzazione
Gli stream hanno uso singolo

# Creare stream
In genere gli stream sono creati a partire da una [[Java Collections|collection]] tramite il metodo `Stream<E> stream()`

## Metodi statici
- `Stream<E> Stream.iterate(E startValue, NextFunc<E>)`
    Crea uno stream *infinito* che parte da `startValue`, con elementi determinati da `NextFunc`
- `Stream<E> Stream.iterate(E startValue, Predicate<E>, NextFunc<E>)`
    Come sopra ma specifica anche una condizione di terminazione

# Riutilizzare stream
Abbiamo visto che gli stream sono utilizzabili solo una volta
Possiamo però creare un oggetto o un metodo che genera stream di una certa collection
    Per esempio con un `Supplier<>`

# Operare su stream
Le operazioni su stream sono divise in operazioni *intermedie* e operazioni *terminali*
Ci sono anche stream "lazy" che raccolgono le operazioni intermedie effettuate su di essi e le eseguono tutte quando si effettua un operazione terminale, chiudendo lo stream

## Ordine di operazioni
L'ordine delle operazioni su uno stream è importante: vengono eseguite nell'ordine in cui sono chiamate sullo stream

### Metodi 'stateful'/'stateless'
Alcuni metodi hanno bisogno di informazioni sullo stato dello stream (per esempio `sorted`)

### Operazioni intermedie
- `distinct()`
    Torna uno stream con solo gli elementi unici dello stream
- `limit(Long k)`
    Torna uno stream con i primi `k` elementi dello stream
- `skip(Long k)`
    Torna uno stream senza i primi `k` elementi dello stream
- `takeWhile(Predicate<E>)`
    Torna uno stream con tutti gli elementi fino al primo elemento che fallisce la condizione
- `dropWhile(Predicate<E>)`
    Contrario di `takeWhile`
- 

### Operazioni terminali
- `collect(Collector)`
    Vedi [[Java streams#Collectors|collectors]]
- `reduce(E identityValue, BiFunction<E, E, E>)`
    Riduce lo stream ad 1 elemento in base alla funzione fornita
- `boolean anyMatch(Predicate<E>)`
    Torna `true` se almeno 1 elemento soddisfa la condizione
- `boolean allMatch(Predicate<E>)`
    Torna `true` se tutti gli elementi soddisfano la condizione
- `boolean noneMatch(Predicate<E>)`
    Contrario di `anyMatch`

## Collectors
Permettono di ridurre il numero di elementi di uno stream, raccogliendoli in 1 singolo oggetto
Usati chiamando `.collect(Collectors.<metodo statico>)` su uno stream
Vedi esempi

### Metodi statici
Tutti (?) i metodi di Collectors hanno come parametro opzionale un riferimento al costruttore del tipo di dati specifico da tornare
- `Map<S,List<T>> groupingBy(Function<T,S>)`
- `Map<S,List<T>> groupingBy(Function<T,S>, Collector downStreamCollector)`
    Raccoglie elementi di tipo `T` in una mappa a chiavi di tipo `S`
- `Collector<Input, Accumulator, Output> of(SupplierFunc<Accumulator>, AccumulatorFunc<Accumulator, Input>, CombinerFunc<Accumulator>, FinisherFunc<Output>)`
    Crea un collector personalizzato
    - Il `Supplier` crea il contenitore per gli elementi
    - L'`Accumulator` specifica come inserire gli oggetti nel contenitore
    - Il `Combiner` determina come unire diverse istanze del contenitore in modo da poter consentire il parallelismo
    - Il `Finisher` trasforma il `Supplier` al tipo `Output`
- `Map<Boolean,List<T>> partitioningBy(Predicate<T>)`
    Torna una mappa a valori booleani con elementi determinati da `Predicate`

# Stream specifici
Ci sono anche degli stream specializzati per certi tipi di elementi
Hanno operazioni specifiche e ottimizzate per il tipo di dato

## IntStream
Assume che ogni elemento dello stream è un intero

### Metodi
- `IntStreamStatistics summaryStatistics()`
    Metodo terminale che torna un oggetto contenente informazioni sugli elementi dello stream
- `max, min, average...`
    Terminali

# Parallelismo
Gli stream sono ottimizzati per le [[Java multithreading|operazioni in parallelo]]
C'è una classe `ParallelStream` che gestisce le operazioni su di essa in parallelo
    Lo fa automaticamente

## Operazioni parallelizzabili
Non tutte le operazioni possono essere eseguite in parallelo
    Se un operazione ha bisogno dell'output di un operazione precedente non può essere parallelizzata
Quindi solo le operazioni stateless sono parallelizzabili
