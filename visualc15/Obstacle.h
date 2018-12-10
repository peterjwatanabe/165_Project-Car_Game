#ifndef Obstacle_h
#define Obstacle_h
#include "TexRect.h"
#include "randomGen.h"

class Obstacle : public TexRect{
protected:
	int lane;
public:
	Obstacle(const char* map_filename) : TexRect(map_filename, x, y, w, h) {
		lane = getRandom();
	};

	void newLane() {
		lane = getRandom();
	}

	void Spawn() {
		if (lane == 1) {

		};
		if (lane == 2) {};
		if (lane == 3) {};
		if (lane == 4) {};
		if (lane == 5) {};
	}

	void Despawn() {
		newLane();
	}

	void movement() {

	}

	void getHit(int positonX, int positonY) {
		if (contains(positionX, positonY)) {
			// animate car explostion
			// game over screen
		}
	}

}


#endif
