# [Shorts_8](/README.md): `SQL`

## `Table o'Contents`

* [Internet Primer](#internet-primer)
    * [IP Address](#ip-address)
    * [IPv6 Address](#ipv6-address)
    * [DHCP](#dhcp)
    * [DNS](#dns)
    * [Access Points](#access-points)
* [IP](#ip)
* [TCP](#tcp)
* [HTTP](#http)
* [HTML](#html)
* [CSS](#css)
    * [Common CSS Properties](#common-css-properties)
* [JavaScript](#javascript)
    * [Variables](#variables)
    * [Conditionals](#conditionals)
    * [Loops](#loops)
    * [Functions](#functions)
    * [Arrays](#arrays)
    * [Objects](#objects)
    * [Loop Redux](#loop-redux)
* [DOM](#dom)
    * [DOM Properties](#dom-properties)
    * [DOM Methods](#dom-methods)
    * [JQuery](#jquery)

___

## [Internet Primer](#table-ocontents)

* We’ve reached the point in the course where we begin the transition away from the `command-line` oriented world of `C` and start considering the `web-based` world of `PHP` and the like.

* Before we dive headlong into that world, it’s a good idea to have a basic understanding of how humans and computers interact over the `internet`.

![Internet Primer](/IMG/Shorts8/3.png)
___

### [_`IP Address`_](#table-ocontents)` [Internet Protocol]`

* In order for your machine to `uniquely identify itself` on the `Internet`, it needs an `address`. 

* This way, it can `send information` out and also `receive information` back to the correct location.

* The addressing scheme used by computers is known as `IP addressing`.

___

As originally developed, the `IP addressing scheme` would effectively allocate a unique `32-bit address` to each device hoping to connect to the `internet`.

* Instead of representing these `32-bit addresses` as `hexadecimal`, we represent them as `four clusters of 8-bits` using `decimal notation`.

___

> w.x.y.z

* Each of `w`, `x`, `y`, and `z` can be a nonnegative value in the `range [0, 255]`.

> 123.45.67.89
>
> 140.247.223.81

___

If each `IP address` is `32 bits`, that means there are roughly `4 billion addresses` to give out.

The population of the world is somewhere in excess of 7 billion, and most folks in the western world have more than 1 device capable of Internet connectivity.

* Some workarounds have allowed us to deal with this problem (for now).

___

In recent years, we’ve been slowly phasing out this old scheme `(IPv4)` and replacing it with a newer scheme `(IPv6)` that assigns computers `128-bit addresses`, instead of `32-bit addresses`.

> (32-bit) ~~4,294,967,296~~
>
> (128-bit) 340,282,366,920,938,463,463,374,607,431,768,211,456

___

### [_`IPv6 Address`_](#table-ocontents)

> s:t:u:v:w:x:y:z

Each of `s`, `t`, `u`, `v`, `w`, `x`, `y`, and `z` is represented by `1` to `4` `hexadecimal digits` in the `range [0,ffff]`.

> 1234:5678:90ab:cdef:fedc:ba09:8765:4321
>
> 2001:4860:4860:0:0:0:0:8844
>
 or
>
> 2001:4860:4860::8844


___

### [_`DHCP`_](#table-ocontents)

* How do we get an IP address in the first place though? Surely we can’t just choose any one we want. What if the want we want is already taken? 

* Somewhere between your computer and the Internet at large exists a `Dynamic Host Configuration Protocol` (`DHCP`) server, whose role is to assign `IP addresses` to devices.

* Prior to the widespread promulgation of `DHCP`, the task of assigning `IP addresses` fell to a `system administrator`, who would need to `manually` assign such `addresses`.

![DHCP](/IMG/Shorts8/5.png)

___

### [_`DNS`_](#table-ocontents)

Odds are, you’ve never actually tried to visit a website by typing its `IP address` into your browser.

The `Domain Name System` (`DNS`) exists to help us translate `IP addresses` to more memorable names that are more human comprehensible.

In this way, `DNS` is somewhat like the `yellow pages` of the web.
___

![DNS](/IMG/Shorts8/6.png)

![DNS](/IMG/Shorts8/8.png)

Much like there is no `yellow pages of the world`, there is really no `DNS record of the entire internet`.

* Rather, `large DNS server systems` (like Google’s own) are more like aggregators, collecting smaller sets of DNS information and pooling them together, updating frequently.

In that way, large `DNS servers` are like libraries that stock many different sets of local yellow page books. In order to have the most up-to-date phone numbers for businesses, libraries must update the books they have on hand.

`DNS` record sets are thus fairly decentralized.

![DNS](/IMG/Shorts8/11.png)

___

### [_`Access Points`_](#table-ocontents)

One of the ways we’ve dealt with the `IPv4 addressing` problem is to start assigning multiple people to the same `IP address`.

The `IP address` is assigned to a `router`, whose job it is to act as a `traffic cop` that allows `data requests` from all of the devices on your `local network` (your home or business, e.g.) to be processed through `a single IP address`.

Modern home networks consist of `access points` that combine a `router`, a `modem`, a `switch`, and `other technologies` together into a `single device`.

Modern `business networks` or `large-scale wide-area networks` (`WANs`) still frequently have these as separate devices to allow the size of their network to scale more easily.

![Access Points](/IMG/Shorts8/13.png)

This isn’t a course on `networking`, so this is `far from the whole story`, but it’s enough to get us started.

At home or at work we have local, small networks, and these networks are woven together to create a large, interconnected network—an Internet.

* If you think about each of these small networks being isolated communities with only a single road in or out, the picture becomes a bit clearer.

![Access Points](/IMG/Shorts8/17.png)

___

## [IP](#table-ocontents)

As discussed previously, “`the Internet`” is really an interconnected network comprised of smaller networks woven together and agreeing to communicate with one another.

How do these networks know how to communicate with one another? This is the responsibility of the `Internet Protocol` (`IP`).

Though it’s admittedly on an extremely small scale, this picture is misleading as it pertains to network communication.

___

![IP](/IMG/Shorts8/18.png)

With only `six networks`, things are rapidly getting out of hand. And the modern `Internet` consists of a lot `more than six networks`. We simply can’t afford to wire them together such that each directly connects with every other.

But still, we need each network to be able to talk to each other network, or we end up with pieces of the network that are unable to speak to other parts of the network.

___

This is where `routers` come back into play.

What if, instead of being connected to every other network, each network was connected to a limited number of routers (each of which was connected to other nearby routers), and each router had instructions built into it on how to move information toward its destination?

This information might be stored in a `routing table`, inside of the `router`.

___

For this illustration, let’s assume each network has IP addresses in the range of `n.x.x.x`, where `n` is its `network number`, and each `x` is in the `range [0, 255]`.

* A generalization of the way things actually work! 

___

![IP](/IMG/Shorts8/21.png)

Now the networks are not directly connected to each other at all, and rely on `routers` to distribute communications.

On a `small scale`, this configuration may actually be more inefficient than just having direct connections.

On a `large scale`, this configuration can dramatically reduce the costs of network infrastructure.

___

![IP](/IMG/Shorts8/23.png)

In reality, if `1.208.12.37` (me) is sending an e-mail, `FTP` file transfer, or web browser request to `5.188.109.14` (you), the data isn’t being sent as one huge block.

* Any slowdown that was caused by sending such a large amount of data would have a ripple effect that would throttle the network for all the other users.

As such, another crucial part of `IP` is splitting data into packets.

___

`IP` is also known as a `connectionless protocol`.
There is not necessarily a defined path from the sender to the receiver, and vice versa.

* This means that in response to traffic that might be `“clogging”` up one particular path through the `Internet`, some packets can be `“re-routed”` around the traffic jam to follow the most optimal path, based on the current state of the network.

The `routing table` then probably consists of more information than just `“where do I send this packet from here,”` but also information `“what is the cost of using that particular route?”`

* Another side of effect of being connectionless is that delivery cannot be guaranteed, since the path from sender to receiver is not guaranteed to be consistent.

___

## [TCP](#table-ocontents)

* If the `Internet Protocol` (`IP`) is thought of as the protocol for getting information from a sending machine to a receiving machine, then `Transmission Control Protocol` (`TCP`) can be thought of as directing the transmitted packet to the correct program on the receiving machine.

* As you might imagine, it is important to be able to identify both where the receiver is and what the packet is for, so `TCP` and `IP` are almost an inseparable pair: `TCP/IP`.

___

* Each program/utility/service on a machine is assigned a `port number`. Coupled with an `IP` address, we can now uniquely identify a specific program on a specific machine.

* The other thing that `TCP` is crucial for is `guaranteeing delivery` of packets, which `IP` alone does not do.

* `TCP` does this by including information about how many packets the receiver should expect to get, and in what order, and transmitting that information alongside the data.

___

* Some ports are so commonly used that they have been standardized across all computers.
    * `FTP` (file transfer) uses port 21.
    * `SMTP` (e-mail) uses port 25.
    * `DNS` uses port 53.
    * `HTTP` (web browsing) uses port 80.
    * `HTTPS` (secure web browsing) uses post 443.

___

Steps of the `TCP/IP` process:

1. When a program goes to send data, `TCP` breaks it into smaller chunks and communicates those packets to the computer’s network software, adding a `TCP` layer onto the packet.

2. IP routes the individual packets from sender to receiver; this info is part of the IP layer surrounding the packet.

3. When the destination computer gets the packet, TCP looks at the header to see which program it belongs to; and since the routes packets take may differ, TCP also must present those packets to the destination program in the proper order.

___

![TCP](/IMG/Shorts8/28.png)

• If at any point along the way a router delivering information using the `Internet Protocol` dropped a packet, `TCP` would use additional information inside the headers to request that the sender pass along the extra packet so it could complete assembly.

• After the packets have arrived, `TCP` ensures they are organized the correct order and can then be reassembled into the intended unit of data and delivered to the correct service.

___

## [HTTP](#table-ocontents)

* In addition to protocols that dictate how information is communicated from machine to machine and application to application (`IP` and `TCP`, respectively), it is frequently the case that the application itself has a system of rules for how to interpret the data that was sent.

* `HTTP` is one such example of an `application layer protocol`, which specifically dictates the format by which clients <u>request</u> web pages from a server, and the format via which servers <u>return</u> information to clients.

Other application layer protocols include:

* File Transfer Protocol (`FTP`)
* Simple Mail Transfer Protocol (`SMTP`)
* Data Distribution Service (`DDS`)
* Remote Desktop Protocol (`RDP`)
* Extensible Message and Presence Protocol (`XMPP`)

___

![HTTP](/IMG/Shorts8/31.png)

Or if something goes wrong

![HTTP](/IMG/Shorts8/32.png)

* A line of the form:

```http
method request-target http-version
```

* Is a simple example of an HTTP request line, a crucial part of an overall HTTP request that a client
may make to a server.

```http
method request-target HTTP/1.1
```

```http
GET request-target HTTP/1.1
```

```http
POST request-target HTTP/1.1
```

___

* The host name (domain name of the server) is also included as a separate line of the overall `HTTP request`.

* Taken together, the host name and the request target from the request line specify a specific resource being sought.

* Based on whether the resource exists and whether the server is empowered to deliver that resource pursuant to the client’s request, a number of `status codes` can result.

___

* A `status code` is part of the first line that a server will use to respond to an `HTTP request`.

```http
http-version status

HTTP/1.1 status
```

![HTTP](/IMG/Shorts8/33.png)

___

## [HTML](#table-ocontents)

HTML (Hypertext Markup Language) is a fundamental component of every website.

* `HTML` is a language, but it is not a programming language. It lacks concepts of variables, logic, functions, and the like.

• Rather, it is a `markup language`, using angle-bracket enclosed tags to semantically define the structure of a web page, causing the plain text inside of sets of tags to be interpreted by web browsers in different ways.

```html
<html>
    <head>
    <title>
    Hello, world
    </title>
    </head>
    <body>
    World, hello
    </body>
</html>
```

* Notice how the `markup` allows us to convey extra information about the text we’ve written.

* There are over 100 `HTML tags`, and lots of great resources online to find them. We won’t cover them all here.

* Another interesting way to learn about `HTML tags` is to view the source of a website you frequent by opening up your browser of choice’s developer tools.

___

### `Common HTML Tags`

```html
<b>...</b>
```

* Text between these tags will be rendered in <b>`boldface`</b> by the browser.

```html
<i>...</i> 
```

* Text between these tags will be rendered in <i>`italics`</i> by the browser.

```html
<u>...</u> 
```

* Text between these tags will be rendered <u>`underlined`</u> by the browser.

___

```html
<p>...</p>
```

* Text between these tags will be rendered as a `paragraph` by the browser, with space above and below.

```html
<hX>, </hX> 
```

> X = 1, 2, 3, 4, 5, or 6

* Text between these tags will be rendered as an `X-level section header`.

___

```html
<ul></ul>
```

* Demarcate the beginning and end of an `unordered (bulleted) list`.

```html
<ol></ol>
```

* Demarcate the beginning and end of an `ordered (numbered) list`.

Inside either `<ul>` and `<ol>`:

```html
<li></li>
```

* Demarcate list items with an `ordered or unordered list`.

___

```html
<table></table>
```

* Demarcate the beginning and end of a `table` definition.

```html
<tr></tr>
```

* Demarcate the beginning and end of a row within a table.

```html
<td></td>
```

* Demarcate the beginning and end of a column within a row within  a table.

___

```html
<form>...</form>
```

* Demarcate the beginning and end of an HTML form.

```html
<div>...</div>
```

* Demarcate the beginning and end of an arbitrary HTML page division.

```html
<input name=X type=Y /> 
```

* Define a field `within an HTML form`. `X` is a unique identifier for that field, `Y` is what type of data it accepts.

___

```HTML
<form> 
    ...
</form>
```

* Demarcate the beginning and end of an `HTML` form.

```html
<div> ... </div>
```

* Demarcate the beginning and end of an arbitrary HTML page division.

```html
<input name=X type=Y /> 
```

* Define a field within an HTML form. X is a unique identifier for that field, Y is what type of data it accepts.

___

```html
<a href=X> ... </a> 
```

* Creates a hyperlink to web page X, with the text between the tags rendered and functional as the link text.

```html
<img src=X ... /> 
```

* Another self-closing tag for displaying an image located at X, with possible additional attributes (such as specifying width and height).

```html
<!DOCTYPE html>
```

* Specific to HTML5, lets the browser know that’s the standard you’re using.

___

```HTML
<!-- ... --> 
```

* Demarcate the beginning and end of an `HTML comment`.

* Beyond the tags as explained here, each can also have multiple attributes that slightly modify the tag.

    * For example, you can usually add an `id=X` attribute, to uniquely identify a tag within an overall page.

___

* It is important that the `HTML` you write be `well-formed`. Every tag you open should be closed (unless it is a self-closing tag), and tags should be closed in reverse order of when they were opened.

* Unlike `C`, your `HTML` will not necessarily fail with syntax errors if not `well-formed`, so it’s up to you to be vigilant.

* Because it can be an arduous task to investigate this, be sure to use online `HTML` validators to help!

___

## [CSS](#table-ocontents)

* `CSS` (`Cascading Style Sheets`) is another language we use to when constructing websites.

* If `HTML` is used to organize the content that we aim to display on our pages, then CSS is the tool we use to customize our website’s look and feel.

* Like `HTML`, `CSS` is not a programming language; it lacks logic. Rather, it is a `styling language` and its syntax describes how certain attributes of `HTML` elements should be modified.

```css
body { 
    background-color: blue; 
}
```

___

* A `style sheet` is constructed by identifying a selector (in the last example, body) and then an open curly brace to indicate the beginning of the style sheet for that selector.

* In between the curly brace you place a list of `key-value pairs` of style properties and values for those properties, each declaration ending with a semicolon.

* Then a closing curly brace terminates the style sheet.

___

### [`Common CSS properties`](#table-ocontents)

`border`: `style` `color` `width`

* Applies a border of the specified color, width, and style (e.g., dotted, dashed, solid, ridge…).

`background-color`: [`keyword` | `#<6-digit hex>`]

* Sets the background color. Some colors are pre-defined in CSS.

`color`: [`keyword` | `#<6-digit hex>`]

* Sets the foreground color (usually text).

___

`font-size`: [`absolute size` | `relative size`]

* Can use keywords (`xx-small`, `medium…`), fixed points (`10pt`, `12pt…`), percentage (`80%`, `120%`), or base off the most recent font size (`smaller`, `larger`).

`font-family`: [`font name` | `generic name`]

* Certain “`web safe`” fonts are pre-defined in `CSS`.

`text-align`: [`left` | `right` | `center` | `justify`]

* For displaying text.

___

Your selectors don’t have to apply only to `HTML` tag categories. There also exist `ID` selectors and `class` selectors.

A `tag` selector will apply to all elements with a given HTML tag.

```css
h2 
{
    font-family: times; color: \#fefefe; 
}
```

• An `ID` selector will apply only to an HTML tag with a unique identifier.

```css
#unique 
{ 
    border: 4px dotted blue; text-align: right; 
}
```

• A `class` selector will apply only to those `HTML tags` that have been given identical `“class” attributes`.

```css
.students 
{ 
    background-color: yellow; opacity: 0.7;
}
```

___

* `Style sheets` can be written directly into your `HTML`.
    * Place them within `<style>` tags within your page’s head.

* `Style sheets` can also be written as separate `CSS` files and then linked in to your document.
    * Use `<link>` tags within your page’s head to accomplish this.

___

## [JavaScript](#table-ocontents)

* Like `PHP`, `JavaScript` is a modern programming language that is derived from the syntax at `C`.

* It has been around just about as long as `PHP`, also having been invented in 1995.

* `JavaScript`, `HTML`, and `CSS` make up the three languages defining most of the user experience on the web.

____

* To start writing `JavaScript`, open up a file with the `.js` file extension.

* No need for any code delimiters like we had in `PHP`. Our website will know that our file is `JavaScript` because we'll explicitly tell it as much in an `HTML` tag.

* Unlike `PHP` which runs server-side, `JavaScript` applications run client-side, on your own machine.

___

### Including JavaScript in your HTML

* Just like CSS with `<style>` tags, you can directly write your `JavaScript` between `<script>` tags.

* Just like CSS with `<link>` tags, you can write your JavaScript in separate files and link them in by using the `src` attribute of the `<script>` tag.

___

### [Variables](#table-ocontents)

* `JavaScript` variables are similar to `PHP` variables.
    * No type specifier.
    * When a local variable is first declared, preface with the `var` keyword.

> $x = 44;
>
> ~~$x = 44;~~
>
> var x = 44;

___

### [Conditionals](#table-ocontents)

* All of the old favorites from `C` are still available for you to use.

```js
if
else if
else
switch
?:
```

___

### [Loops](#table-ocontents)

* All of the old favorites from `C` are still available for you to use.

```js
while
do-while
for
```

### [Functions](#table-ocontents)

* All functions are introduced with the function keyword.

* `JavaScript` functions, particularly those bound specifically to `HTML` elements, can be anonymous—you don't have to give them a name!

* We'll revisit anonymity a little later, and we'll revisit "binding to `HTML` elements" in the video on the `Document Object Model`.

___

### [Arrays](#table-ocontents)

* Declaring an array is pretty straightforward.

```js
var nums = [1, 2, 3, 4, 5]; 
var mixed = [1, true, 3.333, 'five'];
```

___

### [Objects](#table-ocontents)

* `JavaScript` has the ability to behave as an `object-oriented programming` language.

* An `object` is sort of analogous to a `C structure`.

___

* `C` structures contain a number of fields, which we might also call properties.
    * But the properties themselves can not ever stand on their own.

```c
struct car 
{ 
    int year; 
    char model[10]; 
}
```

```c
struct car herbie;
herbie.year = 1963; 
herbie.model = "Beetle";
```

___

* `C structures` contain a number of fields, which we might also call properties.
    * But the properties themselves can not ever stand on their own.

* `Objects`, meanwhile, have properties but also methods, or functions that are inherent to the object, and mean nothing outside of it.
    * Thus, like properties can methods not ever stand on their own.

___
Object oriented programming:

```js
object.function();
```

* The fields and methods of an object are similar in spirit to the idea of an associative array, with which we're familiar from `Python`.

```js
var herbie = {year : 1963, model: 'Beetle'};
```

### [Loops Redux](#table-ocontents)

* How do we iterate across all of the `key-value pairs` of an `object` (or indeed, all of the `elements` of an `array`)?

Iterate over all the keys:

```js
for (var key in object) { 
    // use object[key] in here 
}
```

Iterate over all the values:

```js
for (var key of object) { 
    // use key in here 
}
```

___

```js
var wkArray = [
    'Monday, 
    'Tuesday', 
    'Wednesday', 
    'Thursday', 
    'Friday', 
    'Saturday', 
    'Sunday'
];
```

```js
for (var day in wkArray) { 
    console.log(day); 
}
```

```js
for (var day of wkArray) { 
    console.log(day); 
}
```

### Printing and variable interpolation

```js
console.log(wkArray[day] + ' is day number ' 
    + (day + 1) + 
    ' of the week!');
```

```js
console.log(wkArray[day] + ' is day number ' 
    + (parseInt(day) + 1) + 
    'of the week!');
```

* `Arrays` are a `special case` of an `object` (in fact, everything in `JavaScript` is a `special case` of an `object`), and has numerous methods that can applied to them:
    * `array.size()`, `array.pop()`, `array.push(x)`, `array.shift()`;

* There is also a method for arrays called `map()`, which can be used to apply a function to all elements of an array.
    * A great situation to use an anonymous function

___

```js
var nums = [1, 2, 3, 4, 5];

nums = nums.map(function(num) { 
    return num * 2; 
});
```

```js
var nums = [2, 4, 6, 8, 10]; 

nums = nums.map(function(num) { 
    return num * 2; 
});
```

### [`Event Handlers`](#table-ocontents)

* An event in `HTML` and `JavaScript` is a response to user interaction with the web page.
    * A user clicks a button, a page has finished loading, a user has hovered over a portion of the page, the user typed in an input field.

* `JavaScript` has support for event handlers, which are callback functions that respond to `HTML` events.
    * Many `HTML` elements have support for events as an attribute.

```html
<html>
    <head>
        <title>
            Event Handlers
        </title>
    </head>
    <body>
        <button onclick="">
            Button 1
        </button>
        <button onclick="">
            Button 2
        </button>
    </body>
</html>
```

___

* We can write a generic event handler in `JavaScript`, creating an event `object`, that will tell us which of these two buttons was clicked.

```html
<html>
    <head>
        <title>
            Event Handlers
        </title>
    </head>
    <body>
        <button onclick="alertName(event)">
            Button 1
        </button>
        <button onclick="alertName(event)">
            Button 2
        </button>
    </body>
</html>
```

```js
function alertName(event) 
{ 
    var trigger = event.srcElement;
    alert('You clicked on ' + trigger.innerHTML); 
}
```

___

## [DOM](#table-ocontents)

* As we’ve seen, `JavaScript` objects are incredibly flexible, and can contain various fields, even when those fields are other objects.

* The document object is one way of employing this paradigm, whereby that object organizes the entire contents of a web page.

* By organizing an entire page into a `JavaScript` object, we can manipulate the page’s elements programmatically.

___

```html
<html>
    <head>
        <title>
            Hello, world
        </title>
    </head>
    <body>
        <h2>
            Here’s my page
        </h2>
        <p>
            World, hello
        </p>
        <a href=“test.html”>Link</a>
    </body>
</html>
```

![Hello, world](/IMG/Shorts8/34.png)

• The `document object` itself, as well as all of the objects contained within it, have a number of `properties` and a number of `methods` that can be used to drill down to a very specific piece of your website.

• By resetting those `properties` or calling certain `methods`, the contents of our web pages can change without us needing to refresh the page.

___

### [`DOM Properties`](#table-ocontents)

DOM Property | Description
--- | ---
`innerHTML` | Holds the HTML inside a set of HTML tags.
`nodeName` | The name of an HTML element or element’s attribute.
`id` | The “id” attribute of an HTML element.
`parentNode` | A reference to the node one level up in the DOM.
`childNodes` | An array of references to the nodes one level down in the DOM.
`attributes` | An array of attributes of an HTML element.
`style` | An object encapsulating the CSS/HTML styling of an element.

___

* Gets the element with a given ID below this point in the DOM.

___

### [`DOM Methods`](#table-ocontents)

DOM Method | Description
--- | ---
`getElementById(id)` | Gets the element with a given ID below this point in the DOM.
`getElementsByTagName(tag)` | Gets all elements with the given tag below this point in the DOM.
`appendChild(node)` | Add the given node to the DOM below this point.
`removeChild(node)` | Remove the specified child node from the DOM.

___

* If we start from document, we can get to any piece of our web page that we choose, through careful use of DOM properties and methods.

___

### [jQuery](#table-ocontents)

* Because DOM manipulation is so common with JavaScript, and because the JavaScript to do so can get quite lengthy, people wanted alternatives.

* jQuery is a popular open-source library, released in 2006, that is designed to simplify client-side scripting (such as DOM manipulations).

___

> document.getElementById(‘colorDiv’).style.backgroundColor = ‘green’

> ~~document.getElementById(‘colorDiv’).style.backgroundColor = ‘green’~~

> $(‘#colorDiv’).css(‘background-color’, ‘green’);

___

Change color

```js
function changeColor(color)
{
    document.getElementById(‘colorDiv’).style.backgroundColor = color;
}
```

Change color Event Handler

```js
function changeColorEvent(event)
{
    var triggerObject = event.srcElement;
    document.getElementById('colorDiv').style.backgroundColor = triggerObject.innerHTML.toLowerCase();
}
```

same but in jQuery

```js
// When page is loaded
$(document).ready(function() {
    // Fetch every element with a class of jQButton
    $('.jQButton').click(function() {
        // Change background color
        $('#colorDiv').css('background-color', this.innerHTML.toLowerCase());
    })
})
```

[jQuery Documentation](https://api.jquery.com)

___

Return to [`CS50x`](/README.md)