#include "MathLibraryHeader.h"
class Player
{
public:
	Player() {};
	Player(Vec2 pos)
	{
		position = pos;
		velocity = Vec2(0, 0);
		force = Vec2(0, 0);
	}

	//Vec2 Move(Vec2 direction) {
	//	if (m_speed != 0)
	//		m_direction = m_direction + direction * m_speed;
	//}
	//aie::Texture texture(aie::Texture tex) 
	//{
	//	playerTexture = tex;
	//}
	void Update(float deltaTime)
	{
		velocity += force * deltaTime;
		position += velocity * deltaTime;
	}

	void AddForce(Vec2 f)
	{
		velocity += f;
	}
	bool Dead() {
		if (true)
		{
			return alive = false;
		}
	}
	Vec2 position;
	Vec2 force;
	Vec2 velocity;
private:
	bool alive;


	Vec2 m_direction;
	Vec2 m_force;
	float m_speed;

};