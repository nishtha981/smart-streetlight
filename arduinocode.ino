
int irSensorPin = 2; // IR Sensor is connected to pin 2
int acousticSensorPin = A0; // Acoustic Sensor is connected to pin A0
int ldrPin = A4; // LDR is connected to pin A4
int xpin = A1; // X-Axis connected to pin A1 
int ypin = A2; // Y-Axis connected to pin A2
int zpin = A3; // Z-Axis connected to pin A3
int ledPin = 13; // LED is connected to pin 13
unsigned long previousTime = 0; 

void setup() {
    //setting all sensor pins as input
  pinMode(irSensorPin, INPUT); 
  pinMode(acousticSensorPin, INPUT); 
  pinMode(ldrPin, INPUT); 
  pinMode(xpin, INPUT); 
  pinMode(ypin, INPUT); 
  pinMode(zpin, INPUT);
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  int irValue = digitalRead(irSensorPin); 
  int acousticValue = analogRead(acousticSensorPin); 
  int ldrValue = analogRead(ldrPin); 
  float xAccelValue = analogRead(xpin) * (5.0 / 1023.0) - 2.5; 
  float yAccelValue = analogRead(ypin) * (5.0 / 1023.0) - 2.5; 
  float zAccelValue = analogRead(zpin) * (5.0 / 1023.0) - 2.5; 

  if (irValue == HIGH || acousticValue > 1000 || abs(xAccelValue) > 1.0 || abs(yAccelValue) > 1.0 || abs(zAccelValue) > 1.0 || ldrValue > 1500) { // If IR Sensor detects something or Acoustic Sensor detects sound or Accelerometer detects movement or LDR detects light
    digitalWrite(ledPin, HIGH); 
    previousTime = millis();
  }  

  if (digitalRead(ledPin) == HIGH && millis() - previousTime >= 2000) { 
    digitalWrite(ledPin, LOW);
}
