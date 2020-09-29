void setup() {
  //BT.begin(9600);
  Serial1.begin(38400);
  Serial.begin(38400);
}

void loop() {
  if(Serial1.available()){
    Serial.write(Serial1.read());
  }

  if(Serial.available()){
    Serial1.write(Serial.read());
  }
  /*if(BT.available()){
    Serial.write(BT.read());
  }*/

  /*if(Serial.available()){
    BT.write(Serial.read());
  } */
}
