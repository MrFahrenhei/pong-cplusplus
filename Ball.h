//
// Created by vvberaldo on 03/11/24.
//

#ifndef BALL_H
#define BALL_H
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



#endif //BALL_H
