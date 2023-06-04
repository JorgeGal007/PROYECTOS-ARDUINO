#include <LiquidCrystal_I2C.h>  //Cargamos la librería para el módulo LCD

/*
SDA = PIN A4
SCL = PIN A5
*/

#include <wire.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2);

int ledRojo = 6;
int rojo;
int ledAmarillo = 7;
int ledVerde = 8;
int buffer = 2;
//DECLARAMOS LOS PINES

void Luces(int pin, unsigned long tiempo) {  //La función va fuera del setup y se define el tipo de dato de los parametros
  digitalWrite(pin, 1);
  delay(tiempo);
  digitalWrite(pin, 0);
}

void parpadeoVerde() {

  for (int x = 0; x < 5; x++) {
    delay(400);
    digitalWrite(ledVerde, 1);
    delay(400);
    digitalWrite(ledVerde, 0);
  }  //ESTA FUNCIÓN SE ENCARGA DE PARPADEO DE LED VERDE AL CASI FINALIZAR EL TIEMPO
}

void luzRoja() {

  int rojo = 1;

  digitalWrite(ledRojo, 1);

  for (int y = 0; y <= 10; y++) {
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PASE: ");
    lcd.print(10 - y);
    digitalWrite(buffer, 1);
    delay(500);
    digitalWrite(buffer, 0);
    delay(500);
    //lcd.setCursor(11,0);
    //lcd.print(10 - y);
    //lcd.setCursor(10,0);
    lcd.clear();  //ESTA LINEA ES VITAL PARA EL FUNCIONAMIENTO DE LA PANTALLA LCD

  }  //ESTA FUNCIÓN SE ENCARGA DE ENCENDER EL BUFFER DURANTE LA LUZ ROJA SIMULANDO ASÍ UN PASE PEATONAL, A SU VEZ CONTROLA LA DURACIÓN DE LA LUZ ROJA

  digitalWrite(ledRojo, 0);  // CON ESTAS FUNCIONES EMULAMOS UN SEMÁFORO EN EL CUAL LA LUZ VERDE DURA 15s, LUZ AMARILLA DURA 5s, LUZ ROJA 10s
}

//--------------------------------------------------------------------------------------------CODIGO FUNCIONAL

void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buffer, OUTPUT);
  //DECLARAMOS LOS PINES DE CADA COMPONENTE COMO SALIDA DIGITAL

  //INICIALIZACIÓN DE LA PANTALLA LCD
  lcd.init();
  lcd.backlight();
  lcd.write(0);
}

void loop() {
  lcd.clear();
  lcd.print(" NO PASE ");
  Luces(ledVerde, 10000);
  parpadeoVerde();
  Luces(ledAmarillo, 5000);
  luzRoja();
}
