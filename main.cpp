#include <iostream>
#include "raylib.h"
#include "Application.h"

int main() {
    std::cout << "Starting the game!" << std::endl;
    auto* app = new Application();
    while (!WindowShouldClose()) {
       app->run(); 
    }
    CloseWindow();
    return 0;
}
