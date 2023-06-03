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
* [JavaScript](#javascript)
* [DOM](#dom)

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

___

## [JavaScript](#table-ocontents)

___

## [DOM](#table-ocontents)

___
