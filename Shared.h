/** Commands **/
enum Direction      { FORWARD , BACKWARD };
enum TurnDirection  { RIGHT , LEFT };
enum JointCommand   { EXTEND , COLLAPSE };
enum GripperCommand { GRAB , RELEASE };

/** Pins **/

//Motor
const byte P_MOTOR_R_F = 2,      // Right motor forward
           P_MOTOR_R_B = 3,      //             backward
           P_MOTOR_L_F = 4,      // Left motor forward
           P_MOTOR_L_B = 5;      //             backward

//Arm Servos
const byte P_ARM_BASE    = 6,
           P_ARM_JOINT1  = 7,
           P_ARM_JOINT2  = 8,
           P_ARM_GRIPPER = 9;

//Bluetooth Serial
const byte P_BLUETOOTH_RX = 10,
           P_BLUETOOTH_TX = 11;

//Automatic Sitch
const byte P_LF_SWITCH = 5;

//Line Follower
const byte P_LF_L = A0,        //Left sensor
           P_LF_M = A1,        //Middle sensor
           P_LF_R = A2;        //Right sensor


