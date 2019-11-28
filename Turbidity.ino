#define SENSOR       A0
float voltage,turbidity;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

void setup() 
{
Serial.begin(9600);
pinMode(SENSOR,INPUT);
lcd.begin(16,2);
lcd.backlight();


}

void loop() 
{
voltage=0.004888*analogRead(SENSOR);  //in V
  turbidity=-1120.4*voltage*voltage+5742.3*voltage-4352.9;  //in NTU
  if((voltage>=2.5)&(turbidity>=0))
  {
    Serial.println("Voltage="+String(voltage)+" V Turbidity="+String(turbidity)+" NTU");  
    delay(500);
    lcd.setCursor(0,0); 
    lcd.print(" Voltage :"+String(voltage)); 
    delay(1000);
    lcd.setCursor(0,1);  
    lcd.print("Turbidity="+String(turbidity)+" NTU");
    delay(8000);
    
  }
 

 
}
