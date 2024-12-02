#pragma once
#include "Paddle.h"

class CpuPaddle:public Paddle {
public:
    void Update(int ball_y) {
       if(y + height/2 > ball_y) {
            y = y - static_cast<float>(speed);
       }
        if(y + height/2 <= ball_y) {
            y = y + static_cast<float>(speed);
        }
        limitMovement();
    }
};