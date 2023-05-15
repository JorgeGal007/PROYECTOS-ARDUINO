int ledRojo = 6;
int ledAmarillo = 7;
int ledVerde = 8;
int buffer = 2;
//DECLARAMOS LOS PINES


void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buffer, OUTPUT);
  //DECLARAMOS LOS PINES DE CADA COMPONENTE COMO SALIDA DIGITAL
}

void loop() {
  digitalWrite(ledVerde, 1);
  delay(10000);
  digitalWrite(ledVerde, 0);

  for(int x = 0; x < 5; x++){
    delay(400);
    digitalWrite(ledVerde, 1);
    delay(400);
    digitalWrite(ledVerde, 0);
  } //ESTA FUNCIÓN SE ENCARGA DE PARPADEO DE LED VERDE AL CASI FINALIZAR EL TIEMPO


  digitalWrite(ledAmarillo, 1);
  delay(5000);
  digitalWrite(ledAmarillo, 0);

  digitalWrite(ledRojo, 1);
  for(int y = 0; y <= 10; y++){
    digitalWrite(buffer, 1);
    delay(500);
    digitalWrite(buffer,0);
    delay(500);
    Serial.println(10 - y); 
  }//ESTA FUNCIÓN SE ENCARGA DE ENCENDER EL BUFFER DURANTE LA LUZ ROJA SIMULANDO ASÍ UN PASE PEATONAL, A SU VEZ CONTROLA LA DURACIÓN DE LA LUZ ROJA

  digitalWrite(ledRojo, 0); // CON ESTAS FUNCIONES EMULAMOS UN SEMÁFORO EN EL CUAL LA LUZ VERDE DURA 15s, LUZ AMARILLA DURA 5s, LUZ ROJA 10s


}
