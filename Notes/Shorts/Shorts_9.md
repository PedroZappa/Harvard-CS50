# [Shorts_9](/README.md): `Flask`

## `Table o'Contents`

* [`Flask`](#flask)
* [`Ajax`](#ajax)

___

## [`Flask`](#table-ocontents)

* `Python` is not just used for `command-line programming`, though that’s a major use case.
* `Python` contains native functionality to support networking and more, enabling site backends to be written in `Python`.

___

* `Web frameworks` make this process much easier, abstracting away the minutia of Python’s syntax and providing helper functions.
* Some of the most popular include: `Django`, `Pyramid`, and `Flask`.

* We use `Flask` in `CS50` because it is lightweight for ease of use in `CS50 IDE`, while still being feature-rich.

* We know that we can use `HTML` to build websites, but websites built using pure `HTML` suffer from a serious limitation.
* Imagine we want to create a website that displays the current time in Cambridge, MA, displaying it to the latest minute.

___

```html
<html>
    <head>
        <title>
            Current Time in Cambridge
        </title>
    </head>
        <body>
            The current time in Cambridge is 14:08
        </body>
</html>
```

___

* Websites that are pure `HTML` are completely static. The only way we can update the content of our pages is to manually open up our source files, edit and save, and then the next time the user visits or refreshes the page they’ll get the content.

* Incorporating `Python` into our code can make our code quite a bit more flexible and introduce a way for our pages to update or be dynamic without requiring our intervention.

___

### `Clock Program`

```py
from flask import Flask 
from datetime import datetime 
from pytz import timezone 

app = Flask(__name__)

@app.route("/") 
def time(): 
    now = datetime.now(timezone('America/New_York'))
    return "The current date and time in Cambridge is {}".format(now)

```

___

## `Getting started with Flask`

It’s pretty simple to get started using `Flask` within `CS50 IDE`.

```py
from flask import Flask
```

After importing the `Flask module`, we need to initiate a `Flask application`.

```py
app = Flask(__name__)
```

From there, it’s just a matter of writing functions that define the behavior of our application.

___

```PY
def index(): 
    return "You are at the index page!"

def sample(): 
    return "You are on the sample page!"
```

___

### `Applying Decorators`

```py
@app.route("/") 
def index(): 
    return "You are at the index page!"

@app.route("/sample") 
def sample(): 
    return "You are on the sample page!"
```

* The lines just added are known as `“decorators`.” They are used, in `Flask`, to associate a `particular function` with a `particular URL`.

* Decorators also have more general use in `Python`, but that goes beyond the scope of `CS50`.

___

* It’s also quite straightforward to run our Flask application within `CS50 IDE`.

* When running the `Flask app` for the first time:

```py
# FLASK_APP is a system variable stored in the memory of your IDE specifically, so that if you ever run an application again, it knows exactly which application to run.
# FLASK_DEBUG=1 Debug mode on // set FLASK_DEBUG=0 to disable
export FLASK_APP=app.py 
export FLASK_DEBUG=1 
flask run
```

* From then on simply run `flask run`.

___

### `Passing Data`

Data can be passed in via `URL`s, akin to using `HTTP GET`.

```py
@app.route("/show/<number>") 
def show(number): 
    return "You passed in {}".format(number)
```

Data can be passed in via `HTML forms`, as with HTTP POST, but we need to indicate that Flask should respond to `HTTP POST` requests explicitly.

```py
@app.route("/login", methods=['GET', 'POST']) 
def login(): 
    if not request.form.get("username") 
        return apology("must provide username")
    ...
```

___

### `Handling HTTP Requests`

• We could also vary the behavior of our function depending on the type of `HTTP request` received:

```py
@app.route("/login", methods=['GET', 'POST']) 
def login(): 
    if request.method == "POST": 
        # do one thing
    else: 
        # do a different thing
```

___

`Flask` has a number of functions within its module that will be useful for application development.

```py
# go to url associated with decorator
url_for()
# redirect to another page
redirect() 
# session data, user login, global
session()
# render from template
render_template()
```

* More information available at the `Flask` quick start guide:

[Flask Quickstart](http://flask.pocoo.org/docs/0.12/quickstart/)

* More information on using `Jinja` can be found at:

[Jinja Docs](http://jinja.pocoo.org/)

___

## [`Ajax`](#table-ocontents)

* Up until now, our interaction with `JavaScript` has been mostly limited to: push a button, something happens.

* We still don't have to entirely reload our page, but there is still some degree of user interaction.

* Ajax (formerly `Asynchronous JavaScript` and `XML`) allows us to dynamically update a webpage even more dynamically.

* Though, for now, we won't go too crazy!

___

### `XMLHttpRequests`

* Central to our ability to asynchronously update our pages is to
make use of a special `JavaScript` object called an `XMLHttpRequest`.

```js
var xhttp = new XMLHttpRequest();
```

___

* Central to our ability to asynchronously update our pages is to make use of a special JavaScript object called an XMLHttpRequest.

* After obtaining your new object, you need to define its `onreadystatechange` behavior.
    * This is a function (typically an `anonymous function`) that will be called when the asynchronous `HTTP request` has completed, and thus typically defines what is expected to change on your site.

___

* `XMLHttpRequests` have two additional properties that are used to detect when the page finishes loading.
    * The `readyState` property will change from from 0 (request not yet initialized) to 1, 2, 3, and finally `4` (request finished, response ready).
    * The `status` property will (hopefully!) be `200 (OK)`.

* Then just make your asynchronous request using the `open()` method to define the request and the `send()` method to actually send it.
    * There is a slightly different way to do this syntactically with `jQuery`!

___

```js
function ajax_request(argument) 
{ 
    var aj = new XMLHttpRequest(); 
    // Function to execute on ReadyState change 
    aj.onreadystatechange = function() { 
        // if readyState is 4 and status is 200
        if (aj.readyState == 4 && aj.status == 200) 
            // do something to the page 
    }; 
    aj.open("GET", /* url */, true); 
    aj.send(); 
}
```

___

### `jQuery Ajax ` 

* More commonly, you’ll see Ajax requests written using `jQuery` instead of “raw” `JavaScript`.

[jQuery Ajax Docs](http://api.jquery.com/jquery.ajax/)

___

Refresh  only the contents of selector:

```js
function CS50Info(name) 
{
    // Deal with the situation where nothing is chosen
    if (name == "")
        return; 

    // create new AJAX object
    var ajax = new XMLHttpRequest();

    // when the page is loaded, have a callback function pre-fill our div
    ajax.onreadystatechange = function() {
        if (ajax.readyState == 4 && ajax.status == 200) {
            $('selector').html(ajax.responseText);
        }
    }

    ajax.open("GET", name, ".html", true);
    ajax.send();
}
```

___

Return to [`CS50x`](/README.md)