# Shorts_7: `SQL`

#### Return to [`CS50x`](/README.md)

___

## Table o'Contents

- [Databases](#databases)
- [SQL](#sql)
- [Data Types](#data-types)
- [Primary Key](#primary-key)
- [_`CRUD`_](#crud)
    - [INSERT](#insert)
    - [SELECT](#select)
    - [SELECT (JOIN)](#select-join)
    - [UPDATE](#update)
    - [DELETE](#delete)
- [MyPHPAdmin](#myphpadmin)
___

## [_`Databases`_](#table-ocontents)

- Often times, in order for us to build the most functional website we can, we depend on a `database` to store information.

- If you’ve ever used `Microsoft Excel` or `Google Spreadsheets` (among others), odds are you’re familiar with the notion of a database: a hierarchically organized set of tables, each of which contains a set of rows and columns

## [_`SQL`_](#table-ocontents)


- `SQL` (the `Structured Query Language`) is a programming language whose purpose is to query a database.

- `MySQL` is an `open-source` platform on which you can establish the type of relational database that `SQL` is most adept at working with.

- Many installations of `MySQL` come with a `GUI tool` called `phpMyAdmin` which can be used to execute database queries in a more user-friendly way.

___

- After you create a `database`, the next thing you’ll most likely want to do is `create a table`.

- The syntax for doing this is actually a bit awkward to do programmatically, at least at the outset, and so this is where `phpMyAdmin` will come in handy.

- As part of the process of `creating a table`, you’ll be asked to specify all of the `columns` in that table.

- Thereafter, all your `queries` will refer to `rows` of the `table`.

## [_`Data Types`_](#table-ocontents)

Each column of your `SQL` table is capable of holding data of a particular data type.

![](/IMG/Shorts7/0.png)
Stores `Integers`;

![](/IMG/Shorts7/1.png)
Hold `Integers` with different upper bounds;

![](/IMG/Shorts7/2.png)
Stand for `double` and `float`;

![](/IMG/Shorts7/3.png)
Store `date` and `time`;

![](/IMG/Shorts7/4.png)
Store `geometry` and `line strings`, can be used to store mapping of an area in a map;

![](/IMG/Shorts7/5.png)

Stands for strings;

![](/IMG/Shorts7/6.png)

`Column of a table` used to store a `limited set` of values;

![](/IMG/Shorts7/7.png)

- Unlike in `C`, the `CHAR` data type in `SQL` does not refer to a single character. Rather, it is a _`fixed-length string`_.

- In most `relational databases`, including `MySQL`, you actually specify the fixed-length as part of the type definition, e.g. `CHAR(10)`.

- A `VARCHAR` refers to a _`variable-length string`_.

    - `VARCHARs` also require you to specify the maximum possible length of a string that could be stored in that column, e.g. `VARCHAR(99)`.

`SQLite` has these data types as well, but affiliates each with a "`type affinity`" to simplify things

![SQLite data types](/IMG/Shorts7/21.png)

## [_`Primary Key`_](#table-ocontents)

- One other important consideration when constructing a table in `SQL` is to choose one column to be your `primary key`.

- `Primary keys` enable rows of a table to be uniquely and quickly identified.

    - Choosing your `primary key` appropriately can make subsequent operations on the table much easier.

- It is also possible to establish a joint `primary key` – a combination of two columns that is always guaranteed to be unique.

___

# [_`CRUD`_](#table-ocontents)

`SQL` is a programming language, but its vocabulary is fairly limited.

We will primarily consider just `four operations` that one may perform on a table.

![db](/IMG/Shorts7/8.png)

## [_`INSERT`_](#table-ocontents)

- Add information to a table.

```sql
-- (<columns>) => comma separated list of columns
INSERT INTO <table> (<columns>)
VALUES (<values>)
```

```SQL
--  Insert into users table, into the the username, password and fullname columns, with values of ‘newman’, ‘USMAIL’, ‘Newman’
INSERT INTO users (username, password, fullname)
VALUES (‘newman’, ‘USMAIL’, ‘Newman’)
```

![Insert Example](/IMG/Shorts7/9.png)

- When defining the column that ultimately ends up being your table’s `primary key`, it’s usually a good idea to have that column be an integer.

- Moreover, so as to eliminate the situation where you may accidentally forget to specify a real value for the `primary key` column, you can configure that column to `autoincrement`, so it will pre-populate that column for you automatically when rows are added to the table.

```SQL
INSERT INTO moms (username, mother)
VALUES (‘kramer’, ‘Babs Kramer’)
```

![ Inserted Table](/IMG/Shorts7/10.png)

## [_`SELECT`_](#table-ocontents)

Extract information from a table

```SQL
SELECT <columns>
FROM <table>
WHERE <condition>
ORDER BY <column>
```

```SQL
SELECT idnum, fullname
FROM users
```
![Select Data](/IMG/Shorts7/11.png)

```SQL
SELECT password
FROM users
WHERE idnum < 12
```

![Select Data](/IMG/Shorts7/12.png)

```SQL
SELECT *
FROM moms
WHERE username = ‘jerry’
```

![Select Data](/IMG/Shorts7/13.png)

- Databases empower us to organize information into tables efficiently.

    - We don’t always need to store every possible relevant piece of information in the same table, but can use relationships across the tables to let us pull information from where we need it.

- What if we now find ourselves in a situation where we need to get a user’s full name (from the users table) and their mother’s name (from the mother table).

## [_`SELECT (JOIN)`_](#table-ocontents)

Extract information from multiple tables.

```SQL
SELECT <columns>
FROM <table1>
JOIN <table2>
ON <predicate>
```

```SQL
-- the ON line explicitly specifies the username columns in each table
SELECT users.fullname, moms.mother
FROM users
JOIN moms
ON users.username = moms.username
```

![SELECT JOIN](/IMG/Shorts7/14.png)
![SELECT JOIN](/IMG/Shorts7/15.png)

Displays all the information from both tables;

Second column displays the overlap between the two tables;

![SELECT JOIN](/IMG/Shorts7/16.png)
![SELECT JOIN](/IMG/Shorts7/17.png)

## [_`UPDATE`_](#table-ocontents)

Modify information in a table.

```SQL
UPDATE <table>
SET <column> = <value>
WHERE <predicate>
```

```SQL
UPDATE users
SET password = ‘yadayada’
WHERE idnum = 10
```

![UPDATE JOIN](/IMG/Shorts7/18.png)

## [_`DELETE`_](#table-ocontents)

Remove information from a table.

```SQL
DELETE FROM <table>
WHERE <predicate>
```

```SQL
DELETE FROM users
WHERE username = ‘newman’
```

![UPDATE JOIN](/IMG/Shorts7/19.png)
![UPDATE JOIN](/IMG/Shorts7/20.png)

## [MyPHPAdmin](#table-ocontents)

- All of these operations are pretty easy to do in the graphical interface of `phpMyAdmin`.

- We want a way to do this programmatically, not just typing `SQL` commands into the `“SQL”` tab of `phpMyAdmin`.

- Fortunately, `SQL` integrates with `PHP` very well, by way of functions like `query()`.

After you’ve connected to your database with `PHP` (using a process called `MySQLi` or `PDO`), you can make pass query strings as arguments to functions in `PHP` and store the result set in an associative array.

```php
$results = query(“SELECT fullname FROM users WHERE idnum = 10”);

print(“Thanks for logging in, {$results[‘fullname’]}!”);
```

```php
$results = query(“SELECT fullname FROM users WHERE idnum = ?”,
$_SESSION[“id”]);

print(“Thanks for logging in, {$results[‘fullname’]}!”);
```

It’s also possible your result set might consist of multiple rows, in which case the result set would be an array of associative arrays, so just need to iterate through it!

```php
<p>The moms of TV’s Seinfeld:</p>
<table>

<?php
    $results = query(“SELECT mothers FROM moms”);
        if($results !== false)
        {
            foreach($results as $result)
        {
            print(“<tr><td>” . $result[‘mothers’] . “</td></tr>”);
        }
    }
?>
</table>
```

___

#### Return to [`CS50x`](/README.md)

___
