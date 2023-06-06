from flask import Flask, render_template, request

app = Flask(__name__)

# Capitalize GLOBAL vars
# dictionary with Key-Value = Name-Sport
REGISTRANTS = {}
# Hold all options that will be available in the form
SPORTS = [
    'Basketball',
    'Soccer',
    'Ultimate Frisbee',
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    #  Get user name and sport
    name = request.form.get("name")
    sport = request.form.get("sport")
    #  if no name inputted
    if not name:
        return render_template("failure.html")
    # Check if submitted sport is valid 
    if sport not in SPORTS:
        return render_template("failure.html")
    #  Set value to key
    REGISTRANTS[name] = sport
    return render_template("success.html")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)