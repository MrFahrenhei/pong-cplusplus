#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;

class Application{
    public:
        Application();
        void run();
        void colideBall();
        void colideCPUBall();
        void drawing();
        void renderScore();
    private:
        Ball ball;
        Paddle paddle;
        CpuPaddle cpuPaddle;
        int player_score{};
        int cpu_score{};
        void loadBall();
        void loadPaddle();
        void loadCPUPaddle();
};
