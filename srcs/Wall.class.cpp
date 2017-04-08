
#include "../includes/Wall.class.hpp"

Wall::Wall()
{}

Wall::Wall(Wall const & src)
{
  *this = src;
}

Wall::~Wall()
{}

Wall & Wall::operator=(Wall const & rhs)
{
  (void)rhs;
  return *this;
}

/*Wall::init(Wall *w)
{
	if (w == NULL)
		Entity::init(int x1, int x2, int y1, int y2, int life, char dispChar);
	Entity::init();
}*/