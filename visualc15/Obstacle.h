#ifndef Obstacle_h
#define Obstacle_h
#include "TexRect.h"
#include "randomGen.h"
#include "objectDimesions.h"

class Obstacle : public TexRect{
protected:
	int lane;
	int obstacleType; // 4 different types: 1 regular, 2 desert, 3 jungle, 4 ice

public:
	Obstacle(const char* map_filename) : TexRect(map_filename, x, y, w, h) {
		changeLane();
		obstacleType = 1;
	};

	void changeLane() {		// decides what lane the obstacle is in
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
			setX(LeftmostOne);
			setY();
		};
		if (lane == 2) {
			setX(LeftmostTwo);
			setY();
		};
		if (lane == 3) {
			setX(LeftmostThree);
			setY();
		};
		if (lane == 4) {
			setX(LeftmostFour);
			setY();
		};
		if (lane == 5) {
			setX(LeftmostFour);
			setY();
		};

		if (lane == 6) {		// "lane 6" is the car's current lane position
			if (carLane == 1) {
				setX(LeftmostOne);
			}
			if (carLane == 2) {
				setX(LeftmostTwo);
			}
			if (carLane == 3) {
				setX(LeftmostThree);
			}
			if (carLane == 4) {
				setX(LeftmostFour);
			}
			if (carLane == 5) {
				setX(LeftmostFive);
			}
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

};

#endif