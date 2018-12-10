#ifndef engine_h
#define engine_h

class engine {

	typedef enum { stock, sport, racing } engines;
	engines selected_engine;
	int topSpeed;
	float baseAccel;
	int topRPM;

public:

	engine() : selected_engine(stock){}

	engine(engines selectedEngine) {
		selected_engine = selectedEngine;
		setupEngine(selectedEngine);
	}

	void setupEngine(engines selected_engine) {		//all setters in one because all individual engines will have consistent values; no individual setters.
		switch (selected_engine) {
		case stock:
			topSpeed = 120;
			baseAccel = 10;
			topRPM = 6000;
			break;
		case sport:
			topSpeed = 140;
			baseAccel = 15;
			topRPM = 7000;
			break;
		case racing:
			topSpeed = 180;
			baseAccel = 20;
			topRPM = 7500;
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


	~engine() {

	}

};

#endif