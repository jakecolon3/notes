# Definizione
I dizionari sono una [[Strutture dati|struttura dati]] astratta dinamica con 3 operazioni:
- Inserimento
- Ricerca
- Rimozione
I dizionari sono fondamentali nelle basi di dati

Tra le strutture dati che abbiamo visto, ci sono alcune strutture che potremmo usare per memorizzare i dizionari: array, liste concatenate e liste concatenate doppie
Ma non sono adeguate per questa struttura: negli array ordinati la rimozione e l'inserimento sono in $O(n)$, la ricerca negli array disordinati è in $O(n)$, ecc.
Ci servono delle nuove strutture dati:
- Tabelle and indirizzamento diretto
- Tabelle hash
Queste tabelle sono memorizzate come array, quindi hanno dimensione fissa
### Nomenclatura
- $U$: insieme "universo" dei valori che le chiavi *possono* assumere; sono numeri interi
- $m$: numero di posizioni a disposizione nella struttura dati
- $n$: numero di elementi presenti nel dizionario; gli elementi hanno chiavi diverse tra di loro

## Tabelle a indirizzamento diretto
Molto banalmente una tabella ad indirizzamento diretto è un array dove ogni elemento è posizionato all'indice pari alla sua chiave
Ovviamente in questo modo ognuna delle 3 operazioni necessarie hanno costo in tempo lineare

Però questa struttura ha un problema: l'array dovrà essere grande quanto tutti i possibili valori che le chiavi possono assumere
Ovviamente questo non è pratico, quindi vogliamo trovare una tabella che funziona in modo simile ma che ha un numero di possibili chiavi più vicino al numero di elementi che vogliamo memorizzare

## Tabelle hash
Assumendo che $m > n$, si può definire una funzione detta *funzione hash* che data una chiave calcola l'indice corrispondente alla chiave
Però c'è un problema: dato che l'insieme delle chiavi possibili è molto più grande dell'insieme delle chiavi attuali, potrebbe succedere che la funzione hash assegni lo stesso indice a 2 valori diversi
Una buona funzione hash quindi rendere il più possibile equiprobabili i valori fino a $m - 1$ che produce; deve quindi apparire come una funzione casuale, ma deve essere comunque deterministica in modo tale da poter accedere ai suoi elementi
    L'ipotesi che ogni valore avrà un hash differente è detta *ipotesi di uniformità semplice della funzione hash*
Le collisioni sono però inevitabili, quindi bisogna risolverle in qualche modo
### Liste di trabocco
Risolve le collisioni inserendo tutti gli elementi che hanno lo stesso hash in una [[Strutture dati#Liste puntate semplici|lista concatenata]]
In media le liste avranno lunghezza 1, ma è tecnicamente possibile che ogni elemento finisca nella stessa lista
Quindi in media il costo di ricerca è costante, ma nel caso peggiore è in $\Theta(n)$
Il costo di inserimento è sempre costante
Il costo di cancellazione è relativo al costo di rimozione delle liste puntate/doppiamente puntate

