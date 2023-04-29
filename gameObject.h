#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <iostream>
class GameObject
{
public:
	GameObject() {
		std::cout << "GameObject created\n";
	}
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow window) = 0;
	sf::Vector2f getPositon() { return sprite.getPosition(); }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
protected:
	sf::Texture  texture;
	sf::Sprite sprite;
};

