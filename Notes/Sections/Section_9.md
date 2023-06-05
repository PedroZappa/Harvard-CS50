# [Section_9:](/README.md) _`Flask`_

___

## _`Table o'Contents`_

* [_`Flask & Jinja`_](#flask--jinja)

___

## [_`Flask & Jinja`_](#table-ocontents)

![Flask & Jinja](/IMG/Sect9/0.png)

https://libraryofbabel.info/

![Flask & Jinja](/IMG/Sect9/1.png)

https://libraryofbabel.info/browse.cgi

![Flask & Jinja](/IMG/Sect9/2.png)

https://libraryofbabel.info/browse.cgi?...

![Flask & Jinja](/IMG/Sect9/3.png)

![HTTP /browse.cgi](/IMG/Sect9/4.png)

___

## [_`Forms`_](#table-ocontents)

![Forms](/IMG/Sect9/5.png)

![Forms](/IMG/Sect9/6.png)

![Forms](/IMG/Sect9/7.png)

![Forms](/IMG/Sect9/8.png)

![Forms](/IMG/Sect9/9.png)

![Forms](/IMG/Sect9/10.png)

___

## _`Databases`_

```sql
CREATE TABLE history ( 
    id INTEGER,
    page INTEGER, 
    PRIMARY KEY(id) 
);
```

id | page
--|--

___

```sql
INSERT INTO history (page) 
VALUES (50);
```

id | page
--|--
1 | 50

___

```sql
SQL history sqlite&gt; INSERT INTO history (page) ...&gt; VALUES (100);
```

id | page
--|--
1 | 50
2 | 100

___

```sql
INSERT INTO history (page) 
VALUES (43);
```

id | page
--|--
1 | 50
2 | 100
3 | 43

___

```sql
Python history db.execute("INSERT INTO history (page) VALUES (43);")
```

```sql
db.execute("INSERT INTO history (page) 
            VALUES (?);", placeholder)
```

id | page
--|--
1 | 50
2 | 100
3 | 43

___

Return to [`CS50x`](/README.md)