#include "main.h"

#define MOTOR_PORT 1 
#define DISTANCE_PORT 'A'

// creating objects for readible code
pros::Motor MainDrive(MOTOR_PORT);
pros::ADIButton EndStop(DISTANCE_PORT);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
// setup
MainDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void endStop() {
	(EndStop.get_value() == 1) ? MainDrive.brake() : MainDrive.move_relative(MainDrive.get_position()+0.01 ,1);
	pros::delay(1);
}

void opcontrol() {
	endStop();
	


	// while (true) {
	// 	pros::delay(20);                               // Run for 20 ms then update
	// }
}