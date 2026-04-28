# ”Prova in itinere”
1. 5 combinatoria, 10 logica, 5 algebra
	- In quanti modi posso scegliere 10 domande?
		$C_{20,10}=184,756$
	- In quanti modi posso scegliere 10 domande di cui esattamente 4 sono di logica?
		Modi di scegliere 4 di logica \* domande restanti
		$C_{10,4}\cdot C_{10,6}$
	- In quanti modi posso scegliere 10 domande di cui almeno 1 di combinatoria e almeno 1 di logica?
		Per complementare:
			0 di logica oppure 0 di combinatoria: $PIE_2=C_{10,10}+C_{15,10}-0=3004$
			$184,756-3004=181,752$
2. 3 tra 26\*2 lettere $\cdot$ 2 tra 3 simboli $\cdot$ 3 tra 26\*2 lettere
	- Quante con ! come secondo simbolo
		$52^6*3$
	- L come prima lettere o ! come ultimo simbolo
		$PIE_2=52^5*9+52^6*3-52^5*3$
	- Prima metà password
		$52^3*3$
3. 8 inglese 12 italiano
	- Modi di scegliere 6 brani
		$C_{20,6}$
	- Modi di scegliere 3 brani in inglese e 3 in italiano e tra essi 1 da pubblicare come singolo
		$C_{8,3}*C_{12,3}*6$
	- Modi di scegliere 3 brani in inglese e 3 in italiano e tra essi 1 in inglese e 1 in italiano
		$C_{8,3}*C_{12,3}*9$
4. $A = \{1,2,3\}$
	- Stringhe lunghe 10
		$D’_{3,10}$
	- Stringhe lunghe 10 che non contengono 3 e non iniziano con 2
		$D’_{2,9}$
	- Stringhe lunghe 10 in ordine crescente con ogni cifra presente
		$C’_{12,2}$
