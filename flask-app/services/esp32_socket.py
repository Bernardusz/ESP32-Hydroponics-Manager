import socket
import json
getData = 'getdata\n'
def getESP32Data():
    esp_ip = "192.168.4.1"
    esp_port = 80
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((esp_ip, esp_port))
            s.sendall(getData.encode())

            data = s.recv(1024).decode('utf-8')
            print("Raw Data: ", data)
            json_data = json.loads(data)
            return json_data
    except Exception as e:
        print("ESP32 Socket Error: ", e)
        return {"error" : "ESP32 Unreachable"}