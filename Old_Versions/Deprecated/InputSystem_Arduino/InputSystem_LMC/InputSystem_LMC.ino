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
}

void loop() {
  if (!digitalRead(tlc_0) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(0);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_1) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(1);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_2) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(2);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_3) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(3);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_4) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(4);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_5) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(5);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_6) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(6);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_7) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(7);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_8) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(8);
      delay(500);
    }
  }
  else if (!digitalRead(tlc_9) == HIGH) {
    for (int i = 0; i < 1; i++){
      Serial.println(9);
      delay(500);
    }
  }
  
}
