#ifndef car_h
#define car_h
#include "AnimatedRect.h"
#include "engine.h"
#include "gearbox.h"

class car: public AnimatedRect {
	
	float position, velocity, accel = 0;
	int RPM;
	engine carengine;
	gearbox cargearbox;
	int currentLane;

public:

	car() : position(0), velocity(0), accel(0), RPM(0), AnimatedRect(const char*, int, int, int, float, float, float, float) {}

	car(float pos, engine carengine, gearbox cargearbox) {
		position = pos;
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

	void setPosition(float pos) {
		position = pos;
	}

	void setAccel(float acceleration) {
		accel = acceleration;
	}

	void setLane(int lane) {
		currentLane = lane;
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

	int getLane() const {
		return currentLane;
	}


	~car() {
		
	}

};


#endif
