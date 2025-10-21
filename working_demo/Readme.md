Here’s a **README.md** draft you can use for your Vital Watch project’s result section based on the setup and images you provided:

---

# 🩺 Vital Watch – Results Demonstration

## 📸 System Overview

The below setup demonstrates the working prototype of the **Vital Watch**, designed to measure and transmit real-time environmental parameters such as **Temperature** and **Pressure** using **ESP8266 (NodeMCU)** modules and display the results on an **I2C LCD**.

The setup includes:

* Two NodeMCU (ESP8266) boards – one as **Transmitter**, the other as **Receiver**.
* **BMP280 Sensor** for Temperature and Pressure data acquisition.
* **I2C LCD Display** for real-time visualization.
* Communication established through **ESP-NOW** protocol for efficient data transfer.

---

## ⚙️ Hardware Setup

### Components Used:

* NodeMCU ESP8266 × 2
* BMP280 Sensor Module
* I2C LCD Display (16x2)
* Breadboard and jumper wires
* USB cables for power and programming

### Circuit Description:

* The transmitter NodeMCU reads temperature and pressure data from the BMP280 sensor.
* The receiver NodeMCU receives this data over ESP-NOW.
* The receiver displays the current **Time**, **Temperature**, and **Pressure** on the LCD.

---

## 💻 Software Details

### Arduino Libraries Used:

```cpp
#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

### Data Structure for Communication:

```cpp
typedef struct struct_message {
  float temperature;
  float pressure;
} struct_message;

struct_message receivedData;
```

### LCD Configuration:

```cpp
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
```

This ensures proper mapping of LCD pins for displaying live readings.

---

## 📊 Output Observation

### Serial Monitor Output:

```
Temp: 32.80 °C, Pressure: 1003.63 hPa
Temp: 32.80 °C, Pressure: 1003.69 hPa
Temp: 32.80 °C, Pressure: 1003.72 hPa
```

### LCD Display Output:

```
Time: 5:50 PM
Temp: 32°C  P:1003
```

This confirms the accurate transmission and display of sensor data in real-time.

---

## 🧠 Working Explanation

1. **Transmitter NodeMCU** collects data from BMP280 and sends it via **ESP-NOW**.
2. **Receiver NodeMCU** decodes the data and updates both the **Serial Monitor** and **LCD** display.
3. The LCD continuously refreshes, showing the current temperature and pressure values along with the system clock time.

---

## 🧾 Results Summary

* Successful **wireless transmission** of environmental data using **ESP-NOW**.
* Real-time data displayed on **I2C LCD** with smooth updates.
* Stable readings with accurate temperature and pressure measurement.
* This confirms that the Vital Watch’s sensor and communication modules are functioning correctly.

---

## 📅 Test Details

* **Date of Test:** 18/10/2025
* **Time:** 5:50 PM
* **Temperature:** ~32°C
* **Pressure:** ~1003 hPa
* **Location:** Lab Testing Environment



