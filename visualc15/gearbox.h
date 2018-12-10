#ifndef gearbox_h
#define gearbox_h

class gearbox {
	
	typedef enum { balanced, rally, topspeed } gearing;
	typedef enum { neutral, first, second, third, fourth, fifth, sixth } gears;
	float accelBonus;
	gearing selected_gearing;
	gears current_gear;

public:

	gearbox() : selected_gearing(balanced), current_gear(neutral), accelBonus(0) {}

	gearbox(gearing selected_gearing) {
		this->selected_gearing = selected_gearing;
		setupGearbox(selected_gearing);
	}

	void setupGearbox(gearing selected_gearing) {
		switch (selected_gearing) {
		case (balanced):
			accelBonus = 0;
			break;
		case (rally):
			accelBonus = 10;
			break;
		case (topspeed):
			accelBonus = -10;
			break;
		}
	}

	void shift() {
		switch (current_gear) {
		case sixth:
			break;
		case fifth:
			current_gear = sixth;
			break;
		case fourth:
			current_gear = fifth;
			break;
		case third:
			current_gear = fourth;
			break;
		case second:
			current_gear = third;
			break;
		case first:
			current_gear = second;
			break;
		case neutral:
			current_gear = first;
			break;
		}
	}

	float getBonusAccel() const{
		return accelBonus;
	}


	~gearbox() {

	}

};
#endif