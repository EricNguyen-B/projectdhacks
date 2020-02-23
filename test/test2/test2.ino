const int trigPin = 5;
const int echoPin = 6;
const int RED1 = 13;
const int GREEN1 = 11;
const int RED2 = 2;
const int GREEN2 = 3;

int score1;
int score2;
boolean isGreen_tg1;
boolean isGreen_tg2;
boolean carDetected;
int distance;
long duration;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(RED1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  distance = 0;
  score1 = 50;
  score2 = 20;
  isGreen_tg1 = true;
  isGreen_tg2 = false;
}

//Score changes based on how many seconds it the distance stays the same
void loop(){
  readDistance();
  carDetection();
  check_road1();
}

//A function for the green light to be turned on
void changeGreen(int GreenLight, int RedLight) {
  digitalWrite(GreenLight, HIGH);
  digitalWrite(RedLight, LOW);
}

//A function for the red light to be turned on
void changeRed(int GreenLight, int RedLight) {
  digitalWrite(GreenLight, LOW);
  digitalWrite(RedLight, HIGH);
}

boolean carDetection(){
  if (distance <= 20){
    carDetected = true;
  } 
  else {
    carDetected = false;
  }
}

//Read it 
void readDistance() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
// Calculating the distance
  distance = (duration / 29) / 2;
// Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}


//checks traffic on road 1
void check_road1() {
  if (isGreen_tg1){
    score1 --;
    check_road2();
  }
  else {
      if (carDetected){
        score1 += 3;
      }
      else {
        score1 += 1;
      }
      checker();
  }
}

//checks traffic on road 2
void check_road2() {
  if (isGreen_tg2){
    score2 --;
    check_road1();  
  }
  else{
    if (carDetected) {
      score2 += 3;  
    }  
    else {
      score2 += 1;  
    }
    checker2();
  }
}

//checker
void checker() {
    if (score1 - 10 < score2) {
        check_road2();
    }
    else{
      light_changes();  
    }
}

//checker2
void checker2() {
    if (score2 - 10 < score1) {
      check_road1();  
    }
    else {
      light_changes();
    }
}

//changes the lights
void light_changes() {
  if (isGreen_tg1){
    delay(1000);
    changeRed(GREEN1, RED1);
    changeGreen(GREEN2, RED2);
    isGreen_tg1 = false;
    isGreen_tg2 = true;
    check_road2();
  }
  else{
    delay(1000);
    changeGreen(GREEN1, RED1);
    changeRed(GREEN2, RED2);
    isGreen_tg1 = true;
    isGreen_tg2 = false;
    check_road1();
  }
}
