const int EchoPin = 2;
const int TriggerPin = 5;

double distancia;
double tiempo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TriggerPin,OUTPUT);
  pinMode(EchoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(TriggerPin,LOW);
  delayMicroseconds(5);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin,LOW);

  /* Medición de la longitud del pulso entrante. Mide el tiempo
   * que ha transcurrido entre el envío del pulso ultrasónico y 
   * cuando el sensor recibe el rebote, es decir, desde que el 
   * pin 12 empieza a recibir el rebote, HIGH, hasta que deja de
   * hacerlo, LOW, la logitud del pulso entrante.
   */
  tiempo = pulseIn(EchoPin,HIGH);

  /* Fórmula para calcular la distancia obteniendo un valor entero.*/
  distancia = (0.017*tiempo);

  /*Monitorización en centímetros or el monitor serial.*/
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(100);
}
