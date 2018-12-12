#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "../visualc15/Obstacle.h"
#include <vector>


class App: public GlutApp {
	float mx;
	float my;

    AnimatedRect* explosion;
    AnimatedRect* fastExplosion;

	/*
	TexRect* engines;
	TexRect* gearboxes;
	TexRect* chassis;
	TexRect* engine0;
	TexRect* engine1;
	TexRect* engine2;
	TexRect* gearbox0;
	TexRect* gearbox1;
	TexRect* gearbox2;
	TexRect* chassis0;
	TexRect* chassis1;
	TexRect* chassis2;
	*/

	std::vector <Obstacle*> barrels;
    
	TexRect* background;

    
public:
    App(int argc, char** argv);

	void setup();
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
	void leftMouseDown(float x, float y);
    
    ~App();
    
};

#endif
