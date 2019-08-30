#include "map.h"


using namespace std;

map::map(snake *_snake)
{
    this->_snake = _snake;
}


void map::redraw(void)
{
    int i, j;

    for(i = 0; i < MAP_HEIGHT; i++)
    for(j = 0; j < MAP_LENGTH; j++)
         map_array[i][j] = MAP_CHAR;


    updatesnake(_snake);
    updatefood(_snake);


    for ( i = 0; i < MAP_HEIGHT; i++)
    {
        for(j = 0; j < MAP_LENGTH; j++)
        {
            cout << map_array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Score = " << _snake->score << endl;
    
}

void map::updatesnake(snake* _snake)
{

    _snake->update_head();
    map_array[_snake->head_position_y][_snake->head_position_x] = SNAKE_HEAD;
    
    _snake->update_body();

    for (int i = 0; i < _snake->body_x.size(); i++)
    {
        map_array[_snake->body_y[i]][_snake->body_x[i]] = SNAKE_BODY;


        if(_snake->head_position_y > MAP_HEIGHT - 1 || _snake->head_position_y < 0 || 
           _snake->head_position_x > MAP_LENGTH - 1 || _snake->head_position_x < 0 ||
           (_snake->head_position_y == _snake->body_y[i] && _snake->head_position_x == _snake->body_x[i]) )
           _snake->is_dead = true;

    }
    


}

void map::updatefood(snake *_snake)
{
    if(_snake->food_eaten)
    while(1)
    {
        _snake->food_position_x = rand() % MAP_LENGTH;
        _snake->food_position_y = rand() % MAP_HEIGHT;


        if(map_array[_snake->food_position_y][_snake->food_position_x] == MAP_CHAR)
        {
            break;
        }
    }

        map_array[_snake->food_position_y][_snake->food_position_x] = FOOD_CHAR;
    
}