int led = 7; //DECLARANDO EL LED EN LA SALIDA #7

void setup() {
  pinMode(led,OUTPUT); //EN ESTA LINEA DECLARAMOS EL PIN 7 COMO SALIDA

}

void loop() {
  digitalWrite(led,1);
  delay(2000);
  digitalWrite(led,0);
  delay(1000);  //ESTA FUNCIÓN APAGA EL LED POR UN SEGUNDO Y DESPUES LO ENCIENDE POR OTRO SEGUNDO

}
