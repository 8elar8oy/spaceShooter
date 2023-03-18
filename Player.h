#pragma once
#include "settings.h"
#include "Lazers.h"
#include <list>
class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx;
	int lives = 3;
	std::list<Laser*> lasers;


public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setPosition((WINDOW_WIDTH - bounds.width) / 2, WINDOW_HEIGHT - bounds.height - 10);
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);

	}
	
	void update() {
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float playerx = sprite.getPosition().x;
		float playery = sprite.getPosition().y;
		if (playerx <= bounds.width / 2) { sprite.setPosition(bounds.width / 2, playery); }
		if (playerx >= WINDOW_WIDTH - bounds.width / 2) { sprite.setPosition(WINDOW_WIDTH - bounds.width / 2, playery); }
		if (Keyboard::isKeyPressed(Keyboard::Left)) { speedx = -PLAYER_SPEED; }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { speedx = PLAYER_SPEED; }
		sprite.move(speedx, 0.f);
		speedx = 0.f;
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			
			fire();
			
		}
		for  (auto laser : lasers)
		{
			laser->update();
			
		}
	}
	void fire() {
		Laser* l = new Laser(sprite.getPosition());
		lasers.push_back(l);
	}
	void draw(sf::RenderWindow& window) { 
		window.draw(sprite);
		for (auto laser : lasers)
		{
			laser->getSprite();
		}
	}
	int getLives() { return lives; }
	void incLives() { lives++; }
	void decLives() { lives--; }
};