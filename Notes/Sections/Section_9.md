# [Section_9:](/README.md) _`Flask`_

___

## _`Table o'Contents`_

* [_`Flask & Jinja`_](#flask--jinja)
    * [_`Routes`_](#routes)
* [_`Forms`_](#forms)
* [_`Databases`_](#databases)

___

## [_`Flask & Jinja`_](#table-ocontents)

* `Flask` is a _`micro-framework`_ for `Python`.

* `Jinja` is a _`template engine`_ for `Python`.

Together they allow developers to build more dynamic applications than it is possible with only `HTML`, `CSS` and `JavaScript`.

![Flask & Jinja](/IMG/Sect9/0.png)

___


`Flask` powered website:

> https://libraryofbabel.info/

```notes
https://address/ 
Returns the root of the website
```

___

### [Routes](#table-ocontents)

* We think of a website often having these routes we can go to see different parts of it.

![Flask & Jinja](/IMG/Sect9/1.png)

> https://libraryofbabel.info/browse.cgi

* For this example `/browse.cgi` is the route we want to go to.

![Flask & Jinja](/IMG/Sect9/2.png)

> https://libraryofbabel.info/browse.cgi?...

* We could even, add some parameters to it and look at particular books, using something like this, having parameters in these dot dot dots at the end here.

![Flask & Jinja](/IMG/Sect9/3.png)

___

* You can imagine this website is full of these `HTML` pages look a bit like this. Or we have maybe trillions of `HTML` pages full of different text.

* So if I were to `request a page` from this `server` right here, I can make an `HTTP request`. I might say this: Give me the slash browse.cgi page.

![HTTP /browse.cgi](/IMG/Sect9/4.png)

___

* Instead of having this:

![Forms](/IMG/Sect9/5.png)

___

* Would probably be better, if we could actually have `a single HTML page` and we could just kind of `slot in` some random string of text to that page using something like `Python` or `Flask`, in this case.

* So we could do something like this, where instead of having millions and millions of pages that have all these random strings of text, we could have one page and we could use `Python` to `slot in` a single random string for us-- perhaps like in this example, we could have a `placeholder`.

![Forms](/IMG/Sect9/6.png)

Explore [Library](/Code/Examples/sect9/library/) `Flask` app.
___

## [_`Forms`_](#table-ocontents)

```html
<form>
    <input type="text">
    <button type="submit">
        Submit
    </button>
</form>
```

* This won't work because we need to specify where the data is going to be sent.

* We need to specify the `action` and the `method` properties for the `form`.

```html
<form action="/" method="post">
    <input type="text">
    <button type="submit">
        Submit
    </button>
</form>
```

* If data is sent via `POST`, it won't show up in the `URL`.

* But if data is sent via `GET`, it will show up in the `URL` using these `URL` parameters.

* Notice how in addition to a `type`, which is now omitted up here by default, we have the `name attribute` of our input. And this one is called `page`. 

* We could `reference` that very same name in our `Python` code to then get the value that that input holds at the time the form is submitted.

___

* If a request was submitted via `GET`, we could use `request.args.get`.

* But if a request was submitted via `POST`, we could use `request.form.get`.

___

* `POST` Example:

![Forms](/IMG/Sect9/9.png)

* `GET` Example:

![Forms](/IMG/Sect9/10.png)

___

## _`Databases`_

* This `SQL` query creates a table called history

```sql
CREATE TABLE history ( 
    id INTEGER,
    page INTEGER, 
    PRIMARY KEY(id) 
);
```

id | page
--|--

* For now we have an empty table;

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
INSERT INTO history (page) 
VALUES (100);
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

```py
db.execute("INSERT INTO history (page) VALUES (43);")
```

```py
db.execute("INSERT INTO history (page) VALUES (?);", placeholder)
```

id | page
--|--
1 | 50
2 | 100
3 | 43

___

Return to [`CS50x`](/README.md)