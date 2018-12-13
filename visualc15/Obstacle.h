#ifndef Obstacle_h
#define Obstacle_h
#include "TexRect.h"
#include "../visualc15/randomGen.h"
#include "../visualc15/objectDimensions.h"
#include "../visualc15/car.h"

using namespace std;

class Obstacle : public TexRect, protected Timer {
protected:
	int lane;
	//char* imageFile;
	//int obstacleType; // 4 different types: 1 regular, 2 desert, 3 jungle, 4 ice
	bool spawning;

	int cycle;

	bool animating;

public:

	Obstacle() : TexRect("", 0, 0, 0, 0) {
		changeLane();
		cycle = 1;
		//imageFile = "";
		//obstacleType = 0;
	}

	Obstacle(const char* map_filename, float x = LeftmostThree, float y = 1.35, float w = objWidth, float h = 0.35) : TexRect(map_filename, x, y, w, h) {
		changeLane();
		//imageFile = (char*) map_filename;
		//obstacleType = 1;
		cycle = 1;

		animating = false;
		setRate(1);
		start();
	};

	void changeLane() {		// decides what lane the obstacle is in
		lane = getRandom();
		spawning = true;
	}

	void startMovement() {
		if (spawning == true) {
			animating = true;
			Spawn();
		}
	}

	void Spawn() {
		if (lane == 1) {
			cout << "wow 1" << endl;
			setX(LeftmostOne);
			setY(1.35);
		}
		else if (lane == 2) {
			cout << "wow 2" << endl;
			setX(LeftmostTwo);
			setY(1.35);
		}
		else if (lane == 3) {
			cout << "wow 3" << endl;
			setX(LeftmostThree);
			setY(1.35);
		}
		else if (lane == 4) {
			cout << "wow 4" << endl;
			setX(LeftmostFour);
			setY(1.35);
		}
		else if (lane == 5) {
			cout << "wow 5" << endl;
			setX(LeftmostFive);
			setY(1.35);
		}

		spawning = false;
	}

	void Despawn() {
		changeLane();
	}


	void action() {
		if (animating) {
			y -= 0.01;
			redrawScene();
			if (y <= -1.0) {
				Despawn();
			}
		}
	}

	void getHit(int positionX, int positionY) {
		if (contains(positionX, positionY)) {
			// animate car explostion
			// game over screen
		}
	}

};

#endif