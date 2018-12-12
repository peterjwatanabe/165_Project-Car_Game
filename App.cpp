#include <iostream>
#include "App.h"
#include <vector>
#include <iostream>

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

	/*
	engines = new TexRect("../engines.png", -0.20, 0.95, 0.40, 0.05);
	gearboxes = new TexRect("../gearboxes.png", -0.20, 0.35, 0.40, 0.05);
	chassis = new TexRect("../chassis.png", -0.20, -0.65, 0.40, 0.05);
	engine0 = new TexRect("../standardengine.png", -0.95, 0.30, 0.60, 0.60);
	engine1 = new TexRect("../sportengine.png", -0.30, 0.30, 0.60, 0.60);
	engine2 = new TexRect("../racingengine.png", 0.35, 0.30, 0.60, 0.60);
	gearbox0 = new TexRect("../stockgearing.png", -0.95, -0.30, 0.60, 0.60);
	gearbox1 = new TexRect("../rallygearing.png", -0.30, -0.30, 0.60, 0.60);
	gearbox2 = new TexRect("../racegearing.png", 0.35, -0.30, 0.60, 0.60);
	chassis0 = new TexRect("../E30.png", -0.95, -0.95, 0.60, 0.60);
	chassis1 = new TexRect("../shelby.png", -0.30, -0.95, 0.60, 0.60);
	chassis2 = new TexRect("../lambo.png", 0.35, -0.95, 0.60, 0.60);
	*/
	setup();
	
	for (int i = 0; i < 5; i++) {
		barrels.push_back(new Obstacle("../pixel-barrel.png"));
	}

	background = new TexRect("../road.png", -1, 1, 2, 2);
	
}



void App::draw() {
    explosion->draw(0.15);
    fastExplosion->draw(0.15);

	//barrels[0]->draw(1);

	/*
	engines->draw(0.0);
	gearboxes->draw(0.0);
	chassis->draw(0.0);
	engine0->draw(0.0);
	engine1->draw(0.0);
	engine2->draw(0.0);
	gearbox0->draw(0.0);
	gearbox1->draw(0.0);
	gearbox2->draw(0.0);
	chassis0->draw(0.0);
	chassis1->draw(0.0);
	chassis2->draw(0.0);
	*/
	selectedCar->draw(0);
	background->draw(0);
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


App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete explosion;
    delete fastExplosion;
	/*
	delete engines;
	delete gearboxes;
	delete chassis;
	delete engine0;
	delete engine1;
	delete engine2;
	delete gearbox0;
	delete gearbox1;
	delete gearbox2;
	delete chassis0;
	delete chassis1;
	delete chassis2;
	*/
	
}
