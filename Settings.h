#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
//îêíî
const float WINDOW_WIDTH = 800.f;
const float WINDOW_HEIGHT = 1000.f;
const std::string WINDOW_TITLE = "SFML RACING";
const float FPS = 60;
const float PLAYER_SPEED = 5.f;
std::string PLAYER_FILE_NAME = "image\\playerShip3_green.png";
const size_t METEOR_QTY = 20;
const std::string IMAGES_FOLDER = "image\\";
const std::string RES_FOLDER = "res\\";
const std::string FONT_FILE_NAME = "ds-digib.ttf";
const size_t CHAR_SIZE = 32;
std::string LASER_FILE_NAME = "image\\laserRed01.png";
sf::Vector2f LIFES_POS = sf::Vector2f{ WINDOW_WIDTH / 2,0.f };
sf::Vector2f SCORE_POS = sf::Vector2f{ 0.f,0.f };
const float BONUS_SPEED = 5.f;
const int BONUS_RANGE = 10000;
const int BONUS_CHANCE = 500;
std::string MULTI_LASER_BONUS_FILE_NAME = "things_gold.png";
std::string HP_BONUS_FILE_NAME = "bolt_gold.png";
std::string SHIELD_BONUS_FILE_NAME = "shield_gold.png";