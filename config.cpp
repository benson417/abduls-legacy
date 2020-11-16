#include "api.h"
pros::Motor left1(1, pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left2(2, pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right1(3, pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right2(4, pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor arm (5, pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake2(10, pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake1(9, pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor tilter(6, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::ADIGyro gyro(1);
pros::Controller master (pros::E_CONTROLLER_MASTER);
