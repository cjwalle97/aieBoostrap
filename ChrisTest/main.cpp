#include "ChrisTestApp.h"

int main() {
	
	auto app = new ChrisTestApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}