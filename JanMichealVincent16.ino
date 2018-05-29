
#define trigPin 12 // define the pins of your sensor
#define echoPin 13 

#define IN_1 9
#define IN_2 6
#define IN_3 5
#define IN_4 3

#define ENA_1 11
#define ENB_1 10

int speedCar = 500; 


void setup() {
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  pinMode(IN_1, OUTPUT); 
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(ENA_1, OUTPUT);
  pinMode(ENB_1, OUTPUT);

  Serial.begin(9600); 

  
}
 
void loop() {

   long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  if (distance < 100)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
      analogWrite(ENA_1, speedCar);
 
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
      analogWrite(ENB_1, speedCar);
}
  else {
   delay (15);
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
      analogWrite(ENA_1, speedCar);
 
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW); 
      analogWrite(ENB_1, speedCar);
  }  
  
  
  
 
}
