//declare
int led = BUILTIN_LED; //42
//setup
void setup() {
pinMode(led, OUTPUT);
}
//loop
void loop() {
digitalWrite(led, HIGH); 
Serial.println("Led ON");
delay(5000);
digitalWrite(led, LOW);
Serial.println("Led OFF");
delay(5000);
}
 