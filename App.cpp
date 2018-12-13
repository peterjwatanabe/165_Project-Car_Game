#include <iostream>
#include "App.h"
#include <vector>
#include <iostream>
#include "../visualc15/intro.h"


App::App(int argc, char** argv) : GlutApp(argc, argv) {

	//explosion = new AnimatedRect("../fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);
	
	selectedCar = new car();
	intro = new introduction();
	
}



void App::draw() {

	intro->display();
	intro->setup(mx, my);
	selectedCar = intro->getCar();
	intro->continueToGame();


	//selectedCar->draw(0.15);
	//background->draw(1);


}

void App::idle() {

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
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
	
}
