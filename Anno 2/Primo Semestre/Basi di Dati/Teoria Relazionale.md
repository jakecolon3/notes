# Dipendenze funzionali

I vincoli funzionali sono vincoli che non si basano su una definizione algebrica o matematica ma di "buon senso". Per esempio il vincolo: se due macchine sono dello stesso modello, allora devono essere della stessa casa automobilistica.

Questi vincoli sono difficili da implementare con i trigger, vogliamo evitarli. Ma per evitarli ci serve avere una base di dati "progettata bene" (in terza forma normale)

> Una dipendenza funzionale su uno schema di relazione $R$ è una coppia ordinata $X\to Y$ ("$X$ determina $Y$"), o $(X,Y)$, con $X,Y\subseteq R$.

Le dipendenze funzionali sono simili a funzioni: associano valori di un dominio (i *determinanti*) ad un insieme codominio (dei *dipendenti*).

Esempio:
> Supponiamo di avere uno schema `Voli(Codice, Giorno, Pilota, Ora)`, con i vincoli:
> - Un volo con un certo codice parte sempre alla stessa ora
>   La dipendenza funzionale di questo vincolo è $\text{Codice}\to \text{Ora}$ (`Codice` determina `Ora`).
> - Esiste un solo volo con un dato pilota in una data ora di un dato giorno
>   $\{\text{Giorno},\text{Pilota},\text{Ora}\}\to \text{Codice}$
> - C'è un solo pilota di un dato volo in un dato giorno
>   $\{\text{Codice},\text{Giorno}\}\to \text{Pilota}$

> Una relazione $r$ con schema $R$ *soddisfa* la dipendenza $X\to Y$ se ogni volta che due tuple di $r$ sono uguali su $X$, sono anche uguali su $Y$ (con $X$, $Y$ insiemi di colonne). Formalmente: $\forall t_1,t_2\in r$ se $t_1[x]=t_2[x] \Rightarrow t_1[y]=t_2[y]$.

Un'istanza di relazione *soddisfa* una dipendenza funzionale se non viola il vincolo espresso da essa.

> Dato uno schema $R$ ed un insieme di dipendenze funzionali $F=\{X_1\to Y_1, X_2\to Y_2,...\}$, un'istanza $r$ è *legale* se soddisfa tutte le dipedendenze funzionali di $F$.

> [!NOTE]
> Un'istanza con meno di 2 tuple è sempre legale

## Chiusura di F

Osservazione: data uno schema $R$ con $F={A\to B, B\to X}$, ogni istanza legale soddisfa anche $A\to C$.

L'insieme delle dipendenze funzionali soddisfatte in questo modo è detto *chiusura* dell'insieme di dipendenze di partenza.

> Dato uno schema $R$ con insieme di dipendenze funzionali $F$, l'insieme di dipendenze funzionali soddisfatte da ogni istanza legale è detto *chiusura di $F$*, o $F^+$. Si ha inoltre $F\subseteq F^+$.

Vedremo successivamente una definizione di $F^+$ che non passa per le istanze. Inoltre, con questa definizione ha grandezza esponenziale rispetto ad $F$.
