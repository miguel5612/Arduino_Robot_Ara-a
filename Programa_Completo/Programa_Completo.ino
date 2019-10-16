#include <Servo.h>

Servo rodilla1;
Servo rodilla2;
Servo rodilla3;
Servo rodilla4;

Servo cadera1;
Servo cadera2;
Servo cadera3;
Servo cadera4;

Servo eje1;
Servo eje2;
Servo eje3;
Servo eje4;

const int pinecho = A1;
const int pintrigger = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Eje
  eje1.attach(4);
  eje2.attach(10);
  eje3.attach(7); //40 es la posicion inicial de este eje
  eje4.attach(13);

  cadera1.attach(3);
  cadera2.attach(9);
  cadera3.attach(6);
  cadera4.attach(12);

  rodilla1.attach(2); //5
  rodilla2.attach(8);
  rodilla3.attach(5);
  rodilla4.attach(11); //160

  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  
  posicionInicial();
  delay(500);
  /*
   * salto();
  delay(2000);
  PasitoHaciaAdelante(500);
  PasitoHaciaAdelante(500);
  PasitoHaciaAdelante(500);
  PasitoHaciaAdelante(500);
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  if(medirDistancia() < 20)
  {
    PasitoHaciaDerecha(500);
  }
  else
  {
    PasitoHaciaAdelante(500);  
  }
}
void salto()
{
  for(int i=20; i<=90; i++)
  {//Bajando
    cadera1.write(90-i);
    cadera2.write(70-i);
    cadera3.write(90+i);
    cadera4.write(90+i);
    delay(20);
  }
  for(int i=0; i<=90; i++)
  {//Subiendo
    cadera1.write(i);
    cadera2.write(i);
    cadera3.write(180-i);
    cadera4.write(180-i);
    delay(20);
  }

}
double medirDistancia()
{
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  double tiempo = pulseIn(pinecho, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  double distancia = tiempo / 58;
  return distancia;
}
void PasitoHaciaAdelante(int tiempo)
{
  movimiento1(tiempo);
  movimiento2(tiempo);
  movimiento3(tiempo);
  movimiento4(tiempo);
  posicionInicial();
}


void PasitoHaciaDerecha(int tiempo)
{
  //movimiento1(tiempo);
  movimiento2(tiempo);
  //movimiento3(tiempo);
  movimiento4(tiempo);
  posicionInicial();
}

void posicionInicial()
{
  //Esta es la posicion parada de la araña
  //Escribir posiciones iniciales
  eje1.write(70);
  eje2.write(120);
  eje3.write(40);
  eje4.write(110);

  cadera1.write(90);
  cadera2.write(90);
  cadera3.write(90);
  cadera4.write(70);

  rodilla1.write(0);
  rodilla2.write(5);
  rodilla3.write(0);
  rodilla4.write(180);

  Serial.println("En posicion para caminar :)");
}


void movimiento1(int tiempoMovmiento)
{
  //Primer movimiento
  // La araña estira la pata 1, la corre hacia adelante y luego la baja
  rodilla1.write(90);
  delay(tiempoMovmiento);
  cadera1.write(40);
  delay(tiempoMovmiento);
  eje1.write(40);
  delay(tiempoMovmiento);
  cadera1.write(90);
  delay(tiempoMovmiento);
  rodilla1.write(0);
  delay(tiempoMovmiento);
}
void movimiento2(int tiempoMovmiento)
{
  //Segundo movimiento
  //Para estabilizar hago lo mismo con la pata opuesta
  rodilla4.write(90);
  delay(tiempoMovmiento);
  cadera4.write(150);
  delay(tiempoMovmiento);
  eje4.write(150);
  delay(tiempoMovmiento);
  cadera4.write(90);
  delay(tiempoMovmiento);
  rodilla4.write(180);
  delay(tiempoMovmiento);
}
void movimiento3(int tiempoMovmiento)
{  
  //Tercer movimiento
  rodilla3.write(90);
  delay(tiempoMovmiento);
  cadera3.write(140);
  delay(tiempoMovmiento);
  eje3.write(10);
  delay(tiempoMovmiento);
  cadera3.write(90);
  delay(tiempoMovmiento);
  rodilla3.write(0);
  delay(tiempoMovmiento);
}
void movimiento4(int tiempoMovmiento)
{
  //Cuarto movimiento
  rodilla2.write(90);
  delay(tiempoMovmiento);
  cadera2.write(40);
  delay(tiempoMovmiento);
  eje2.write(150);
  delay(tiempoMovmiento);
  cadera2.write(90);
  delay(tiempoMovmiento);
  rodilla2.write(5);
  delay(tiempoMovmiento);
}
