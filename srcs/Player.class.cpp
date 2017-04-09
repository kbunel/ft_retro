#include "../includes/Player.class.hpp"
#include "../includes/Game.class.hpp"

Player::Player( void ) {
	this->init(3, Game::height / 2 - 1, 100, "test.file" );
	return;
}

Player::Player( Player const & player ) {
	*this = player;
	return;
}

Player::~Player( void ) {
	return;
}

void 				Player::activateMissiles( void ) {
	int			i = 0;
	while (i < MAX_MISSILES_IN_SLOT) {
		if (this->missiles[i].activated == false) {
			this->missiles[i].activated = true;
			this->missiles[i].initiate(this->x2 + 3, this->y1 + ((this->y2 - this->y1) / 2));
			break;
		}
		i++;
	}
}

void				Player::loop( void ) {
	int			i = 0;

	while (i < MAX_MISSILES_IN_SLOT)
			missiles[i++].loop( PLAYER );
}

void 				Player::moveUp( void ) {
	Game::map->addReference(*this, NULL);
	if (this->y1 > 0) {
		this->y1 -= 1;
		this->y2 -= 1;
	}
	this->checkColision();
	Game::map->addReference(*this, this);
}

void 				Player::moveLeft( void ) {
	Game::map->addReference(*this, NULL);
	if (this->x1 > 1) {
		this->x1 -= 1;
		this->x2 -= 1;
	}
	this->checkColision();
	Game::map->addReference(*this, this);
}

void 				Player::moveRight( void ) {
	Game::map->addReference(*this, NULL);
	if (this->x2 < Game::width - 1) {
		this->x1 += 1;
		this->x2 += 1;
	}
	this->checkColision();
	Game::map->addReference(*this, this);
}

void 				Player::moveDown( void ) {
	Game::map->addReference(*this, NULL);
	if (this->y2 < Game::height - 1) {
		this->y1 += 1;
		this->y2 += 1;
	}
	this->checkColision();
	Game::map->addReference(*this, this);
}

MissileInline*		Player::getMissiles( void ) {
	return this->missiles;
}

Player &			Player::operator=( Player const & rhs ) {
	this->init(rhs.x1, rhs.x2, rhs.y1, rhs.y2, rhs.life, 'D');
	return *this;
}
