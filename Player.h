#pragma once
#include "settings.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx;
	
public:
	Player() {
		texture.loadFromFile("playerShip3_green.png");
		
		sprite.setTexture(texture);
		sprite.setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT-100);
		
	}
	void update() {
		float player_size = texture.getSize().x;
		float playerx = sprite.getPosition().x;
		float playery = sprite.getPosition().y;
		if (playerx <= 0) sprite.setPosition(0.f, playery);
		if (playerx >= WINDOW_WIDTH-player_size) sprite.setPosition(WINDOW_WIDTH-player_size, playery);
		if (Keyboard::isKeyPressed(Keyboard::Left)) speedx = -PLAYER_SPEED;
		if (Keyboard::isKeyPressed(Keyboard::Right)) speedx = PLAYER_SPEED;
		sprite.move(speedx, 0.f);
		speedx = 0.f;
	}
	sf::Sprite getSprite() {
		return sprite;
	}

};