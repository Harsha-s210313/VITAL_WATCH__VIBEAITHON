

## 🚀 Project Overview

The **Vital Watch** is a next-generation wearable device designed for accurate, continuous, and comprehensive health monitoring. Built around the powerful **ESP32** microcontroller, it integrates a suite of clinical-grade sensors onto a single, compact, circular PCB, making it suitable for a sleek watch form factor.

This project delivers a multi-sensor solution for health-tech enthusiasts, researchers, and individuals seeking reliable personal health data.

### Key Features
* **Clinical ECG:** Dedicated analog front-end for high-fidelity heart signal acquisition.
* **Continuous Vitals:** Real-time monitoring of Heart Rate (PPG), Blood Oxygen (SpO2), and Body Temperature.
* **Activity Tracking:** Integrated Inertial Measurement Unit (IMU) for accurate motion and step tracking.
* **Robust Power:** Multi-day battery life with a safe, efficient **USB-C** charging circuit.
* **Modular Design:** Removable ESP32-WROOM module for easy programming, prototyping, and future upgrades.

---

## 🛠️ Hardware & Components

This PCB is a two-layer design that integrates all components into a 40-45mm circular form factor.

### Core Technology Stack
| Component | Function | Communication |
| :--- | :--- | :--- |
| **ESP32-WROOM-32** | Main Microcontroller (MCU) | Wi-Fi, Bluetooth, I²C, UART |
| **AD8232ACPZ-R7** | ECG Analog Front-End (AFE) | Analog (ADC) |
| **MAX30101EFD+T** | Heart Rate (PPG) & SpO2 Sensor | I²C |
| **MPU-6050** | 6-Axis Inertial Measurement Unit (IMU) | I²C |
| **TMP112A** | High-Accuracy Digital Temperature Sensor | I²C |
| **BQ24040DSQR** | Li-ion Battery Charger | Power Management |
| **MCP1700-3302E** | 3.3V Low-Dropout Regulator (LDO) | Power Supply |
| **CP2102-GM** | USB-to-UART Bridge | Programming |

### Safety and Power Integrity
* **Polyfuse:** A 500mA resettable polyfuse is placed on the VBUS line for protection against overcurrent at the USB-C port.
* **Power Rail:** A dedicated LDO provides a clean, stable **3.3V** VDD rail to all digital components.

---

## 🖼️ Design Visuals

### PCB Layout (Top View)
This view shows the component placement and routing on the primary side of the circular board. The circular form factor is crucial for the watch enclosure.

### PCB in Enclosure (3D View)
A 3D rendering of the PCB inside its custom-designed, low-profile enclosure, highlighting the use of a USB-C port for charging.

---

## 🔌 Hardware Implementation Details

### **1. Signal Integrity**
* **Analog Isolation:** The sensitive **AD8232 ECG** circuit (along with its complex filter network) is intentionally placed away from the noisy digital components (ESP32) and high-current power traces to minimize noise and interference.
* **Ground Plane:** A large, contiguous ground plane (shown in red/maroon) is utilized to ensure signal return paths are short and to improve EMI performance.

### **2. I²C Bus**
The entire I²C bus, connecting the **OLED Display, MAX30101, MPU-6050, and TMP112**, is pulled up to 3.3V with 4.7kΩ resistors (not explicitly visible in the main image but assumed from the schematic). All four devices share the same SDA (IO21) and SCL (IO22) lines.

### **3. Removable ESP32 Module**
The ESP32 is connected via dual **1x19 through-hole headers** to allow for easy removal. This simplified design ensures all critical signals (UART, I²C, Power, ADC) are available on the headers.

### **4. Power Flow**
The circuit follows a strict power flow for safety and efficiency:
`USB-C (VBUS) → Polyfuse → BQ24040 (Charging) ⇌ Li-ion Battery → LDO (MCP1700) → 3.3V VDD Rail`

---

## 💻 Firmware & Setup

### **Requirements**
* **IDE:** Arduino IDE or VS Code with PlatformIO extension.
* **Framework:** ESP-IDF or Arduino Core for the ESP32.
* **Drivers:** CP2102 USB-to-UART bridge drivers must be installed for programming.

### **Programming**
1.  Connect the board via the **USB-C port**.
2.  The **CP2102** chip provides the necessary auto-reset functionality to put the **ESP32** into bootloader mode.
3.  Upload firmware via the serial port using the chosen development environment.
