#pragma once
#include "settings.h"

class ShieldSprite {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedy;


public:
	ShieldSprite(sf::Vector2f pos) {
		texture.loadFromFile(IMAGES_FOLDER + LASER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(pos);
		
	}

	void update(int speedx) {
		sprite.move(speedx,0);
	}

	sf::Sprite& getSprite() { return sprite; }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};

