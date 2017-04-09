
#include "../includes/MenuStar.class.hpp"

MenuStar::MenuStar(void) {

	this->x = Game::width;
	this->y = 0;
	this->activated = false;
}

MenuStar::MenuStar(MenuStar const & src)
{
  *this = src;
}

MenuStar::~MenuStar()
{
}

MenuStar & 		MenuStar::operator=(MenuStar const & rhs)
{
  (void)rhs;
  return *this;
}

void MenuStar::loop()
{
	this->x -= 1;
	if (this->x == 0)
		this->activated = false;
	mvprintw(this->y, this->x, "*");
}

void MenuStar::activate()
{
	this->activated = true;
	this->y = std::rand() % Game::height;
	this->x = Game::width;
}

bool MenuStar::isActivated()
{
	return this->activated;
}