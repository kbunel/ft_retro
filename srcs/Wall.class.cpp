
#include "../includes/Wall.class.hpp"
#include "../includes/Game.class.hpp"

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

void Wall::init(int x)
{
	Entity::init(x, x, 0, 2, 99999, 'q');
}

void Wall::move(Wall w)
{
	Entity::init(0, 0, 0, 2, 99999, 'a');
	int rand = std::rand() % 2;
	this->x1 = w.getX1()+1;
	this->x2 = w.getX2()+1;
	this->y1 = w.getY1();
	if (rand)
		this->y2 = w.getY2() + 1;
	else
		this->y2 = w.getY2() - 1;
}