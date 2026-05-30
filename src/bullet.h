#ifndef _BULLET_H
#define _BULLET_H

#include "constants.h"
#include "raylib.h"

typedef struct {
        Vector2 pos;
        Color color;
        int speed;
        int width;
        int height;
        bool active;
} Bullet;

void InitBullet(Bullet *bullet);
void DrawBullet(Bullet bullet);
void UpdateBullet(Bullet *bullet, float dt);

extern Bullet bulletPool[MAX_BULLETS];

#endif // _BULLET_H
