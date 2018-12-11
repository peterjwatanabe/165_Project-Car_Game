#ifndef Obstacle_h
#define Obstacle_h
#include "TexRect.h"
#include "randomGen.h"

class Obstacle : public TexRect{
protected:
	int lane;
	int obstacleType;

public:
	Obstacle(const char* map_filename) : TexRect(map_filename, x, y, w, h) {
		changeLane();
		obstacleType = 1;
	};

	void changeLane() {		// decides what lane the 
		lane = getRandom();
	}

	void changeObstacle() {	// changes the image of the obstacle
		if () {

		}

		else if () {

		}

		else if () {

		}

		else if () {

		}
	}

	void Spawn(int carLane) {
		if (lane == 1) {
			setX();
			setY();
		};
		if (lane == 2) {
			setX();
			setY();
		};
		if (lane == 3) {
			setX();
			setY();
		};
		if (lane == 4) {
			setX();
			setY();
		};
		if (lane == 5) {
			setX();
			setY();
		};
		if (lane == 6) {		// "lane 6" is the car's current lane position
			setX();		// would obtain the fixed lane position that the car is currently in
			setY();
		};
	}

	void Despawn() {
		changeLane();
	}

	void movement() {
		setY();
	}

	void getHit(int positonX, int positonY) {
		if (contains(positionX, positonY)) {
			// animate car explostion
			// game over screen
		}
	}

}


#endif
