#include "GlutApp.h"
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "engine.h"
#include "gearbox.h"
#include "car.h"

using namespace std;

int main(int argc, char** argv) {

#include "TexRect.h"
	//filename, x, y, w, h
	TexRect engines = TexRect("engines.png", -0.20, 0.95, 0.40, 0.05);
	TexRect gearboxes = TexRect("gearboxes.png", -0.20, 0.35, 0.40, 0.05);
	TexRect chassis = TexRect("chassis.png", -0.20, -0.65, 0.40, 0.05);
	TexRect engine0 = TexRect("standardengine.png", -0.95, 0.30, 0.60, 0.60);
	TexRect engine1 = TexRect("sportengine.png", -0.30, 0.30, 0.60, 0.60);
	TexRect engine2 = TexRect("racingengine.png", 0.35, 0.30, 0.60, 0.60);
	TexRect gearbox0 = TexRect("stockgearing.png", -0.95, -0.30, 0.60, 0.60);
	TexRect gearbox1 = TexRect("rallygearing.png", -0.30, -0.30, 0.60, 0.60);
	TexRect gearbox2 = TexRect("racegearing.png", 0.35, -0.30, 0.60, 0.60);
	TexRect chassis0 = TexRect("E30.png", -0.95, -0.95, 0.60, 0.60);
	TexRect chassis1 = TexRect("shelby.png", -0.30, -0.95, 0.60, 0.60);
	TexRect chassis2 = TexRect("lambo.png", 0.35, -0.95, 0.60, 0.60);

	
}