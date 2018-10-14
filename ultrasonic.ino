int trigPin=11;
int echoPin=12;
long duration,cm,inches;
int motor=8;
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
cm = (duration/2) / 29.1; 
inches = (duration/2) / 74;


  if(90>=cm) 
   analogWrite(motor,100); 
   else
   analogWrite(motor,0); 
 
  analogWrite(motor,200);
Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);

}
