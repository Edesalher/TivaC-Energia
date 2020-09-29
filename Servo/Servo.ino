#include <Servo.h>

Servo motor1; // DECLARAR SERVO 1
int grados1 = 0; // GRADOS DEL SERVO 1

void setup() { 
motor1.attach (6); // PIN DIGITAL PWM 6 DONDE ESTÁ CONECTADO EL SERVO 1
}

void loop() {

grados1 = 0;
motor1.write (grados1); // ENVIAR LOS GRADOS AL SERVO 1
delay(1000);  // ESPERA 1 SEGUNDO EN LA POSICIÓN FIJADA

grados1 = 60;
motor1.write (grados1); 
delay(1000);

grados1 = 120;
motor1.write (grados1);
delay(1000);

grados1 = 180;
motor1.write (grados1); 
delay(1000);

grados1 = 120;
motor1.write (grados1); 
delay(1000);

grados1 = 60;
motor1.write (grados1); 
delay(1000);
}
