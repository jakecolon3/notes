Per calcolare il costo computazionale di un algoritmo (nel modello RAM a costo uniforme), bisogna contare le operazioni elementari
Serve quindi individuare la dimensione dell'input dell'algoritmo
Nell'analisi del costo computazionale ci interessa sapere il comportamento asintotico dell'algoritmo per input molto grandi
# Costo delle istruzioni
### Istruzioni elementari
Le istruzioni elementari hanno costo costante ($\Theta(1)$):
- Operazioni aritmetiche
- Lettura/scrittura di variabili
- Valutazione di una condizione logica su un numero costante di operandi
- Stampa del valore di una variabile
### Istruzioni condizionali
Come si calcola il costo di questo programma?
```
if (condizione):
	istruzione1
else:
	istruzione2
```
Dato che ci interessa l'o grande dell'algoritmo, dobbiamo considerare solo l'istruzione più lenta
	Quindi il costo totale sarà il costo della verifica della condizione + il massimo del costo tra istruzione 1 e istruzione 2
### Cicli
Il costo dei cicli è la somma del costo di ogni iterazione del ciclo
	La verifica della condizione è eseguita 1 volta in più rispetto alle istruzioni contenute nel ciclo

Questi 3 tipi di istruzioni bastano per scrivere *qualsiasi* programma
Conoscendo il costo di ogni operazione di un algoritmo, possiamo calcolarne il costo complessivo, che è semplicemente la somma del costo di ogni istruzione

## Input vantaggiosi e svantaggiosi
È possibile che un algoritmo abbia costo computazionale differente ad input di grandezza uguale: per calcolare il caso migliore e peggiore di un algoritmo dobbiamo fissare la dimensione di input
	Se il caso migliore ed il caso peggiore sono la stessa funzione allora l'algoritmo sarà theta di quella funzione
	Se i 2 casi sono diversi *non si può* dire che l'algoritmo è in theta di una funzione

### Calcolo del costo nel caso medio
Per calcolare il costo medio di un algoritmo dobbiamo fare un ipotesi di *equiprobabilità*
Per esempio nella ricerca sequenziale ipotizziamo che ogni indice dell'array ha la stessa probabilità di essere l'elemento cercato
	Abbiamo quindi che la probabilità che l'elemento si trovi nell'i-esima posizione $P=\frac{1}{n}$
	Il numero medio di iterazioni è dato dalla somma di tutte le posizioni \* la loro probabilità = $\frac{1}{n}\cdot \sum_{i=1}^n=\frac{1}{n}\frac{n(n+1)}{2}=\frac{n+1}{2}$
	