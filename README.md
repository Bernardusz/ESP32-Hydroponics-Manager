# 🌱 ESP32-Hydroponics-Manager

> An IoT-based hydroponics monitoring system using ESP32

## 📊 Features (MVP)
- Real-time pH sensor reading
- TDS (PPM) sensor monitoring
- Water level detection
- Data sent via serial to Java Android app
- SD Card data logging (soon)

## 🖨 Hardware List 
- ESP32 CP2102 38 Pin
- pH Meter Sensor (PH-4502C with Probe)
- TDS Meter Sensor
- DHT22
- USB Power Adapter + USB C Cable
- Jumper Wires
- Breadboard / PCB

## 🖥 Software & Dependencies
- 💻 Software :
  - PlatformIO (Arduino Framework)
  - Java Android Studio for companion app
  
- 📚 Library / Dependencies:
  - | Sensor        | Library       |
    | ------------- | ------------- |
    | DHT22  | Adafruit DHT sensor library|
    | TDS Meter  | Analog reading (No library)  |
    | Water Level Sensor | Analog reading (No Library)|
    | pH Meter | Analog reading (No Library) |

## 🚀 How To Use
1. 📩 Upload ESP32 firmware via PlatformIO
2. ⚡ Connect sensors to ESP32 (Later see wiring diagrams)
3. 📲 Run Java App to fetch and display data via serial

## 🌟 Future Features
1. Relay controlling Fan, Exhaust and Lamp via fetching time
2. Android app data graph display
3. Smart house integration
4. Camera monitoring Hydroponics

## 📷 Doccumentation
> To be added in the future

## 📃 License 
> MIT License - see [License](LICENSE)

## Remember 🌠!
> *"Sometimes the biggest idea comes from idling around and being bored !"* - Made by [**Bernardusz**](https://github.com/Bernardusz), a 10th grader bored in a holiday
