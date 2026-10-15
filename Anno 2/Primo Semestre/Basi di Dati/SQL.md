Il linguaggio più utilizzato per interagire con basi di dati è *SQL* (Structured Query Language).

SQL contiene istruzioni sia per definire (DDL; Data Definition Language) una base di dati che per interrogarla (DML; Data Manipulation Language).

# Storia

Lo standard SQL nasce nel 1983, ma già esistevano delle implementazioni. Anche oggi lo standard non è seguito alla lettera da ogni implementazione.

---

SQL è formato da diversi "sottolinguaggi" con funzionalità diverse:
- DDL (Data Definition Language)
    Definizione della base di dati
- DML (Data Manipulation Language)
    Manipolazione dei dati nella base
- DQL (Data Query Language)
    Interrogazione dei dati
- DCL (Data Control Language)
    Gestione dei permessi di accesso

# DDL

Vediamo come implementare una base di dati progettata seguendo il processo che abbiamo visto usando SQL

## Domini

SQL ha dei domini (tipi) predefiniti, ma è anche possibile definirne altri.

I domini predefiniti sono:
- Carattere
- Bit
    Singoli o sequenze di bit
- Numero
    Interi, fratti
- Data/Ora/Intervallo
- Da SQL 1999:
    - Bool
    - File grandi (binari o di testo)

Per creare domini personalizzati ("ad hoc") si usa l'istruzione `CREATE DOMAIN`. Per esempio:
```sql
CREATE DOMAIN Voti
    AS SMALLINT DEFAULT NULL
    CHECK (value >= 18 AND value <= 31 )
```
Questo comando crea un nuovo dominio *Voti* che può contenere valori interi tra 18 e 31, inizializzato a `NULL`.

Il comando `CHECK` viene utilizzato spesso per definire vincoli, e può anche essere utilizzato direttamente nella definizione di una tabella per imporre vincoli sui valori consentiti.

## Definizione degli Schemi

Per creare tabelle si usa l'istruzione `CREATE TABLE`, seguita dal nome e gli attributi, domini, e vincoli.

Esempio:
```sql
CREATE TABLE Impiegato(
    Matricola CHAR(6) PRIMARY KEY,
    CF CHAR(16) UNIQUE,
    Nome CHAR(20) NOT NULL,
    Cognome CHAR(20) NOT NULL,
    Dipart CHAR(15) REFERENCES
        Dipartimento(Codice),
    Stipendio NUMERIC(9) DEFAULT 0,
    -- per aggiungere vincoli a più attributi si scrive prima il vincolo e poi la tupla di attributi
    UNIQUE (Cognome, Nome)
);
```

Con questo comando si crea una tabella `Impiegato` con chiave primaria `Matricola`, vari altri attributi (tra cui `Dipart` che si riferisce all'attributo `Codice` di un'altra tabella `Dipartimento`), e con il vincolo che ogni coppia `Cognome, Nome` deve essere unica.
    Teoricamente si dovrebbe usare `VAR CHAR` per dire "stringa fino a (x) caratteri"; solo `CHAR` impone che sia esattamente quella lunghezza

### Vincoli

Da notare che il comportamento di default di SQL è accettare valori nulli per gli attributi. Per evitare valori nulli si deve utilizzare `NOT NULL`.

`UNIQUE` definisce attributi o insiemi di attributi non ripetibili.

`PRIMARY KEY` implica `UNIQUE` e `NOT NULL`.

Per definire vincoli interrelazionali si usano le keyword `REFERENCES` e `FOREIGN KEY`.
    La tabella da cui proviene il riferimento è detta "master", quella che lo importa è detta "slave".

Si possono definire delle politiche per gestire le violazioni di vincoli. Se non sono definite politiche il comportamento di default è annullare l'operazione.

Le politiche più utilizzate sono:
- `ON DELETE SET NULL`
    Quando una riga è cancellata i riferimenti a quella riga sono settati a `NULL`.
- `ON DELETE CASCADE`
    Quando una riga è cancellata le righe contenente riferimenti a quella riga sono *eliminate*.
- `ON UPDATE SET NULL`
    Quando una riga è aggiornata i riferimenti a quella riga sono settati a `NULL`.
- `ON UPDATE CASCADE`
    Quando una riga è aggiornata i riferimenti a quella riga sono aggiornati con i nuovi valori.

