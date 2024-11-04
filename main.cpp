#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "CpuPaddle.h"
#include "Paddle.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;

Ball ball(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
Paddle paddle;
CpuPaddle cpuPaddle;

int player_score = ball.getPlayerScore();
int cpu_score = ball.getCpuScore();
int main() {
    std::cout << "Starting the game!" << std::endl;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong game");
    SetTargetFPS(60);

    ball.setRadius(20);
    ball.setSpeed(7, 7);

    paddle.setSize(25, 120);
    paddle.setPosition(SCREEN_WIDTH - paddle.getWidth() -10, (SCREEN_HEIGHT/2) - (paddle.getHeight()/2));
    paddle.setSpeed(6);

    cpuPaddle.setSize(25, 120);
    cpuPaddle.setPosition(10, SCREEN_HEIGHT / 2 - cpuPaddle.getHeight() / 2);
    cpuPaddle.setSpeed(6);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ball.Update();
        paddle.Update();
        cpuPaddle.Update(ball.getBallY());

        if(CheckCollisionCircleRec(
            Vector2{ball.getBallX(), ball.getBallY()},
            ball.getBallRadius(),
            Rectangle{paddle.getX(), paddle.getY(), paddle.getWidth(), paddle.getHeight()}
            ))
        {
            ball.setSpeed_x();
        };
        if (CheckCollisionCircleRec(
            Vector2{ball.getBallX(), ball.getBallY()},
            ball.getBallRadius(),
            Rectangle{cpuPaddle.getX(), cpuPaddle.getY(), cpuPaddle.getWidth(), cpuPaddle.getHeight()}
        )) {
            ball.setSpeed_x();
        };

        ClearBackground(BLACK);
        DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
        ball.Draw();
        paddle.Draw();
        cpuPaddle.Draw();
        DrawText(TextFormat("%i", cpu_score), SCREEN_WIDTH/4 -20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3*SCREEN_WIDTH/4 -20, 20, 80, WHITE);
        player_score = ball.getPlayerScore();
        cpu_score = ball.getCpuScore();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
