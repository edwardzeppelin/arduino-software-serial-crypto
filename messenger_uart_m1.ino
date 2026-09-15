#include <SoftwareSerial.h>

//Serial RX=0 TX=1
//Serial1 RX=19 TX=18
//Serial2 RX=16 TX=17
//Serial3 RX=15 TX=14

SoftwareSerial M1toM2(50, 51);

const int shift = 3; // Сдвиг Цезаря

void setup() {
  Serial.begin(9600);
  M1toM2.begin(9600);
}

void loop() {
  //if (Serial.available() > 0) {

    String c = Serial.readString();

    String encryptmsg = encryptCaesar(c, shift);

    //char enc = caesarEncrypt(c);
    M1toM2.println(encryptmsg);
    //Serial.println("a");

    //M1toM2.println("m1tom2 output");

    //Serial.println("Serial output");

  //}

  

  //delay(1000);

}

String encryptCaesar(String text, int shift) {
  String result = "";
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    if (isAlpha(c)) {
      char base = isUpperCase(c) ? 'A' : 'a';
      c = (c - base + shift) % 26 + base;
    }
    result += c;
  }
  return result;
}

bool isAlpha(char c) { 
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isUpperCase(char c) {
  return (c >= 'A' && c <= 'Z');
}
