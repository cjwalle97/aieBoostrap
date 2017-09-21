#include "LightingApplication.h"


int main() {
	
	auto app = new LightingApplication();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}