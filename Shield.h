#pragma once
#include "settings.h"
#include "Lazers.h"
#include <list>
#include "Lives.h"

class Shield {
public:
	Shield(sf::Vector2f PlayerCenterPos) {
		texture.loadFromFile(IMAGES_FOLDER + SHIELD_FILE_NAME);
		sprite.setTexture(texture);
	
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width/2,bounds.height/2);
		sprite.setPosition(PlayerCenterPos);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	
	
	void setPosition(sf::Vector2f pos);
sf::FloatRect getHitBox();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock timer;
};
void Shield::setPosition(sf::Vector2f pos) { sprite.setPosition(pos); };

sf::FloatRect Shield::getHitBox() { return sprite.getGlobalBounds(); };