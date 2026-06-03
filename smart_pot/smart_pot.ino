#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BUZZER_PIN 12
#define BUTTON_PIN 2
#define SENSOR_PIN A6
#define LCD_ADDRESS 0x27
#define THRESHOLD 650

long timer, sub_timer;
bool alarmReady = false;
int sensor;
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  sensor = analogRead(SENSOR_PIN);

  if (sensor > THRESHOLD && !alarmReady) {
  
    delay(15000);
    alarmReady = true;
  } else if (sensor > THRESHOLD && alarmReady) {
    
    timer = millis();
    while (millis() - timer < 15000 && sensor > THRESHOLD && digitalRead(BUTTON_PIN) == HIGH) {
      sensor = analogRead(SENSOR_PIN);
      digitalWrite(BUZZER_PIN, HIGH);
      sub_timer = millis();
      while (millis() - sub_timer < 1000 && sensor > THRESHOLD && digitalRead(BUTTON_PIN) == HIGH) {
        sensor = analogRead(SENSOR_PIN);
      }
      digitalWrite(BUZZER_PIN, LOW);
      sub_timer = millis();
      while (millis() - sub_timer < 1000 && sensor > THRESHOLD && digitalRead(BUTTON_PIN) == HIGH) {
        sensor = analogRead(SENSOR_PIN);
      }
    }
    alarmReady = false;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture:");
  lcd.setCursor(0, 1);
  lcd.print(sensor);
  delay(500);
}