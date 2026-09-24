# Argomenti

- Funzionalità di sistemi per basi di dati DBMS
- Modellazione
- Sistemi relazionali e SQL
- Teoria di database relazionali
- Sistemi NoSQL
- Architettura dei DBMS

# Basi di Dati

Una base di dati raggruppa i dati di un'organizzazione e li relaziona con altri dati.

Un esempio di una base di dati è una tabella

## Sistemi informativi

> Un sistema informativo di un'organizzazione è una combinazione di risorse (umane e materiali) e di procedure organizzate per la raccolta, archiviazione, ...

Il sistema informativo di un'organizzazione è indipendente dalla sua "computerizzazione" (può essere uno schedario ecc.), e opera a supporto delle altre componenti dell'organizzazione

## Sistemi informatici

Il sistema informatico è l'insieme di tecnologie che un sistema informativo può implementare (?)

Il sistema informativo automatizzato è la parte del sistema informativo che gestisce le informazioni usando il sistema informatico

## Perché usare database

I database evitano ridondanza (e quindi possibile inconsistenza) e ?

# DBMS

> Una *base di dati* (o database) è un insieme di file mutuamente connessi.

Questi dati sono organizzati in diverse strutture dati. Per gestire i database si usano i *Database Management System* (DBMS).

### Possibili dati

I tipi di dati che vogliamo collocare in un database possono essere (?)
- Strutturati
    Gli oggetti sono rappresentati da stringhe di simboli e numeri
- Non strutturati
    Linguaggio naturale

??

I database permettono ad ogni componente di un'organizzazione di accedere ai dati che interessano a quella componente, mantenendo sempre però un'unica copia dei dati. Inoltre è possibile stabilire regole di visibilità in base alla componente.

I database devono anche concedere l'accesso e la modifica concorrente dei dati

Nei sistemi computerizzati le informazioni sono rappresentati sotto forma di dati che devono essere interpretati e correlati
    I singoli dati non contengono informazioni, hanno valore solo quando interpretati

# OLTP

L'uso principale dei DBMS è l'*On-Line Transaction Processing*. Utilizzano operazioni predefinite e in genere con pochi dati.

# OLAP

L'use principale dei data warehouse è l'*On-Line Analytical Processing*. Utilizzano operazioni complesse su dati casuali
    Operazioni da data scientist

# DBMS

> Un DMBS è un sistema centralizzato o distribuito che offre linguaggi per
> - Definire lo schema di una base di dati
> - Scegliere le strutture dati per la memorizzazione dei dati
> - Memorizzare i dati rispettando i vincoli definiti nello schema
> - Accedere e modificare i dati interattivamente (*query language*)

Un DMBS è l'interfaccia tra gli utenti e la base di dati

## DB in un DBMS

- Le basi di dati gestite dai DBMS raccolgono dati organizzati in insiemi *strutturati ed omogenei*, tra i quali sono definite delle *relazioni*. La strutture dei dati e le relazioni sono definite nello schema.
- I dati devono essere accessibili tramite *transazioni*: unità di lavoro **atomiche** senza effetti parziali
- I dati devono essere protetti
- I dati devono essere accessibili contemporaneamente da più utenti

## Modello relazionale

Il meccanismo fondamentale dei database relazionali è la *relazione*. Le relazioni sono praticamente tabelle contenenti dati fondamentali.

Per esempio, in un database di studenti, lo studente è una relazione con campi definiti da uno schema (nome, cognome, matricola...)
    Una relazione (o tabella) è un insieme di dati definiti in uno schema
