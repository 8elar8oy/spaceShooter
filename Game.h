#pragma once
#include "Settings.h"
#include "Player.h"
#include "Meteor.h"
class Game {
private:
	sf::RenderWindow window;
	Player player;
	Meteor meteor;
	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)	window.close();
		}
	}
	void update() {
		player.update();
		meteor.update();
	}
	void checkCollisions() {}
	void draw() {
		window.clear();
		window.draw(player.getSprite());
		window.draw(meteor.getSprite());
		window.display();
	}
public:
	Game() {
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
	}
	void play() {
		while (window.isOpen())
		{
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}

};
