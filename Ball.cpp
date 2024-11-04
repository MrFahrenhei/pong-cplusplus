//
// Created by vvberaldo on 03/11/24.
//

#include "Ball.h"

Ball::Ball(const float x, const float y) {
    this->x = x;
    this->y = y;
}

void Ball::setSpeed(const int speed_x, const int speed_y) {
    this->speed_x = speed_x;
    this->speed_y = speed_y;
}

void Ball::setSpeed_x() {
    this->speed_x *=-1;
}


void Ball::Draw() const {
    DrawCircle(x, y, radius, WHITE);
}

void Ball::setRadius(int radius) {
    this->radius = radius;
}

void Ball::resetBall() {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speed_choices[2] = {-1, 1};
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
}


void Ball::checkCollision() {
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth()) {
        cpuScore++;
        resetBall();
    }
    if(x - radius <= 0) {
        playerScore++;
        resetBall();
    }
}

void Ball::Update() {
    x += speed_x;
    y += speed_y;
    checkCollision();
}
float Ball::getBallY() const {
   return y;
}

float Ball::getBallX() const {
    return x;
}

float Ball::getBallRadius() const {
    return radius;
}

int Ball::getCpuScore() const {
   return cpuScore;
}
int Ball::getPlayerScore() const {
   return playerScore;
}

