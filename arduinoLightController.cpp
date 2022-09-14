// Wiring
// Photocell: A0, 5V, GND
// IR Motion Sensor: D4, 5V, GND
// Relay: D5, 5V, GND

int ptc=A0;
int irm=4;
int rel=5;
void setup(){
	pinMode(ptc,INPUT);
	pinMode(rel,OUTPUT);
	Serial.begin(9600);
}
void loop(){
	int a=analogRead(ptc);
	// If Motion detected 
	if (a<25 && digitalRead(irm) == HIGH) {
		digitalWrite(rel, HIGH);
		Serial.println("Relay is ON");
		delay(10000);
	} else {
		digitalWrite(rel, LOW);
		Serial.println("Relay is OFF");
		delay(1000);
	}
}