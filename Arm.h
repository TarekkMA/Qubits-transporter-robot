#include <Servo.h>

struct ArmMotor{
  Servo motor;
  int val = 0;
  void writeVal(){
    motor.write(val);                                                      
  }
};


ArmMotor base;
ArmMotor joints[2];
ArmMotor gripper;

setupArm(){
  //attach arm motors
  base.motor.attach(P_ARM_BASE);
  joints[0].motor.attach(P_ARM_JOINT1);
  joints[1].motor.attach(P_ARM_JOINT2);
  gripper.motor.attach(P_ARM_GRIPPER);

  // reset to inital val
  base.writeVal();
  joints[0].writeVal();
  joints[1].writeVal();
  gripper.writeVal();
}

void moveArmBase(TurnDirection dir){
  if(dir == LEFT){
    base.val--;
  }else if(dir == RIGHT){
    base.val++;
  }
  base.writeVal(); 
}

void moveArmJoint(byte jointNum,JointCommand cmd){
  if(cmd == EXTEND){
    joints[jointNum].val--;
  }else if(cmd == COLLAPSE){
    joints[jointNum].val++;
  }
  joints[jointNum].writeVal();
}

void moveArmGripper(GripperCommand cmd){
  if(cmd == GRAB){
    gripper.val--;
  }else if(cmd == RELEASE){
    gripper.val--;
  }
  gripper.writeVal();
}

