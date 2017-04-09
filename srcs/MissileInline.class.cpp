#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"
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
	this->init(x, x + 3, y, y, 1, '*');
}

void					MissileInline::loop( int from ) {
	Game::map->addReference(*this, NULL);
	if (this->checkColision() == true || this->life <= 0)
		this->activated = false;
	else {
		if (from == PLAYER) {
			if (this->x1 <= Game::width && this->activated) {
				this->x1++;
				this->x2++;
				if (this->checkColision())
					this->activated = false;
				Game::map->addReference(*this, this);
			}
			else
				this->activated = false;
		}
		else if (from == ENEMY ) {
			if (this->x2 > 0 && this->activated) {
				this->x1++;
				this->x2++;
				if (this->checkColision())
					this->activated = false;
				Game::map->addReference(*this, this);
			}
			else
				this->activated = false;
		}
	}
}
