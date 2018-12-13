#include <iostream>
#include "App.h"
#include <vector>
#include <iostream>
#include "../visualc15/intro.h"

car* selectedCar;

void App::setup() {
	engine* selectedEngine = new engine();
	gearbox* selectedGearbox = new gearbox();
	char* vehicle;
	int eng, gear, chas;
	std::cout << "Choose an engine: 1 for stock, 2 for sport, or 3 for racing" << std::endl;
	std::cin >> eng;
	switch (eng) {
	case 1:
		selectedEngine->setupEngine(1);
		break;
	case 2:
		selectedEngine->setupEngine(2);
		break;
	case 3:
		selectedEngine->setupEngine(3);
		break;
	}
	std::cout << "Choose a gearbox: 1 for balanced, 2 for rally, or 3 for racing" << std::endl;
	std::cin >> gear;
	switch (gear) {
	case 1:
		selectedGearbox->setupGearbox(1);
		break;
	case 2:
		selectedGearbox->setupGearbox(2);
		break;
	case 3:
		selectedGearbox->setupGearbox(3);
		break;
	}
	std::cout << "Choose a chassis: 1 for M5 E30, 2 for Shelby GT, or 3 for Murcielago" << std::endl;
	std::cin >> chas;
	switch (chas) {
	case 1:
		vehicle = "../E30.png";
		break;
	case 2:
		vehicle = "../shelby.png";
		break;
	case 3:
		vehicle = "../lambo.png";
		break;
	}
	selectedCar = new car(vehicle, *selectedEngine, *selectedGearbox);
}



App::App(int argc, char** argv) : GlutApp(argc, argv) {

	explosion = new AnimatedRect("../fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);

	fastExplosion = new AnimatedRect("../fireball.bmp", 6, 6, 10, 0.5, 0.5, 0.5, 0.5);
	
	selectedCar = new car();
	intro = new introduction();
	
}



void App::draw() {
    explosion->draw(0.15);
    fastExplosion->draw(0.15);

	intro->display();
	intro->setup(mx, my);
	selectedCar = intro->getCar();
	intro->continueToGame();


	//selectedCar->draw(0.15);
	//background->draw(1);


}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
        fastExplosion->playOnce();
        explosion->playOnce();
    }
}

void App::leftMouseDown(float x, float y) {
	mx = x;
	my = y;


}


App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete explosion;
    delete fastExplosion;

	delete selectedCar;
	delete intro;
	
}