Le politiche sono settate quando si definisce una tabella:
```sql
CREATE TABLE Infrazione(
    Codice CHAR(6) PRIMARY KEY,
    Vigile CHAR(4)
        REFERENCES Vigili(Matricola)
        ON UPDATE CASCADE,
    ...
);
```

Per definire vincoli più complessi si utilizza `CHECK (<condizione>)`. Per esempio:
```sql
CREATE TABLE Impiegato(
    Matricola CHAR(6),
    Sesso CHAR NOT NULL
        CHECK (Sesso IN ('M', 'F')),
    ...
);
```

Per definire vincoli tra colonne si aggiunge `CHECK (cond)` dopo gli attributi.

Questi vincoli in SQL sono detti `CONSTRAINT`, e sono definibili usando la keyword `CONSTRAIN` ed un *nome*. I vincoli definiti in questo modo sono manipolabili con il comando `ALTER TABLE`.

![Esempio di definizione con keyword CONSTRAINT](./images/constraint-keyword-example.png)
*Esempio di un vincolo definito tramite `CONSTRAINT`.*

### Indici

Gli indici sono riferimenti a record nel file principale: è mantenuto un file che associa un valore (o gruppo di valori) di un record al record effettivo. Questo rende l'accesso ai dati più veloce, dato che va cercato solo il file dei record (più piccolo) e non il file principale.

Servono solo per ottimizzare l'accesso ai dati, non sono parte dello schema della base.

Gli indici sono creati con `CREATE INDEX`:
```sql
CREATE INDEX nomeIndice
    ON nomeTabella(attr1, attr2, ...);
```
Quando si effettua un'interrogazione sugli attributi per cui si è definito un indice si avrà un tempo di ricerca minore.

Se si usa `CREATE UNIQUE INDEX...` è aggiunto un vincolo di unicità *alle colonne utilizzate nell'indice*. È consigliato usare la keyword `UNIQUE` nella creazione della tabella, non negli indici.

Gli indici hanno diversi vantaggi:
1. Ricerche filtrate più veloci
2. Ottimizzano relazioni
3. Raggruppamento più rapido
    I file indice sono ordinati

Ma anche degli svantaggi:
1. Rallentano le operazioni di modifica, dato che devono essere aggiornati gli indici
2. Occupano spazio su disco

Per questo, è meglio utilizzare gli indici solo su colonne usate frequentemente.

## Modifica degli Schemi

Alcuni comandi di modifica:
- `ALTER DOMAIN`
    Modifica la definizione di un dominio
    - `[SET|DROP] DEFAULT`
        Aggiunge o rimuove un valore di default
    - `[SET|DROP] NOT NULL`
        Modifica vincolo di nullabilità
    - `ADD CONSTRAINT nome...`
        Aggiungi nuovo constraint
    - `DROP nomeConstraint`
        Rimuovi constraint
    - `RENAME TO...`
        Rinomina dominio
- `ALTER TABLE nomeTabella`
    Aggiunge o elimina attributi o vincoli
    - `ADD nomeAttributo nomeDomain`
        Aggiungi nuova colonna con dominio specificato
    - `DROP COLUMN nomeAttributo`
        Rimuovi colonna specificata
    - `MODIFY nomeAttributo nomeDominio` o `ALTER COLUMN nomeAttributo SET DATA TYPE nomeDominio` (in base al linguaggio)
        Modifica dominio di una colonna
    - `ADD CONSTRAINT...`
        Aggiunge constraint
    - `DROP CONSTRAINT nomeConstraint`
        Rimuove constraint
    - `RENAME TO nuovoNome`
        Rinomina attributo
- `DROP DOMAIN`
    Elimina un dominio
- `DROP TABLE`
    Elimina una tabella, sia lo schema che l'istanza
- `DROP INDEX`
    Elimina un indice
- `DELETE <query>`
    Elimina le righe ottenute da un'interrogazione
- `TRUNCATE nomeTabella`
    Elimina le righe di una tabella
...

## View

Con il comando `CREATE VIEW` si può creare una tabella *virtuale* contenente un sottoinsieme degli attributi di una tabella. Simile a `SELECT`, ma non crea una copia dei dati che soddifsano il query.

Al contrario delle tabelle create da `SELECT`, le viste sono automaticamente aggiornate quando sono aggiunti nuovi dati che soddisfano il query.

Le viste sono interrogabili esattamente come le tabelle normali.

# DML

Un Data Manipulation Language serve a manipolare i *dati* all'interno di una base senza modificarne lo schema.
