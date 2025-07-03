from flask import Flask, render_template, jsonify
from services.esp32_socket import getESP32Data

app = Flask(__name__)
app.config['TEMPLATES_AUTO_RELOAD'] = True


@app.route("/")
def home():
    return render_template("index.html")

@app.route("/data")
def data_page():
    return render_template("data_read.html")

@app.route("/ota")
def ota_page():
    return render_template("ota.html")

@app.route("/get_esp32_data")
def get_sensor_data():
    data = getESP32Data()
    return jsonify(data)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)