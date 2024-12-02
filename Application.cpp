#include "Application.h"

Application::Application() {
    Ball ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Paddle paddle;
    CpuPaddle cpuPaddle;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong game");
    SetTargetFPS(60);
    loadBall();
    loadPaddle();
    loadCPUPaddle();
}

void Application::run()
{
    BeginDrawing();
    ball.Update();
    paddle.Update();
    cpuPaddle.Update(ball.getBallY());
    colideBall();
    colideCPUBall();
    ClearBackground(BLACK);
    drawing();
    renderScore();
}

void Application::loadBall()
{
    ball.setRadius(20);
    ball.setSpeed(7, 7);
}
void Application::loadPaddle()
{
    paddle.setSize(25, 120);
    paddle.setPosition(SCREEN_WIDTH - paddle.getWidth() - 10, (SCREEN_HEIGHT / 2) - (paddle.getHeight() / 2));
    paddle.setSpeed(6);
}
void Application::loadCPUPaddle()
{
    cpuPaddle.setSize(25, 120);
    cpuPaddle.setPosition(10, SCREEN_HEIGHT / 2 - cpuPaddle.getHeight() / 2);
    cpuPaddle.setSpeed(6);
}

void Application::colideBall()
{
    if (CheckCollisionCircleRec(
            Vector2{ball.getBallX(), ball.getBallY()},
            ball.getBallRadius(),
            Rectangle{paddle.getX(), paddle.getY(), paddle.getWidth(), paddle.getHeight()}))
    {
        ball.setSpeed_x();
    };
}
void Application::colideCPUBall()
{
    if (CheckCollisionCircleRec(
            Vector2{ball.getBallX(), ball.getBallY()},
            ball.getBallRadius(),
            Rectangle{cpuPaddle.getX(), cpuPaddle.getY(), cpuPaddle.getWidth(), cpuPaddle.getHeight()}))
    {
        ball.setSpeed_x();
    };
}

void Application::drawing()
{
    DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
    ball.Draw();
    paddle.Draw();
    cpuPaddle.Draw();
    DrawText(TextFormat("%i", cpu_score), SCREEN_WIDTH / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player_score), 3 * SCREEN_WIDTH / 4 - 20, 20, 80, WHITE);
    EndDrawing();
}

void Application::renderScore(){
    this->player_score = ball.getPlayerScore();
    this->cpu_score = ball.getCpuScore();

}