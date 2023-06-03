# Section_7: _`HTML, CSS, JavaScript`_

Return to [`CS50x`](/README.md)

___

## _`Table o'Contents`_

* [HTTP](#http)
* [HTML](#html)
* [CSS](#css)
    * [CSS Selectors](#css-selectors)
    * [CSS Colors](#css-colors)
* [JavaScript](#javascript)

___

![HTML,CSS,JavaScript,Graph](/IMG/Sect8/0.png)

## [HTTP](#table-ocontents) [ `Hypertext Transfer Protocol` ]

___

### HyperText

* `Hypertext` is somehow a dated term.
* It referred to `text` that had `links` inside of it that would link to other `pages`/`text`.
* The `hypertext` part in this `hypertext transfer protocol` has to do with the `language` we use or the `files` we get to actually view websites with their links to other text on their pages.

### Transfer Protocol

* Used to `send` and `receive` data from one computer to another.
* The `Transfer Protocol` is common set of rules we use to communicate between computers.
* Similar to how humans have languages, computers themselves also need some rules to follow when they ask each other for information or, in this case some `hypertext`.

We end up using `HTTP`, when we `request a website` from a computer or some server out there on the internet.

```web
http://cs50.harvard.com/...
```

For example, let's say you go to our very own web page here using this URL, `cs50.harvard.edu`, and in front of that you prefix it with prefix it with `http colon slash slash` ( http:// ), meaning you want to use the `hypertext transfer protocol` to access whatever files are at `cs50harvard.edu`.

![HTTP](/IMG/Sect8/00.png)

* The key thing to know right now is that for `HTTP`, you have maybe two computers a bit like this, where your `computer`'s on the right and maybe a `server` is on the left hand side.

* You want to `request` some web page. So you go to some `URL`.

* You might make a `request` by sending some data to a `server`, and that `request` is formatted in a way that the `server` knows what to expect because of `HTTP`.

* `HTTP` is the  `protocol` that specifies how to `request`, `send` and `receive` data from a `server`.

![HTTP](/IMG/Sect8/1.png)

* If the `server` responds with a `200` code, by convention, it tends to means that everything went OK.

* The `server` knows how to respond, because of the rules defined by `HTTP`, it will give us back some data, in this case, it will give us the `requested page`.

This is what happens when we `request` a `web page` from a `server` using `HTTP` successfully.

___

What if there is a problem with the `request`?

* When the web page requested is `not found`, by convention in `HTTP`, the `server` will respond with a `404` code.

![HTTP](/IMG/Sect8/2.png)

* Maybe we try to `get access` to some `page that isn't there` or we have a `wrong URL`.
* When we make such a `HTTP request`, by convention the `server` returns a `404` error code.
* Instead of displaying the `requested page` the server will give back some page noting that it is `not found`.

![HTTP](/IMG/Sect8/3.png)

* A `500 error code` means that something went wrong with the `server`, there was an internal server error.

* An error has happened and it can't complete the request, in which case, it will give me back by convention this `500 error code` and give me back a page saying that something went wrong in here.

`HTTP` is a protocol for `requesting hypertext`, (some pages on a website) that you can then view on your computer. For each request received, the `server` by convention will respond with a `status/error code` according to the `HTTP` protocol.

___

* To build our own local `server` we can do that in `VS codespaces` using this command:

```sh
http-server
```

___

## [HTML](#table-ocontents) [ `HyperText Markup Language` ]

* When thinking of `HTML`, you should often think of it as designing this `tree structure`.
* This structure is called the `document object model`, or `DOM` for short.
* The `DOM` helps visualize the structure of our webpage.

![HTML](/IMG/Sect8/4.png)

* `HTML` is composed by elements called `tags` containing `attributes`.
* The `Document` element ( `<!DOCTYPE html>` ) is used to specify the version of `HTML` that we are using.
* The `<html>` element is the root element of the `HTML` document.
* `<head>` is the `head` element of the `HTML` document.
* `<body>` is the `body` element of the `HTML` document.
* Both `<head>` and `<body>` are children of the `<html>` element.
* The `<title>` element is a child of the `<head>` element.
* The `<title>` element holds the text `hello, title`.
* The `<p>` element is a child of the `<body>` element.
* The `<p>` element holds the text `hello, body`.

![HTML](/IMG/Sect8/5.png)

___

### [`<head>`](#table-ocontents)

* the `<head>` tag is used to specify the webpage's:
    * `title`,
    * `metadata`,
    * `scripts` (or at the bottom of `<body>` tag),
    * and `styles` .
* It is the first element within the `<html>` element.

___

### [`<body>`](#table-ocontents)

* the `<body>` tag is below the `<head>` tag ( `NOT within` ).
* the `<body>` tags contains the contents to be displayed in the web browser.

___

### [`<table>`](#table-ocontents)

![<table>](/IMG/Sect8/6.png)

### [`<tr>`](#table-ocontents)

* the `<tr>` tag is used to specify a row in a `<table>`.

### [`<td>`](#table-ocontents)

* the `<td>` tag is used to specify a cell in a `<tr>` ( table row).

___

Breaking down the `<table>`'s children elements:

* Three `<tr>` tags (rows):

![`<tr>`](/IMG/Sect8/7.png)

* Two `<td>` tags per `<tr>` (cells per row):

![`<td>`](/IMG/Sect8/8.png)

* Now we child a `<button>` tag inside each of the nested `<td>`s inside the 3rd `<tr>`.

![`<td>`](/IMG/Sect8/9.png)

___

## [`Semantic HTML`](#table-ocontents)

* Tags like `<main>` ( `<head>`, `<body>`, ... ) are used to define the tags in a semantic way with more meaning than if we were only using `<div>`s ( division ).
* `Semantic tags` are helpful to inform `screen readers` about the key contents of the webpage.

For a comprehensive list of `HTML tags`, check:
* [developer.mozilla](https://developer.mozilla.org/en-US/docs/Web/HTML/Element).
* [W3Schools](https://www.w3schools.com/tags/)

___

### [`<main>`](#table-ocontents)

- With the `<main>` tag, we can define the main content of the webpage we want search engines to pay attention to.

___

## [CSS](#table-ocontents) [ `Cascading Style Sheets` ]

* Selects `HTML tags`, `classes` or `ID`s and applies styles to them.
* Cascading meaning that whatever `styles` are applied to a particular `HTML tag` will cascade down ( and be `inherited` ) by  all its children.

### [`CSS Syntax` ](#table-ocontents)

![`<tr>`](/IMG/Sect8/10.png)

* Let's say I want to `select` all the `buttons` on a page and make all buttons red:

![`<tr>`](/IMG/Sect8/10-1.png)

* Add a `dashed "border" property` with the value `4pt` to the `<button>`:

![`<tr>`](/IMG/Sect8/10-2.png)

## [`CSS Selectors` ](#table-ocontents)

### [`ID Selectors`](#table-ocontents)

* To change the color of each bottom independently of the other we need to have a different selector, either a `class` or an `ID` that is unique to each `<button>`:

```note
Notice the `#` preceding the `ID`;
```

![`<tr>`](/IMG/Sect8/11.png)

![`<tr>`](/IMG/Sect8/12.png)

### [`Class Selectors`](#table-ocontents)

* `Classes` allow us to change the color of any elements that have that particular `class`:

```note
Notice the `.` preceding the `class` name;
```

![`<tr>`](/IMG/Sect8/14.png)

![`<tr>`](/IMG/Sect8/15.png)

### [ _`IDs Vs. Classes`_](#table-ocontents)

* `IDs` are unique to each element. They are ideal for when we are targeting only one element.
* `Classes` on the other hand can apply to multiple elements with that class

___

## [_`CSS Colors`_](#table-ocontents)

In `CSS` colors can be defined with:

* `RGB` (Red, Green, Blue);
* `HEX` (Hexadecimal);
* `HSL` (Hue, Saturation, Lightness);
* `CMYK` (Cyan, Magenta, Yellow, Black);

___

For a comprehensive list of `CSS Selectors`:

* [W3schools](https://www.w3schools.com/css/css_selectors.asp)

For a comprehensive list of `CSS Properties`:

* [W3schools](https://www.w3schools.com/cssref/index.php)

___

## [_`JavaScript`_](#table-ocontents)

![`<tr>`](/IMG/Sect8/16.png)

* Create `team1` and `team2` and initialize them to `0`;
* Then select element with ID `score1` and `score2`;

```js
team1++
document.querySelector(#score1).innerHTML = team1;
...

team2++
document.querySelector(#score2).innerHTML = team2;
```

___

Looking at the `JavaScript` code in the example file [scoreboard.html](/Code/Examples/sect8/scoreboard.html)

```js
// Select element with ID #add1 and Increment team1
document.querySelector(#add1).onclick = function() {
    team1++;
    document.querySelector(#score1).innerHTML = team1;
}

// Select element with ID #add2 and Increment team2
document.querySelector(#add2).onclick = function() {
    team2++;
    document.querySelector(#score2).innerHTML = team2;
}
```

___

Return to [`CS50x`](/README.md)
