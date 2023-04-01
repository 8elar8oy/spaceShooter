#pragma once
#include "settings.h"
#include "Lazers.h"
#include <windows.h>
#include <list>
class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx = 0.f;
	int lives = 300;
	int score = 0;
	
	std::list<Laser*> lasers;
	sf::Clock timer;
	sf::FloatRect bounds;

public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		bounds = sprite.getGlobalBounds();
		
		sprite.setPosition((WINDOW_WIDTH - bounds.width) / 2, WINDOW_HEIGHT - bounds.height - 10);
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		timer.restart();
	}

	void update() {
		sf::Clock timer;
		float time = timer.getElapsedTime().asMilliseconds();
		
		float playerx = sprite.getPosition().x;
		float playery = sprite.getPosition().y;
		if (playerx <= bounds.width / 2) { sprite.setPosition(bounds.width / 2, playery); }
		if (playerx >= WINDOW_WIDTH - bounds.width / 2) { sprite.setPosition(WINDOW_WIDTH - bounds.width / 2, playery); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { speedx = -PLAYER_SPEED; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { speedx = PLAYER_SPEED; }
		sprite.move(speedx, 0.f);
		speedx = 0.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {


			fire();


		}
		for (auto laser : lasers)
		{

			laser->update();
		}
	}

	void draw(sf::RenderWindow& window) {
		for (auto laser : lasers)
		{
			window.draw(laser->getSprite());
		}
		window.draw(sprite);
	}
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	int getLives() { return lives; }
	void incLives() { lives++; }
	void decLives(int damage) { lives-= damage; }
	
	int getScore() { return score; }
	void incScore(int value) { score+= value; }
	
	bool isAlive() { return lives > 0; }
	void fire() {
		int time = timer.getElapsedTime().asMilliseconds();
		if (time > 200) {
			sf::Vector2f laserPos{ sprite.getPosition().x + bounds.width / 2, sprite.getPosition().y };
			Laser* l = new Laser(sprite.getPosition());
			lasers.push_back(l);
			timer.restart();
		}

	}
	std::list<Laser*>* getLasers() { return &lasers; }
};
