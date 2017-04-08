#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "ft_retro.h"
#include "Wall.class.hpp"

#define MAX_SHIPENEMY 10

#define MIN_SIZE_WALL 2
#define MAX_SIZE_WALL 20

#define SIZE_INTERFACE 5

#define FPS 120

class Game {

private:

int x;

bool stop;

//Player p;
//ShipEnemy ens[];
Wall *walls;

void initWall();

public:

static int width;
static int height;

Game();
Game(Game const & game);
~Game();

Game & operator=(Game const & src);

void input();
void loop();
void aff();


int getWidth();
int getHeight();
bool isStop();
};


#endif