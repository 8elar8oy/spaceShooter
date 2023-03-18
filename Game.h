#pragma once
#include "Settings.h"
#include "Player.h"
#include "Meteor.h"
#include <vector>
#include "Lives.h"
#include "Lazers.h"
class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<Meteor*> meteorSprites;
	TextObject lives;
	sf::RectangleShape rect;
	
	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)	window.close();
		}
	}
	void update() {
		player.update();
		for (auto m: meteorSprites)
		{
			m ->update();
		}
		lives.update(std::to_string(player.getLives()));
	}
	void checkCollisions() {}
	void draw() {
		window.clear();
		player.draw(window);
		for (auto m : meteorSprites)
		{
			window.draw(m->getSprite());
		}
		window.draw(rect);
		window.draw(lives.getText());

		window.display();
	}
public:
	Game() : lives(std::to_string(player.getLives()), sf::Vector2f{WINDOW_WIDTH/2,0.f}){
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		rect.setFillColor(Color::Green);
		rect.setSize(Vector2f{ WINDOW_WIDTH, 50 });
		rect.setPosition(Vector2f{ 0, 0 });
		meteorSprites.reserve(METEOR_QTY);
		for (int i = 0; i < METEOR_QTY; i++)
		{
			Meteor* m = new Meteor();
			meteorSprites.push_back(m);
		}
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