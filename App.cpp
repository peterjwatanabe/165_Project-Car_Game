#include <iostream>
#include "App.h"
#include <vector>
#include <iostream>
#include "../visualc15/intro.h"

using namespace std;

float explosionX;
float explosionY;
bool animateOnce = false;

bool gameoverState = false;
bool gamewonState = false;
int gameStatus = 0;		// 1:over, 2:won

App::App(int argc, char** argv) : GlutApp(argc, argv) {

	explosion = new AnimatedRect("../explode_1.png", 4, 4, 100, -0.5, 0.5, 0.5, 0.5);

	selectedCar = new car();
	intro = new introduction();
	background = new TexRect("../5lane.png", -1, 1, 2, 2);

	
	for (int i = 0; i < 3; i++) {
		barrels.push_back(new Obstacle("../pixel-barrel.png"));
	}
	finish = new finishLine();

	gameover = new Game_Over("../gameover.jpg", 0, 0);
	gamewon = new Game_Won("../gamewon.jpg", 0, 0);
	
	used = false;
	used2 = false;
	points = 0;
}



void App::draw() {
	
	if (!(intro->getIntroDone())) {
		intro->display();
		intro->setup(mx, my);
		selectedCar = intro->selectedCar;
		intro->continueToGame();
	}

	
	if (intro->getIntroDone() && !(selectedCar->getEndState())) {
		background->draw(-0.5);

		barrels[0]->draw(-0.1);
		barrels[1]->draw(-0.1);
		barrels[2]->draw(-0.1);
		finish->draw(-0.1);

		selectedCar->draw(0.0);

		explosion->draw(0.15);
		
	}

	if (selectedCar->getEndState() == true && gameoverState == false && gameStatus == 1) {
		gameover->finishTheGame();
		gameover->displayStats(0, 1);
		gameoverState = true;
	}
	if (gameoverState == true) {
		gameover->drawStats();
	}


	if (selectedCar->getEndState() == true && gamewonState == false && gameStatus == 2) {
		gamewon->finishTheGame();
		gamewon->displayStats(0, 1);
		gamewonState = true;
	}
	if (gamewonState == true) {
		gamewon->drawStats();
		gamewon->drawBiker();
	}

	
	
}

void App::idle() {
	/*
	if (intro->getIntroDone() == true && used == false) {
		startTime = clock();
		used = true;
	}

	if (intro->getIntroDone() == true && selectedCar->getEndState() == true && used2 == false) {
		cout << "goodbye" << endl;
		endTime = clock();
		elapsedTime = startTime - endTime;
		elapsedTime = (elapsedTime / CLOCKS_PER_SEC);
		if (gamewonState == true) {
		points = (500 + selectedCar->getEngineBonus() + (100 / elapsedTime * 1000))
			}
			else if (gameoverState == true) {
			points = (0 + selectedCar->getEngineBonus() + ((elapsedTime / 10) * 1000))
			}
		used2 = true;
	}
	*/
	

	if (intro->getIntroDone()) {
		barrels[0]->startMovement();
		barrels[1]->startMovement();
		barrels[2]->startMovement();

		barrels[0]->changeImage();
		barrels[1]->changeImage();
		barrels[2]->changeImage();

		if (barrels[0]->lastCycle()) {
			barrels[0]->setAnimating(false);
			barrels[1]->setAnimating(false);
			barrels[2]->setAnimating(false);
			finish->moveFinish();
		}

		

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
						selectedCar->setEndState(true);
						gameStatus = 1;
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
						selectedCar->setEndState(true);
						gameStatus = 1;
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
						selectedCar->setEndState(true);
						gameStatus = 1;
						break;
					}
				}
			}
		}

		
		if (finish->getHit(selectedCar->getX(), selectedCar->getY()) && gameStatus != 2) {
			selectedCar->setEndState(true);
			gameStatus = 2;
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

	delete finish;
	delete gameover;
	delete gamewon;
	
	
}
