#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h" 
#include <iostream>
#include <fstream>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	float x = getWindowWidth() / 2.0f;
	float y = getWindowHeight() / 2.0f;
	destination = Vec2(x + 10, y + 10);
	p = new Player(Vec2(x, y));
	m_2dRenderer = new aie::Renderer2D();
	
	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_playerTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	std::fstream * file = new std::fstream();
	file->open("test.text", std::ios_base::out);
	if (file->is_open()) *file << "Hello World" << std::endl;
	file->close();

	return true;
}

void Application2D::shutdown() {
	
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_playerTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	//use wsad to move the player
	if (input->isKeyDown(aie::INPUT_KEY_W))
		p->AddForce(Vec2(0, 1) * 10.0f);

	if (input->isKeyDown(aie::INPUT_KEY_S))
		p->AddForce(Vec2(0, -1) * 10.0f);

	if (input->isKeyDown(aie::INPUT_KEY_D))
		p->AddForce(Vec2(1, 0)* 10.0f);

	if (input->isKeyDown(aie::INPUT_KEY_A))
		p->AddForce(Vec2(-1, 0)* 10.0f);

	//allow for 5* the normal Speed when the Spacebar is held down
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		if (input->isKeyDown(aie::INPUT_KEY_W))
			p->AddForce(Vec2(0, 1)* 50.0f);
		if (input->isKeyDown(aie::INPUT_KEY_S))
			p->AddForce(Vec2(0, -1)* 50.0f);
		if (input->isKeyDown(aie::INPUT_KEY_D))
			p->AddForce(Vec2(1, 0)* 50.0f);
		if (input->isKeyDown(aie::INPUT_KEY_A))
			p->AddForce(Vec2(-1, 0)* 50.0f);
	}

	//keeps the Player in the center of the Camera
	m_cameraX = p->position.x - (getWindowWidth() / 2);
	m_cameraY = p->position.y - (getWindowHeight() / 2);

	// example of audio
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		m_audio->play();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	Vec2 seek = destination - p->position;
	Vec2 seekDirection = seek.Normalize();
	p->AddForce(seekDirection * 5.0f);
	p->Update(deltaTime);
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();	

	// draw player
	m_2dRenderer->setUVRect(0,0,1,1);
	m_2dRenderer->drawSprite(m_playerTexture, p->position.x, p->position.y, 0, 0, 0, 1);

	// draw a thin line
	m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// draw a small blue circle that will act as the Destination for the Player to orbit around
	m_2dRenderer->setRenderColour(0, 0, 1, 1);
	m_2dRenderer->drawCircle(destination.x, destination.y, 50, 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "WASD To move, Space to increase movement speed", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}