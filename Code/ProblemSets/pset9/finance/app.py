import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Get users total stocks
    stocks = db.execute(
        "SELECT symbol, SUM(history.shares) AS sum_shares FROM history WHERE user_id = ? GROUP BY symbol HAVING sum_shares > 0",
        session["user_id"]
    )
    # Get users total cash
    cash = db.execute(
        "SELECT cash FROM users WHERE id = ?",
        session["user_id"]
    )
    # Get cash value float
    cash = cash[0]["cash"]

    # Initialize variables
    total = cash
    grand_total = cash

    # Loop through live Stocks and add price and total value
    for stock in stocks:
        quote = lookup(stock["symbol"])
        stock["name"] = quote["name"]
        stock["price"] = quote["price"]
        stock["value"] = stock["price"] * stock["sum_shares"]

        # Increment totals
        total += stock["value"]
        grand_total += stock["value"]

    return render_template("index.html", stocks=stocks, cash=usd(cash), total=usd(total), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        #  Unpack POST data
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        # Check current stock price
        quote = lookup(symbol)

        ''' Validate symbol, quote & shares '''

        # if symbol doesn't exist
        if not symbol:
            return apology("invalid symbol", 400)
        # Ensure shares was submitted
        if not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("must provide a positive number shares", 400)
        #  Validate quote
        if quote is None:
            return apology("invalid symbol", 400)

        ''' Make the Purchase '''

        # Ensure shares is a number
        shares = int(shares)
        # Price to be paid
        price = quote["price"]
        total_price = price * int(shares)
        # Select user's cash balance
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = cash[0]["cash"]
        remainder = cash - price

        #  If price exceeds balance, return
        if cash < total_price:
            return apology("not enough money", 400)

        ''' Update Database '''

        # Update users table
        db.execute(
            "UPDATE users SET cash = cash - ? WHERE id = ?",
            total_price, session["user_id"]
        )

        # Update history table
        db.execute(
            "INSERT INTO history (user_id, symbol, shares, method, price) VALUES (?, ?, ?, 'Buy', ?)", session["user_id"],
            symbol, shares, price
        )

        flash(f"Congrats! You just bought {shares} shares of {symbol} for {usd(total_price)}!")
        #  Return to homepage
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Query for user'shistory, ordered by most recent first
    history = db.execute("SELECT * FROM history WHERE user_id = ? ORDER BY transacted DESC", session["user_id"])

    # Render history page w/ transactions
    return render_template("history.html", transactions=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        # Unpack the POST data
        symbol = request.form.get("symbol")
        if symbol is None:
            return apology("invalid symbol", 400)
        # Query database for symbol
        quote = lookup(symbol)
        if quote is None:
            return apology("unable to retrieve quote", 400)

        # Format usd
        quote["price"] = usd(quote["price"])

        # Display the quote
        return render_template("quote.html", quote=quote)

    else:
        # Get request
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user session
    session.clear()

    # Handle POST request
    if request.method == "POST":

        # Unpack the POST data
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 400)

        # if password different from confirmation
        elif password != confirmation:
            return apology("passwords do not match", 400)

        # Check if username already exists in db
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?",
            username
        )

        #  Make sure user doesn't already exist
        if len(rows) != 0:
            return apology("username already exists", 400)

        # Insert user into database with generated password hash
        db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?)",
            username, generate_password_hash(password)
        )

        # Query db for newly created user
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Remember who's logged in
        session["user_id"] = rows[0]["id"]

        return redirect("/")

    # Handle GET request (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # Get user's stocks
    stocks = db.execute(
        "SELECT symbol, SUM(shares) AS sum_shares FROM history WHERE user_id = ? GROUP BY symbol HAVING sum_shares > 0",
        session["user_id"]
    )

    # Handle POST request
    if request.method == "POST":
        # Unpack POST data
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        # Get Stock quote
        quote = lookup(symbol)

        ''' Validate symbol, quote & shares '''

        # if symbol doesn't exist
        if not symbol:
            return apology("invalid symbol", 400)
        # Ensure shares was submitted
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("must provide a positive number of shares", 400)
        else:
            shares = int(shares)

        ''' Sell '''

        for stock in stocks:
            if stock["symbol"] == symbol:
                if stock["sum_shares"] < shares:
                    return apology("not enough shares", 400)
                else:
                    if quote is None:
                        return apology("invalid symbol", 400)
                    price = quote["price"]
                    total_price = shares * price

                    # Update users table
                    db.execute(
                        "UPDATE users SET cash = cash + ? WHERE id = ?",
                        total_price, session["user_id"]
                    )

                    # Update history table
                    db.execute(
                        "INSERT INTO history (user_id, symbol, shares, method, price) VALUES (?, ?, ?, 'Sell', ?)",
                        session["user_id"], symbol, shares, price
                    )

                    flash(f"Congrats! You just sold {shares} shares of {symbol} for {usd(total_price)}!")

        return redirect("/")

    else:
        # on GET request
        user_id = session["user_id"]
        user_symbols = db.execute(
            "SELECT symbol, SUM(shares) AS sum_shares FROM history WHERE user_id = ? GROUP BY symbol HAVING sum_shares > 0",
            session["user_id"]
        )

        # stocks gets a 'list comprehension' that generates a list of symbols from a list of row objects.
        return render_template("sell.html", stocks=user_symbols)

