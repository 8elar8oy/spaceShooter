#pragma once
#include "settings.h"

class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
	int damage;


public:
	static std::string mFileNames[];
	static int mDamage[];
	Meteor() {
		int index = rand() % METEOR_TYPES_QTY;
		damage = mDamage[index];
		texture.loadFromFile(IMAGES_FOLDER + mFileNames[index]);
		sprite.setTexture(texture);
		spawn();
	}

	void update() {
		sprite.move(speedx, speedy);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		if (bounds.left < -bounds.width || bounds.left > WINDOW_WIDTH ||
			bounds.top > WINDOW_HEIGHT)
		{
			spawn();
		}
	}

	sf::Sprite getSprite() { return sprite; }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	void spawn() {
		speedy = rand() % 6 + 2;
		speedx = rand() % 5 - 2;
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
		float y = -(rand() % (int)(WINDOW_HEIGHT - bounds.height) + bounds.height);
		sprite.setPosition(x, y);
	}

	int getDamage() { return damage; }

	sf::Vector2f getPosition() { return sprite.getPosition(); }
};

std::string Meteor::mFileNames[] = { "meteorGrey_tiny1.png",	"meteorGrey_tiny2.png",
											"meteorGrey_big1.png",	"meteorGrey_big2.png",
											"meteorGrey_med1.png",	"meteorGrey_med2.png",
											"meteorGrey_small1.png","meteorGrey_small2.png" };
int Meteor::mDamage[] = { 30,30,20,20,10,10,5,5 };