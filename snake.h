#ifndef _snake_h
#define _snake_h


#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <vector>
#include <semaphore.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/time.h>
#include <ctime>
#include "index.h"

using namespace std;

class snake
{
public:
    snake();
    void update_head(void);
    void update_body(void);
    void get_direction(void);
    bool food_eaten;
    int head_position_x, head_position_y;
    int food_position_x, food_position_y;
    vector<int> body_x, body_y;
    void initialize_matrix(void);
    int score;
    bool is_dead;
private:
    int head_position_x_old, head_position_y_old;
    char direction;

};

void changemode(int dir);
int kbhit (void);

#endif