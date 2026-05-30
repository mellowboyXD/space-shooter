#include <stdio.h>

#include "bullet.h"
#include "constants.h"
#include "player.h"
#include "raylib.h"

void InitGameState(GameState *gameState);
void MainDraw(GameState gameState);
void MainUpdate(GameState *gameState, float dt);

Bullet bulletPool[MAX_BULLETS];

int main(void)
{
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter");
        SetTargetFPS(FPS);

        GameState gameState = { 0 };

        InitGameState(&gameState);

        while (!WindowShouldClose()) {
                float dt = GetFrameTime();
                MainDraw(gameState);
                MainUpdate(&gameState, dt);
        }

        CloseWindow();
        return 0;
}

void InitGameState(GameState *gameState)
{
        gameState->currentState = STATE_PLAY;
        InitPlayer(&gameState->player);
        for (int i = 0; i < MAX_BULLETS; i++)
                InitBullet(bulletPool + i);
}

void MainDraw(GameState gameState) 
{
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(0, 0);
        DrawPlayer(gameState.player);
        
        for (int i = 0; i < MAX_BULLETS; i++)
                DrawBullet(bulletPool[i]);

        EndDrawing();
}

void MainUpdate(GameState *gameState, float dt)
{
        UpdatePlayer(&gameState->player, dt);
        
        for (int i = 0; i < MAX_BULLETS; i++)
                UpdateBullet(bulletPool + i, dt);
}

