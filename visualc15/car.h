#ifndef car_h
#define car_h
#include "engine.h"
#include "gearbox.h"
#include "AnimatedRect.h"

class car : public TexRect, protected Timer {
	
	float velocity, accel = 0;
	int RPM;
	char* filename;
	engine* carengine;
	gearbox* cargearbox;

public:

	car::car() : TexRect("", 0, 0, 0, 0) {
		velocity = 0; accel = 0; RPM = 0;
	}
																	  //filename, rows, columns, rate, x, y, w, h
	car::car(char* fileName, engine &carengine, gearbox &cargearbox) : TexRect(fileName, LeftmostThree, 0, 0.370, 0.632) {
		this->carengine = &carengine;
		this->cargearbox = &cargearbox;
		this->filename = fileName;
		accel = this->carengine->getBaseAccel();
		accel += this->cargearbox->getBonusAccel();
	}

	car::car(const car& someCar): TexRect((&someCar)->filename, 0, 0, 0.370, 0.632) {
		this->carengine = someCar.carengine;
		this->cargearbox = someCar.cargearbox;
		this->filename = someCar.filename;
		accel = this->carengine->getBaseAccel();
		accel += this->cargearbox->getBonusAccel();
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

	void setAccel(float acceleration) {
		accel = carengine->getBaseAccel() + cargearbox->getBonusAccel();
	}

	void shift() {
		RPM = 0;
		accel += -0.02;		//lull in gear shifting affects accel & speed
		cargearbox->shift();
		glutPostRedisplay();
	}

	void turnLeft() {
		if (getX() == LeftmostOne) {
			return;
		}
		else if (getX() == LeftmostTwo) {
			setX(LeftmostOne);
		}
		else if (getX() == LeftmostThree) {
			setX(LeftmostTwo);
		}
		else if (getX() == LeftmostFour) {
			setX(LeftmostThree);
		}
		else if (getX() == LeftmostFive) {
			setX(LeftmostFour);			//can make it explode instead...
		}
	}

	void turnRight() {
		if (getX() == LeftmostOne) {
			setX(LeftmostTwo);
		}
		else if (getX() == LeftmostTwo) {
			setX(LeftmostThree);
		}
		else if (getX() == LeftmostThree) {
			setX(LeftmostFour);
		}
		else if (getX() == LeftmostFour) {
			setX(LeftmostFive);
		}
		else if (getX() == LeftmostFive) {
			return;						//can make it explode instead...
		}
	}

	/*----------------------------Getters-------------------------------------*/

	float getAccel() const{
		return accel;
	}

	float getVelocity() const {
		return velocity;
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
		
		return velocity + accel;

	}

	void Timer::action() {

	}

	~car() {
		
	}

};


#endif
