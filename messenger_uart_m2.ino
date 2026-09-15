#include <SoftwareSerial.h>

SoftwareSerial M1toM2(50, 51); // RX, TX 

void setup() {
  M1toM2.begin(9600); // from M1 
  Serial1.begin(9600); // to M3 (hardware)
  Serial.begin(9600);

}

void loop() {
  //if (M1toM2.available()) {
    String c = M1toM2.readString();
    Serial1.println(c);
    Serial.println(c);
    //Serial1.println("abc");

    //delay(1000);

  //}
}
