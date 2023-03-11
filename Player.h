#pragma once
#include "settings.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx;
	

public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);

		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setPosition((WINDOW_WIDTH - bounds.width )/ 2, WINDOW_HEIGHT - bounds.height-10);

	}
	
	void update() {
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float playerx = sprite.getPosition().x;
		float playery = sprite.getPosition().y;
		if (playerx <= 0) sprite.setPosition(0.f, playery);
		if (playerx >= WINDOW_WIDTH - bounds.width) sprite.setPosition(WINDOW_WIDTH - bounds.width, playery);
		if (Keyboard::isKeyPressed(Keyboard::Left)) speedx = -PLAYER_SPEED;
		if (Keyboard::isKeyPressed(Keyboard::Right)) speedx = PLAYER_SPEED;
		sprite.move(speedx, 0.f);
		speedx = 0.f;
	}
	sf::Sprite getSprite() {
		return sprite;
	}

};
