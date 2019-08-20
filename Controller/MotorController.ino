#include <LiquidCrystal_I2C.h>
#include <Encoder.h>

int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
Encoder motorEnc(D5, D6); // D5=14, D6=12

unsigned long starttime = millis();

long encPos;
float depth;
char dtext [8];

void setup(){
  Serial.begin(74880);
  lcd.init();
  lcd.backlight();

  boot_message();
  pinMode(D4,INPUT_PULLUP);  // Set zeroing pin.  Will zero when set low.
  analogWrite(D0,32);  // Set the speed of the motor
  
}

void boot_message(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water Tank");
  lcd.setCursor(0,1);
  lcd.print("Version 0.1a");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Depth: ");  
}

void show_heartbeat(){

  if ((millis()-starttime)/500 % 2 == 0){
    lcd.setCursor(15, 1);
    lcd.print(".");
    }
  else{
    lcd.setCursor(15, 1);
    lcd.print(" ");
  }
}

void loop(){
  
  show_heartbeat();
  encPos = motorEnc.read();
  //depth = encPos/2000.0;
  depth = -1*encPos/60000.0;  // Should be calibrated to cm now
  sprintf(dtext,"%7.2f cm",depth);
  lcd.setCursor(6, 0);
  lcd.print(dtext);

  if (digitalRead(D4) == LOW){
    motorEnc.write(0);
  }
  
  delay(50);

}
