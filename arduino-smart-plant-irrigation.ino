/*
 * Automatic Plant Watering System with I2C LCD Display
 * 
 * Components:
 * - Arduino Uno
 * - YL-69 Soil Moisture Sensor (Analog Pin A0)
 * - 5V Relay Module (Digital Pin 8)
 * - Mini Submersible Water Pump (Controlled via Relay)
 * - 16x2 I2C LCD Display (SDA to A4, SCL to A5)
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h> // You will need to install this library via the Library Manager

// Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows
// Note: If 0x27 shows a blank screen, try address 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int soilSensorPin = A0; 
const int relayPin = 8;       

// Define the dry threshold for the raw analog value
const int dryThreshold = 700; 

void setup() {
  Serial.begin(9600);
  
  // Initialize LCD
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");
  lcd.setCursor(0, 1);
  lcd.print("Starting up...");
  delay(2000);
  lcd.clear();
  
  pinMode(soilSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  // Ensure the pump is off at startup
  digitalWrite(relayPin, LOW); 
}

void loop() {
  // Read raw analog value
  int moistureValue = analogRead(soilSensorPin);
  
  // Convert raw value (approx 1023 dry, 300 wet) to a user-friendly percentage (0-100%)
  int moisturePercent = map(moistureValue, 1023, 300, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100); 
  
  // Display Moisture Percentage on Row 1
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%   "); // Trailing spaces overwrite leftover characters
  
  // Display Pump Status on Row 2
  lcd.setCursor(0, 1);
  if (moistureValue > dryThreshold) {
    lcd.print("Pump: ON        ");
    digitalWrite(relayPin, HIGH); // Turn pump ON
    delay(5000);                  // Keep pump running for 5 seconds
  } else {
    lcd.print("Pump: OFF       ");
    digitalWrite(relayPin, LOW);  // Turn pump OFF
  }
  
  // Wait 2 seconds before next reading
  delay(2000); 
}