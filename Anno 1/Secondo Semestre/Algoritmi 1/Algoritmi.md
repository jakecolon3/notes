https://twiki.di.uniroma1.it/twiki/view/Algoritmi1/Algoritmi1PrimoCanale

La definizione di "informatica" proposta dall'*Association for Computing Machinery* è:
	"La scienza degli **algoritmi** che descrivono e trasformano l'informazione: la loro teoria, analisi, progetto, efficienza, realizzazione e applicazione"
Sono quindi fondamentali nell'informatica
# Definizione di algoritmo
Un algoritmo è: "una sequenza di comandi *elementari* ed *univoci* che terminano in un tempo finito ed operano su strutture dati".
Se i comandi sono elementari ed univoci non serve pensare per eseguire il programma, basta eseguirlo (che i calcolatori fanno molto bene)

# Strutture dati
Per risolvere i problemi dobbiamo gestire i dati necessari: lo facciamo definendo **strutture dati**.
Ogni problema richiede strutture dati differenti; bisogna quindi conoscere le proprietà di ogni struttura per poter risolvere problemi con efficienza.

# Efficienza
È possibile più o meno prevedere il tempo di esecuzione di un algoritmo, ed è importante per poter progettare algoritmi efficienti.
Vedremo come calcolare il costo computazionale degli algoritmi, sia in tempo di esecuzione che in spazio di memoria, in funzione della grandezza dell'input.

# Problem solving
- Analisi del problema
	Leggere il problema e comprenderne le caratteristiche
- Esplorazione degli approcci possibili
	Identificare i possibili metodi di risoluzione
	Inclusi algoritmi pre-esistenti
- Selezione di un approccio
- Definizione dell'algoritmo risolutivo
	Identificare i dati e progettare l'algoritmo definitivo
- Riflessione critica
### Esempio di problema computazionale
- Definizione del problema:
	Orinare $n$ numeri dal più piccolo al più grande
- Input (o "istanza del problema"):
	Sequenza di $n$ numeri $a_1, a_2, ..., a_n$
- Output:
	Permutazione di $n$ numeri ordinati

# Analisi dell'efficienza di un algoritmo
Per valutare l'efficienza di un algoritmo in modo oggettivo si usa la "*Random Access Machine*", una macchina *astratta*, quindi indipendente dalle capacità di un calcolatore specifico
### Random Access Machine
La RAM è:
- Single-core, esegue le operazioni sequenzialmente
- Può eseguire delle operazioni elementari che richiedono tempo **costante**
- Esiste un limite alla dimensione dei dati memorizzati e alla quantità di dati memorizzati. I dati hanno come dimensione massima 2 elevato alla grandezza in bit di ogni parola in memoria (32 o 64)
	Quindi ogni operazione elementare ha tempo costante, dato che la dimensione del dato è finita (misura di costo uniforme)
	È possibile memorizzare dati separandoli in più parole di memoria, ed in questo caso le operazioni elementari non avranno più tempo costante (misura di costo logaritmico)

# Pseudocodice
Nella progettazione degli algoritmi si usa un linguaggio formale, indipendente dal linguaggio di programmazione che si intende usare nell'implementazione, detto *pseudocodice*
Lo pseudocodice utilizza i costrutti di controllo (if... else ecc.), ma può utilizzare il linguaggio naturale per alcune operazioni e spesso omette alcuni dettagli come la gestione degli errori