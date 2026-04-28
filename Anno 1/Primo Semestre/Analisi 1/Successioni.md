Caso particolare di funzione, ha come insieme di partenza i numeri naturali:
$f: \mathbb{N}\rightarrow \mathbb{R}$
# Definizione
Una successione di numeri reali $a_n$ è una funzione da $\mathbb{N}$ a $\mathbb{R}$: $a:\mathbb{N}_{(n)}\rightarrow \mathbb{R}_{a_n}$
$a_n=a_0a_1a_2…a_n$
	$a_n$ n è il termine della successione
	$n$ è l’indice del termine $a_n$

Le successioni possono essere definite solo per certi valori di n:
	$a_n=\frac{1}{n},n≥1$
	$a_n=\frac{1}{n^2-9},n≥4$

**Insieme immagine di una successione**
$Im(a)=a(\mathbb{N})=\{a_n,n\in \mathbb{N}\}$
	Es.
	- $a_n=3,\ a(\mathbb{N})=\{3\}$
	- $a_n=(-1)^n,\ a(\mathbb{N})=\{-1,1\}$

L’immagine di una successione è un *sottoinsieme* di $\mathbb{R}$:
$a(\mathbb{N})\subseteq \mathbb{R}$
	Quindi accetta estremo superiore/inferiore
	
### Esempi di successioni
- **Successione costante**:
$a_n=c$
	Ogni $x\in \mathbb{N}=c$

- **Successione $a_n=n$**:
 $a_n=n$
	 Ogni punto è sulla retta $x=y$

- **Successione degli interi $\mathbb{Z}$**:
$a_n=\{^{\frac{-n}{2}\text{n pari}}_{\frac{n+1}{2}\text{n dispari}}$
$(a_n)_n=0,1,-1,2,-2,…$
	Alterna tra numeri naturali e negativi

- **$a_n=-1^n$**
$(a_n)_n=1,-1,1,-1,…$
	Quando n è pari vale 1, quando n è dispari vale -2

- $a_n=n!$
$(a_n)_n=1,1,1*2,1*2*3,…$

### Successioni limitate/illimitate
Una successione $(a_n)_n$ è **limitata** se $\exists M>0:|a_n|≤M\ \forall n\in \mathbb{N}$
	Cioè $-M≤a_n≤M$
	Cioè $a(\mathbb{N})\subseteq [-M,M]$
	Quindi se la successione ha sia un minorante che un maggiorante

Una successione $(a_n)_n$ è **illimitata** superiormente se l’insieme dei maggioranti $M(a(\mathbb{N}))=\emptyset$
	Cioè $\forall k>0\ \exists\ n_k:(a_n)_k>k$
		Comunque io scelgo k c’è un termine della successione che è maggiore di k
	Se $a_n$ è ill. sup. allora $sup(a(\mathbb{N}))=+∞$
Una successione $(a_n)_n$ è **illimitata** inferiormente se l’insieme dei minoranti $m(a(\mathbb{N}))=\emptyset$
	Cioè $\forall k>0\ \exists\ n_k:(a_n)_k<-k$
		Comunque io scelgo k c’è un termine della successione che è inferiore di k
	Se $a_n$ è ill. inf. allora $inf(a(\mathbb{N}))=-∞$

Una successione illimitata non ammette necessariamente limiti

# [[Limiti di successioni]] di successione
