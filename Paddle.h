#pragma once
#include <raylib.h>
#include <iostream>
class Paddle {
protected:
    float x = 0, y = 0;
    float width = 0, height = 0;
    int speed = 0;
    void limitMovement();
public:
    void setSize(float width, float height);
    void setPosition(float x, float y);
    void setSpeed(int speed);
    void Draw() const;
    float getWidth() const;
    float getHeight() const;
    void Update();
    float getX() const;
    float getY() const;
};