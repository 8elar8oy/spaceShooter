#pragma once
#include "Settings.h"
#include "Player.h"
#include "Meteor.h"
#include <vector>
#include "textobj.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<Meteor*> meteorSprites;
	TextObj lives;
	sf::RectangleShape rect;
	TextObj score;
	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)	window.close();
		}
	}
	void update() {
		player.update();
		for (auto m : meteorSprites)
		{
			m->update();
		}
		lives.update(std::to_string(player.getLives()));
		score.update(std::to_string(player.getScore()));
	}
	void checkCollisions() {
		sf::FloatRect playerHitBox = player.getHitBox();
		auto laserSprites = player.getLasers();
		for (auto& meteor : meteorSprites) {
			sf::FloatRect meteorHitBox = meteor->getHitBox();
			if (meteorHitBox.intersects(playerHitBox)) {
				meteor->spawn();
				player.decLives(meteor->getDamage());
			}
			for (auto& laser : (*laserSprites)) {
				sf::FloatRect laserHitBox = laser->getHitBox();
				if (laserHitBox.intersects(meteorHitBox)) {
					player.incScore(meteor->getValue());
					meteor->spawn();
					laser->setHit();
				}
			}
		}
		(*laserSprites).remove_if([](Laser* laser) { return laser->isHited(); });
	}
	
	void draw() {
		window.clear();
		player.draw(window);
		for (auto m : meteorSprites)
		{
			window.draw(m->getSprite());
		}
		window.draw(rect);
		window.draw(lives.getText());
		window.draw(score.getText());
		window.display();
	}
public:
	Game() : lives(std::to_string(player.getLives()), LIFES_POS), score(std::to_string(player.getScore()), SCORE_POS)
	{
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		meteorSprites.reserve(METEOR_QTY);
		for (int i = 0; i < METEOR_QTY; i++)
		{
			Meteor* m = new Meteor();
			meteorSprites.push_back(m);
		}
		rect.setFillColor(Color::Green);
		rect.setSize(Vector2f{ WINDOW_WIDTH, 50 });
	}
	void play() {
		while (window.isOpen() && player.isAlive())
		{
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}

};