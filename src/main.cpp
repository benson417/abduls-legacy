#include "main.h"
#include "math.h"
#include "api.h"
#include "config.cpp"
#include "variables.cpp"

void resetP(){
	left1.tare_position();
	left2.tare_position();
	right1.tare_position();
	right2.tare_position();
	gyro.reset();
	pros::Task::delay(5);
}
void pidCD(double tPosInches){
	resetP();
	double lAPos = (left1.get_position() + left2.get_position())/2;
	double rAPos = (right1.get_position() + right2.get_position())/2;
	double aPos = (lAPos + rAPos)/2;
	double aPosInches = aPos * ItoE;
	double tPos = tPosInches/ItoE;

	while(aPosInches < tPosInches){
		error = aPos - tPos;
		de = error - pError;
		tE = tE + error;
		double motorP = (error * kP + de * kD + tE * kI);
		left1 = motorP;
		left2 = motorP;
		right1 = motorP;
		right2 = motorP;
		pError = error;
		pros::Task::delay(5);
	}
}
void pidCT(double deg, bool LorR){
	resetP();
	double gyroUnits = deg * 10;
		while (abs(gyro.get_value()) < gyroUnits){
			error = gyro.get_value() - gyroUnits;
			de = error - pError;
			double motorP = (error * kP + de * kD);

			if(LorR == true){
				left1 = -motorP;
				left2 = -motorP;
				right1 = motorP;
				right2 = motorP;
				pError = error;
				//left
			}
			if(LorR == false){
				left1 = motorP;
				left2 = motorP;
				right1 = -motorP;
				right2 = -motorP;
				pError = error;
			//right
			}
	}
}

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}
void disabled() {}
void competition_initialize() {}
void autonomous() {}
void opcontrol() {
	while (true) {
		left1 = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		right1 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
		right2 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
		left2 = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

		pros::delay(2);
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		 intake1 = -127;
		 intake2 = -127;
		 master.set_text(0, 0, "LiFTiNg nOw ");
	 }
	 else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		 intake1 = 127;
		 intake2 = 127;
		 master.set_text(0, 0, "LoWeRiNg nOw");
	 }
	 else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
		 arm = 127;
		 master.set_text(0, 0, "i gRaB      ");
	 }
	 else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
		 arm = -127;
		 master.set_text(0, 0, "i ReLeAsE   ");
	 }
	 else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
		 tilter = -127;
		 master.set_text(0, 0, "I'm gay");
	 }
	 else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
		 tilter = 127;
		 master.set_text(0,0, "I'm gayer");
	 }
	 else{
		 left1 = 0;
		 left2 = 0;
		 right1 = 0;
		 right2 = 0;
		 intake1 = 0;
		 intake2 = 0;
		 arm = 0;
		 tilter = 0;
	 }
 }
}
