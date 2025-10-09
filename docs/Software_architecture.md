### Our VitalWatch Software Architecture

We have developed our **VitalWatch** software architecture using a layered approach to ensure modularity, reliability, and efficient data flow. The system is designed to be highly responsive, with a clear separation of concerns between hardware interaction, data processing, and communication.

---

### Layered Architecture

* **1. Hardware Abstraction Layer (HAL):** This is the lowest layer, responsible for interacting directly with the hardware components. We've built this layer to abstract away the complexities of each sensor and peripheral. This allows us to easily swap out or upgrade a sensor without rewriting the core application logic. The HAL includes drivers for our sensors (ECG, SpO2, Accelerometer) and the microcontroller peripherals (I2C, SPI, ADC).
* **2. Data Processing & Logic Layer:** This is the core of our application, where all the magic happens. It takes the raw data from the HAL and processes it into meaningful health metrics. This layer contains:
    * **Signal Processing Algorithms:** We use these to filter noise and extract clean data from the raw sensor readings.
    * **Alerting Logic:** This logic constantly compares the processed vitals against predefined safe thresholds. If a value falls outside the normal range, it triggers a high-priority alert.
    * **Fall Detection Algorithm:** Our algorithm analyzes accelerometer data for patterns consistent with a fall (e.g., free-fall followed by a sudden impact and inactivity).
* **3. Communication Layer:** This layer manages all data transfer. We have implemented a state machine that seamlessly switches between our primary and secondary communication protocols.
    * **ESP-NOW Manager:** This module handles the direct, peer-to-peer communication with the master device. It's designed for low-power, high-speed data bursts.
    * **Wi-Fi Manager:** This module is activated when the ESP-NOW connection is lost. It handles connecting to a Wi-Fi network and sending data to a central server or directly to the master device.
* **4. User Interface Layer (Master Device Only):** On the master device, this layer is responsible for displaying the information.
    * **Display Driver:** Renders real-time vital signs and alerts on the OLED screen.
    * **Notification System:** Manages the haptic, visual, and audio alerts to ensure the caregiver is immediately notified of a critical event.

---

### Communication Protocol State Machine

Our software's most crucial feature is its ability to intelligently manage communication. We have implemented a state machine that ensures continuous connectivity. 

* **State 1: ESP-NOW Connected:** The default and most efficient state. The device actively sends vital data via the ESP-NOW protocol.
* **State 2: ESP-NOW Disconnected:** If the device can no longer ping the master, it transitions to the next state.
* **State 3: Wi-Fi Connecting:** The device attempts to connect to a known Wi-Fi network.
* **State 4: Wi-Fi Connected:** Data and alerts are now sent via the Wi-Fi network to the central server or the master device.
* **Transition Back:** Periodically, the device will attempt to re-establish the ESP-NOW connection. If successful, it transitions back to the ESP-NOW connected state, ensuring we always use the most power-efficient protocol when possible.
