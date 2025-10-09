### Our Communication Protocol

Our **VitalWatch** system utilizes a robust and adaptive communication protocol that guarantees continuous, reliable data transfer. We have engineered a two-tiered system that leverages the strengths of both **ESP-NOW** and **Wi-Fi** to ensure that our caregivers are always connected to their patients, regardless of their location within a facility.

---

### ESP-NOW: The Primary Protocol 📡

ESP-NOW is a fast, connectionless, peer-to-peer communication protocol designed by Espressif Systems. We chose it as our primary protocol for its key advantages:

* **Low Power Consumption:** It requires significantly less power than Wi-Fi, extending the battery life of our patient's wearable device.
* **Low Latency:** Data and alerts are transmitted almost instantaneously, which is critical in a medical emergency.
* **Independence from a Router:** It creates a direct link between our slave (patient) and master (caregiver) devices, eliminating the need for a central Wi-Fi access point. This makes our system highly reliable, even in areas with poor or no Wi-Fi coverage.

In this mode, the patient's device sends vital sign data directly to the caregiver's device when they are in close proximity. This ensures that when the caregiver is on the same floor or within a certain range, all alerts are delivered with maximum speed and efficiency. 

---

### Wi-Fi: The Fallback Protocol 🌐

To address the limited range of ESP-NOW, we have implemented an intelligent **Wi-Fi fallback system**. This serves as our long-range communication solution.

* **Automatic Switching:** Our system continuously monitors the ESP-NOW connection. If the caregiver's device moves out of range and the connection is lost, the patient's device automatically switches to a pre-configured Wi-Fi network.
* **Extended Range:** By utilizing a facility's existing Wi-Fi infrastructure, our system can send alerts to the caregiver from anywhere within the network, even if they are on a different floor or in another part of the building.
* **Seamless Integration:** The transition between protocols is seamless and requires no manual intervention from the user. Once the master and slave devices are back within ESP-NOW range, they automatically reconnect to the more efficient protocol.

This hybrid approach guarantees that our **VitalWatch** provides continuous monitoring and ensures that critical alerts are never missed.
