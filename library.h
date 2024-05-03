#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#define PLAYER_WIDTH 2
#define PLAYER_HEIGHT 5

struct Ball
{
    int x;
    int y;
    bool moveVer;
    bool moveHor;
};

struct Player
{
    int x;
    int y;
    int sizeX;
    int sizeY;
};

typedef struct Ball Ball;
typedef struct Player Player;

int getWindowWidth();
int getWindowHeight();

void initBall(Ball *ball);
void initPlayer(Player *player);
void initEnnemy(Player *ennemy);

void clear();
void render(Player player, Player ennemy, Ball ball);
void clean(Player player, Player ennemy, Ball ball);