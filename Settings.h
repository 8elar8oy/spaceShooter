#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
//îêíî
const float WINDOW_WIDTH = 800.f;
const float WINDOW_HEIGHT = 1000.f;
const std::string WINDOW_TITLE = "SFML RACING";
const float FPS = 60;
const float PLAYER_SPEED = 5.f;
std::string PLAYER_FILE_NAME = "png\\playerShip3_green.png";
const float posx_arr[]{ (0.f),(100.f) ,(200.f), (300.f),(400.f),(500.f),(600.f),(700.f) };
const float posy_arr[]{ (-200.f),(-400.f) ,(-600.f), (-800.f) };
const Vector2f MeteorPos(posx_arr[rand() % 4], posy_arr[rand() % 4]);