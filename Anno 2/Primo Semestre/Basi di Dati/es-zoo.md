Genere(*Nome*)
Esemplare(*Codice*, Sesso, Nome, LuogoNascita, DataNascita, DataArrivo, Gabbia, Genere) (vincolo genere casa)
Gabbia(*Numero*, Casa)
Casa(*Numero*, Tipo, Area, Addetto, GiornoPulizia, Genere)
AreaGeografica(*Nome*, Responsabile UNIQUE)
Veterinario(*CF*, Nome)
Addetto(*CF*, Nome)
Responsabile(*CF*, Nome)
Visita(*Data, Esemplare*, Malattia, Peso, Dieta, Veterinario)

```sql
CREATE TABLE
    Genere(
        Nome STRING PRIMARY KEY
    );

CREATE TABLE
    Esemplare(
        CodiceInventario STRING PRIMARY KEY,
        Sesso CHAR NOT NULL CHECK (Sesso IN ('M', 'F'),
        Nome STRING NOT NULL,
        LuogoNascita STRING,
        DataNascita DATE,
        DataArrivo DATE NOT NULL,
        Genere STRING REFERENCES Genere,
        Gabbia NUMERIC(5) NOT NULL REFERENCES Gabbia
    );

CREATE TABLE
    Gabbia(
        Numero NUMERIC(5) PRIMARY KEY,
        GiornoPulizia INT NOT NULL,
        Casa NUMERIC(5) REFERENCES Casa
    );

CREATE TABLE
    Casa(
        Numero NUMERIC(5) PRIMARY KEY,
        Tipo STRING
    );
```
