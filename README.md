# Prosthetic-arm-Robotic-arm-using-voice-recognition

**Objective :** 
To Develop a 3D printed prototype prosthetic arm / Robotic arm which uses voice command to control the moment of fingers and to create prosthetic arm / Robotic arm which weighs less then 1Kg.

**Working principle :**

The working principle for Objective two is the controlling of prosthetic arm is based on Voice recognition module, the steps of controlling is explained below;
**Step1:** The Voice recognition module will sense the voice command which is less than 1.5 seconds and it converts the voice signal to an electronic signal which stores in the decimal format from 0 to 255.
**Step2:** This converted signal will feed to the Arduino Nano which convert received electronic signal in the form of decimal value to string value like open, close, thumb, etc. these values will feed to the transmitter like Bluetooth Hc-05 module.
**Step3:** The received signal from the transmitter will sends the string value to the receiver Bluetooth module. Then received signal will send to the Arduino Nano which converts the string value to servo rotations.
**Step4:** Develop the 3D Prosthetic arm using .stl file from the Inmoov open-source file who develops the robot using 3D printing materials.
**Step5:** The servo motor will rotate at angle of 0-90º and these servo motors are connected to the fingers of prosthetic arm using the fishing wires.
