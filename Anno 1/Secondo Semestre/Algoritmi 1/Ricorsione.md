Se proviamo a calcolare il costo computazionale di una funzione ricorsiva otteniamo una funzione matematica ricorsiva:
```python
def fattoriale(n):
	if n == 0: return 1
	return n * fattoriale(n - 1)
```
$$
\text{Costo computazionale = }\begin{cases} T(n)=\Theta (1)+T(n-1)\\T(0)=\Theta(1)\end{cases}
$$
Per trovare il costo asintotico di queste funzioni si usano le equazioni di ricorrenza

# Equazioni di ricorrenza
Esistono diversi metodi per risolvere le equazioni di ricorrenza:
### Metodo iterativo
Per risolvere un equazione di ricorrenza con il metodo iterativo si sviluppa l'equazione in modo tale da poterla scrivere come somma di termini dipendenti da n:
- Esempio:
$$
T(n)=\begin{cases}
T(n)=T(n-1)+\Theta(1) \\
T(0)=\Theta(1)
\end{cases}
$$
	Riscriviamo $T(n)$ come:
$$
\begin{multline}
    \begin{aligned}
        T(n)&=T(n-1)+\Theta(1)=\\
        &=\Theta(1)+\Theta(1)+T(n-2)=\\
        &=\Theta(1)+\Theta(1)+\Theta(1)+T(n-3)+=\\
		&...\\
		&=\sum_{k=0}^n{\Theta(1)}=\\
		&=n\Theta(1)=\Theta(n)
    \end{aligned}
\end{multline}
$$
- Esempio 2:
$$
\begin{multline}
    \begin{aligned}
        T(n)&=
        \begin{cases}
                T(n)=T(\frac{n}{2})+\Theta(1) \\
                T(1)=\Theta(1)
        \end{cases} \\
        &=\Theta(1) + T(\frac{n}{2})=\\
		&=\Theta(1)+\Theta(1)+T(\frac{(\frac{n}{2})}{2})=\Theta(1)+\Theta(1)+T(\frac{n}{2^2})=\\
		&=\Theta(1)+...+T(\frac{n}{2^3})=\\
		&...\\
		&=T(\frac{n}{2^k})+k\Theta(1)
    \end{aligned}
\end{multline}
$$
	Quando $k=\log n$, si ha $\frac{n}{2^k}$ = 1, quindi otteniamo:
$$
T(n)=\Theta(1)+\log (n)\Theta(1) = \Theta(\log n)
$$
Se non riusciamo a calcolare precisamente $T(n)$ (per esempio per Fibonacci), possiamo maggiorare e minorare l'equazione per avere una stima tra $\Omega$ e $O$.


### Metodo dell'albero
In un'albero binario completo il numero di nodi è $n=2^{h+1}$ dove $h$ è l'altezza dell'albero
Esempio:
$$
\begin{cases}
    T(n)=2T\left( \frac{n}{2} \right)+\Theta(n^2) \\
	T(1)=\Theta(1)
\end{cases}
$$
(vedi ipad)
Vediamo che il metodo dell'albero è equivalente al metodo iterativo: i conti risultano uguali

### Metodo di sostituzione
Metodo:
- Si ipotizza una soluzione per l'eq. di ricorrenza
- Si verifica se la soluzione funziona con una dimostrazione per induzione
- Se funziona abbiamo trovato la soluzione
Difficoltà:
- Bisogna stare attenti a trovare la soluzione di ordine corretto: se si cerca $O$, ogni soluzione più grande funzionerà (opposto per $\Omega$)!
Esempio:
$$
\begin{cases}
    T(n)=T(n-1)+\Theta(1) \\
	T(1)=\Theta(1)
\end{cases}
$$
Problema: dobbiamo trovare una funzione che è un identità (perché ?)
	Ipotizziamo la soluzione $T(n)=cn$ per una costante $c$
$$
\begin{cases}
    T(n)=cn=c(n-1)+\Theta(1) \text{, cioè c }= \Theta(1)\\
	T(1)=\Theta(1)=c=\Theta(1)
