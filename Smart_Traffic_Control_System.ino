#define sensorLaneA 5 //sensor for lane A
#define sensorLaneB 2 //sensor for lane B
#define sensorLaneC 4 //sensor for lane C
#define sensorLaneD 3 //sensor for lane D
#define ledRedLaneA 6 //Traffic red led for lane A
#define ledRedLaneB 7 //Traffic red led for lane B
#define ledRedLaneC 8 //Traffic red led for lane C
#define ledRedLaneD 9 //Traffic red led for lane D
#define ledYellowLaneA 11 //Traffic yellow led for lane A
#define ledYellowLaneB 12 //Traffic yellow led for lane B
#define ledYellowLaneC 13 //Traffic yellow led for lane C
#define ledYellowLaneD 10 //Traffic yellow led for lane D
#define ledGreenLaneA A1 //Traffic Green led for lane A
#define ledGreenLaneB A2 //Traffic Green led for lane B
#define ledGreenLaneC A3 //Traffic Green led for lane C
#define ledGreenLaneD A0 //Traffic Green led for lane D


void setup() {
  //serial baud rate setup
  Serial.begin(9600);
  //pin mode setup declartion of sensors for lane A,B,C and D
  pinMode(sensorLaneA,INPUT);
  pinMode(sensorLaneB,INPUT);
  pinMode(sensorLaneC,INPUT);
  pinMode(sensorLaneD,INPUT);
  //pin mode setup declartion of traffic ligts of lane A
  pinMode(ledRedLaneA,OUTPUT);
  pinMode(ledYellowLaneA,OUTPUT);
  pinMode(ledGreenLaneA,OUTPUT);
  //pin mode setup declaration of traffic ligts of lane B
  pinMode(ledRedLaneB,OUTPUT);
  pinMode(ledYellowLaneB,OUTPUT);
  pinMode(ledGreenLaneB,OUTPUT);
  //pin mode setup declaration of traffic ligt of lane C
  pinMode(ledRedLaneC,OUTPUT);
  pinMode(ledYellowLaneC,OUTPUT);
  pinMode(ledGreenLaneC,OUTPUT);
  //pin mode setup declaration of traffic ligts of lane D
  pinMode(ledRedLaneD,OUTPUT);
  pinMode(ledYellowLaneD,OUTPUT);
  pinMode(ledGreenLaneD,OUTPUT);
  

}

