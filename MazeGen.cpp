#include "raylib.h"
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int gridSize = 25;

    InitWindow(screenWidth, screenHeight, "A* Random Maze");

    vector<Rectangle> walls;

    //generate random wall positions
    for (int i = 0; i < 100; ++i) //change i < (set number of walls)
    {
        Rectangle wall;

        wall.x = GetRandomValue(0, (screenWidth / gridSize) - 1) * gridSize;
        wall.y = GetRandomValue(0, (screenHeight / gridSize) - 1) * gridSize;
        wall.width = gridSize;
        wall.height = gridSize;

        walls.push_back(wall);
    }

    while (!WindowShouldClose()) 
    {

        //Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < walls.size(); ++i) 
        {
            DrawRectangleRec(walls[i], BLACK);
        }
     
        EndDrawing();
    }

    CloseWindow();

    return 0;
}