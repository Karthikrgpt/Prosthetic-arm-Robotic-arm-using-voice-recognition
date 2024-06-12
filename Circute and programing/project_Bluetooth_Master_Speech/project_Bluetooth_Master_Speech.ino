// Libraries:
#include <SoftwareSerial.h>
/* Built-In Library */

#include "VoiceRecognitionV3.h"
/*Download ZIP: https://github.com/elechouse/VoiceRecognitionV3 */

// Pin Numbers: Bluetooth
#define BT_RxPin 2       //Connect to RX of Bluetooth Module
#define BT_TxPin 3       //Connect to TX of Bluetooth Module

// Pin Numbers: Voice Recognition Module V3
#define VR_TxPin 4  // Connect to Tx Pin of VR_v3 Module
#define VR_RxPin 5  // Connect to Rx Pin of VR_v3 Module


#define Open (1)
#define Close (2)
#define Thumb (3)
#define Index (4)
#define Middle (5)
#define Ring (6)
#define Little (7)

// Software Serial Port:
SoftwareSerial SerialBT(BT_RxPin, BT_TxPin);

// Objects:
VR myVR(VR_TxPin, VR_RxPin);

uint8_t records[7];
uint8_t buf[64];

unsigned long pingTime;

void setup() {
  /* Begin serial communication with Arduino and Arduino IDE (Serial Monitor) */
  Serial.begin(9600);

  /* Begin serial communication with Arduino and SIM Module */
  SerialBT.begin(38400);
  delay(500);

  // Initialise Voice Recognition Module:
  myVR.begin(9600);

  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find Voice Recognition Module.");
    Serial.println("Please check connection and restart Arduino.");
    while (true);
  }


  if (myVR.load((uint8_t)Open) >= 0) {
    Serial.println("Open loaded");
  }

  if (myVR.load((uint8_t)Close) >= 0) {
    Serial.println("Close loaded");
  }

  if (myVR.load((uint8_t)Thumb) >= 0) {
    Serial.println("Thumb loaded");
  }

  if (myVR.load((uint8_t)Index) >= 0) {
    Serial.println("Index loaded");
  }

  if (myVR.load((uint8_t)Middle) >= 0) {
    Serial.println("Middle loaded");
  }

  if (myVR.load((uint8_t)Ring) >= 0) {
    Serial.println("Ring loaded");
  }

  if (myVR.load((uint8_t)Little) >= 0) {
    Serial.println("Little loaded");
  }
}

void loop() {
  while (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }

 // if (millis() - pingTime > 3000) {
   // SerialBT.write("Ping");
//pingTime = millis();
//}

  int ret;
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    SerialBT.listen();
    while (!SerialBT.isListening());
    switch (buf[1]) {
      case Open:
        SerialBT.write("Open");
        break;
      case Close:
        SerialBT.write("Close");
        break;
      case Thumb:
        SerialBT.write("Thumb");
        break;
      case Index:
        SerialBT.write("Index");
        break;
      case Middle:
        SerialBT.write("Middle");
        break;
      case Ring:
        SerialBT.write("Ring");
        break;
      case Little:
        SerialBT.write("Little");
        break;
      default:
        Serial.println("Record function undefined");
        break;
    }
    myVR.listen();
    while (!myVR.isListening());
    /* Voice recognized */
    printVR(buf);
  }
}

void printSignature(uint8_t *buf, int len) {
  int i;
  for (i = 0; i < len; i++) {
    if (buf[i] > 0x19 && buf[i] < 0x7F) {
      Serial.write(buf[i]);
    }
    else {
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf) {
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if (buf[0] == 0xFF) {
    Serial.print("NONE");
  }
  else if (buf[0] & 0x80) {
    Serial.print("UG ");
    Serial.print(buf[0] & (~0x80), DEC);
  }
  else {
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if (buf[3] > 0) {
    printSignature(buf + 4, buf[3]);
  }
  else {
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}
