#ifndef gamewon_h
#define gamewon_h

#include "../visualc15/gameover.h"

class Game_Won : public Game_Over {
	char* image;
	TexRect* biker;

public:

	Game_Won() : Game_Over() {}

	Game_Won(char* filename, float totalTime, int points) : Game_Over(filename, totalTime, points) {
		if (checkScore() > 0) {
			image = "../bikerkyrilov.png";
		}
		else {
			image = "../bikerman.png";
		}
		biker = new TexRect(image, -0.4, 0.85, 0.6, 0.5);
	}

	void drawBiker() {
		biker->draw(0.2);
	}

	~Game_Won() {
		delete biker;	
	}
};

#endif
