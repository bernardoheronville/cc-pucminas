#include <TimerOne.h>
#include <MultiFuncShield.h>
#include <Wire.h>

#define ULTRASONIC_TRIGGER_PIN 5
#define ULTRASONIC_ECHO_PIN 6
#define BUZZER_PIN 9

const int DISTANCE_1 = 50;
const int DISTANCE_2 = 30;
const int DISTANCE_3 = 15;

int distance = 0;
bool sensingEnabled = false;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  Timer1.initialize();
  MFS.initialize(&Timer1);
  MFS.write("");
}

void loop() {
  byte btn = MFS.getButton();
  if (btn) {
    byte buttonNumber = btn & B00111111;
    byte buttonAction = btn & B11000000;
    if (buttonAction == BUTTON_SHORT_RELEASE_IND) {
      sensingEnabled = !sensingEnabled;  
      if (!sensingEnabled) {
        MFS.writeLeds(LED_ALL, OFF);
        MFS.write("");
      }
    }
  }

  if (sensingEnabled) {
    distance = 0.01723 * readUltrasonicDistance(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > DISTANCE_1) {
      MFS.writeLeds(LED_ALL, OFF);
    } else if (distance <= DISTANCE_1 && distance > DISTANCE_2) {
      MFS.writeLeds(LED_ALL, OFF);
      MFS.writeLeds(0b0001, ON);
    } else if (distance <= DISTANCE_2 && distance > DISTANCE_3) {
      MFS.writeLeds(LED_ALL, OFF);
      MFS.writeLeds(0b0011, ON);
    } else if (distance <= DISTANCE_3) {
      MFS.writeLeds(LED_ALL, OFF);
      MFS.writeLeds(0b0111, ON);
      Buzzer();
    }

    MFS.write(distance);
    delay(100);
  }
}

void Buzzer() {
  MFS.beep();  
  delay(1000);
}