#pragma once
#include "settings.h"
#include "Lazers.h"
#include <list>
#include "Lives.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx = 0.f;
	int score = 0;
	std::list<Laser*> lasers;
	int hp = INITIAL_PLAYER_HP;
	TextObj hpText;
	sf::FloatRect bounds;
	sf::Clock timer;
	sf::Clock timer2;
	bool threeLasers = false;
	bool shieldAct = false;


public:
	Player() : hpText(std::to_string(hp), sf::Vector2f(0.f, 0.f)) {
		texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		bounds = sprite.getGlobalBounds();
		sprite.setPosition(
			(WINDOW_WIDTH - bounds.width) / 2,
			WINDOW_HEIGHT - bounds.height - 50.f
		);
		
		
		timer.restart();
	}

	void update() {
		speedx = 0.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			speedx = -PLAYER_SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			speedx = PLAYER_SPEED;
		}
		sprite.move(speedx, 0.f);

		sf::Vector2f playerPos = sprite.getPosition();
		if (playerPos.x < 0) {
			sprite.setPosition(0.f, playerPos.y);
		}
		else if (playerPos.x > WINDOW_WIDTH - bounds.width) {
			sprite.setPosition(WINDOW_WIDTH - bounds.width, playerPos.y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			fire();
		}
		for (auto laser : lasers) {
			laser->update();
		}
		
		hpText.update("HP:" + std::to_string(hp));
		
	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
		for (auto laser : lasers) {
			window.draw(laser->getSprite());
		}
		
		
		window.draw(hpText.getText());
	}

	int getScore() { return score; }
	void incScore(int damage) { score = score + damage; }
	void decScore() { score--; }
	int getSpeed() { return speedx; }
	void fire() {
		int now = timer.getElapsedTime().asMilliseconds();
		int now1 = timer2.getElapsedTime().asSeconds();
		if (now > FIRE_COOLDOWN) {
			sf::Vector2f centralLaserPos{ sprite.getPosition().x + bounds.width / 2,  sprite.getPosition().y };
			Laser* centralLaser = new Laser(centralLaserPos);
			lasers.push_back(centralLaser);
			
			if (threeLasers) {
				if (now1 < 10) {
					sf::Vector2f leftLaserPos{ sprite.getPosition().x,
					sprite.getPosition().y + bounds.height / 2 };
					Laser* leftLaser = new Laser(leftLaserPos);
					lasers.push_back(leftLaser);

					sf::Vector2f rightLaserPos{ sprite.getPosition().x + bounds.width,
					sprite.getPosition().y + bounds.height / 2 };
					Laser* rightLaser = new Laser(rightLaserPos);
					lasers.push_back(rightLaser);
				}
				else {
					deactivateThreeLasers();
					timer2.restart();
				}
				
			}
			timer.restart();
		}
	}
	


	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	bool isDead() { return hp <= 0; }
	bool isAlive() { return hp > 0; }
	void receiveDamage(int damage) { hp -= damage; }
	void incLives() {   hp += 25; if (hp > 100) { hp = 100; } }
	std::list<Laser*>* getLasers() { return &lasers; }
	sf::Vector2f getPos() { return sprite.getPosition(); }
	void activateThreeLasers() { threeLasers = true; }
	void deactivateThreeLasers() { threeLasers = false; }
	void activateShield() { shieldAct = true; }
	void deactivateShield() { shieldAct = false; }
};

