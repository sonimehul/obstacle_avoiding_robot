/* Obstacle Avoiding Robot Using Ultrasonic Sensor and Arduino UNO
 *
 */

//Define the variables used in the program
int triggerPin9 = 9;      // trigger pin of Sensor HC-SR04
int echoPin10 = 10;     // Echo pin of Sensor HC-SR04

int revLeft4 = 4;       //REVerse motion of Left motor
int fwdLeft5 = 5;       //ForWarD motion of Left motor
int revRight6 = 6;      //REVerse motion of Right motor
int fwdRight7 = 7;      //ForWarD motion of Right motor

long duration, distance;

//Board Setup, set input and output pins
void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600); //Set the pulse rate for sensor
  pinMode(revLeft4, OUTPUT);      // set Motor pins as output
  pinMode(fwdLeft5, OUTPUT);
  pinMode(revRight6, OUTPUT);
  pinMode(fwdRight7, OUTPUT);
  
  pinMode(triggerPin9, OUTPUT);         // set trig pin as output
  pinMode(echoPin10, INPUT);          //set echo pin as input to capture reflected waves
}


void loop() {

  digitalWrite(triggerPin9, LOW);
  delayMicroseconds(2);   
  digitalWrite(triggerPin9, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin10, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
  
  if (distance > 19)            
  {
    digitalWrite(fwdRight7, HIGH);                    // move forward
    digitalWrite(revRight6, LOW);
    digitalWrite(fwdLeft5, HIGH);                                
    digitalWrite(revLeft4, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(fwdRight7, LOW);  //Stop                
    digitalWrite(revRight6, LOW);
    digitalWrite(fwdLeft5, LOW);                                
    digitalWrite(revLeft4, LOW);
    delay(500);
 }

}
