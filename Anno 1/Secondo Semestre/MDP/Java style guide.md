```java
public class NuovaClasse{
	int nuovaVariabile;
	final int NUOVA_COSTANTE = 17;

	public void myMethod() {}
}
```

I nomi delle variabili:
- Possono contenere lettere, cifre, `_` e `$`
- *Devono* iniziare con una lettera o `_` o `$`
	In genere minuscola
- Non possono contenere spazi (duh)
- Non devono essere identici alle keyword di Java

# Classi
In una classe si dichiarano prima tutti i campi (attributi) di una classe, poi tutti i metodi:
```java
public class MyClass {
	private int var1;    // campi
	private String var2; // tipicamente privati; usa metodi per accedere esternamente
	...

   /**
	* costruttore dell'oggetto
	* inizializza i valori dell'oggetto
	* può prendere input
	*/    // commento Javadoc
	public MyClass() {
		var1 =...;
		var2 =...;
		...
	}
	public void myMethod() {
		...
	}
}
```

