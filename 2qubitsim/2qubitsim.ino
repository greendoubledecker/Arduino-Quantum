bool q1 = false;
bool q2 = false;

bool sp1 = false;
bool sp2 = false;

bool ent = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter 'HDM' for Hadamard, and then the qubit number(1 or 2). Enter 'ENT' to entangle or disentangle the qubits. Enter 'MSR' to measure, then the qubit number. Enter 'NOT' then the qubit number to flip its state.");
  randomSeed(analogRead(A0));
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  while(!Serial);
}

void loop() {
  if(Serial.available() > 0){
    String cmd = Serial.readStringUntil('\n');
    if(cmd == "HDM1"){
      if(ent){
        ent = false;
      }else{
        sp1 = !sp1;
      }
    }
    if(cmd == "HDM2"){
      if(ent){
        ent = false;
      }else{
        sp2 = !sp2;
      }
    }
    if(cmd == "ENT"){
      ent = !ent;
    }
    if(cmd == "MSR1"){
      if(sp1){
        int collapse = random(2);
        q1 = collapse;
        sp1 = false;
      }
      Serial.println("Q1 is in state");
      Serial.println(q1);
      if(ent){
        q2 = q1;
        sp2 = false;
      }
    }
    if(cmd == "MSR2"){
      if(sp2){
        int collapse = random(2);
        q2 = collapse;
        sp2 = false;
      }
      Serial.println("Q2 is in state");
      Serial.println(q2);
      if(ent){
        q1 = q2;
        sp1 = false;
      }
    }
    if(cmd == "NOT1"){
      q1 = !q1;
    }
    if(cmd == "NOT2"){
      q2 = !q2;
    }
  }
  if(ent){
    int brightness = random(0, 256);
    analogWrite(9, brightness);
    analogWrite(11, brightness);
  }else{
    if(sp1){
      int brightness = random(0, 256);
      analogWrite(9, brightness);
    }else{
      if(q1){
        analogWrite(9, 255);
      }else{
        analogWrite(9, 0);
      }
    }
    if(sp2){
      int brightness = random(0, 256);
      analogWrite(11, brightness);
    }else{
      if(q2){
        analogWrite(11, 255);
      }else{
        analogWrite(11, 0);
      }
    }
  }
  delay(50);
}
