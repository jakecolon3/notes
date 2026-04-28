# Definizione di funzione
Siano X, Y due insiemi
ƒ: X -> Y
	Una funzione ƒ definita in X a valori in Y è una legge che associa ad **ogni elemento** x ∈ X *un* elemento y ∈ Y
	y **dipende** da x: y = ƒ(x)
X è il *dominio* della funzione
Y è il *codominio* della funzione
L’insieme degli elementi y = ƒ(x) formano l’*immagine* di ƒ
	Im(ƒ) = ƒ(X) = {ƒ(x) ∈ Y, x ∈ X} ⊆ Y

**Esempi di funzioni**:
- X = {studenti Sapienza}, Y = {numeri di matricola degli studenti}
	ƒ: studente –> # matricola
- X = {studenti Sapienza}, Y = {altezza in cm}
	ƒ: studente –> altezza
- X = {sedie in aula}, Y = {studenti in aula}
	ƒ: sedia –> studente
	Dato che non tutte le sedie sono occupate questa *non è una funzione*, ƒ deve essere definita su tutti gli elementi x
- X = {studenti in aula}, Y = {sedie in aula}
	ƒ: studente –> sedia

### Funzioni suriettive ed iniettive
ƒ: X –> Y
ƒ è:
- *Suriettiva* se ƒ(X) = Y
	Cioè se ∀ y ∈ Y ∃ x ∈ X: ƒ(x) = y
	Posso “tornare indietro” da Y (funzioni invertibili)
	La funzione del primo esempio è suriettiva
		Se modifichiamo il suo codominio a Y = ℕ *non è più* suriettiva: ci sono matricole che non sono state assegnate ad uno studente
	Se ho una ƒ: X –> Y non suriettiva, posso considerare un’altra funzione suriettiva ”restringendo” il codominio:
		ƒ: X –> ƒ(X)
	Per verificare in quale intervallo una funzione è suriettiva invertila e trova il dominio della funzione inversa, la funzione sarà suriettiva in $dom(f)\rightarrow dom(f^{-1})$
- *Iniettiva* se ∀ x1, x2, x1 ≠ x2 allora ƒ(x1) ≠ ƒ(x2)
	Quindi ogni valore y può avere massimo 1 valore di x ad esso associato
		Funzione sempre crescente o decrescente
	Dire che ƒ è iniettiva è equivalente a dire che ogni retta orizzontale che interseca il grafico Γ(ƒ) lo interseca *una sola volta*
	Per verificare l’iniettività risolvi l’equazione $f(x_1)=f(x_2)$ e controlla che l’unica soluzione è $x_1=x_2$
- *Biettiva* o *biunivoca* se ƒ è **sia suriettiva che iniettiva**
# Grafico di una funzione
Il grafico di ƒ è un sottoinsieme del piano ℝ^2:
$$
Γ(f) = {(x, f(x)), x ∈ X} ⊆X\cdot Y
$$
Dal grafico di una funzione si può stabilire se una funzione $f$ è iniettiva o suriettiva:
	- $f$ è iniettiva se ogni retta orizzontale che interseca $\Gamma(f)$, lo interseca **una sola volta**
	- $f$ è suriettiva in Y se ogni retta orizzontale $y = c \in Y$ interseca il grafico 
### Grafici fondamentali
- **Retta**
	$f(x) = ax + b, (a, b) ∈ ℝ$
	$f: ℝ \rightarrow ℝ$ (dominio e codominio sono uguali)
	$\Gamma(f) = {(x, ax+ b), x ∈ ℝ} ⊆ ℝ^2$
		*Non è iniettiva* per a = 0, iniettiva per a ≠ 0
		*Non è suriettiva* per a = 0, suriettiva per a ≠ 0
- **Parabola**
	$f(x) = x^2:ℝ\rightarrowℝ$
		$x≠0, f(x_{1})=f(-x_{1})=(x_{1}^2)$
		Iniettiva *solo in* $[0,+∞)=X$ **oppure** $(-∞,0]$
		Suriettiva *solo in* $[0,+∞)$
			Quindi $x^2:[0,+∞)\rightarrow[0,+∞)$ è *biunivoca*
