### VitalWatch: Our Power Management Strategy

We understand that for a wearable medical device, a long-lasting battery is as critical as its functionality. We have meticulously designed our power management system to optimize energy consumption, ensuring our **VitalWatch** can operate for extended periods without frequent recharging.

---

### Low-Power Hardware Selection

* **ESP32-WROOM-32 Module:** We chose the ESP32 for its built-in low-power features. The chip has different power modes, and we can switch between them based on our needs.
* **Power-Efficient Sensors:** We have selected sensors that consume minimal current, especially during periods of inactivity. Many of our chosen sensors support a low-power mode, which we leverage when not actively taking a reading.
* **OLED Display:** Our choice of an OLED screen is deliberate. Unlike LCDs, OLEDs only consume power for the pixels that are turned on, making them highly efficient, especially when displaying simple text or icons on a black background.

---

### Intelligent Software Optimization

Our software architecture plays a key role in extending battery life. We have implemented several strategies:

1.  **Sleep Modes:** We utilize the ESP32's various sleep modes to conserve power.
    * **Light Sleep:** This mode keeps the Wi-Fi and Bluetooth radios off while the CPU and RAM are still running. We enter this mode when the device is idle but needs to stay responsive for immediate communication.
    * **Deep Sleep:** We use this mode for more extended periods of inactivity. In this mode, only the RTC (Real-Time Clock) and RTC memory are powered, allowing the device to wake up at specific intervals to take a reading or when an interrupt is triggered (e.g., from an accelerometer for fall detection).

2.  **Optimized Sensor Polling:** We don't keep our sensors on constantly. Instead, we have developed a dynamic polling system.
    * **Standard Polling:** Under normal circumstances, our devices take vital sign readings at regular, predefined intervals (e.g., every 5 minutes).
    * **Event-Driven Polling:** If a vital sign shows an abnormal trend, or if the fall detection algorithm is triggered, the system instantly switches to a higher polling frequency to gather more data and confirm the alert.

3.  **Dynamic Communication Management:** As we have already outlined, our communication protocol is a core part of our power strategy.
    * We prioritize **ESP-NOW** communication because it is significantly more energy-efficient than Wi-Fi. By automatically switching to Wi-Fi only when necessary, we avoid unnecessary power drain from the more power-hungry protocol.

---

### Battery & Charging

* **Rechargeable Battery:** Our VitalWatch is powered by a high-capacity, rechargeable lithium-ion battery. This ensures long-term usability and reduces waste.
* **Integrated Charging Circuit:** We have integrated a standard USB charging circuit into our device. This allows our users to easily and conveniently recharge the device using a standard USB cable, just like a smartphone.

By combining low-power hardware, smart software, and a robust battery system, we ensure our **VitalWatch** can provide reliable, continuous monitoring for extended periods, minimizing the need for frequent charging and maximizing patient safety.
