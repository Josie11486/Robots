int switchState = 0;

void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop(){
  switchState = digitalRead(2);
  if (switchState == LOW) {
    //button not pressed
    digitalWrite(3, HIGH); //green
    digitalWrite(4, LOW); //red
    digitalWrite(5, LOW); //red
  }

  else {
    //button is pressed
    digitalWrite(3, LOW); //green
    digitalWrite(4, LOW); //red
    digitalWrite(5, HIGH); //red

    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250); 
  }

}
