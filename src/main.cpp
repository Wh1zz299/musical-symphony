#include "main.h"

#define MOTOR_PORT 21 
#define BUMPER_PORT 'A'

#define BPM 80

#define C 1
#define D 100
#define E 1
#define F
#define G
#define A
#define B




// creating objects for readible code
pros::Motor MainDrive(MOTOR_PORT);
pros::ADIButton EndStop(BUMPER_PORT);

//ms to bpm formula
double noteLength = 60000/BPM ;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {}

void endStop() {
	while (EndStop.get_value() == 0) {
		MainDrive.move_relative(10 ,200);
		pros::delay(0.01);
	}
	MainDrive.brake();
	MainDrive.set_zero_position_all(1000);

	MainDrive.move_absolute(0,200);
}

/*use the defined notes A-G   
*note length is one for quarter 1/2 for eighth 2 for half etc...
*/
void playNote(double note,double time){
	MainDrive.move_absolute(note,99999999);
	pros::delay(time*noteLength); 
}

/* 
*note length is one for quarter 1/2 for eighth 2 for half etc...
*/
void rest(double time){
	MainDrive.move_absolute(-10,200);
	pros::delay(time*noteLength); 
}


void opcontrol() {
	MainDrive.set_encoder_units_all(pros::E_MOTOR_ENCODER_DEGREES);
	MainDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	endStop();
	pros::delay(500);

	playNote(C,1);
	rest(1);
	playNote(D,1);
	rest(1);
	playNote(C,1);
	rest(1);
	playNote(D,1);
	
	


	// while (true) {
	// 	pros::delay(20);                               // Run for 20 ms then update
	// }
}