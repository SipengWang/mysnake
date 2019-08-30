#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "index.h"
#include "map.h"
#include "snake.h"

using namespace std;


void start_game(void)
{
    snake _snake;
    map _map(&_snake);

    cout << "************INSTRUSTION************" << endl;
    cout << "Use W,A,S,D to control the direction" << endl;
    usleep(INSTRUCTION_SLEEP_TIME);
   

    while(1)
    {
        _map.redraw();
        if(_snake.is_dead)
        {
            cout << "Game Over!" << endl;
            break;
        }
        //usleep(SLEEP_TIME);
        //_snake.get_direction();
        //cout <<  _snake.food_position[0][1];
    }
}

int main()
{
    start_game();
    return 0;
}
