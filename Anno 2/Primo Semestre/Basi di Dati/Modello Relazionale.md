# Chiavi

Possiamo fissare degli attributi di una relazione come le *chiavi* della relazione. Questi attributi identificheranno un'unica tupla nella tabella.

Un insieme di attributi deve soddisfarre 2 condizioni per essere una chiave:
1. Per ogni istanza della relazione, non esistono 2 tuple che hanno gli stessi valori per tutti gli attributi nell'insieme delle chiavi.
2. Non può esserci un sottinsieme degli attributi scelti che soddisfa la prima condizione (quindi deve essere il minimo sottinsieme degli attributi scelti).

È abbastanza impossibile verificare praticamente che un certo insieme di attributi verifichi queste condizioni, quindi in genere le chiavi sono scelte manualmente durante la progettazione. Bisogna quindi assicurarsi che i vincoli sono impostati correttamente in modo tale da rendere le chiavi scelte valide.

# Riferimenti

Nel modello relazionale, i riferimenti tra i dati sono rappresentati dai valori nelle tuple (boh non so come spiegarlo ma è quando la chiave di una tupla compare in un'altra tupla)

In genere questi riferimenti sono vincolati dai vincoli interrelazionali (e.g. un valore nella colonna "studente" di una tabella "esami" deve comparire nella tabella "studenti")

# NULL

Quando dobbiamo segnalare che una tupla non contiene un certo attributo, usiamo `NULL`

sai cos'è null non te lo devo scrivere

Possiamo vincolare degli attributi in modo che non accettino il valore NULL (le chiavi hanno questo vincolo implicitamente)

# Vincoli

Si possono imporre dei vincoli che vanno rispettati da ogni istanza della tabella. Questi sono detti *vincoli di integrità*.
    Esempio: se Voto < 30 -> Lode = false

![Tipi di vincoli](./images/tipi-vincoli.png)
*Diversi tipi di vincoli.*
