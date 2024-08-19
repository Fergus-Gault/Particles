#pragma once

#include "Particle.h"
#include <vector>

class ParticleManager {
public:
	void createParticle(sf::Vector2f pos, float lifetime);

	void update(sf::Time& deltaTime);
	void render();

	bool checkIfCollisionWithParticle(Particle& particle);
private:
	std::vector<std::shared_ptr<Particle>> m_particles;
};