#include <iostream>
#include "App.h"
#include <vector>
#include <iostream>
#include "../visualc15/intro.h"

float explosionX;
float explosionY;
bool animateOnce = false;

App::App(int argc, char** argv) : GlutApp(argc, argv) {

	explosion = new AnimatedRect("../explode_1.png", 4, 4, 100, -0.5, 0.5, 0.5, 0.5);

	selectedCar = new car();
	intro = new introduction();
	background = new TexRect("../5lane.png", -1, 1, 2, 2);

	
	for (int i = 0; i < 3; i++) {
		barrels.push_back(new Obstacle("../pixel-barrel.png"));
	}
	
	
}



void App::draw() {
	
	if (!(intro->getIntroDone())) {
		intro->display();
		intro->setup(mx, my);
		selectedCar = intro->selectedCar;
		intro->continueToGame();
	}

	
	if (intro->getIntroDone()) {
		background->draw(-0.5);

		barrels[0]->draw(-0.1);
		barrels[1]->draw(-0.1);
		barrels[2]->draw(-0.1);

		selectedCar->draw(0.0);

		explosion->draw(0.15);
	}
	
}

void App::idle() {
	if (intro->getIntroDone()) {
		barrels[0]->startMovement();
		barrels[1]->startMovement();
		barrels[2]->startMovement();

		if (selectedCar->getEndState() == false) {
			for (int i = 0; i < 3; i++) {
				if (barrels[i]->getHit(selectedCar->getX(), selectedCar->getY())) {
					if (selectedCar->getFilename() == "../lambo.png") {
						selectedCar->setImage("../lambobroke.png");
						selectedCar->setAnimating(false);
						barrels[0]->setAnimating(false);
						barrels[1]->setAnimating(false);
						barrels[2]->setAnimating(false);
						explosionX = barrels[i]->getX();
						explosionY = barrels[i]->getY();
						explosion->setX(explosionX);
						explosion->setY(explosionY);
						//explosion->playOnce();
						selectedCar->setEndState(true);
						break;
					}
					else if (selectedCar->getFilename() == "../shelby.png") {
						selectedCar->setImage("../shelbybroke.png");
						selectedCar->setAnimating(false);
						barrels[0]->setAnimating(false);
						barrels[1]->setAnimating(false);
						barrels[2]->setAnimating(false);
						explosionX = barrels[i]->getX();
						explosionY = barrels[i]->getY();
						explosion->setX(explosionX);
						explosion->setY(explosionY);
						//explosion->playOnce();
						selectedCar->setEndState(true);
						break;
					}
					else if (selectedCar->getFilename() == "../E30.png") {
						selectedCar->setImage("../E30broke.png");
						selectedCar->setAnimating(false);
						barrels[0]->setAnimating(false);
						barrels[1]->setAnimating(false);
						barrels[2]->setAnimating(false);
						explosionX = barrels[i]->getX();
						explosionY = barrels[i]->getY();
						explosion->setX(explosionX);
						explosion->setY(explosionY);
						//explosion->playOnce();
						selectedCar->setEndState(true);
						break;
					}
				}
			}
		}

		

		if (selectedCar->getEndState()) {
			explosion->playOnce();
		}

	}
	

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }

	if (key == ' ') {
		explosion->playOnce();
	}

	if (key == 'a') {
		selectedCar->turnLeft();
	}

	if (key == 'd') {
		selectedCar->turnRight();
	}
    
}

void App::leftMouseDown(float x, float y) {
	mx = x;
	my = y;
}


App::~App(){
    std::cout << "Exiting..." << std::endl;

	delete selectedCar;
	delete intro;
	delete background;

	
	for (int i = 0; i < 3; i++) {
		delete barrels[i];
	}
	
	
}
