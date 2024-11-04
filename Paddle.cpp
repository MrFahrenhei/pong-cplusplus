//
// Created by vvberaldo on 03/11/24.
//

#include "Paddle.h"

void Paddle::Draw() const {
        DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::setSize(const float width, const float height) {
        this->width = width;
        this->height = height;
}

void Paddle::setPosition(const float x, const float y) {
        this->x = x;
        this->y = y;
}

float Paddle::getWidth() const {
       return width;
}

float Paddle::getHeight() const {
       return height;
}

float Paddle::getX() const {
    return x;
}

float Paddle::getY() const {
    return y;
}
void Paddle::setSpeed(const int speed) {
   this->speed = speed;
}

void Paddle::Update() {
    if (IsKeyDown(KEY_UP)) {
       y = y - speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
        y = y + speed;
    }
    limitMovement();
}

void Paddle::limitMovement() {
     if(y <= 0) {
        y=0;
    }
    if(y + height >= GetScreenHeight()) {
        y = GetScreenHeight() - height;
    }
}
