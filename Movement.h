void setupMotor(){
  pinMode(P_MOTOR_R_F,OUTPUT);
  pinMode(P_MOTOR_R_B,OUTPUT);
  pinMode(P_MOTOR_L_F,OUTPUT);
  pinMode(P_MOTOR_L_B  ,OUTPUT);
}

//set all pins to zero to erase state from previous command
//or simply stop the robot :)
void stopAll(){
  digitalWrite(P_MOTOR_R_F,LOW);
  digitalWrite(P_MOTOR_L_F,LOW);
  digitalWrite(P_MOTOR_R_B,LOW);
  digitalWrite(P_MOTOR_L_B,LOW);
}

void turnRobot(TurnDirection dir){
  stopAll();
  if(dir == LEFT){

    // turn to the left by sending opposite signals to each motor
    digitalWrite(P_MOTOR_R_F,LOW);
    digitalWrite(P_MOTOR_L_F,HIGH);
     
  }else if(dir == RIGHT){

    // turn to the right by sending opposite signals to each motor
    digitalWrite(P_MOTOR_R_F,HIGH);
    digitalWrite(P_MOTOR_L_F,LOW);
    
  }
}

void moveRobot(Direction dir){
  stopAll();
  if(dir == FORWARD){

    //send signal to both motors to move forward
    digitalWrite(P_MOTOR_R_F,HIGH);
    digitalWrite(P_MOTOR_L_F,HIGH);
       
  }else if(dir == BACKWARD){

    //send signal to both motors to move backward
    digitalWrite(P_MOTOR_R_B,HIGH);
    digitalWrite(P_MOTOR_L_B,HIGH);
    
  }
}





