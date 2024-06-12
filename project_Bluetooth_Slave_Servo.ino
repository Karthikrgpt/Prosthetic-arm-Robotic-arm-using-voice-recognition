// Libraries:
#include <SoftwareSerial.h>
/* Built-In Library */

#include <Servo.h>
/* Built-In Library */

// Pin Numbers: Bluetooth
#define BT_Rx_Pin 2  // Connect to Tx of Bluetooth module
#define BT_Tx_Pin 3  // Connect to Rx of Bluetooth module

//Open Close Thumb Index Middle Ring Little

// Pin Numbers: Servo Motor
#define ServoThumb_Pin 5    // Connect to the Servo Motor
#define ServoIndex_Pin 6    // Connect to the Servo Motor
#define ServoMiddle_Pin 9   // Connect to the Servo Motor
#define ServoRing_Pin 10    // Connect to the Servo Motor
#define ServoLittle_Pin 11  // Connect to the Servo Motor

// Objects:
SoftwareSerial SerialBT(BT_Rx_Pin, BT_Tx_Pin);

// Objects: Servo
Servo objThumb;
Servo objIndex;
Servo objMiddle;
Servo objRing;
Servo objLittle;

// Variables:
String str;

void setup() {
  /* Begin serial communication with Arduino and Arduino IDE (Serial Monitor) */
  Serial.begin(9600);

  /* Begin serial communication with Arduino and Bluetooth Module */
  SerialBT.begin(38400);

  OpenAll();
  delay(2000);
  CloseAll();
  delay(2000);
  OpenAll();
}

void loop() {
  if (SerialBT.available()) {
    delay(100);
    while (SerialBT.available()) {
      str += SerialBT.readString();
    }
    Serial.print("Serial Buffer:");
    Serial.println(str);

    if (str == "Open") {
      OpenAll();
    } else if (str == "Close") {
      CloseAll();
    } else if (str == "Thumb") {
      objThumb.attach(ServoThumb_Pin);
      objThumb.write(90);
      delay(2000);
      objThumb.detach();
    } else if (str == "Index") {
      objIndex.attach(ServoIndex_Pin);
      objIndex.write(90);
      delay(2000);
      objIndex.detach();
    } else if (str == "Middle") {
      objMiddle.attach(ServoMiddle_Pin);
      objMiddle.write(90);
      delay(2000);
      objMiddle.detach();
    } else if (str == "Ring") {
      objRing.attach(ServoRing_Pin);
      objRing.write(90);
      delay(2000);
      objRing.detach();
    } else if (str == "Little") {
      objLittle.attach(ServoLittle_Pin);
      objLittle.write(90);
      delay(2000);
      objLittle.detach();
    }
    str = "";
  }
}

void OpenAll() {
  objThumb.attach(ServoThumb_Pin);
  objThumb.write(180);

  objIndex.attach(ServoIndex_Pin);
  objIndex.write(180);

  objMiddle.attach(ServoMiddle_Pin);
  objMiddle.write(180);

  objRing.attach(ServoRing_Pin);
  objRing.write(180);

  objLittle.attach(ServoLittle_Pin);
  objLittle.write(180);

  delay(2000);

  objThumb.detach();
  objIndex.detach();
  objMiddle.detach();
  objRing.detach();
  objLittle.detach();
}

void CloseAll() {
  objThumb.attach(ServoThumb_Pin);
  objThumb.write(90);

  objIndex.attach(ServoIndex_Pin);
  objIndex.write(90);

  objMiddle.attach(ServoMiddle_Pin);
  objMiddle.write(90);

  objRing.attach(ServoRing_Pin);
  objRing.write(90);

  objLittle.attach(ServoLittle_Pin);
  objLittle.write(90);

  delay(2000);

  objThumb.detach();
  objIndex.detach();
  objMiddle.detach();
  objRing.detach();
  objLittle.detach();
}
