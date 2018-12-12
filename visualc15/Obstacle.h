#ifndef Obstacle_h
#define Obstacle_h
#include "TexRect.h"
#include "../visualc15/randomGen.h"
#include "../visualc15/objectDimensions.h"
#include "../visualc15/car.h"

class Obstacle : public TexRect{
protected:
	int lane;
	int obstacleType; // 4 different types: 1 regular, 2 desert, 3 jungle, 4 ice

public:
	Obstacle(const char* map_filename, float x = 0, float y = 0, float w = 0.5, float h = 0.5) : TexRect(map_filename, x, y, w, h) {
		changeLane();
		obstacleType = 1;
	};

	void changeLane() {		// decides what lane the obstacle is in
		lane = getRandom();
	}

	/*
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
	*/

	void Spawn(int carLane) {
		if (lane == 1) {
			setX(LeftmostOne);
			setY(1.4);
		};
		if (lane == 2) {
			setX(LeftmostTwo);
			setY(1.4);
		};
		if (lane == 3) {
			setX(LeftmostThree);
			setY(1.4);
		};
		if (lane == 4) {
			setX(LeftmostFour);
			setY(1.4);
		};
		if (lane == 5) {
			setX(LeftmostFour);
			setY(1.4);
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
			setY(1.4);
		};
	}

	void Despawn() {
		changeLane();
	}

	void movement(car& car) {
		
	}

	void getHit(int positionX, int positionY) {
		if (contains(positionX, positionY)) {
			// animate car explostion
			// game over screen
		}
	}

};

#endif