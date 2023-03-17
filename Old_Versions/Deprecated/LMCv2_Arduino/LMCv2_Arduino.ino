#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  startup();
}

void startup () {
  // Clear the current output on display
  lcd.clear();
  // Configuração da primeira linha (setting the cursor on the correct row on display)
  lcd.setCursor(0, 0);
  lcd.print("|---- LMC -----|");
  // Configuração da segunda linha (setting the cursor on the correct row on display)
  lcd.setCursor(0, 1);
  lcd.print("|Arduino v1.0.0|");
  // Delay for something else (maybe...?)
  delay(5000);
}
 
void loop() {
  menu();
  char option = Serial.read();
  delay(5000);
  controller(option);
}

void menu() {
  short int option;
  lcd.setCursor(0, 0);
  // --------1234567890123456
  lcd.print("|1| Binary Rules");
  lcd.setCursor(0,1);
  lcd.print("|2| Binary Adder");
  delay(2000);

  lcd.setCursor(0, 0);
  // --------1234567890123456
  lcd.print("|3| Validate sum");
  lcd.setCursor(0,1);
  lcd.print("|4|  Bin to Dec ");
  delay(2000);

  lcd.setCursor(0, 0);
  // --------1234567890123456
  lcd.print("|5|  Dec to Bin ");
  lcd.setCursor(0,1);
  lcd.print("|6| Complement 2");
  delay(2000);

  lcd.setCursor(0,0);
  lcd.print("Enter the option");
  lcd.setCursor(1,1);
  lcd.print("Serial Monitor");
  Serial.println("Digite a opção desejada e envie pelo Monitor Serial!");
}

// Interface: exibição das regras de soma binária
void binaryRules () {
  short int i;
  for (i = 0; i < 2; i++) {
    lcd.clear();
    lcd.setCursor(3,0);
    //---------01234567890123456
    lcd.print("First Rule");
    lcd.setCursor(4,1);
    //---------01234567890123456
    lcd.print("0 + 0 = 0");
    delay(3500);

    lcd.clear();
    lcd.setCursor(2,0);
    //---------01234567890123456
    lcd.print("Second Rule");
    lcd.setCursor(4,1);
    //---------01234567890123456
    lcd.print("0 + 1 = 0");
    delay(3500);

    lcd.clear();
    lcd.setCursor(3,0);
    //---------01234567890123456
    lcd.print("Third Rule");
    lcd.setCursor(4,1);
    //---------01234567890123456
    lcd.print("1 + 0 = 0");
    delay(3500);

    lcd.clear();
    lcd.setCursor(2,0);
    //---------01234567890123456
    lcd.print("Fourth Rule");
    lcd.setCursor(0,1);
    //---------01234567890123456
    lcd.print("1+1 = 0 (up one)");
    delay(3500);
  }
}

void controller (char option) {
  short int firstBool[8], secondBool[8], resultado[8];
  switch (option) {
    case '1':
      binaryRules();
      break;
    /*case '2':
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input in 8-bit");
      lcd.setCursor(1,1);
      lcd.print("Serial Monitor");

      delay(3000);
      Serial.println(" 1) Digite o primeiro valor (8 Bits ~ Bit a Bit): ");
      for (int i = 0; i < 8; i++) {
        if (inputLow.read() == HIGH) {
          firstBool[i] = 0;
        } else if (inputHigh.read() == HIGH) {
          firstBool[i] = 1;
        }
      }
      Serial.println(" 2) Digite o segundo valor (8 Bits ~ Bit a Bit).: ");
      scanf("%hd%hd%hd%hd%hd%hd%hd%hd", &secondBool[0], &secondBool[1], &secondBool[2], &secondBool[3], &secondBool[4], &secondBool[5], &secondBool[6], &secondBool[7]);
      break;*/
  }
}
