#ifndef car_h
#define car_h
#include "engine.h"
#include "gearbox.h"
#include "AnimatedRect.h"

class car : public TexRect, protected Timer {
	
	float position, velocity, accel = 0;
	int RPM;
	engine* carengine;
	gearbox* cargearbox;

public:

	car::car() : TexRect("", 0, 0, 0, 0) {
		position = 0; velocity = 0; accel = 0; RPM = 0;
	}
																	  //filename, rows, columns, rate, x, y, w, h
	car::car(char* fileName, engine &carengine, gearbox &cargearbox) : TexRect(fileName, 0, 0, 0.370, 0.632) {
		this->carengine = &carengine;
		this->cargearbox = &cargearbox;
	}

	/*---------------------------Setters-------------------------------------*/

	

	void setEngine(engine newengine) {	//if engine needs to be swapped; shouldn't necessarily be called
		carengine = &newengine;
		accel = carengine->getBaseAccel();
		accel += cargearbox->getBonusAccel();
	}

	void setGearbox(gearbox newgearbox) {	//if gearbox needs to be swapped; shouldn't necessarily be called
		accel = carengine->getBaseAccel();
		cargearbox = &newgearbox;
		accel += cargearbox->getBonusAccel();
	}

	void setPosition(float pos) {
		position = pos;
	}

	void setAccel(float acceleration) {
		accel = carengine->getBaseAccel() + cargearbox->getBonusAccel();
	}

	void shift() {
		RPM = 0;
		accel += -0.02;		//lull in gear shifting affects accel & speed
		cargearbox->shift();
		glutPostRedisplay();
	}

	/*----------------------------Getters-------------------------------------*/

	float getAccel() const{
		return accel;
	}

	float getVelocity() const {
		return velocity;
	}

	float getPosition() const {
		return position;
	}

	int getRPM() const {
		return RPM;
	}

	/*--------------------------------Special----------------------------------*/

	float accelerate() {
		if (RPM >= carengine->getTopRPM()) {
			return velocity;					//Don't accelerate if at max RPM
		}
		switch (cargearbox->getCurrentGear()) {	//increasing RPM
		case gearbox::gears::first:
			RPM += 1500;
			break;
		case gearbox::gears::second:
			RPM += 1100;
			break;
		case gearbox::gears::third:
			RPM += 800;
			break;
		case gearbox::gears::fourth:
			RPM += 400;
			break;
		case gearbox::gears::fifth:
			RPM += 200;
			break;
		case gearbox::gears::sixth:
			RPM += 100;
			break;
		}
		
		return (position += velocity += accel);

	}

	void Timer::action() {

	}

	~car() {
		
	}

};


#endif
