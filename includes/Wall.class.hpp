
#ifndef WALL_CLASS_HPP
#define WALL_CLASS_HPP

#include "ft_retro.h"
#include "Entity.class.hpp"

class Wall: public Entity {

private:



public:

Wall();
Wall(Wall const & game);
~Wall();

Wall & operator=(Wall const & src);


};

#endif