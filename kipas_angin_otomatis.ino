float temp;
float isMotorOn;

void setup()
{
  DDRB|=(1<<PD3); // PD3 is an output pin
  Serial.begin(9600);
  pinMode(A0, INPUT);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  
  digitalWrite(2, HIGH);
}

void loop()
{
  PORTD|=(1<<PD3); // HIGH to PD3
  temp = analogRead(A0);
  float tempc = (((temp * 5.0)/1024.0)-0.5)*100;
  float tempf = (9/5) * tempc + 32;
  
  // Print 
  Serial.print("C: ");
  Serial.print(tempc);
  Serial.print(" F: ");
  Serial.print(tempf);
  Serial.print(" Fan Status: ");
  if (isMotorOn) {
    Serial.print("On");
  } else {
    Serial.print("Off");
  }
  Serial.println("");
  // Print
  
  if (tempc >= 25) {
    // LED
    digitalWrite(8, HIGH);
    
   	digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    
    isMotorOn = true;
  } else {
    // LED
    digitalWrite(8, LOW);
    
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    isMotorOn = false;
  }
  
}


