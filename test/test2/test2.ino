/*




void setup() {
  // put your setup code here, to run once:
 i = 0
 green = true
 red = false
 distance = 
}

void loop() {
  // put your main code here, to run repeatedly:

  // Dependings on the color of the light, one of them will be turned on
  // using if-else statement
  if (green == true){
    changeGreen();
  } else if (red == true) {
    changeRed();
  } else {
    Serial.print("Sorry I cannot detect")
  }
}

//A function for the green light to be turned on
void changeGreen(GreenLight, RedLight) {
  digitalWrite(GreenLight, HIGH);
  digitalWrite(RedLight, LOW);
}

//A function for the red light to be turned on
void changeRed(Greenlight, RedLight) {
  digitalWrite(GreenLight, LOW);
  digitalWrite(RedLight, HIGH);
}

void Score(i, points) {
  if (green == true) {
    seconds = delayMicroseconds(10)
    points = i + 1 
  }
}

boolean carDetection {
  if (distance >= 20){
    
  } else if(distance {
    
  }
}
*/

void setup() {
  check_road_1;
  readDistance();
  int score = 50
  
}

//Score changes based on how many seconds it the distance stays the same
void loop(){
  if (carDetection == true) {
    if (traffic == changeGreen){
      Score -= 1
      
    } else if (traffic == changeRed) {
      Score += 1
    }

   else {
    break;
   }
    
  }
}

//Read it 
int readDistance() {
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
  distance= (duration / 29) / 2;
// Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

//detects if distance change
boolean carDetection {
  if (distance <= 20){
    return true;
  } else if(distance >= 20) {
    return false;
  }
}

//change light depending of score
def fun(){
  if (Score >= 61) {
    changeGreen = true;
  } else if (Score <= 49){
    changeRed = true;
  }
}
