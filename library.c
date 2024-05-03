#include <library.h>

int getWindowWidth(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    // Obtention du handle de la console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if (hConsole == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Erreur lors de l'obtention du handle de la console\n");
        return 1;
    }
    
    // Obtention des informations sur le buffer d'écran de la console
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        fprintf(stderr, "Erreur lors de l'obtention des informations sur le buffer d'écran de la console\n");
        return 1;
    }

    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getWindowHeight(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    // Obtention du handle de la console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if (hConsole == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Erreur lors de l'obtention du handle de la console\n");
        return 1;
    }
    
    // Obtention des informations sur le buffer d'écran de la console
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        fprintf(stderr, "Erreur lors de l'obtention des informations sur le buffer d'écran de la console\n");
        return 1;
    }

    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void initBall(Ball *ball){
    ball->x = getWindowWidth() / 2;
    ball->y = getWindowHeight() / 2;

    ball->moveHor = true;
    ball->moveVer = false;
}

void initPlayer(Player *player){
    player->sizeX = PLAYER_WIDTH;
    player->sizeY = PLAYER_HEIGHT;

    player->x = 0;
    player->y = (getWindowHeight() / 2) - (player->sizeY / 2);
}

void initEnnemy(Player *ennemy){
    ennemy->sizeX = PLAYER_WIDTH;
    ennemy->sizeY = PLAYER_HEIGHT;

    ennemy->x = getWindowWidth() - ennemy->sizeX;
    ennemy->y = (getWindowHeight() / 2) - (ennemy->sizeY / 2);
}

void clear(){
    printf("\033[2J");
}

void render(Player player, Player ennemy, Ball ball){
    printf("\033[0;47m");
    //render ball
    printf("\033[%d;%dH ", ball.y, ball.x);
    //render player
    printf("\033[%d;%dH", player.y, player.x);
    for (int i = 0; i < player.sizeY; i++)
    {
        for (int j = 0; j < player.sizeX; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    //render ennemy
    printf("\033[%d;%dH", ennemy.y, ennemy.x);
    for (int i = 0; i < ennemy.sizeY; i++)
    {
        for (int j = 0; j < ennemy.sizeX; j++)
        {
            printf(" ");
        }
        printf("\033[%d;%dH", ennemy.y + i, ennemy.x);
    }
    for (int i = 0; i < ennemy.sizeX; i++)
    {
        printf(" ");
    }
    printf("\033[0;00m");
}

void clean(Player player, Player ennemy, Ball ball){
    //render ball
    printf("\033[%d;%dH ", ball.y, ball.x);
    //render player
    printf("\033[%d;%dH", player.y, player.x);
    for (int i = 0; i < player.sizeY; i++)
    {
        for (int j = 0; j < player.sizeX; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    //render ennemy
    printf("\033[%d;%dH", ennemy.y, ennemy.x);
    for (int i = 0; i < ennemy.sizeY; i++)
    {
        for (int j = 0; j < ennemy.sizeX; j++)
        {
            printf(" ");
        }
        printf("\033[%d;%dH", ennemy.y + i, ennemy.x);
    }
    printf("  ");
}