#ifndef car_h
#define car_h
#include "engine.h"
#include "gearbox.h"
#include "AnimatedRect.h"

class car : public TexRect {
	
	float position, velocity, accel = 0;
	int RPM;
	engine carengine;
	gearbox cargearbox;

public:

	car::car() : TexRect("", 0, 0, 0, 0) {
		position = 0; velocity = 0; accel = 0; RPM = 0;
	}
																	  //filename, rows, columns, rate, x, y, w, h
	car::car(char* fileName, engine &carengine, gearbox &cargearbox) : TexRect(fileName, 0, 0, 0.370, 0.632) {
		this->carengine = carengine;
		this->cargearbox = cargearbox;
	}

	/*---------------------------Setters-------------------------------------*/

	void setEngine(engine newengine) {	//if engine needs to be swapped; shouldn't necessarily be called
		carengine = newengine;
		accel = carengine.getBaseAccel();
		accel += cargearbox.getBonusAccel();
	}

	void setGearbox(gearbox newgearbox) {	//if gearbox needs to be swapped; shouldn't necessarily be called
		accel = carengine.getBaseAccel();
		cargearbox = newgearbox;
		accel += cargearbox.getBonusAccel();
	}

	void setChassis(TexRect chas) {	//if gearbox needs to be swapped; shouldn't necessarily be called
		
	}

	void setPosition(float pos) {
		position = pos;
	}

	void setAccel(float acceleration) {
		accel = acceleration;
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


	~car() {
		
	}

};


#endif
