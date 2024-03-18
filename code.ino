const int ldrPin = A0;  // Pin connected to the LDR sensor
const int buzzerPin = 2; // Pin connected to the buzzer
const int threshold = 500; // Adjust this value according to ambient light conditions

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  digitalWrite(buzzerPin, LOW); // Turn off buzzer initially
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Read LDR sensor value
  
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  
  // Check if LDR value is below threshold (i.e., laser light detected)
  if (ldrValue < threshold) {
    Serial.println("Object detected!");
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    delay(1000); // Wait for 1 second
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
  }
  
  delay(100); // Delay for stability
}
