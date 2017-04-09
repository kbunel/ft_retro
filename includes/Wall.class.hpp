
#ifndef WALL_CLASS_HPP
#define WALL_CLASS_HPP

#include "ft_retro.h"
#include "Entity.class.hpp"

class Wall: public Entity {

private:

void calculatePosition();

bool haut;

public:

Wall();
Wall(Wall const & game);
~Wall();

Wall & operator=(Wall const & src);

void init(int x, bool haut);
//void display();
void loop(Wall const & w);
void generate(Wall const & w);
};

#endif
