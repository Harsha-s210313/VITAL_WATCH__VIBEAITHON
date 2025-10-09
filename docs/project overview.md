# VITAL WATCH

VitalWatch is a smart, wearable medical device that serves as a **vital sign monitoring system** for patients. Each patient wears a device set to **slave mode** that tracks oxygen levels, blood pressure, ECG, and detects falls. These devices communicate with a nurse's or caregiver's **master device** via a peer-to-peer network using the **ESP-NOW protocol**. This system enables a single caregiver to monitor multiple patients simultaneously and receive instant alerts for critical changes in vitals or emergencies like a fall.

The core strength of VitalWatch lies in its communication flexibility. It primarily uses **ESP-NOW** for its low power consumption and high speed, making it ideal for real-time, short-range alerts. If the caregiver moves out of range, the system automatically switches to a **Wi-Fi connection**, ensuring alerts are delivered regardless of distance. This seamless transition provides continuous monitoring and reliable communication in a hospital or care home setting, significantly reducing the risk of a missed medical emergency.


**Key Components & Their Roles:** 

* Slave Device (Patient's Watch): Gathers vital data and broadcasts alerts.

* Master Device (Caregiver's Watch): Receives data from multiple slaves and displays alerts.

* ESP-NOW Protocol: The primary, short-range, low-power communication channel.

* Wi-Fi Module: The long-range, fallback communication method for alerts.

* Sensors: Include an oximeter, blood pressure cuff, ECG electrodes, and an accelerometer for fall detection.
