#include <SoftwareSerial.h>

const int shift = 3;


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600); 
}

void loop() {
  //if (Serial1.available()) {
    String c = Serial1.readString();
    String decMsg = decryptCaesar(c, shift);
    Serial.println(decMsg);
    //delay(1000);
  //}
}

String decryptCaesar(String text, int shift) {
  String result = "";
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
  if (isAlpha(c)) {
    char base = isUpperCase(c) ? 'A' : 'a';
    c = (c - base - shift + 26) % 26 + base; 
  }
    result += c;
  }
    return result;
  }
  bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
  }
  // Проверка на верхний регистр
  bool isUpperCase(char c) {
     (c >= 'A' && c <= 'Z');
}
