#include <iostream>
#include "App.h"
#include <vector>
#include <iostream>
#include "../visualc15/intro.h"


App::App(int argc, char** argv) : GlutApp(argc, argv) {

	//explosion = new AnimatedRect("../fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);

	selectedCar = new car();
	intro = new introduction();

	
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
		selectedCar->draw(0.15);
		
											// place stuff outside of here in here once done : NOTE
		barrels[0]->draw(0.0);
		barrels[1]->draw(0.0);
		barrels[2]->draw(0.0);

	}
	
}

void App::idle() {
	if (intro->getIntroDone()) {
		barrels[0]->startMovement();
		barrels[1]->startMovement();
		barrels[2]->startMovement();

		/*
		barrels[0]->getHit(selectedCar->getX(), selectedCar->getY());
		barrels[1]->getHit(selectedCar->getX(), selectedCar->getY());
		barrels[2]->getHit(selectedCar->getX(), selectedCar->getY());
		*/

	}
	

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
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

	
	for (int i = 0; i < 3; i++) {
		delete barrels[i];
	}
	
	
}
