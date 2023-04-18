
#pragma once
#include "settings.h"
#include "player.h"
#include "meteor.h"
#include <vector>
#include "Lives.h"
#include "bonus.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<Meteor*> meteorSprites;
	TextObj score;
	sf::RectangleShape rect;
	std::list<Bonus*> bonusSprites;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		player.update();
		for (auto& m : meteorSprites) {
			m->update();
		}
		score.update(std::to_string(player.getScore()));
		for (auto& bonus : bonusSprites) {
			bonus->update();
		}
	}

	void checkCollisions() {
		sf::FloatRect shieldHitBox = player.getShieldHitBox();
		sf::FloatRect playerHitBox = player.getHitBox();
		auto laserSprites = player.getLasers();
		for (auto& meteor : meteorSprites) {


			sf::FloatRect meteorHitBox = meteor->getHitBox();
			if (player.ShieldIsActive()) {
				if (meteorHitBox.intersects(shieldHitBox)) {
					meteor->spawn();
					player.decreaseShieldMargin();
				}

			}
			if (meteorHitBox.intersects(playerHitBox)) {
				meteor->spawn();
				player.receiveDamage(meteor->getDamage());
				
			}

			for (auto& laser : (*laserSprites)) {
				sf::FloatRect laserHitBox = laser->getHitBox();

				if (laserHitBox.intersects(meteorHitBox)) {

					meteor->spawn();
					player.incScore(meteor->getDamage());
					laser->setHit();
					int chance = rand() % BONUS_RANGE;
					int BonusType = rand() % Bonus::BonusType::BONUSES_TYPE;
					if (chance < BONUS_CHANCE) {
						Bonus* bonus = new Bonus(((Bonus::BonusType)BonusType), meteor->getPosition());
						bonusSprites.push_back(bonus);
					}
				}
			}

			for (auto& bonus : bonusSprites) {
				sf::FloatRect bonusHitBox = bonus->getHitBox();
				if (bonusHitBox.intersects(playerHitBox)) {
					bonus->act(player);
					bonus->setDel();
				}
			}
		}
		(*laserSprites).remove_if([](Laser* laser) {return laser->isHited(); });
		(*laserSprites).remove_if([](Laser* laser) {return laser->offScreen(); });
		bonusSprites.remove_if([](Bonus* bonus) {return bonus->offScreen(); });
		bonusSprites.remove_if([](Bonus* bonus) {return bonus->isToDel(); });
	}

	void draw() {
		window.clear();
		for (auto m : meteorSprites) {
			window.draw(m->getSprite());
		}
		window.draw(rect);
		player.draw(window);
		window.draw(score.getText());
		for (auto& bonus : bonusSprites) {
			bonus->draw(window);
		}

		window.display();
	}

public:
	Game() :
		window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
		score(std::to_string(player.getScore()), sf::Vector2f{ WINDOW_WIDTH / 2,0.f })
	{
		window.setFramerateLimit(FPS);
		meteorSprites.reserve(METEOR_QTY);
		for (int i = 0; i < METEOR_QTY; i++) {
			meteorSprites.push_back(new Meteor());
		}
		rect.setFillColor(sf::Color::Green);
		rect.setSize(sf::Vector2f{ WINDOW_WIDTH, 40.f });
	}

	void play() {
		while (window.isOpen() && player.isAlive())
		{
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
};