#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (Your configuration)
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Structure must match sender
typedef struct struct_message {
  float temperature;
  float pressure;
} struct_message;

struct_message receivedData;

// Callback function that runs when data is received
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&receivedData, incomingData, sizeof(receivedData));
  
  Serial.print("Temp: ");
  Serial.print(receivedData.temperature);
  Serial.print(" °C, Pressure: ");
  Serial.print(receivedData.pressure);
  Serial.println(" hPa");

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(receivedData.temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Pres:");
  lcd.print(receivedData.pressure);
  lcd.print("hPa");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Waiting data...");

  if (esp_now_init() != 0) {
    Serial.println("ESP-NOW init failed!");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // Nothing else needed
}
