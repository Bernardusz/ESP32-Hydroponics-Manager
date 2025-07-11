import socket
import json

esp_ip = "192.168.4.1"
esp_port = 80

def getESP32Data():
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((esp_ip, esp_port))
            s.sendall('GET:DATA\n'.encode())

            data = s.recv(1024).decode('utf-8')
            print("Raw Data: ", data)
            json_data = json.loads(data)
            return json_data
    except Exception as e:
        print("ESP32 Socket Error: ", e)
        return {"error" : "ESP32 Unreachable"}
    
def readFile(filename):
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((esp_ip, esp_port))
            s.sendall(f'READ:{filename}\n'.encode())

            data = s.recv(1024).decode('utf-8')
            print("Raw Data: ", data)
            json_data = json.loads(data)
            return json_data
    except Exception as e:
        print("ESP32 Socket Error: ", e)
        return {"error" : "ESP32 Unreachable"}
    
def writeFile(filename):
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((esp_ip, esp_port))
            s.sendall(f'WRITE:{filename}\n'.encode())

            data = s.recv(1024).decode('utf-8')
            print("Raw Data: ", data)
            json_data = json.loads(data)
            return json_data
    except Exception as e:
        print("ESP32 Socket Error: ", e)
        return {"error" : "ESP32 Unreachable"}
    
def listFiles():
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((esp_ip, esp_port))
            s.sendall(f'LIST:\n'.encode())

            data = s.recv(1024).decode('utf-8')
            print("Raw Data: ", data)
            json_data = json.loads(data)
            return json_data
    except Exception as e:
        print("ESP32 Socket Error: ", e)
        return {"error" : "ESP32 Unreachable"}

def addNewFile(filename):
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((esp_ip, esp_port))
            s.sendall(f'CREATE:{filename}\n'.encode())

            data = s.recv(1024).decode('utf-8')
            print("Raw Data: ", data)
            json_data = json.loads(data)
            return json_data
    except Exception as e:
        print("ESP32 Socket Error: ", e)
        return {"error" : "ESP32 Unreachable"}