#include <Wire.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <MPU6050.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
SoftwareSerial bluetooth(2, 3); // RX, TX

MPU6050 mpu;

const int flexPins[5] = {A0, A1, A2, A3, A4};
int flexValues[5];

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Initializing...");

  Wire.begin();
  mpu.initialize();
  if (mpu.testConnection()) {
    lcd.setCursor(0, 1);
    lcd.print("MPU6050 OK");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("MPU FAIL");
  }

  delay(2000);
  lcd.clear();
}

void loop() {
  // Read flex sensor values
  for (int i = 0; i < 5; i++) {
    flexValues[i] = analogRead(flexPins[i]);
  }

  // Detect gesture
  String gesture = detectGesture(flexValues);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Gesture:       ");
  lcd.setCursor(0, 1);
  lcd.print(gesture + "       ");

  // Send via Bluetooth
  bluetooth.println(gesture);

  delay(1000);
}

String detectGesture(int flex[]) {
  if (flex[0] > 400) return "HELLO";
  if (flex[1] > 400) return "THANK YOU";
  if (flex[2] > 400) return "HELP";
  if (flex[3] > 400) return "YES";
  if (flex[4] > 400) return "NO";
  return "UNKNOWN";
}
