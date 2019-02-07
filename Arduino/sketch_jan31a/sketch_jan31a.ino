int button1 = 2;
int button2 = ;



void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(11,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int button = digitalRead(button1);
  Serial.print("button1: ");
  Serial.print("button1: ");
  Serial.print("button1: ");

  
  digitalWrite(11,button);
} 
