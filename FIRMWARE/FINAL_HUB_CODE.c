#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>  // For BMP180

Adafruit_BMP085 bmp;

// Replace with your Receiver (Slave) MAC Address
uint8_t receiverAddress[] = {0x24, 0x6F, 0x28, 0xA1, 0xBC, 0xDE}; // <-- change this

// Structure for sending data
typedef struct struct_message {
  float temperature;
  float pressure;
} struct_message;

struct_message sensorData;

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Send Status: ");
  Serial.println(sendStatus == 0 ? "Success" : "Fail");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (!bmp.begin()) {
    Serial.println("BMP180 not found. Check connections!");
    while (1);
  }

  if (esp_now_init() != 0) {
    Serial.println("ESP-NOW initialization failed!");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  esp_now_add_peer(receiverAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  // Read sensor data
  sensorData.temperature = bmp.readTemperature();
  sensorData.pressure = bmp.readPressure() / 100.0; // convert to hPa

  // Print to Serial
  Serial.print("Temp: "); Serial.print(sensorData.temperature);
  Serial.print(" °C, Pressure: "); Serial.print(sensorData.pressure);
  Serial.println(" hPa");

  // Send data
  esp_now_send(receiverAddress, (uint8_t *) &sensorData, sizeof(sensorData));

  delay(2000); // Send every 2 seconds
}
