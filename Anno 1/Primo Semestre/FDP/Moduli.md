# `typing`
Tipi:
	`None`
		Valore `None`
	`Any`
		Accetta qualsiasi tipo
	`Union[T1,T2] alias T1 | T2`
		Tipo 1 **o** tipo 2
	`Optional[T]`
		Equivalente a `T | None`
		L’argomento può non essere fornito
	`Sized`
		Oggetti che hanno dimensione, cioè che hanno metodo `__len__`

# `os`
- `.getcwd()`
	Torna il path della dir corrente
- `.chdir(path)`
	Cambia dir corrente
- `.stat(path)`
	Torna un oggetto con le informazioni sul file o directory con attribtui
	- `st_mode`
	- `st_ino`
	- `st_dev`
	- `st_nlink`
	- 
	- ...
- `.listdir()`
	= `ls` in terminal
- `.path.exists()`
	Controlla se esiste il file/dir
- `.path.isfile()`
	Controlla se il path è un file
