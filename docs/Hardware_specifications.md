### VitalWatch: Our Hardware Specifications

We have carefully selected each component for our **VitalWatch** system to ensure it is compact, low-power, and highly reliable. Our hardware is built on the robust ESP32 platform, making it an ideal foundation for a wearable medical device.

---

### Central Processing Unit (CPU)
* **Microcontroller:** We have chosen the **ESP32-WROOM-32** module. It features an Xtensa dual-core 32-bit LX6 microprocessor, capable of running up to 240 MHz.
* **Memory:** It includes 520 KB of SRAM, 448 KB of ROM, and 16 KB of SRAM in the RTC (Real-Time Clock), providing ample memory for our sensor data processing and communication protocols.

---

### Communication Modules
* **ESP-NOW Protocol:** Our primary communication method. It's a connectionless protocol that offers low latency and consumes minimal power.
    * **Range:** We have achieved reliable indoor communication up to **40-100 meters**, and in open-field scenarios, the range extends to **220-400 meters**.
    * **Data Rate:** The default data rate is **1 Mbps**, which is more than sufficient for transmitting vital sign data.
* **Wi-Fi Connectivity:** For extended range, we have implemented an automatic switch to Wi-Fi. The ESP32 supports 802.11 b/g/n Wi-Fi, with a bit rate of up to **150 Mbps**.
* **Bluetooth:** The ESP32 also supports Bluetooth V4.2 BR/EDR and BLE (Bluetooth Low Energy), which we can utilize for future expansions or for direct, short-range connections to other devices.

---

### Sensors
We have integrated a suite of medical-grade sensors to provide accurate and comprehensive vital sign monitoring.
* **Blood Oxygen (SpO2) Monitoring:** We use a pulse oximetry sensor that works by shining red and infrared light through the skin to measure blood oxygen saturation, a standard method in clinical practice.
* **Blood Pressure Monitoring:** Our system uses a non-invasive blood pressure sensor that measures systolic, diastolic, and mean arterial pressure using the oscillometric method.
* **ECG Monitoring:** We use a wearable ECG sensor, such as a compact cardiac patch, to provide a continuous electrocardiogram to monitor heart rhythm and detect any irregularities.
* **Fall Detection:** We have integrated a **3-axis MEMS accelerometer**, such as the ADXL345 or ADXL367. Our custom algorithm detects a fall by analyzing a sequence of events: a period of weightlessness (free-fall), followed by a sudden impact, and a subsequent period of inactivity.

---

### User Interface & Power
* **Display:** We have selected a compact and power-efficient **OLED display**, such as the 0.96-inch or 1.3-inch I2C module with a resolution of 128x64 pixels. This screen is large enough to display critical vitals and alerts clearly while keeping the overall device size small.
* **Power Source:** Our wearable device is powered by a rechargeable **lithium-ion battery** (e.g., a small LiPo or 18650 cell). We have integrated an onboard battery management and charging circuit to allow for easy recharging via a standard USB port, ensuring long-lasting performance with low-power consumption modes.
