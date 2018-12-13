#ifndef gearbox_h
#define gearbox_h

class gearbox {
	
	typedef enum { balanced, rally, topspeed } gearing;
	
	float accelBonus;
	gearing selected_gearing;
	

public:
	
	typedef enum { neutral, first, second, third, fourth, fifth, sixth } gears;
	gears current_gear;
	
	gearbox() : selected_gearing(balanced), current_gear(neutral), accelBonus(0) {}

	gearbox(gearing selected_gearing) {
		this->selected_gearing = selected_gearing;
		setupGearbox(selected_gearing);
	}

	void setupGearbox(int num) {
		switch (num) {
		case (1):
			accelBonus = 0;
			selected_gearing = balanced;
			break;
		case (2):
			accelBonus = .10;
			selected_gearing = rally;
			break;
		case (3):
			accelBonus = -.07;
			selected_gearing = topspeed;
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

	gears getCurrentGear() const{
		return current_gear;
	}

	~gearbox() {

	}

};
#endif