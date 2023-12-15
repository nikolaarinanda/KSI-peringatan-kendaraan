#include "DFRobotDFPlayerMini.h"
#define pinPIR 5

HardwareSerial mySoftwareSerial(1);
DFRobotDFPlayerMini myDFPlayer;

void setup() {

  mySoftwareSerial.begin(9600, SERIAL_8N1, 16, 17);  // speed, type, RX, TX
  // mySoftwareSerial.begin(16, 17)
  Serial.begin(115200);
  pinMode(pinPIR, INPUT);
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //If use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin: 1.Please recheck the connection! 2.Please insert the SD card!"));
    while(true);
  }

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  myDFPlayer.volume(30);  //Set volume value (0~30).
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);


  Serial.println(F("Memulai alat!"));
  myDFPlayer.play(1);  //Play the first mp3

  delay (5000);
}

void loop() {
  int motionSensorValue = digitalRead(pinPIR);

  if (motionSensorValue == HIGH) {
    Serial.println("Gerakan terdeteksi!");
    myDFPlayer.play(1);  //Play the first mp3

    // Tunggu sampai sensor kembali ke kondisi LOW sebelum melanjutkan
    while (digitalRead(pinPIR) == HIGH) {
      delay(100);
    }
  } else {
    Serial.println(".....");
    delay(200);
  }
}