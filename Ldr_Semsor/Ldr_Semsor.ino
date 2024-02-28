int ldr = 7;
int buzzle = 6;


void setup() {
  // put your setup code here, to run once:
pinMode(ldr, INPUT);
pinMode(buzzle, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int data = digitalRead(ldr);
Serial.println(data);
if (data == 0)
{
  digitalWrite(buzzle,HIGH);
  delay(1000);
}
else{
   digitalWrite(buzzle,LOW);
  delay(1000);

}
}