Java fornisce un framework per la memorizzazione di gruppi di dati, le `Collections`
Le Collections sono una serie di interfacce che forniscono modi di memorizzare i dati e operazioni su questi gruppi di dati
La principale è l'interfaccia `Collection`

# interface Collection<E>
Estende `Iterable<E>`
Estesa da `Set<E>`, `List<E>`, `Queue<E>`

Questa interfaccia fornisce dei metodi che danno informazioni e operazioni sui dati memorizzati, tra cui:
- `size()`
- `add(E e)`
- `remove(E e)`
- `isEmpty()`
- `add/removeAll(Collection<? extends E>`
Inoltre dato che estende `Iterable`, una classe che implementa collection può essere usata in un for-each
    `Iterable` fornisce anche il *metodo* `forEach(Consumer<T> c)`
    `Consumer<T>` è un'interfaccia funzionale con un solo metodo `void accept(T t)`
Esempio:
```java
List<Integer> l = List.of(1, 2, 3, 5);
l.forEach(x -> IO.println(x)); // stampa ogni elemento di l
```

Normalmente non è possibile rimuovere gli elementi di un Iterable mentre lo si sta iterando, ma si può tramite il suo Iterator:
```java
for (int k : l) { if (k == x) l.remove(x); }            // errore

Iterator<Integer> i = l.iterator();
while (i.hasNext()) { if (i.next() == x) l.remove(x); } // si può fare
```

# interface List<E>
Anche se è un interfaccia, `List` ha un metodo `of(E ...)` che torna un oggetto *immutabile*
Implementazioni:
- `ArrayList`
    Usa un array che viene ridimensionato quando si riempe
- `LinkedList`
    Implementato come lista doppiamente puntata

Hanno un iterator `listIterator` che permette di andare sia avanti che indietro nella lista

# interface Set<E>
Gli insiemi sono Collection che contengono elementi *distinti*
Implementazioni:
- `HashSet`
    Hash table disordinata
- `TreeSet`
    Hash table ordinata
- `LinkedHashSet`
    Hash table che contiene anche una lista puntata che traccia l'ordine di inserimento

# interface Map<E>
Implementazioni:
- `HashMap`
- `TreeMap`
- `LinkedHashMap`
Come i Set ma ci si può accedere tramite chiavi
Si possono ottenere l'insieme delle chiavi (`.keySet()`), l'elenco dei valori (`.values()`) e l'insieme delle coppie chiave-valore (`.entrySet()`)
