#include "_5_TexturesApp.h"

int main() {
	
	auto app = new _5_TexturesApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}