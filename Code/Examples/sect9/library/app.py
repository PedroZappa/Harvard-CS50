from cs50 import SQL
from flask import Flask, render_template, request
from helpers import random_string
import random

# Create FLASK app based on this file 
# __name__ refers to the name if THIS file
app = Flask(__name__)

db = SQL("sqlite:///history.db")

app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # From this request, from submitted form, get me the value of the input named 'page'.
        page = request.form.get("page")
        # Check if integer
        try:
            page = int(page)
        except ValueError:
            return render_template("index.html", random_string="Type in a number!")
        # Accept only positive integers
        if page < 0:
               return render_template("index.html", random_string="Type a positive integer!")
        # Insert page number into db
        db.execute("INSERT INTO history (page) VALUES (?);", page)
        # set random string by the page number
        random.seed(page)
        
    string = random_string(1000)
    # Will return a list of all the rows as dictionaries.
    rows = db.execute("SELECT * FROM history;")
    
    name = "Zedro"
    return render_template("index.html", random_string=string, history=rows)
