#ifndef car_h
#define car_h
#include "engine.h"
#include "gearbox.h"
#include "AnimatedRect.h"
#include "objectDimensions.h"

using namespace std;

class car : public TexRect, protected Timer {
	
	float velocity, accel = 0;
	int RPM;
	char* filename;
	engine* carengine;
	gearbox* cargearbox;
	bool animating;

	bool left_right;		 // false = left, true = right

public:

	car::car() : TexRect("", 0, 0, 0, 0) {
		velocity = 0; accel = 0; RPM = 0;
	}
																			 //filename, rows, columns, rate, x, y, w, h
	car::car(char* fileName, engine &carengine, gearbox &cargearbox) : TexRect(fileName, LeftmostThree, 0, 0.370, 0.632) {
		this->carengine = &carengine;
		this->cargearbox = &cargearbox;
		this->filename = fileName;
		accel = this->carengine->getBaseAccel();
		accel += this->cargearbox->getBonusAccel();
		animating = false;

		left_right = true;

		setRate(16);
		start();
	}

	car::car(const car& someCar): TexRect((&someCar)->filename, 0, 0, 0.370, 0.632) {
		this->carengine = someCar.carengine;
		this->cargearbox = someCar.cargearbox;
		this->filename = someCar.filename;
		accel = this->carengine->getBaseAccel();
		accel += this->cargearbox->getBonusAccel();
		this->RPM = someCar.RPM;
		animating = false;

		left_right = true;

		setRate(16);
		start();
	}

	/*---------------------------Setters-------------------------------------*/
	
	void setEngine(engine newengine) {	//if engine needs to be swapped; shouldn't necessarily be called
		carengine = &newengine;
		accel = carengine->getBaseAccel();
		accel += cargearbox->getBonusAccel();
	}

	void setGearbox(gearbox newgearbox) {	//if gearbox needs to be swapped; shouldn't necessarily be called
		accel = carengine->getBaseAccel();
		cargearbox = &newgearbox;
		accel += cargearbox->getBonusAccel();
	}

	void setAccel(float acceleration) {
		accel = carengine->getBaseAccel() + cargearbox->getBonusAccel();
	}

	void shift() {
		RPM = 0;
		accel += -0.02;		//lull in gear shifting affects accel & speed
		cargearbox->shift();
		glutPostRedisplay();
	}

	void setImage(char* filename) {
		texture_id = SOIL_load_OGL_texture
		(
			filename,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}

	void turnLeft() {
		left_right = false;
		animating = true;
		
		/*
		if (getX() == LeftmostOne) {
			return;
		}
		else if (getX() == LeftmostTwo) {
			setX(LeftmostOne);
		}
		else if (getX() == LeftmostThree) {
			setX(LeftmostTwo);
		}
		else if (getX() == LeftmostFour) {
			setX(LeftmostThree);
		}
		else if (getX() == LeftmostFive) {
			setX(LeftmostFour);			//can make it explode instead...
		}
		*/
	}

	void turnRight() {
		left_right = true;
		animating = true;

		/*
		if (getX() == LeftmostOne) {
			setX(LeftmostTwo);
		}
		else if (getX() == LeftmostTwo) {
			setX(LeftmostThree);
		}
		else if (getX() == LeftmostThree) {
			setX(LeftmostFour);
		}
		else if (getX() == LeftmostFour) {
			setX(LeftmostFive);
		}
		else if (getX() == LeftmostFive) {
			return;						//can make it explode instead...
		}
		*/
	}

	/*----------------------------Getters-------------------------------------*/

	float getAccel() const{
		return accel;
	}

	float getVelocity() const {
		return velocity;
	}

	int getRPM() const {
		return RPM;
	}

	bool getAnimating() const {
		return animating;
	}

	bool getLeftRight() const {
		return left_right;
	}



	/*--------------------------------Special----------------------------------*/

	float accelerate() {
		
		if (RPM >= carengine->getTopRPM()) {
			return velocity;					//Don't accelerate if at max RPM
		}
		switch (cargearbox->getCurrentGear()) {	//increasing RPM
		case gearbox::gears::first:
			RPM += 1500;
			break;
		case gearbox::gears::second:
			RPM += 1100;
			break;
		case gearbox::gears::third:
			RPM += 800;
			break;
		case gearbox::gears::fourth:
			RPM += 400;
			break;
		case gearbox::gears::fifth:
			RPM += 200;
			break;
		case gearbox::gears::sixth:
			RPM += 100;
			break;
		}
		
		return velocity + accel;

	}

	void movementStart() {

	}

	void movementLoop() {
		if (left_right == false) {

			if (x < -0.97) {
				animating = false;
				return;
			}
			x -= 0.01;

			
			/*
			if (x == LeftmostOne || x == LeftmostTwo || x == LeftmostThree || x == LeftmostFour) {
				cout << "left stop" << endl;
				animating = false;
				return;
			}
			*/
		}
		else if (left_right == true) {

			if (x > 0.7) {
				animating = false;
				return;
			}

			x += 0.01;

			

			/*
			if (x == LeftmostTwo || x == LeftmostThree || x == LeftmostFour || x == LeftmostFive) {
				cout << "right stop" << endl;
				animating = false;
				return;
			}
			*/

		}
	}

	void action() {
		if (animating) {
			movementLoop();
			redrawScene();


			//animating = false;
		}
	}

	~car() {
		delete filename;
		delete carengine;
		delete cargearbox;
	}

};


#endif
