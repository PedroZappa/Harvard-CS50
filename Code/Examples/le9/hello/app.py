from flask import Flask, render_template, request

#  Create web app
app = Flask(__name__)

# Define routes
@app.route('/', methods=["GET", "POST"])
def index():
    if request.method == "GET":  
        return render_template('index.html')
    elif request.method == "POST":
        return render_template('greet.html', name=request.form.get("name", "whirl"))