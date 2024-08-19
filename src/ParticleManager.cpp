#include "ParticleManager.h"
#include "main.h"

void ParticleManager::createParticle(sf::Vector2f pos, float lifetime) {
	m_particles.push_back(std::make_shared<Particle>(pos, lifetime)); // Create a new particle and add to the vector
}

bool ParticleManager::checkIfCollisionWithParticle(Particle& particle) {
	for (auto& other : m_particles) {
		if (particle.m_id != other->m_id && particle.getParticle().getGlobalBounds().intersects(other->getParticle().getGlobalBounds())) {
			return true;
		}
	}
	return false;
}

void ParticleManager::update(sf::Time& deltaTime) {
	for (auto& particle : m_particles) {
		particle->update(deltaTime, checkIfCollisionWithParticle(*particle)); // Update every particle
	}

	// Erase dead particles
	m_particles.erase(std::remove_if(m_particles.begin(), m_particles.end(),
		[](const std::shared_ptr<Particle>& p) { return !p->isAlive(); }), m_particles.end()); 
}

void ParticleManager::render() {
	for (auto& particle : m_particles) {
		app.getWindow().draw(particle->getParticle()); // Draw every particle
	}
}