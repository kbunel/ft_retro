#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "ft_retro.h"

class Game {

private:

int x;
bool stop;

public:

Game();
~Game();
void input();
void loop();
void aff();

bool isStop();
};


#endif