#ifndef engine_h
#define engine_h

class engine {

	typedef enum { stock, sport, racing } engines;
	engines selected_engine;
	int topSpeed;
	float baseAccel;
	int topRPM;
	int engineBonus;

public:

	engine() : topSpeed(0), baseAccel(0), topRPM(0){}

	engine(engines selectedEngine) {
		selected_engine = selectedEngine;
		setupEngine(selectedEngine);
	}

	void setupEngine(int num) {		//all setters in one because all individual engines will have consistent values; no individual setters.
		switch (selected_engine) {
		case 1:
			selected_engine = stock;
			topSpeed = 3.0;
			baseAccel = 0.1;
			topRPM = 6000;
			engineBonus = 0;
			break;
		case 2:
			selected_engine = sport;
			topSpeed = 3.5;
			baseAccel = 0.15;
			topRPM = 7000;
			engineBonus = 250;
			break;
		case 3:
			selected_engine = racing;
			topSpeed = 4.0;
			baseAccel = 0.20;
			topRPM = 7500;
			engineBonus = 500;
			break;
		}
	}

	float getBaseAccel() const{
		return baseAccel;
	}

	int getTopSpeed() const{
		return topSpeed;
	}

	int getTopRPM() const {
		return topRPM;
	}

	int getEngineBonus() const {
		return engineBonus;
	}


	~engine() {

	}

};

#endif