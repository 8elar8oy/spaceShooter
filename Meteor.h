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
		texture.loadFromFile(METEOR_FILE_NAME[rand()%8]);
		sprite.setTexture(texture);
		
		speedx = rand() % 5 -2;
		speedy = rand()%6+2;
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
		float y = (rand() % (int)(WINDOW_HEIGHT - bounds.height)+bounds.height);
		sprite.setPosition(x,y);
	}
	void update() {
		
		sprite.move(0.f, speedy);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {                                          
			texture.loadFromFile(METEOR_FILE_NAME[rand() % 8]);
			sprite.setTexture(texture);
			sprite.setPosition(posx_arr[rand() % 8],posy_arr[rand() % 4]);
		}
	}
	sf::Sprite getSprite() {
		return sprite;
	}
};
std::string Meteor::METEOR_FILE_NAME[] = { "png\\meteorBrown_tiny1.png","png\\meteorBrown_tiny2.png",
		"png\\meteorBrown_big1.png","png\\meteorBrown_big2.png", "png\\meteorBrown_med1.png",
		"png\\meteorBrown_med3.png","png\\meteorBrown_small1.png","png\\meteorBrown_small2.png" };