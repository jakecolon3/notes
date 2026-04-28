### Con ripetizione:
D’(n, k) = n^k 
Problema tipico:
Insieme A = {a, b, c}
	\# di sequenze ordinate di lunghezza 2 degli elementi di A con possibili ripetizioni?
	# = 3^2 = 9

A = {a1, a2, …, an}
\# di sequenze di lunghezza k di elementi in A con possibili ripetizioni
\= (x1, …, xi) xi € A, 1 <= i <= k = **n^k** = **D‘(n, k)**
	Disposizioni con ripetizione di ordine k di n elementi

### Senza ripetizione:
Problema tipico:
A = {a, b, c}
	# di sequenze ordinate di k elementi distinti scelti in A?
	# = 3!

A = {a1, …, an}
\# di sequenze ordinate di k elementi distinti in A con gli xi in A tutti distinti
\= $n\cdot(n - 1)\cdot(n - 2)\cdot\ldots\cdot(n - (k -  1)) = \frac{n!}{(n-k!)}=D_{n,k}$
	Disposizioni senza ripetizione di ordine k di n elementi
	Con k = n sono dette permutazioni di n = $P_n = n!$
