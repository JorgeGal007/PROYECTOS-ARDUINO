#include <Wire.h>
#include <LiquidCrystal_I2C.h> //DESCARGAR LIBRERÍA:https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip

LiquidCrystal_I2C lcd(0x3f,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

byte customChar[] = {
  0x06,
  0x0C,
  0x18,
  0x0C,
  0x06,
  0x0C,
  0x18,
  0x10
};

void setup() {
  /*Serial.begin(9600); //Inicializar la comunicación serial a 9600 bits por segundo
  lcd.init();
  lcd.backlight();
  lcd.clear();*/

  lcd.init();
  

  lcd.backlight();
  lcd.write(5);

}

void loop() {
  int sensorValue = analogRead(A0); //Lee la entrada en el pin analógico 0
  float voltaje = sensorValue * (5.0 / 1023.0);
  //lcd.createChar(5, customChar);

  lcd.setCursor(0,0);
  lcd.print(" => VOLTAJE <="); 
  lcd.setCursor (5,1);
  lcd.write(customChar);
  lcd.print(voltaje);
  lcd.write(customChar);

  Serial.println(voltaje); //Imprime el valor de la lectura
  delay(100);

}
