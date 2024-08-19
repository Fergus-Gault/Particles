#include "main.h"
#include "ParticleManager.h"

App::App() : m_window(sf::VideoMode(800, 600), "Particles") {}

void App::processEvents() {
	sf::Event event;

	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0.f, 0.f, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			m_window.setView(sf::View(visibleArea));
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				particleManager.createParticle(sf::Vector2f(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y), 5.f);
			}
		}
	}

}

void App::update(sf::Time deltaTime) {
	particleManager.update(deltaTime);
}

void App::render() {
	m_window.clear();

	particleManager.render();

	m_window.display();

}


void App::run() {
	sf::Clock clock;
	while (m_window.isOpen()) {
		processEvents();
		update(clock.restart());
		render();
	}
}

App app{};
int main() {

	app.run();

	return 0;
}