void loop() {
  
  int laneA = digitalRead(sensorLaneA);
  int laneB = digitalRead(sensorLaneB);
  int laneC = digitalRead(sensorLaneC);
  int laneD = digitalRead(sensorLaneD);
  

  if (!Congested(laneA, laneB, laneC, laneD)){
    Serial.println("Default "+(String)laneA+" "+(String)laneB+" "+(String)laneC+" "+(String)laneD);
    congestLaneCheck(laneA, laneB, laneC, laneD);
  }else if(Congested(laneA, laneB, laneC, laneD)) {
    congestLaneCheck(laneA, laneB, laneC, laneD);
  }
}
boolean Congested(int A, int B, int C, int D){
  if (A == 1 && B == 1 && C == 1 && D == 1){
    return false;
  }else{
    return true;
  }
}
void congestLaneCheck(int A, int B, int C, int D){
  char lane = 'A';
  switch (lane){
    case 'A':
      if(A == 0 && B == 1 && C == 1 && D == 1){
        Serial.println("lane A conjested");
        openLaneA();
        break; 
      }
    case 'B':
      if(A == 1 && B == 0 && C == 1 && D == 1){
        Serial.println("lane B conjested");
        openLaneB();
        break; 
      }
    case 'C':
      if(A == 0 && B == 0 && C == 1 && D == 1){
        Serial.println("lane A and B conjested");
        openLaneA();
        closeLaneA();
        openLaneB();
        closeLaneB();
        break; 
      }
    case 'D':
      if(A == 1 && B == 1 && C == 0 && D == 1){
        Serial.println("lane C conjested");
        openLaneC();
        break; 
      }
    case 'E':
      if(A == 0 && B == 1 && C == 0 && D == 1){
        Serial.println("lane A and C conjested");
        openLaneA();
        closeLaneA();
        openLaneC();
        closeLaneC();
        break; 
      }
    case 'F':
      if(A == 1 && B == 0 && C == 0 && D == 1){
        Serial.println("lane B and C conjested");
        openLaneB();
        closeLaneB();
        openLaneC();
        closeLaneC();
        break; 
      }
    case 'G':
    if(A == 0 && B == 0 && C == 0 && D == 1){
        Serial.println("lane A, B and C conjested");
        openLaneA();
        closeLaneA();
        openLaneB();
        closeLaneB();
        openLaneC();
        closeLaneC();
        break; 
      }
    case 'H':
    if(A == 1 && B == 1 && C == 1 && D == 0){
        Serial.println("lane D conjested");
        openLaneD();
        break; 
      }
    case 'I':
    if(A == 0 && B == 1 && C == 1 && D == 0){
        Serial.println("lane A and D conjested");
        openLaneA();
        closeLaneA();
        openLaneD();
        closeLaneD();
        break; 
      }
    case 'J':
    if(A == 1 && B == 0 && C == 1 && D == 0){
        Serial.println("lane B and D conjested");
        openLaneB();
        closeLaneB();
        openLaneD();
        closeLaneD();
        break; 
      }
    case 'K':
    if(A == 0 && B == 0 && C == 1 && D == 0){
        Serial.println("lane A,B and D conjested");
        openLaneA();
        closeLaneA();
        openLaneB();
        closeLaneB();
        openLaneD();
        closeLaneD();
        break; 
      }
    case 'L':
    if(A == 1 && B == 1 && C == 0 && D == 0){
        Serial.println("lane C and D conjested");
        openLaneC();
        closeLaneC();
        openLaneD();
        closeLaneD();
        break; 
      }
    case 'M':
    if(A == 0 && B == 1 && C == 0 && D == 0){
        Serial.println("lane A, C and D conjested");
        openLaneA();
        closeLaneA();
        openLaneC();
        closeLaneC();
        openLaneD();
        closeLaneD();
        break; 
      }
    case 'N':
    if(A == 1 && B == 0 && C == 0 && D == 0){
        Serial.println("lane B, C and D conjested");
        openLaneB();
        closeLaneB();
        openLaneC();
        closeLaneC();
        openLaneD();
        closeLaneD();
        break; 
      }
    default:
        Serial.println("all lane conjested");
        openLaneA();
        closeLaneA();
        openLaneB();
        closeLaneB();
        openLaneC();
        closeLaneC();
        openLaneD();
        closeLaneD();
        break; 
  }
}
void openLaneA(){
  Serial.println("lane A opened");
  digitalWrite(ledRedLaneB,HIGH);
  digitalWrite(ledRedLaneC,HIGH);
  digitalWrite(ledRedLaneD,HIGH);
  digitalWrite(ledGreenLaneA,HIGH);
  digitalWrite(ledGreenLaneB,LOW);
  digitalWrite(ledGreenLaneC,LOW);
  digitalWrite(ledGreenLaneD,LOW);
  digitalWrite(ledYellowLaneA,LOW);
  digitalWrite(ledRedLaneA,LOW);
  delay(5000);
}
void closeLaneA(){
  Serial.println("lane A Closed");
  digitalWrite(ledRedLaneB,HIGH);
  digitalWrite(ledRedLaneC,HIGH);
  digitalWrite(ledRedLaneD,HIGH);
  digitalWrite(ledGreenLaneA,LOW);
  digitalWrite(ledYellowLaneA,HIGH);
  digitalWrite(ledRedLaneA,LOW);
  delay(2000);
  digitalWrite(ledRedLaneD,LOW);
  digitalWrite(ledRedLaneC,LOW);
  digitalWrite(ledRedLaneB,LOW);
  digitalWrite(ledGreenLaneA,LOW);
  digitalWrite(ledYellowLaneA,LOW);
  digitalWrite(ledRedLaneA,HIGH);
  
}
void openLaneB(){
  Serial.println("lane B Opened");
  digitalWrite(ledRedLaneA,HIGH);
  digitalWrite(ledRedLaneC,HIGH);
  digitalWrite(ledRedLaneD,HIGH);
  digitalWrite(ledGreenLaneB,HIGH);
  digitalWrite(ledGreenLaneA,LOW);
  digitalWrite(ledGreenLaneC,LOW);
  digitalWrite(ledGreenLaneD,LOW);
  digitalWrite(ledYellowLaneB,LOW);
  digitalWrite(ledRedLaneB,LOW);
  delay(5000);
}
void closeLaneB(){
  Serial.println("lane B Closed");
  digitalWrite(ledRedLaneD,HIGH);
  digitalWrite(ledRedLaneC,HIGH);
  digitalWrite(ledRedLaneA,HIGH);
  digitalWrite(ledGreenLaneB,LOW);
  digitalWrite(ledYellowLaneB,HIGH);
  digitalWrite(ledRedLaneB,LOW);
  delay(2000);
  digitalWrite(ledRedLaneD,LOW);
  digitalWrite(ledRedLaneC,LOW);
  digitalWrite(ledRedLaneA,LOW);
  digitalWrite(ledGreenLaneB,LOW);
  digitalWrite(ledYellowLaneB,LOW);
  digitalWrite(ledRedLaneB,HIGH);
  
}
void openLaneC(){
  Serial.println("lane C Opened");
  digitalWrite(ledRedLaneD,HIGH);
  digitalWrite(ledRedLaneA,HIGH);
  digitalWrite(ledRedLaneB,HIGH);
  digitalWrite(ledGreenLaneC,HIGH);
  digitalWrite(ledGreenLaneA,LOW);
  digitalWrite(ledGreenLaneB,LOW);
  digitalWrite(ledGreenLaneD,LOW);
  digitalWrite(ledYellowLaneC,LOW);
  digitalWrite(ledRedLaneC,LOW);
  delay(5000);
}
void closeLaneC(){
  Serial.println("lane C Closed");
  digitalWrite(ledRedLaneD,HIGH);
  digitalWrite(ledRedLaneA,HIGH);
  digitalWrite(ledRedLaneB,HIGH);
  digitalWrite(ledGreenLaneC,LOW);
  digitalWrite(ledYellowLaneC,HIGH);
  digitalWrite(ledRedLaneC,LOW);
  delay(2000);
  digitalWrite(ledRedLaneD,LOW);
  digitalWrite(ledRedLaneA,LOW);
  digitalWrite(ledRedLaneB,LOW);
  digitalWrite(ledGreenLaneC,LOW);
  digitalWrite(ledYellowLaneC,LOW);
  digitalWrite(ledRedLaneC,HIGH);
  
}
void openLaneD(){
  Serial.println("lane D Opened");
  digitalWrite(ledRedLaneA,HIGH);
  digitalWrite(ledRedLaneC,HIGH);
  digitalWrite(ledRedLaneB,HIGH);
  digitalWrite(ledGreenLaneD,HIGH);
  digitalWrite(ledGreenLaneA,LOW);
  digitalWrite(ledGreenLaneB,LOW);
  digitalWrite(ledGreenLaneC,LOW);
  digitalWrite(ledYellowLaneD,LOW);
  digitalWrite(ledRedLaneD,LOW);
  delay(5000);
}
void closeLaneD(){
  Serial.println("lane D Closed");
  digitalWrite(ledRedLaneA,HIGH);
  digitalWrite(ledRedLaneC,HIGH);
  digitalWrite(ledRedLaneB,HIGH);
  digitalWrite(ledGreenLaneD,LOW);
  digitalWrite(ledYellowLaneD,HIGH);
  digitalWrite(ledRedLaneD,LOW);
  delay(2000);
  digitalWrite(ledRedLaneD,LOW);
  digitalWrite(ledRedLaneA,LOW);
  digitalWrite(ledRedLaneB,LOW);
  digitalWrite(ledGreenLaneD,LOW);
  digitalWrite(ledYellowLaneD,LOW);
  digitalWrite(ledRedLaneD,HIGH);
  
}
