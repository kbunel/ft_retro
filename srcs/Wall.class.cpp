
#include "../includes/Wall.class.hpp"
#include "../includes/Game.class.hpp"
#include <unistd.h>
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
	Entity::init(x, x, 0, 3, 99999, ' ');
}

void Wall::loop(Wall const & w)
{
	this->y1 = w.getY1();
	this->y2 = w.getY2();
	Entity::generateDispChars(' ');
}

void Wall::generate(Wall const & w)
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
	Entity::generateDispChars(' ');
}

void Wall::display()
{
	int			i = 0;
	int			j;
	Game::map->addReference(*this, NULL);
	while (i <= x2 - x1) {
		j = 0;
		while (j <= y2 - y1) {
			mvprintw( this->y1 + j, this->x1 + i, this->dispChars[i][j].c_str() );
			mvprintw( Game::height - j - SIZE_INTERFACE, this->x1 + i, this->dispChars[i][j].c_str() );
			mvprintw( Game::height - SIZE_INTERFACE, this->x1 + i, this->dispChars[i][j].c_str() );
			j++;
		}
		i++;
	}
	this->checkColision();
	Game::map->addReference(*this, this);
}
