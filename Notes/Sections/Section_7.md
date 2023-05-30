# Section_7: _`SQL`_

Return to [`CS50x`](/README.md)

___

## _`Table o'Contents`_

- [SQL _Databases_](#sql-databases)
- [_Selecting_](#selecting)
- [_Ordering_](#ordering)
- [_Limiting_](#limiting)
- [_Aggregating_](#aggregating)
- [_Database Design_](#database-design)
- [_INSERTing_](#inserting)
- [_SELECTs_](#selects)
- [_JOINs_](#joins)

___

## [_`SQL Databases`_](#table-ocontents)

![roster.db](/IMG/Sect7/0.png)

___

## [_`Selecting`_](#table-ocontents)

```sql
SELECT * 
FROM students;
```

![Selecting Example](/IMG/Sect7/1.png)

```sql
SELECT student_name 
FROM students;
```

![Selecting student names](/IMG/Sect7/2.png)

```sql
SELECT student_name 
FROM students 
WHERE house = 'Slytherin';
```

![Selecting Slytherin student_names](/IMG/Sect7/3.png)

```SQL
SELECT student_name, house
FROM students
WHERE house = 'Slytherin';
```

![Selecting Slytherin student_names](/IMG/Sect7/13.png)


Find the names of students whose name has "`%Potter`":


```sql
SELECT student_name 
FROM students 
WHERE student_name LIKE "%Potter";

-- would yeald the same output

SELECT student_name 
FROM students 
WHERE student_name = "Harry James Potter";

-- Attetion: WHERE is case sensitive
```

![Selecting Potter student_names](/IMG/Sect7/14.png)

Find the names and houses of students whose names begin with "`H`":

```sql
SELECT student_name, house
FROM students 
WHERE student_name LIKE "H%";
```

![Selecting H student_names](/IMG/Sect7/15.png)


```note
LIKE is case insensitive.
Appropriate for fuzzy matching.
```

___

## [Ordering](#table-ocontents)

```sql
SELECT * 
FROM students;
```

![Ordering Example](/IMG/Sect7/16.png)


```sql
SELECT * FROM students 
ORDER BY student_name;
```

![Ordering Example](/IMG/Sect7/17.png)

By default `ORDER BY` gives out the data in `ascending order`:

```sql
SELECT * FROM students 
ORDER BY student_name ASC;
```

```sql
SELECT * FROM students 
ORDER BY student_name DESC;
```

![Ordering Example](/IMG/Sect7/18.png)

```sql
SELECT * FROM students 
ORDER BY house;
```

![Ordering Example](/IMG/Sect7/19.png)

Sort the student data `in alphabetical order`, first `by house` and then `by
student name`:

```sql
SELECT * FROM students 
ORDER BY house, student_name;
```

![Ordering Example](/IMG/Sect7/20.png)

___

## [_Limiting_](#table-ocontents)

```sql
... LIMIT 1;
```

```sql
SELECT * FROM students
ORDER BY student_name 
LIMIT 10;
```

![Limiting Example](/IMG/Sect7/21.png)


```sql
SELECT * FROM students
ORDER BY student_name DESC
LIMIT 10;
```

![Limiting Example](/IMG/Sect7/22.png)


___

## [_Aggregating_](#table-ocontents)

Count number of rows of students:

```sql
SELECT COUNT(*) 
FROM students;
```

![Aggregating Example](/IMG/Sect7/23.png)

```SQL
SELECT COUNT(*) AS number_of_students
FROM students;
```

![Aggregating Example](/IMG/Sect7/24.png)

Count the number of students in Gryffindor:

```sql
SELECT * FROM students
WHERE house = 'Gryffindor';
```

![Aggregating Example](/IMG/Sect7/25.png)

Count the number of students in each Gryffindor house:

```sql
SELECT COUNT(*) FROM students
WHERE house = 'Gryffindor';
```

![Aggregating Example](/IMG/Sect7/26.png)

Count the number of students in each house:

```sql
SELECT COUNT(*) FROM students
GROUP BY house;
```

![Aggregating Example](/IMG/Sect7/27.png)

___

## [Database Design](#table-ocontents)

![roster.db](/IMG/Sect7/0.png)

### _`Design Principles`_

- Each table should be a collection of a `single entity`. 
- For example, we should have a different table for each of `students`, `houses`, and `student-house assignments`.

![roster.db: students & houses tables](/IMG/Sect7/4.png)

- `Each piece of data` should be stored in a `single location`, and thereafter referred to by its `ID` ("`primary key`").
- For example, we should ensure every `student` and `house` has an `ID`, then use those `ID`s in the `house assignments table`.

![roster.db: students, houses & assignments tables](/IMG/Sect7/5.png)

Creating a `table` using `SQL`:

```sql
CREATE TABLE houses ( 
    id, 
    house, 
    head, 
    PRIMARY KEY(id) 
);
```

The code above wouldn't work, we have to specify the `data type` when crating a `table`:

```sql
CREATE TABLE houses ( 
    id INTEGER, 
    house TEXT, 
    head TEXT, 
    PRIMARY KEY(id) 
);
```

We can also implement `NULL` checking:

```sql
CREATE TABLE houses ( 
    id INTEGER NOT NULL, 
    house TEXT NOT NULL, 
    head TEXT NOT NULL, 
    PRIMARY KEY(id) 
);

-- NOT NULL 
-- ==
-- "required"
```

![roster.db: students & houses tables](/IMG/Sect7/6.png)

### [_`INSERTing`_](#table-ocontents)

Adding data to a newly crated empty table:

```sql
INSERT INTO tablename (column1, column2) 
VALUES (value1, value2);
```

```sql
INSERT INTO houses (house, head) 
VALUES ('Gryffindor', 'McGonagall');
```

![roster.db: students & houses tables filled](/IMG/Sect7/7.png)

```note
…
```

![roster.db: students, houses & assignments tables filled](/IMG/Sect7/8.png)

```note
Count the number of students in Gryffndor
```

### [_`SELECTs`_](#table-ocontents)

![roster.db: students, houses & assignments filtering](/IMG/Sect7/9.png)

```sql
SELECT id FROM houses
WHERE house = 'Gryffindor'
```

![roster.db: students, houses & assignments filtering](/IMG/Sect7/10.png)

```sql
SELECT COUNT(student_id) FROM assignments 
WHERE house_id = 
( 
    SELECT id FROM houses 
    WHERE house = 'Gryffindor' 
);
```

![count students in Gryffindor](/IMG/Sect7/28.png)

### [_`JOINs`_](#table-ocontents)

```note
Count the number of students in Gryffindor
```

![roster.db: students, houses & assignments tables filled](/IMG/Sect7/8.png)

![roster.db: students, houses & assignments tables filled](/IMG/Sect7/11.png)

![roster.db: students, houses & assignments tables filled](/IMG/Sect7/12.png)

```SQL
SELECT * FROM assignments 
JOIN houses ON assignments.house_id = houses.id;
```

![](/IMG/Sect7/29.png)

Select the  count of students in Gryffindor:

```SQL
SELECT COUNT(student_id) FROM assignments 
JOIN houses ON houses.id = assignments.house_id 
WHERE houses.house = 'Gryffindor';
```

![](/IMG/Sect7/30.png)

Display the number of students in each house:

```sql
SELECT house, COUNT(student_id) FROM assignments
JOIN houses ON houses.id = assignments.house_id
GROUP BY house;
```

![JOIN then GROUP by](/IMG/Sect7/31.png)

Can we use AS when merging two tables?

```sql
SELECT * FROM assignments
JOIN houses ON houses.id = assignments.house_id AS id;
```

Ups... We get an error because we are trying to rename these columns after merging them. `SQL` expects the columns names not their aliases.

![fail](/IMG/Sect7/32.png)

Select all `students` and their assignments (`house` & `head`):

```sql
SELECT * students
JOIN assignments ON students.id = assignments.student_id;
JOIN houses ON houses.id = assignments.house_id;
```

![Join example](/IMG/Sect7/33.png)

___

Return to [`CS50x`](/README.md)

___
