#include "particle.h"
#include "main.h"

Particle::Particle(sf::Vector2f pos, float lifetime)
	: m_lifetime(lifetime)
	{
	// Random lifetime created in particlemanager 
	//TODO: lifetime randomly created on init??
	setSize(sf::Vector2f(10.f, 10.f));
	setPos(pos); // Set the position of the particle (to where the mouse is)
	m_id++;
}

int Particle::m_id{ 0 };


bool Particle::checkCollisionWithWindow() {
	return getParticle().getPosition().y + getParticle().getSize().y >= app.getWindow().getSize().y;
	
}

void Particle::update(sf::Time& deltaTime, bool collided) {
	if (checkCollisionWithWindow() || collided) {
		setPos(sf::Vector2f(getParticle().getPosition().x, app.getWindow().getSize().y - getParticle().getSize().y));
		m_velocity.y = 0;
		m_gravity = 0.f;
	}
	else {
		m_gravity = GRAVITY;
		m_velocity.y = m_velocity.y + m_gravity * deltaTime.asSeconds();
		getParticle().move(sf::Vector2f(0.f, m_velocity.y)); // Move by the velocity
	}
	m_lifetime -= deltaTime.asSeconds(); // Decrease lifetime
}
