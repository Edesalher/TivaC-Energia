#include <Servo.h>

const int TRIGGER = 3;  //Pin digital 3 para el Trigger del sensor.
const int ECHO = 4;     //Pin digital 4 para el Echo del sensor.
Servo myservo;

void setup() {
  Serial.begin(115200);       //iniciailzamos la comunicación.
  pinMode(TRIGGER, OUTPUT);   //pin TRIGGER como salida.
  pinMode(ECHO, INPUT);       //pin ECHO como entrada.
  digitalWrite(TRIGGER, LOW); //Inicializamos el pin TRIGGER con 0.
  myservo.attach(23);
}

double GetPosition(){
  double tiempo;    //tiempo que demora en llegar el echo.
  double distancia; //distancia en centimetros.

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(TRIGGER, LOW);
  
  tiempo = pulseIn(ECHO, HIGH); //obtenemos el ancho del pulso
  distancia = tiempo/59;             //escalamos el tiempo a una distancia en cm
  //distancia = (0.017*tiempo);
  return distancia;
}

void WriteAngleServo(double control){
  double angulo;
  angulo = ((180/29)*control) - (540/29);
  myservo.write(angulo);
}

void loop(){
  double posicion;
   
  posicion = GetPosition();
  WriteAngleServo(posicion);  
  Serial.print("Distancia: ");
  Serial.print(posicion);      //Enviamos serialmente el valor de la distancia
  Serial.print(" cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
}
