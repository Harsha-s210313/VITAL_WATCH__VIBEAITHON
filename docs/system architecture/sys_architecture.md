### VitalWatch: Our System Architecture

We have designed our **VitalWatch** system with a robust and modular architecture to ensure reliable performance. The system is centered on a hub-and-spoke model where multiple patient devices (**slaves**) communicate with a single caregiver's device (**master**). This architecture is built upon a dual-mode communication protocol to guarantee seamless data transmission.

---

### Key Components

* **Slave Device (Patient Unit):** This wearable unit, built on an **ESP32 microcontroller**, is the data source. It integrates various sensors to monitor the patient's vitals.
    * **Sensors:** We have included sensors for blood pressure, SpO2 (oxygen levels), and ECG. An accelerometer handles fall detection.
    * **Data Processing:** The ESP32 processes the raw sensor data and converts it into usable health metrics.
    * **Communication Module:** This unit has both an ESP-NOW module and a Wi-Fi module. It continuously monitors the connection status and automatically switches between protocols.
    * **Power Source:** A rechargeable lithium-ion battery powers the device, optimized for low-power consumption. 

* **Master Device (Caregiver Unit):** This unit, also using an **ESP32 microcontroller**, serves as the central hub. It receives and interprets data from multiple slave devices.
    * **Display:** A small LCD or OLED screen displays real-time vitals and alerts for each assigned patient.
    * **Alert System:** The device uses haptic feedback (vibration), audible alerts, and visual indicators to notify the caregiver of a critical event.
    * **Communication Module:** This module receives data via ESP-NOW or Wi-Fi, depending on the slave device's protocol.

---

### Communication Flow

The data flow within our system is designed for reliability and efficiency.

1.  **ESP-NOW Mode (Local Communication):** When a patient is within the caregiver's vicinity, the slave device uses ESP-NOW to send vital signs every few seconds. If any vital sign falls outside a predefined safe range, or if a fall is detected, the slave immediately sends a high-priority alert to the master. This communication is direct, fast, and highly reliable for short distances.

2.  **Wi-Fi Mode (Remote Communication):** If the master device moves out of ESP-NOW range, our slave device automatically connects to a pre-configured Wi-Fi network. It then sends vital data and alerts to a central server or directly to the master device's IP address on the network. This ensures uninterrupted monitoring even when the caregiver is in a different room or floor.
