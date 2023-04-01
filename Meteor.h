#pragma once
#include "settings.h"
#include "ctime"
#include <vector>
class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx;
	float speedy;
	static int arrDamage[];
	static int arrValue[];
	int damage;
	int value;

public:
	void spawn() {
		speedx = rand() % 5 - 2;
		speedy = rand() % 6 + 2;
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
		float y = rand() % 200 - (200 + bounds.height);
		sprite.setPosition(x, y);
	}

	static std::string METEOR_FILE_NAME[];
	Meteor() {
		int index = rand() % 8;
		damage = arrDamage[index];
		value = arrValue[index];
		texture.loadFromFile(IMAGES_FOLDER + METEOR_FILE_NAME[index]);
		sprite.setTexture(texture);

		spawn();

	}
	void update() {
		sprite.move(speedx, speedy);
		sf::FloatRect bounds = sprite.getGlobalBounds();

		if (bounds.top >= WINDOW_HEIGHT || bounds.left <= -bounds.width || bounds.left >= WINDOW_WIDTH) {
			spawn();
		}
	}
	sf::Sprite getSprite() {
		return sprite;
	}
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	int getDamage() { return damage; }
	int getValue() { return value; }
};
std::string Meteor::METEOR_FILE_NAME[] = { "meteorGrey_tiny1.png",	"meteorGrey_tiny2.png",
											"meteorGrey_big1.png",	"meteorGrey_big2.png",
											"meteorGrey_med1.png",	"meteorGrey_med2.png",
											"meteorGrey_small1.png","meteorGrey_small2.png" };
int Meteor::arrDamage[] = { 5,5,20,20,15,15,10,10 };
int Meteor::arrValue[] = { 1,1,4,4,3,3,2,2 };