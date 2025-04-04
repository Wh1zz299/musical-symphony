#include "main.h"
#include <list>

#define MOTOR_PORT -21 
#define LIMIT_SWITCH 'A'
#define WARNINGLED 'H'
#define READYLED 'F'

#define BPM 80

#define C1 -403
#define D1 
#define E1 -303
#define F1
#define G1 -200
#define A1
#define B1
#define C2 -100
#define E2 3
#define G2 100
#define C3 200

// SONG ARRAYS use 999 for rest
int Song[] = {C1,C2};
int Time[] = {1,2};


// creating objects for readible code
pros::Motor MainDrive(MOTOR_PORT);
pros::ADIButton EndStop(LIMIT_SWITCH);
pros::ADIDigitalOut Ready(READYLED, 1);
pros::ADIDigitalOut Warn(WARNINGLED, 1);

//ms to bpm formula
double noteLength = 60000/BPM ;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

}

void endStop() {
	while (EndStop.get_value() == 0) {
		MainDrive.move_relative(-100 ,200);
		Warn.set_value(0);

	}
	MainDrive.brake();
	MainDrive.set_zero_position_all(1000);
	Warn.set_value(1);
	MainDrive.move_absolute(0,200);
}

/*use the defined notes A-G   
*note length is one for quarter 1/2 for eighth 2 for half etc...
*/
void playNote(double note,double time){
	Ready.set_value(0);
	MainDrive.move_absolute(note,200);
	pros::delay(time*noteLength); 
}

/* 
*note length is one for quarter 1/2 for eighth 2 for half etc...
*/
void rest(double time){
	Ready.set_value(1);
	//MainDrive.move_absolute(500,200);
	pros::delay(time*noteLength); 
}




void play(){
	int i;
	for (i = 0; i == sizeof(Song); i++){

		playNote(Time[i],Song[i]);

	}
        // if type(note) == str:     playNote(*note) 
        // elif type(note) == str:     hold(note)
}
void opcontrol() {
	
	MainDrive.set_encoder_units_all(pros::E_MOTOR_ENCODER_DEGREES);
	MainDrive.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	endStop();
	pros::delay(5000);

	play();
	
	// playNote(C2,1);
	// rest(1);
	// playNote(G2,1);
	// rest(1);
	// playNote(C2,1);
	// rest(1);
	// playNote(E2,1);
	// rest(1);
	// playNote(C2,1);
	// rest(1);
	// playNote(E2,1);
	// rest(1);
	// playNote(G2,1);	
	// rest(1);
	// playNote(C3,1);


	Ready.set_value(1);
	Warn.set_value(0);


	// while (true) {
	// 	pros::delay(20);                               // Run for 20 ms then update
	// }
}