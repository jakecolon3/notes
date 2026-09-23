### Info

testi:
- "Operating Systems Concepts" 9th edition - Silberchatz...
- "Modern Operating Systems" 4th edition - Tanenbaum...
- "[Operating Systems: Three Easy Pieces][os-online]" - Remzi...

[os-online]: http://pages.cs.wisc.edu/~remzi/OSTEP/

# Introduzione

un sistema operativo è un pezzo di software che gestice l'hardware di un computer, quindi per capire che ruolo hanno è utile indagare l'architettura dell'hardware di un computer

## cosa fanno i sistemi operativi

iniziamo osservando il ruolo dei sistemi operativi in un sistema computazionale  
un sistema computazionale può essere diviso in 4 componenti:
- hardware
- sistema operativo
- applicazioni
- utente
l'hardware fornisce le risorse computazionali per il sistema; le applicazioni decidono queste risorse sono utilizzate per risolvere i problemi dell'utente; il sistema operativo gestisce controlla l'hardware e ne coordina l'utilizzo tra le diverse applicazioni degli utenti
    il sistema operativo non fa niente di utile da sè, ma crea uno spazio in cui altre applicazioni possono lavorare
```
 -------------------
|       utente      |
 -------------------
          ^
          | interagisce con
          v
 -------------------
|     applicazioni     |
 -------------------
          ^
          | interagiscono con
          v
 -------------------
| sistema operativo |
 -------------------
          ^
          | interagisce con
          v
 -------------------
|      hardware     |
 -------------------
```
*i componenti di un sistema computazionale*

osserveremo i sistemi operativi da 2 lenti diverse: quella dell'utente e quella del sistema

### utente

la maggior parte dei computer è ottimizzato per l'utilizzo da un singolo utente, e per massimizzare la produttività di questo. quindi un sistema operativo progettato a questo scopo dà priorità principalmente alla *semplicità di utilizzo* (e alla performance e sicurezza), tralasciando la *condivisione dell'utilizzo delle risorse*  
un sistema operativo per un dispositivo mobile, invece, deve supportare connettività wireless e input da touchscreen o microfono  
i computer presenti, per esempio, negli elettrodomestici e nelle macchine (detti "embedded") in genere hanno poco o nulla di interfaccia per utenti, e sono quindi progettati per essere utilizzati principalmente senza intervento dall'utente

### sistema

dal punto di vista del computer, il sistema operativo è principalmente un gestore delle risorse hardware e dei suoi input e output  
deve gestire le richieste per le risorse da parte delle applicazioni in modo da operare il computer in maniera efficiente

---

### definire "sistemi operativi"

originalmente i computer erano specializzati per un singolo utilizzo, ma con la loro evoluzione a sistemi *general-purpose* è nata la necessita dei sistemi operativi per gestirne le risorse. come abbiamo visto, però, un sistema operativo deve essere progettato in base all'utilizzo previsto (direi non serve un touchscreen sulla tua lavatrice, ma...), quindi sono nati un gran numero di sistemi operativi specializzati a diversi compiti  
non c'è quindi un'unica definizione di "sistema operativo". in genere, però, i sistemi operativi hanno come scopo rendere più semplice l'esecuzione dei programmi e la risoluzione dei problemi dell'utente

una definizione utile, però, è questa: **il sistema operativo è l'unico programma che è *sempre* in esecuzione nel computer**. questo programma è spesso anche chiamato *kernel*.  
oltre al kernel, ci sono altri due tipi di programmi: i **programmi di sistema**, che sono associati al sistema operativo ma non necessariamente parte del kernel (per esempio i driver per le periferiche del sistema), e le **applicazioni**, che sono tutti i programmi non associati con l'operazione del sistema.

spesso i sistemi operativi (come quelli per dispositivi mobili) includono programmi che non sono parte del kernel ma che forniscono altri funzionalità per sviluppatori ed utenti

## organizzazione dei sistemi computazionali

un computer moderno consiste di uno o più *processori* e di diversi *device controller* connessi attraverso un **bus** comune il quale fornisce l'accesso tra i componenti e la memoria condivisa. ogni controller è incaricato di uno specifico tipo di dispositivo (usb, display, disco ecc.)  
in genere ogni controller è associato ad un *driver* nel sistema operativo che espone un'interfaccia uniforme al resto del sistema  
infine, un *controllore della memoria* assicura l'accesso ordinato alla memoria condivisa.

### gli interrupt

un controller di un dispositivo deve poter informare il driver associato quando finisce un operazione. questo è compiuto tramite un **interrupt**.

#### funzionamento

l'hardware può mandare un interrupt al processore in qualsiasi momento tramite il bus di sistema. quando il processore riceve un interrupt, interrompe quello che sta facendo e sposta l'esecuzione ad un indirizzo di memoria predefinito, esegue del codice, e poi riprende l'esecuzione del programma precedente.

dato che gli interrupt sono molto frequenti, la loro gestione deve essere rapida. per questo motivo l'indirizzo al codice da eseguire quando è ricevuto un interrupt è tenuto in un array all'inizio della memoria indicizzato da un numero mandato insieme alla richiesta di interruzione.

in pratica, nei sistemi operativi moderni è necessario un sistema più sofisticato:
- bisogna poter ritardare la gestione degli interrupt durante processi critici
    boh
- serve un sistema efficiente per la scelta del gestore dell'interrupt
    l'array degli interrupt contiene indirizzi a liste di handler
- serve un sistema di priorità per gli interrupt
    implementato con 2 linee di richiesta di interruzione



continua a p39; 1.2.2
