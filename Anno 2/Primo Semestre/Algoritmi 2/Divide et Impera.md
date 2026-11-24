Gli algoritmi *divide et impera* spezzano i problemi in sotto-problemi più piccoli più facili da risolvere, e poi ricostruiscono la soluzione finale dalle soluzioni dei sotto-problemi.

Ricordiamo il *master theorem* per risolvere equazioni di ricorrenza del tipo $T(n) = aT(\frac{n}{b})+f(n);\ a\geq 1,\ b>1$:
- Se $f(n)=\Theta(n^c);\ c<\log_ba$: $$ T(n)=\Theta(n^{\log_ba}) $$
- Se $f(n)=\Theta(n^{\log_ba}\log^kn);\ k\geq 0$: $$ T(n)=\Theta(n^{\log_ba}\log^{k+1}n) $$
- Se $f(n)=\Theta(n^c);\ c>\log_ba$: $$ T(n)=\Theta(n^c) $$

Questo teorema può anche essere usato al contrario: si parte dalla complessità voluta e si ottiene una "outline" di come funzionerà l'algoritmo.
