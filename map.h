#ifndef _map_h
#define _map_h

#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "snake.h"
#include "index.h"

class map
{
public:
    map(snake *_snake);
    void redraw(void);
    void updatesnake(snake *_snake);
    void updatefood(snake *_snake);
    char map_array[MAP_HEIGHT][MAP_LENGTH];

private:
    snake *_snake;

};


#endif