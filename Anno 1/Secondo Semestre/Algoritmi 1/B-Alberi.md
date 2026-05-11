Parte dei [[Dizionari|dizionari]]
Dato che le strutture dati memrizzate con puntatori (come gli alberi visti finora) non hanno garanzie di ordine dei dati in memoria, spesso capita che per ogni accesso consecutivo ad una di queste strutture dati bisogna accedere a memoria secondaria e non memoria centrale
    Dato che gli array sono memorizzati sequenzialmente, accedere ad 1 dato di un array carica l'intero array in memoria centrale
Abbiamo visto che ogni accesso ad un albero consiste nello scorrere un ramo di un albero
Quindi per ridurre il numero di accessi a memoria secondaria bisogna ridurre l'altezza dell'albero
Per ridurre l'altezza, nei B-alberi ogni nodo contiene *più* chiavi
In particolare ogni nodo contiene un *array* di chiavi
Questo aiuta perché così ogni accesso carica un array di chiavi in memoria invece che solo una chiave
Sono comunque bilanciati per garantire altezza logaritmica

# Definizione
Un B-albero di grado minimo $t\geq 2$ ha le seguenti proprietà:
    Il numero di chiavi massime in ogni nodo è proporzionale al grado
- La radice contiene $s$ chiavi memorizzate in ordine crescente, con $0\leq s\leq 2t-1$
- Ogni altro nodo contiene $s$ chiavi memorizzate in ordine crescente, con $t-1\leq s\leq 2t-1$
- Un nodo interno con $s$ chiavi $k_1 < k_2 < ... < k_s$ ha $s+1$ figli
Per le chiavi negli $s+1$ sottoalberi $T_i$, si ha:
- Le chiavi in $T_1$ sono minori di $k_1$
- Le chiavi in $T_{s+1}$ sono maggiori di $k_S$
- Le chiavi in $T_i$ con $1 < i < s+1$ sono comprese tra $k_{i-1}$ e $k_i$

Quindi in un B-albero:
- Ogni nodo ha un numero di figli pari al suo numero di chiavi + 1
- Ogni array di chiavi è ordinato
- I nodi sono ordinati in base alle loro chiavi più piccole e più grandi
    Quindi `[6, 34] a sinistra di [44, 51, 60] a sinistra di [68, 73]...`
- Ogni nodo contiene un numero di chiavi tra il grado dell'albero - 1 e 2 * il grado dell'albero - 1

## Utilità dei B-alberi
Alcuni pro dei B-alberi:
- Riducono la necessità di passare da un nodo ad un altro
- Si possono effettuare inserimenti e rimozioni senza dover modificare l'intera struttura, solo una piccola parte (come gli AVL)

## Bilanciamento
Dimostriamo che i B-alberi sono bilanciati
Dato che il numero di figli dipende da $t$, dobbiamo dimostrare che l'altezza è in ordine di $\log_t n$
Vediamo i casi estremi:
- Ogni nodo contiene il numero minimo di chiavi:
Quindi la radice ha 1 chiave e 2 figli e ogni altro nodo ha $t-1$ chiavi e $t$ figli
A parità di altezza, il numero minimo di chiavi è:
$$
n_{min} = 1 + 2(t-1) \sum_{j=0}^{h-1} t^j = 2(t-1) \frac{t^h-1}{t-1} > 2(t^h-1)
$$
Quindi dato che $n\geq n_{min} \longrightarrow h<\log_t(n/2+1)$

- Ogni nodo contiene il numero massimo di chiavi:
Quindi ogni nodo contiene $2t-1$ chiavi e ha $2t$ figli
A parità di altezza, il numero massimo di chiavi è:
$$
n_{max} = \sum_{j=0}^{h} (2t-1)(2t)^j = (2t-1)\frac{(2t)^{h+1}-1}{2t-1}=(2t)^{h+1}-1
$$
Quindi dato che $n\leq n_{max} \longrightarrow h\geq\log_{2t}(n+1)-1$

Riassumendo:
$$
\log_{2t}(n+1)-1\leq h < \log_t(n/2+1) \longrightarrow h=\Theta(\log_t n)
$$
Osservazioni:
- In generale $t$ non cresce con $n$
- Nel caso in cui $t=\Theta(1)$ si ha $h=\Theta(\log n)$
Inoltre con $N=$ numero nodi e $n=$ numero chiavi:
$$
(t-1)(N-1)\leq n\leq 2(t-1)N
$$

## Operazioni
### Ricerca
Strategia:
- Parti dalla radice `r`
    Se è vuota torna `None` (caso base)
- Ricerca in foglia:
    Se `k` è nel nodo torna puntatore e indice di `k`
- Ricerca in nodo interno:
    Se `k` è nel nodo torna puntatore e indice di `k`
    Altrimenti procedi ricorsivamente:
        Se `k` è minore della chiave più piccola vai a sinistra, se è maggiore vai a destra altrimenti vai in mezzo al ramo dove "dovrebbe essere" la chiave nell'array

Orientativamente il costo sarà proporzionale all'altezza e al numero di chiavi
Costo: $\begin{cases} T(h) = T(h-1) + O(\log t) \\ T(0) = O(t) \end{cases}$
Soluzione: $O(\log t h) = O(\log t \log_t n) = O(\log t (\log n/\log t)) = O(\log n)$

### Inserimento
- Cerca la foglia in cui inserire `k`
    Inserisco la chiave nell'array ordinato
    Se il numero delle chiavi è il massimo devo fare un operazione di `split`

#### `split`
Se sto inserendo in un nodo con $2t-1$ chiavi, devo spezzare il nuovo nodo con $2t$ chiavi in 2
    Dato che il numero di figli di un nodo deve essere pari al suo numero di chiavi + 1 una delle chiavi deve essere aggiunta al padre
        Se anche il padre diventa pieno bisogna procedere ricorsivamente verso l'alto
        Quindi se si propaga fino alla radice *cambia l'altezza dell'albero*
    Poi divido l'array

Costo:
- Ricerca: $O(\log t)$ con ricerca binaria
- Inserimento nell'array ordinato: $O(t)$
- Split: $O(1)$ ripetuta al più $h$ volte: $O(\log_t n)$
Totale: $O(t\log_t n)$

### Rimozione
- Ricerca fino al nodo `P`
    Non è necessariamente una foglia come prima
- Se `P` è interno `k` viene sostituita con il suo predecessore e ci riduciamo alla cancellazione in una foglia
    Il predecessore sarà necessariamente una foglia (è il nodo più a destra nel sottoalbero sinistro (relativo alla chiave) senza figli)
        Rivedi predecessore di [[Dizionari#Alberi binari di ricerca|ABR]]
- Se `P` è una foglia si rimuove la chiave dall'array
- Dopo la rimozione `P` potrebbe non avere il minimo di $t-1$ chiavi
    Se è possibile si prende un figlio dal fratello sinistro o destro
    Altrimenti se anche i fratelli sono al minimo si deve fondere `P` con uno dei suoi fratelli prendendo una chiave dal padre
        $t-1 + t-1 + 1 = 2t-1$

Costo:
- Ricerca: $O(\log t)$ con ricerca binaria
- Cancellazione di `k`: $O(t)$
- Spostamento di chiavi: $O(1)$
- Fusione: $O(t)$ ripetuta al più $h$ volte: $O(\log_t n)$
