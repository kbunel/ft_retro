
#include "../includes/Wall.class.hpp"
#include "../includes/Game.class.hpp"
#include <unistd.h>
Wall::Wall( void ) {
	this->type = WALL;
}

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

void Wall::init(int x, bool haut)
{
	if (haut)
		Entity::init(x, x, 0, 3, 99999, '#');
	else
		Entity::init(x, x, Game::height - SIZE_INTERFACE-3, Game::height - SIZE_INTERFACE, 99999, '#');		
	this->haut = haut;
}

void Wall::loop(Wall const & w)
{
	this->checkColision();
	Game::map->addReference(*this, NULL);
	this->y1 = w.getY1();
	this->y2 = w.getY2();
	this->checkColision();
	Entity::generateDispChars('#');
	Game::map->addReference(*this, this);
}

void Wall::generate(Wall const & w)
{
	this->checkColision();
	if (haut)
	{
		int rand = std::rand() % 3;
		this->y1 = w.getY1();
		if (rand == 0)
		{
			if (this->y2 < Game::height / 2 - 15)
				this->y2 = w.getY2()+1;
		}
		else if (rand == 1)
		{
			if (this->y2 > 0)
				this->y2 = w.getY2() - 1;		
		}
		else
			this->y2 = w.getY2();		
	}
	else
	{
		int rand = std::rand() % 3;
		this->y2 = w.getY2();
		if (rand == 0)
		{
			if (this->y1 <= Game::height - SIZE_INTERFACE-3)
				this->y1 = w.getY1()+1;
		}
		else if (rand == 1)
		{
			if (this->y1 > Game::height / 2 + 10)
				this->y1 = w.getY1() - 1;
		}
		else
			this->y1 = w.getY1();		
	}
	this->checkColision();
	Entity::generateDispChars(' ');
}
