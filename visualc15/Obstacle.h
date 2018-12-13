#ifndef Obstacle_h
#define Obstacle_h
#include "TexRect.h"
#include "../visualc15/randomGen.h"
#include "../visualc15/objectDimensions.h"
#include "../visualc15/car.h"

class Obstacle : public TexRect{
protected:
	int lane;
	char* imageFile;
	int obstacleType; // 4 different types: 1 regular, 2 desert, 3 jungle, 4 ice

public:

	Obstacle() : TexRect("", 0, 0, 0, 0) {
		changeLane();
		imageFile = "";
		obstacleType = 0;
	}

	Obstacle(const char* map_filename, float x = LeftmostThree, float y = 1.10, float w = objWidth, float h = 0.35) : TexRect(map_filename, x, y, w, h) {
		changeLane();
		imageFile = (char*) map_filename;
		obstacleType = 1;
	};

	void changeLane() {		// decides what lane the obstacle is in
		lane = getRandom();
	}

	void changeObstacle(char* imageFile) {	// changes the image of the obstacle		!!!
		Obstacle* temp = new Obstacle(imageFile);
		//this = temp;
	}


	void Spawn(int carLane) {
		if (lane == 1) {
			setX(LeftmostOne);
			setY(1.0);
			std::cout << "This is 1" << std::endl;
		};
		if (lane == 2) {
			setX(LeftmostTwo);
			setY(1.0);
		};
		if (lane == 3) {
			setX(LeftmostThree);
			setY(1.0);
		};
		if (lane == 4) {
			setX(LeftmostFour);
			setY(1.0);
		};
		if (lane == 5) {
			setX(LeftmostFour);
			setY(1.0);
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
			setY(1.0);
		};
		this->draw(-0.10);
	}

	void Despawn() {
		changeLane();
	}

	void movement(car& car) {
		setY(y - 0.01);
	}

	void getHit(int positionX, int positionY) {
		if (contains(positionX, positionY)) {
			// animate car explostion
			// game over screen
		}
	}

};

#endif