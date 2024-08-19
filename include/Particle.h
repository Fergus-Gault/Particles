#pragma once

#include <SFML/Graphics.hpp>

class Particle {
public:
	Particle(sf::Vector2f pos, float lifetime);
	void update(sf::Time& deltaTime, bool collided);

	bool isAlive() const { return m_lifetime > 0; }

	void setSize(sf::Vector2f size) { m_particle.setSize(size); }
	void setPos(sf::Vector2f pos) { m_particle.setPosition(pos); }

	sf::RectangleShape& getParticle() { return m_particle; }

	bool checkCollisionWithWindow();

	const float GRAVITY{ 0.98f };

	static int m_id;

private:
	sf::RectangleShape m_particle{};
	sf::Vector2f m_velocity{ 0.f, 0.f };
	float m_gravity{ .98f };
	float m_lifetime{};
};