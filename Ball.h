#pragma once
#include <raylib.h>

class Ball {
private:
    float x, y;
    int speed_x{}, speed_y{};
    int radius{};
    int playerScore = 0;
    int cpuScore = 0;
    void checkCollision();
    void resetBall();
public:
    Ball() = default;
    Ball(float x, float y);
    void setRadius(int radius);
    void setSpeed(int speed_x, int speed_y);
    void setSpeed_x();
    void Draw() const;
    void Update();
    float getBallY() const;
    float getBallX() const;
    float getBallRadius() const;
    int getPlayerScore() const;
    int getCpuScore() const;
};