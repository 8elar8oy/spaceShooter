#pragma once
#include "settings.h"
#include "ctime"
#include <vector>
class Bonus {
public:
	enum BonusType {MULTI_LASER,HP,SHIELD};
	Bonus(BonusType type, sf::Vector2f position);
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void setDel();
	bool isToDel();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	BonusType type;
	bool del = false;
	
};
Bonus::Bonus(BonusType type, sf::Vector2f position) {
	switch (type) {
	case MULTI_LASER:
		this->type = type;
		texture.loadFromFile(IMAGES_FOLDER + MULTI_LASER_BONUS_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		break;
	
	case HP:
		this->type = type;
		texture.loadFromFile(IMAGES_FOLDER + HP_BONUS_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		break;
	
	case SHIELD:
		this->type = type;
		texture.loadFromFile(IMAGES_FOLDER + SHIELD_BONUS_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		break;
	
	}
}
void Bonus::update() { sprite.move(0.f, BONUS_SPEED); }
void Bonus::draw(sf::RenderWindow& window) { window.draw(sprite); }
sf::FloatRect Bonus::getHitBox() { return sprite.getGlobalBounds(); };
sf::Vector2f Bonus::getPosition() { return sprite.getPosition(); };
void Bonus::setDel() { del = true; };
bool Bonus::isToDel() { return del; };