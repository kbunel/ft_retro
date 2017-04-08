#include "../includes/Game.class.hpp"
#include "../includes/ft_retro.h"
#include "../includes/MissileInline.class.hpp"

MissileInline::MissileInline( void ) : activated(false) {
	return;
}


MissileInline::MissileInline( MissileInline const & missileInliine ) {
	*this = missileInliine;
	return;
}

MissileInline::~MissileInline( void ) {
	return;
}

MissileInline &			MissileInline::operator=( MissileInline const & rhs ) {
	this->init(rhs.x1, rhs.x2, rhs.y1, rhs.y2, rhs.life, '=');
	return *this;
}

void					MissileInline::initiate( int x, int y ) {
	this->init(x, x + 3, y, y, 1, '=');
}

void					MissileInline::loop( void ) {
	if (this->x1 <= Game::width && this->activated) {
		this->display();
		this->x1++;
		this->x2++;
	}
	else
		this->activated = false;
}
