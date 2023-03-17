#include <Keyboard.h>

const int tlc_0 = 0;
const int tlc_1 = 9;
const int tlc_2 = 10;
const int tlc_3 = 11;
const int tlc_4 = 6;
const int tlc_5 = 5;
const int tlc_6 = 4;
const int tlc_7 = 3;
const int tlc_8 = 2;
const int tlc_9 = 12;
int digitCounter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(tlc_0, INPUT_PULLUP);
  pinMode(tlc_1, INPUT_PULLUP);
  pinMode(tlc_2, INPUT_PULLUP);
  pinMode(tlc_3, INPUT_PULLUP);
  pinMode(tlc_4, INPUT_PULLUP);
  pinMode(tlc_5, INPUT_PULLUP);
  pinMode(tlc_6, INPUT_PULLUP);
  pinMode(tlc_7, INPUT_PULLUP);
  pinMode(tlc_8, INPUT_PULLUP);
  pinMode(tlc_9, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
    if (!digitalRead(tlc_0) == HIGH) {
    Serial.println("Tecla: 0");
    Keyboard.write(48);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_1) == HIGH) {
    Serial.println("Tecla: 1");
    Keyboard.write(49);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_2) == HIGH) {
    Serial.println("Tecla: 2");
    Keyboard.write(50);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_3) == HIGH) {
    Serial.println("Tecla: 3");
    Keyboard.write(51);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_4) == HIGH) {
    Serial.println("Tecla: 4");
    Keyboard.write(52);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_5) == HIGH) {
    Serial.println("Tecla: 5");
    Keyboard.write(53);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_6) == HIGH) {
    Serial.println("Tecla: 6");
    Keyboard.write(54);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_7) == HIGH) {
    Serial.println("Tecla: 7");
    Keyboard.write(55);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_8) == HIGH) {
    Serial.println("Tecla: 8");
    Keyboard.write(56);
    Keyboard.write(32);
  }
  else if (!digitalRead(tlc_9) == HIGH) {
    Serial.println("Tecla: 9");
    Keyboard.write(57);
    Keyboard.write(32);
  }
}
