// include the library code:
#include <LiquidCrystal.h> 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int BUTTON_INC  = 1;
const int BUTTON_DEC = 0;

int Counts = 0;

void setup()
{
  pinMode(BUTTON_INC, INPUT_PULLUP); 
  pinMode(BUTTON_DEC, INPUT_PULLUP); 
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print("Counts: ");
  lcd.print(Counts);
}

void loop()
{
  if(digitalRead(BUTTON_INC) == LOW)
  {
    Counts++;
    lcd.setCursor(0, 0);
    lcd.print("Counts: ");
    lcd.print(Counts);
    delay(200);
  }
  if(digitalRead(BUTTON_DEC) == LOW)
  {
    if(Counts > 0){
      Counts--;
      lcd.setCursor(0, 0);
      lcd.print("Counts: ");
      lcd.print(Counts);
      delay(200);
    }
  }
}
