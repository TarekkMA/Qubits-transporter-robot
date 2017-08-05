void setupLineFollower(){
  pinMode(P_LF_L,OUTPUT);
  pinMode(P_LF_M,OUTPUT);
  pinMode(P_LF_R,OUTPUT);
}

//vars used in linefollwer
bool left,middle,right;

void autoDrive(){

  left = digitalRead(P_LF_L) == LOW;
  middle = digitalRead(P_LF_M) == LOW;
  right = digitalRead(P_LF_R) == LOW;


  if(left  && !middle && right){
    moveRobot(FORWARD);
  }else if(left && middle && !right){
    turnRobot(RIGHT);
  }else if(!left && middle && right){
    turnRobot(LEFT);
  }
 

}