- **Modulo**
	$f(x)=|x|=\{^{x\ se\ x≥0\ \ \ \ \ \ y=x}_{-x\ se\ x<0\ \ \ y=-x}$
		Iniettiva in $[0,+∞)$ oppure $(-∞,0]$
		Suriettva in $[0,+∞)$
- **Iperbole**
	$f(x)=\frac{1}{x}\rightarrow x\cdot y=1$
		$X=dom(f)=ℝ\text{\\}\{0\}\rightarrowℝ$
		Iniettiva nel suo dominio
		Suriettiva in $ℝ\text{\\}\{0\}$
- **Parabola con a,b,c variabili**
	$f(x)=ax^2+bx+c$
		$a,b,c\inℝ,a≠0$
	$\Gamma(x)$: parabola
		Rivolta verso l’alto se $a>0$
		Rivolta verso il basso se $a<0$
		Non iniettiva in ℝ
		Non suriettiva in ℝ
- **Seno e coseno** 
	$f(x)=\sin x:ℝ\rightarrowℝ$
	$g(x)=\cos x:ℝ\rightarrowℝ$
		$(\sin x)^2+(\cos x)^2=1$
		Assumono sempre valori compresi tra -1 e 1:
			$-1≤\sin x≤1$
			$-1≤\cos x≤1$
		Periodiche con periodo $2\pi$
		Non iniettive in ℝ
		Non suriettive in ℝ
- **Esponenziale**
	$a>0\rightarrow a^x$
	$x=\frac{p}{q}\in \mathbb{Q},(q,p)>0$
		$a^{\frac{p}{q}}=\sqrt[q]{a^p}=(\sqrt[q]{a})^p$
	$x=\sqrt{2}$
		Per trovare $a^\sqrt{2}$:
		$E=\left\{ 2^r,r=\frac{q}{p},r≤\sqrt{2} \right\}$
- **Logaritmo**
	Inverso dell’esponenziale
	$f(x)=\log_a{x}:\mathbb{R}^+\rightarrow \mathbb{R}$
	$dom(f)=\{x\in \mathbb{R}:x>0\}$

### Operazioni elementari con i grafici
Prendiamo una funzione $f(x)$
	Il grafico di $g(x)=f(x)+c$ è dato da una traslazione verticale di $\Gamma(f)$:
		- Verso l’alto se $c>0$
		- Verso il basso se $c<0$
	Il grafico di $g(x)=f(x+c)$ è dato da una traslazione orizzontale di $\Gamma(f)$:
		- Verso destra se $c<0$
		- Verso sinistra se $c>0$
	Il grafico di $g(x)=f(cx),c\in\mathbb{R}\text{\\}(0,1)$ è dato da una dilatazione di un fattore $\frac{1}{c}$

### Funzione inversa
Prendiamo una funzione biiettiva $f: X\rightarrow Y=f(X)$
	Suriettività: $\forall y \in Y \exists{x}\in X:y=f(x)$
	Iniettività: $\forall y \in Y \exists !x \in X:y=f(x)$
Da una funzione biunivoca possiamo definire una nuova funzione che ad ogni $y\in Y$ associa una $x\in X:f(x)=y$, detta **funzione inversa**:
$$
x=f^{-1}(y)=f^{-1}(f(x))
$$
$$
y=f(x)=f(f^{-1}(y))
$$
Ogni funzione biunivoca accetta funzione inversa, quindi le funzioni biunivoche sono *invertibili*

Dato che la funzione $f(x)=x^2$ è biunivoca $[0,+∞)\rightarrow [0,+∞)$, accetta funzione inversa:
$$f^{-1}(x^2)=\sqrt{y}$$
Verifichiamo se $f(x)=x^3$ è biiettiva
	- Iniettività:
		$x_1^3=x_2^3$
		$x^3_1 -x^3_2=0$
		$(x_1-x_2)(x_1^2+x_1x_2+x_2^2)=0$
		$x_1=x_2\ ||\ x^2_1+x_1x_2+x_2^2=0$ non ha soluzioni in $\mathbb{R}$
		è iniettiva $\mathbb{R}\rightarrow \mathbb{R}$
	- Suriettività: si $\mathbb{R}\rightarrow \mathbb{R}$
$$
f^-1(x^3)=\sqrt[3]{y}
$$
Generalmente una $f(x)=x^n$:
	- Se n è pari: $n=2k,k\in \mathbb{N} ≥1$
		$\exists f^{-1}:[0,+∞)\rightarrow [0,+∞)$
			$y\rightarrow \sqrt{y}$
			$\sqrt[2k]{x^{2k}}=x, \forall x≥0$
			$(\sqrt[2k]{y})^{2k}=y,\forall y≥0$
	- Se n è dispari: $n=2k+1$
		$\exists f^{-1}:\mathbb{R} \rightarrow \mathbb{R}$
			$\sqrt[2k+1]{x^{2k+1}}=x, \forall x$
			$(\sqrt[2k+1]{y})^{2k+1}=y,\forall$


- **Seno e coseno**
**Seno:**
	$\exists f^{-1}:[-1,1]\rightarrow [-\frac{\pi}{2},\frac{\pi}{2}]$
	$y\rightarrow f^{-1}(y)=\arcsin(y)$
**Coseno:**
	$\exists f^{-1}:[-1,1]\rightarrow [0,{\pi}]$
	$y\rightarrow f^{-1}(y)=\arccos(y)$

### Relazione tra $\Gamma(f)$ e $\Gamma(f^{-1})$
$\Gamma(f^{-1})=\{(y,f^{-1}(y)),y\in Y\}=\{(f(x),x),x\in X\}$
$\Gamma(f)=\{(x,f(x)),x\in X$
Quindi $\Gamma(f^{-1})$ si trova **ribaltando** $\Gamma(f)$ rispetto alla retta $y=x$