\end{cases}
$$
	Ma i $c$ potrebbero essere diversi e quindi $c$ sarebbe 2 valori contemporaneamente (?)
Dobbiamo quindi eliminare la notazione asintotica (nota le 2 costanti diverse):
$$
\begin{cases}
    T(n)=T(n-1)+c \\
	T(1)=d
\end{cases}
$$
	Per 2 costanti $c$ e $d$ fissate
Ipotizziamo la soluzione $T(n)=O(n)$, ossia $T(n)\leq kn$ dove k è una costante che va ancora determinata
	La differenza è che ora dobbiamo *trovare* k
$$
\begin{cases}
    T(n)=T(n-1)+\Theta(1) \\
	T(1)\leq k\cdot 1
\end{cases}
$$
Dim. induttiva:
	Base: Dato che sapevamo che $T(1)=d$, $T(1)\leq k$ è soddisfatta s.se $k\geq d$
	Passo: $T(n)\leq k\cdot (n-1)+c=kn-k+c\leq?\ k\cdot n$, vera s.se $k\geq c$
$T(n)\leq kn$ è corretta per qualsiasi valore di $k>c$ e $k>d$
ripeti per $\Omega$ e hai $\Theta$

È possibile che la disequazione $T(n)\leq kn$ risulti falsa *anche se $T(n)=\Theta(n)$*, se $T(n)$ è descritta da un'altra funzione che è theta di n (per esempio $kn-h$)

### Metodo principale
Il metodo principale è un'approccio meccanico per risolvere ogni generica eq. di ricorrenza
Questo metodo però funziona solo su eq. di ricorrenza del tipo
$$
\begin{cases}
    T(n)=aT\left( \frac{n}{b} \right)+f(n) \\
	T(1)=\Theta(1)
\end{cases}
$$
E ci sono comunque casi particolari per cui non funziona
Teorema:
Dati $a\geq 1, b> 1$, una funzione asintoticamente positiva $f(n)$ ed un'eq. di ricorrenza di forma:
$$
\begin{cases}
    T(n)=aT\left( \frac{n}{b} \right)+f(n) \\
	T(1)=\Theta(1)
\end{cases}
$$
Vale che:
- Se $f(n)=O(n^{\log_b (a)-\varepsilon})$ per qualche costante $\varepsilon>0$, allora $T(n)=\Theta(n^{log_b a})$
- Se $f(n)=\Theta(n^{\log_b a})$ allora $T(n) = \Theta(n^{\log_b a}\log n)$
- Se $f(n)=\Omega(n^{\log_b(a)+\varepsilon})$ per qualche costante $\varepsilon>0$ e se $f\left( \frac{n}{b} \right)\leq c$ per qualche costante $c<1$ e per $n$ sufficientemente grande, allora $T(n)=\Theta(f(n))(\leq f(n)?????????)$
Quindi $f(n)$ deve essere asintoticamente più grande boh
Tra i casi (1 e 2) e (2 e 3) c'è un intervallo in cui $f(n)$ è più grande di $n^{\log_b a}$ ma non polinomialmente
Esempio:
	$T(n)=3T\left( \frac{n}{4} \right)+\Theta(n\log n)$
	$a=3, b=4$
	$f(n)=\Theta(n\log n)$
	$n^{\log_b a}=n^{\log_4 3}\approx n^{0.7}$ 
	Poiché $f(n)=\Omega(n^{\log_4 (3)+\varepsilon})$, con $\varepsilon=0.2$ per es., siamo nel caso 3 se posso dimostrare che $\frac{3n}{4}\log \frac{n}{4}\leq c n \log n$ per qualche $c<1$ ed $n$ abbastanza grande
		Ponendo $c=\frac{3}{4}$, otteniamo $boh$ che è vero quindi si s.se $\frac{3}{4}\leq c$



### Esercizi
```python
def coeff_binom_ric(n, k):
	if k == n: return 1
	if k == 0: return 1
	return coeff_binom_ric(n-1, k) + coeff_binom_ric(n-1, k-1)
```
```python
def mcd_ric(x, y):
	if y == 0: return x
	return mcd_ric(y, x%y)
```