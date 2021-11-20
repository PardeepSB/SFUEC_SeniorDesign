#define MOTOR_EN_1_2  10
#define MOTOR_IN1     9
#define MOTOR_IN2     8
#define MOTOR_EN_3_4  5
#define MOTOR_IN3     4
#define MOTOR_IN4     3

 
#define slow 64
#define normal 128
#define fast 255
 
int Speed; 
long duration, cm;
const int pingPin = 7;
const int ledPin = 13;


void Forward_Rev_Right(void){
  analogWrite(MOTOR_EN_1_2, Speed);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
}

void Forward_Rev_Left(void){
  analogWrite(MOTOR_EN_3_4, Speed);
  digitalWrite(MOTOR_IN3, HIGH);
  digitalWrite(MOTOR_IN4, LOW);
  }

void Backward_Rev_Left(void){
  analogWrite(MOTOR_EN_3_4, Speed);
  digitalWrite(MOTOR_IN3, LOW);
  digitalWrite(MOTOR_IN4, HIGH);
}
 
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  pinMode(MOTOR_EN_1_2, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  
  pinMode(MOTOR_EN_3_4, OUTPUT);
  pinMode(MOTOR_IN3, OUTPUT);
  pinMode(MOTOR_IN4, OUTPUT);
  
}
 
void loop() {
 
  Speed = normal; // Normal Speed
 

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  // Print the distance
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  // Turn on the LED if the object is too close:
  if(cm < 40) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    Forward_Rev_Right(); 
  	Backward_Rev_Left();
    
  }
  else {
    digitalWrite(ledPin, LOW);
    delay(100);
    Forward_Rev_Right(); 
    Forward_Rev_Left(); 
  }
  
  delay(100);
}




long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;

}
