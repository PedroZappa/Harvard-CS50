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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        #  Unpack POST data
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        # Check current stock price
        quote = lookup(symbol)
        
        ''' Validate quote & shares '''
        # if symbol doesn't exist
        if not quote:
            return apology("invalid stock symbol", 403)
        
        # Ensure shares was submitted
        if not shares:
            return apology("must provide shares", 403)
        
        
        ''' Make the Purchase '''
        # Cast symbol to uppercase
        symbol = symbol.upper()
        # Ensure shares is a number
        shares = int(shares)
        # Price to be paid
        purchase = quote["price"] * shares
        
        # Select user's cash balance
        balance = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        balance = balance[0]["cash"]
        remainder = balance - purchase
        
        #  If price exceeds balance, return 
        if remainder < 0:
            return apology("not enough money", 403)
        
        # Query shares table for row with this user_id and symbol
        row = db.execute("SELECT * FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)
        
        # if row doesn't exist, create it
        if not row:
            db.execute("INSERT INTO portfolio (user_id, symbol) VALUES (?, ?)", session["user_id"], symbol)
        
        # Get previous # of shares owned by user
        prev_shares = db.execute("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)
        prev_shares = prev_shares[0]["shares"]
        
        #  Add purchased shares to prev_shares
        updated_shares = prev_shares + shares
        
        ''' Update Database '''
        
        # Update shares table
        db.execute("UPDATE portfolio SET shares = ? WHERE user_id = ? AND symbol = ?", updated_shares, session["user_id"], symbol)
        
        # Update user's cash balance
        db.execute("UPDATE users SET cash = ? WHERE id = ?", remainder, session["user_id"])
        
        # Update history table
        db.execute("INSERT INTO history (user_id, symbol, shares, method, price) VALUES (?, ?, ?, 'Buy', ?)", session["user_id"], symbol, shares, quote["price"])
        
        
        #  Return to homepage
        return redirect("/")
    
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

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
        
        # Ensure symbol was submitted
        if not symbol:
            return apology("must provide symbol", 403)
        
        # Query database for symbol
        quote = lookup(symbol)
        
        # Ensure symbol exists
        if not quote:
            return apology("invalid symbol", 403)
        
        # Display the quote
        return render_template("quoted.html", quote=quote)
    
    else:
        # Get stock quote page
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
            return apology("must provide username", 403)
        
        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 403)
        
        # if password different from confirmation
        elif password != confirmation:
            return apology("passwords do not match", 403)
        
        # Check if username already exists in db
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        
        #  Make sure user doesn't already exist
        if len(rows) != 0:
            return apology("username already exists", 403)
        
        # Insert user into database with generated password hash
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", 
                          username, generate_password_hash(password)) 
        
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
    return apology("TODO")
