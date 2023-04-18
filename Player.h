#pragma once
#include "settings.h"
#include "Lazers.h"
#include <list>
#include "Lives.h"
#include "Shield.h"
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
	bool ShieldActive = false;
	Shield shield;
	int currTime, prevFireTime;
	int prevThreeLasersBonusTime;
	int prevShieldTime;
	int ShieldMargin = SHIELD_MARGIN;
public:
	
	Player() : hpText(std::to_string(hp), sf::Vector2f(0.f, 0.f)),shield(getCenterPosition()) {
		texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		bounds = sprite.getGlobalBounds();
		sprite.setPosition(
			(WINDOW_WIDTH - bounds.width) / 2,
			WINDOW_HEIGHT - bounds.height - 50.f
		);


		timer.restart();
		prevFireTime = timer.getElapsedTime().asMilliseconds();
	}
	

	void update() {
		currTime = timer.getElapsedTime().asMilliseconds();
		if (currTime - prevThreeLasersBonusTime >THREE_LASERS_BONUS_DURATION)
		{
			threeLasers = false;
		}
		if (ShieldMargin <= 0) {
			ShieldActive = false;
		}
		bounds = sprite.getGlobalBounds();
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
		if (ShieldIsActive()) {
			shield.setPosition(getCenterPosition());
		}
		else {
			shield.setPosition(sf::Vector2f{ WINDOW_WIDTH / 2,WINDOW_HEIGHT + 100.f });
		}
	}
	void activateShield() { 
		ShieldActive = true;
		ShieldMargin = SHIELD_MARGIN;
		prevShieldTime = timer.getElapsedTime().asMilliseconds();
	}
	bool ShieldIsActive() { return ShieldActive; };
	void ShieldDeactivate() { ShieldActive = false; };
	void decreaseShieldMargin() { ShieldMargin--; };

	void draw(sf::RenderWindow& window) {
		if (ShieldIsActive()) {
			shield.draw(window);
		}
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
		
		
		if (currTime-prevFireTime > FIRE_COOLDOWN) {
			sf::Vector2f centralLaserPos{ sprite.getPosition().x + bounds.width / 2,  sprite.getPosition().y };
			Laser* centralLaser = new Laser(centralLaserPos);
			lasers.push_back(centralLaser);
			
			if (threeLasers) {
				
				
					sf::Vector2f leftLaserPos{ sprite.getPosition().x,
					sprite.getPosition().y + bounds.height / 2 };
					Laser* leftLaser = new Laser(leftLaserPos);
					lasers.push_back(leftLaser);

					sf::Vector2f rightLaserPos{ sprite.getPosition().x + bounds.width,
					sprite.getPosition().y + bounds.height / 2 };
					Laser* rightLaser = new Laser(rightLaserPos);
					lasers.push_back(rightLaser);

			}
			prevFireTime = currTime;
		}
	}
	
	
	
	sf::FloatRect getShieldHitBox() { return shield.getHitBox(); };


	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	bool isDead() { return hp <= 0; }
	bool isAlive() { return hp > 0; }
	void receiveDamage(int damage) { hp -= damage; }
	void incLives() { hp += 25; if (hp > 100) { hp = 100; } }
	std::list<Laser*>* getLasers() { return &lasers; }
	sf::Vector2f getPos() { return sprite.getPosition(); }
	void activateThreeLasers() { threeLasers = true; 
	prevThreeLasersBonusTime = timer.getElapsedTime().asMilliseconds();
	}
	void deactivateThreeLasers() { threeLasers = false; }
	sf::Vector2f getCenterPosition(); 
	

};
sf::Vector2f Player:: getCenterPosition() {
	
	return sf::Vector2f(bounds.left+ bounds.width / 2, bounds.top +bounds.height/ 2);
}