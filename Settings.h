﻿#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "SFML Space Shooter P33122";
const float FPS = 60.f;

const std::string IMAGES_FOLDER = "image\\";

const std::string PLAYER_FILE_NAME = "playerShip3_green.png";
const float PLAYER_SPEED = 10.f;
const int INITIAL_PLAYER_HP = 100;
const int FIRE_COOLDOWN = 200;

const int METEOR_TYPES_QTY = 8;
const size_t METEOR_QTY = 20;

const std::string RES_FOLDER = "res\\";
const std::string FONT_FILE_NAME = "ds-digib.ttf";
const size_t CHAR_SIZE = 32;

const std::string LASER_FILE_NAME = "laserRed01.png";

const float BONUS_SPEED = 10.f;
const int BONUS_RANGE = 10000;
const int BONUS_CHANCE = 1500;

const std::string MULTI_LASER_BONUS_FILE_NAME = "things_gold.png";
std::string HP_BONUS_FILE_NAME = "pill_red.png";
std::string SHIELD_BONUS_FILE_NAME = "shield_gold.png";
std::string SHIELD_FILE_NAME = "shield3.png";
const size_t THREE_LASERS_BONUS_DURATION{ 5000 };
const size_t SHIELD_MARGIN{ 10 };