#include <stdio.h>
#include <library.h>
#include <pthread.h>

Ball ball;
Player player;
Player ennemy;
int speed = 22;

int key;

void *manageKeyboard(){
    while(1){
        key = getch();
        if (key == 'q' || key == 'Q') {
            break;
        }
    }
    return EXIT_SUCCESS;
}

int main() {
    initBall(&ball);
    initPlayer(&player);
    initEnnemy(&ennemy);
    
    clear();
    render(player, ennemy, ball);

    pthread_t keyboardManager;
    pthread_create(&keyboardManager, NULL, manageKeyboard, NULL);
    bool mvVert = true;
    while (1)
    {
        render(player, ennemy, ball);
        Sleep(speed);
        clean(player, ennemy, ball);
        if (key == 's')
        {
            if ((player.y + player.sizeY) < getWindowHeight())
            {
                player.y++;
            }
            key = '\0';
        }
        else if (key == 'z')
        {
            if (player.y > 0)
            {
                player.y--;
            }
            key = '\0';
        }
        if (key == 'q' || key == 'Q') {
            break;
        }
        //
        if (ball.moveHor == true)
        {
            ball.x++;
        }
        else
        {
            ball.x--;
        }
        //
        if (mvVert)
        {
            if (ball.moveVer == true)
            {
                ball.y--;
            }
            else
            {
                ball.y++;
            }
            mvVert = false;
        }
        else
        {
            mvVert = true;
        }
        
        //rebonds horizontales
        if (ball.x >= getWindowWidth())
        {
            ball.moveHor = false;
            speed--;
        }
        else if (ball.x <= 0 + player.sizeX)
        {
            if (ball.y >= player.y && ball.y <= (player.y + player.sizeY))
            {
                ball.moveHor = true;
                speed--;
            }
            else
            {
                break;
            }
        }
        //rebonds verticales
        if (ball.y >= getWindowHeight())
        {
            ball.moveVer = true;
        }
        else if (ball.y <= 0)
        {
            ball.moveVer = false;
        }
    }
    clear();
    printf("\033[H");

    return EXIT_SUCCESS;
}