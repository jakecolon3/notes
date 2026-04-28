Codice classroom: w2hdev56
### Esame
Prova in laboratorio
	5-7 esercizi da svolgere in 2-3 ore
	Minimo 18 punti, massimo 32
Niente orale
Consigli:
	Spezzare il problema in più parti
	Non creare e manipolare immagini
	Non risolvere problemi ricorsivamente
	Non saltare la seconda parte del corso
Svolgeremo simulazioni d’esame in laboratorio che danno un bonus di .5 punti se superate
	Sarà necessaria la prenotazione (guardare Classroom)
	Date:
	- 22/10
	- 12/11
	- 26/11
	- 10/12
	- 17/12
	L’ultima se superata può **valere come prova d’esame**

Libri utili:
	“Pensare in Python” (disponibile gratuitamente online)

Software:
	Python Anaconda
	Ambiente di sviluppo

### Argomenti:
- Linguaggio Python
- Tipi di dati, variabili, strutture dati
- Costrutti di controllo
- ecc.

### Risorse utili
Su classroom

### Storia
Telai Jacquard nel 1800 (?) crea una macchina che usa schede perforate per programmare disegni sulla stoffa
Nel 1822 Charles boh progetta la “Difference Engine”
Nel 1848 Ada Lovelace
Nel 1940 sono creati i primi circuiti elettronici, con cui potevano essere creati programmi collegando fisicamente questi circuiti tra di loro
Nel 1948 nasce EDVAC, il primo computer a “programmazione automatizzata”
	Nasce il linguaggio macchina, scritto in codice binario
Nel 1949 nasce ASSEMBLY, che utilizza parole invece che stringhe di 0 e 1 come comandi
Nel 1957 nasce FORTRAN, il primo linguaggio ad “alto livello”, cioè che crea automaticamente le istruzioni da dare alla macchina
Nel 1959 nasce LISP
Nel 1964 nasce BASIC, un linguaggio semplificato per insegnare la programmazoine
Nel 1970 nasce PASCAL, per l’insegnamento della programmazione strutturata. Elimina i GOTO
Nel 1972 nascono Smalltalk, C, SQL, ALGOL, ecc.
1983: C++/C#, linguaggi ad oggwtti
Nel 1991 nasce Python, con focus sulla leggibilità e facilità di utilizzo
1995: Java, JS, PHP
	Il codice Java non deve essere progettato per uno specifico processore, utilizza un processore virtuale


### Linguaggi compilati vs interpretati
**Compilati**:
	C’è un programma diverso che compila il programma, generando un programma in Assembly che contiene il codice oggetto
	Il codice oggetto non mantiene informazioni come nomi delle variabili, mantiene solo le istruzioni strettamente necessarie al computer
	Per essere eseguito il codice oggetto deve essere “linkato” alla/e libreria/e necessarie
	I linguaggi compilati devono essere fermati e compilati nuovamente per fare cambiamenti
	Esempi:
		C, C++, Obj C, Swift, Pascal, Delphi, Rust, Java (passa attraverso JVM)
	Pro:
		Efficienti
		Eseguibili non modificabili (decompilabili)
	Con:
		Più difficili da programmare e imparare
**Interpretati**:
	?
	Meno efficienti nell’esecuzione ma più semplici da programmare
	Esempi:
		BASIC, JS, Python, Perl, PHP
	Python non analizza il linguaggio continuamente ma lo trasforma in un formato più leggibile per l’interpretatore (?)
	Pro:
		Facili da modificare
		Decentemente ottimizzati
		Buona leggibilità (soprattutto Python)
		Facili da imparare
		Molto utilizzati (Python è nella top 3)
	Con:


### Computer
Struttura di Von Neumann:
	- CPU
		Collegata ad input e output
		Riceve dati e li elabora nella memoria
		Contiene un’unità che contiene le istruzioni aritmetiche e logiche
		Contiene diversi registri (tra 32-64), piccoli spazi di memoria molto veloce
	- RAM


### [[Python]]

### Concetti fondamentali
- Le informazioni si trovano nella memoria
- Le variabili sono nomi che corrispondono a spazi nella memoria contenenti dati
- Le istruzioni indicano al computer quali operazioni compiere
- Le funzioni/procedure sono parti di codice riutilizzabili
		Le funzioni restituiscono un risultato (return())
		Le procedure NON restituiscono un risultato ma fanno cose