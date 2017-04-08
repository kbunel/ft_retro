#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "ft_retro.h"
#include "Wall.class.hpp"

#define MAX_SHIP_ENEMY 10

#define SIZE_INTERFACE 5

#define FPS 120

class Game {

private:

bool stop;
int usq;

Entity test;

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