#include "snake.h"

using namespace std;


void changemode(int dir)
{
    static struct termios oldt, newt;
 
    if ( dir == 1 )
    {
        tcgetattr( STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    }
    else
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
 
int kbhit (void)
{
    struct timeval tv;
    fd_set rdfs;
 
    tv.tv_sec = 0;
    tv.tv_usec = 0;
 
    FD_ZERO(&rdfs);
    FD_SET (STDIN_FILENO, &rdfs);
 
    select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
}

snake::snake()
{

    head_position_x = 10;
    head_position_y = 10;
    head_position_x_old = 0;
    head_position_y_old = 0;
    food_position_x = 15;
    food_position_y = 15;
    body_x = {9};
    body_y = {10};
    score = 0;
    is_dead = false;
    direction = 'd';

}


void snake::update_head(void)
{

    head_position_x_old = head_position_x;
    head_position_y_old = head_position_y;

    get_direction();

    switch (direction)
    {
    case 'w':
        head_position_y--;
        break;
    case 's':
        head_position_y++;
        break;
    case 'a':
        head_position_x--;
        break;
    case 'd':
        head_position_x++;
        break;
    
    default:
        break;
    }

    if((head_position_x == food_position_x) && (head_position_y == food_position_y))
    {
        food_eaten = true;
        score++;
    }
    else 
    food_eaten = false;

}

void snake::update_body()
{

    body_x.push_back(head_position_x_old);
    body_y.push_back(head_position_y_old);

    if(!food_eaten)
    {
        body_x.erase(body_x.begin());
        body_y.erase(body_y.begin());
    }   
    
}

void snake::get_direction()
{  

    clock_t start;
    start = clock();
    changemode(1); 
    while (clock() - start < SLEEP_TIME)
    {
        if(kbhit())
        {
            direction = getchar();
        }
    }
    changemode(0);   
}

