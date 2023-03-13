#pragma once
#include "settings.h"
#include "ctime"
class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx;
	float speedy;
	

public:
	
	
	static std::string METEOR_FILE_NAME[];
	Meteor() {
		srand(time(nullptr));
		
		
		speedx = rand() % 5 - 2;
		speedy = rand() % 6 + 2;
		texture.loadFromFile(METEOR_FILE_NAME[rand() % 8]);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
		float y = rand() % 200 - (200 + bounds.height);
		sprite.setPosition(x, y);
		
	}
	void update() {
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.move(speedx, speedy);
		if (sprite.getPosition().y >= WINDOW_HEIGHT || sprite.getPosition().x + bounds.width <= 0 || sprite.getPosition().x >= WINDOW_WIDTH) {
			
			speedx = rand() % 5 - 2;
			speedy = rand() % 6 + 2;
			texture.loadFromFile(METEOR_FILE_NAME[rand() % 8]);
			sprite.setTexture(texture);
			float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
			float y = rand() % 200 - (200 + bounds.height);
			sprite.setPosition(x, y);
		}
	}
	sf::Sprite getSprite() {
		return sprite;
	}
};
std::string Meteor::METEOR_FILE_NAME[] = { "png\\meteorBrown_tiny1.png","png\\meteorBrown_tiny2.png",
		"png\\meteorBrown_big1.png","png\\meteorBrown_big2.png", "png\\meteorBrown_med1.png",
		"png\\meteorBrown_med3.png","png\\meteorBrown_small1.png","png\\meteorBrown_small2.png" };