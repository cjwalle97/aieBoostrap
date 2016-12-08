#include <iostream>
#include "MathLibraryHeader.h"
#include "Application2D.h"
#include "Texture.h"

class Player
{
private:
	bool alive;
	Vec2 position;
	Vec2 m_direction;
	float m_speed;
	aie::Texture playerTexture;
public:
	Player() {};
	Player(Vec2 pos) {
		position = pos;
	}
	Vec2 Move(Vec2 direction) {
		if (m_speed != 0)
			m_direction = m_direction + direction * m_speed;
	}
	aie::Texture texture(aie::Texture tex) {
		playerTexture = tex;
	}
};