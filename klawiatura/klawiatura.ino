#include <Keypad.h>
#include <LiquidCrystal_I2C.h>



const byte row = 4;
const byte col = 4;

byte colPins[col] = {5,4,3,2};
byte rowPins[row] = {9,8,7,6};
String a ="kupa";
char keys[row][col] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'*','0','#','/'}
  };

Keypad klawiatura = Keypad(makeKeymap(keys),rowPins, colPins, row, col);

LiquidCrystal_I2C lcd(0x27,20,4);
int c = 0;
int k = 0;
  
void setup() {
  Serial.begin(9600);
  lcd.init();                       
  lcd.backlight();
}

void loop() {
  char klawisz = klawiatura.getKey();
  if(klawisz){
  if (c<16)
  {
  lcd.setCursor(c,k);
  lcd.print(klawisz);
  c++;
  Serial.print(c);
  }
  else
  {
  /*
  c = 0;
  k++;
  if (k>1){k=0}
  lcd.setCursor(c,k);
  lcd.print(klawisz);
  Serial.print("jest prawie ok");
  */
  lcd.clear();
  c=0;
  k=0;
  }
  };
}
