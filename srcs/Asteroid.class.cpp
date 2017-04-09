#include "../includes/Player.class.hpp"
#include "../includes/Asteroid.class.hpp"
#include "../includes/Game.class.hpp"


Asteroid::Asteroid( void ) {
	this->init(30, Game::height / 2, 1, "Asteroid.file" );
	this->activated = false;
	return;
}

Asteroid::Asteroid( Asteroid const & Asteroid ) {
	*this = Asteroid;
	return;
}

Asteroid::~Asteroid( void ) {
	return;
}

void				Asteroid::loop( void ) {
	if (this->isActivated())
		this->moveLeft();
}

void				Asteroid::repop( void ) {
	int rand = std::rand() % (int)(Game::height - 10);
	this->y1 = 5 + rand;
	this->y2 = 5 + rand;
	this->x1 = Game::width;
	this->x2 = Game::width;
	this->activated = true;	
}

void 				Asteroid::moveLeft( void ) {
	if (this->x2 < 0) {
		this->activated = false;
	}
	else {
		this->x1 -= 1;
		this->x2 -= 1;
	}
}

Asteroid &			Asteroid::operator=( Asteroid const & rhs ) {
	this->init(rhs.x1, rhs.x2, rhs.y1, rhs.y2, rhs.life, 'D');
	return *this;
}

bool				Asteroid::isActivated()
{
	return this->activated;
}