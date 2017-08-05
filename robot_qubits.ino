#include "Shared.h"
#include "Movement.h"
#include "Arm.h"
#include "LineFollower.h"

String cmd;
int cmdNum;



void readBluethooth();

void setup() {
  
  //Setup pins
  setupMotor();
  setupArm();
  setupLineFollower();
  Serial.begin(9600); 
  
}

void loop() {
  if(digitalRead(P_LF_SWITCH) == HIGH){
    autoDrive();
  }else{
    readBluethooth();
  }
}


void readBluethooth(){
  if (Serial.available() > 0) {
    cmd = Serial.readString();
    Serial.println(cmd);
    switch(cmd[0]){

      case 'M': //Movement
        readMovement();
        break;
      case 'A': //Arm
        readArm();
        break;

        
    }
  }
}

void readMovement(){
  switch(cmd[1]){
    case 'F':
      moveRobot(FORWARD);
      Serial.println("Robot Forward");
      break;
    case 'B':
      moveRobot(BACKWARD); 
      Serial.println("Robot Back");
      break;
    case 'L':
      turnRobot(LEFT);
      Serial.println("Robot Left");
      break;
    case 'R':
      turnRobot(RIGHT);
      Serial.println("Robot Back");
      break;
  }
}

void readArm(){
  switch(cmd[1]){
    
    case 'R': 
      moveArmBase(RIGHT);
      Serial.println("Arm Right");
      break;
      
    case 'L':
      moveArmBase(LEFT);
      Serial.println("Arm Left");
      break;


    case 'G':
      moveArmGripper(GRAB);
      Serial.println("Arm Grab");
      break;
      
    case 'S':
      moveArmGripper(RELEASE);
      Serial.println("Arm Relese");
      break;

    
    case 'E':
      cmdNum = charToInt(cmd[2]);
      moveArmJoint(cmdNum,EXTEND);
      Serial.print("Arm Extend");
      Serial.println(cmdNum);
      break;
    case 'C':
      cmdNum = charToInt(cmd[2]);
      moveArmJoint(cmdNum,COLLAPSE);
      Serial.print("Arm Collapse");
      Serial.println(cmdNum);
      break;
  }
}

int charToInt(char c){
  if(c=='1')return 1;
  else if(c=='2')return 2;
  else return -1;
}

