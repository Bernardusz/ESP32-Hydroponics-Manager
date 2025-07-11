from flask import Flask, render_template, jsonify
from services.esp32_socket import getESP32Data, listFiles, readFile, writeFile, addNewFile

app = Flask(__name__)
app.config['TEMPLATES_AUTO_RELOAD'] = True


@app.route("/")
def home():
    return render_template("index.html")

@app.route("/data")
def data_page():
    return render_template("data_read.html")

@app.route("/data_page/<filename>")
def files_page(filename):
    return render_template("data_page.html", file=filename)
    
@app.route("/data_list")
def logs_page():
    return render_template("data_list.html")



@app.route("/get_esp32_data")
def get_sensor_data():
    sensor_data = getESP32Data()
    return jsonify(sensor_data)

@app.route("/get_list_of_files")
def get_list_files():
    files_data = listFiles()
    return jsonify(files_data)

@app.route("/get_data/<filename>")
def get_data_from_logs(filename):
    log_data = readFile(filename)
    return jsonify(log_data)

@app.route("/set_write/<filename>")
def set_write(filename):
    status = writeFile(filename)
    return status
    
@app.route("/create_file/<filename>")
def create_file(filename):
    status = addNewFile(filename)
    return status

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)