#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleManager.h"

class App {
public:
	App();
	~App() = default;

	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	void run();

	sf::RenderWindow& getWindow() { return m_window; }

	ParticleManager particleManager{};
	
private:
	sf::RenderWindow m_window;

};

extern App app;
