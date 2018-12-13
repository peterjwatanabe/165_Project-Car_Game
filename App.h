#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "../visualc15/Obstacle.h"
#include "../visualc15/intro.h"
#include <vector>


class App: public GlutApp {
	float mx;
	float my;

    AnimatedRect* explosion;
    AnimatedRect* fastExplosion;

	car* selectedCar;
	introduction* intro;
	
    
public:
    App(int argc, char** argv);

	void setup();
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
	void leftMouseDown(float x, float y);
    
    ~App();
    
};

#endif
