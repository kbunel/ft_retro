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

	this->display();
	while (i < MAX_MISSILES_IN_SLOT)
			missiles[i++].loop();
}

void 				Player::moveUp( void ) {
	if (this->y1 > 0) {
		this->y1 -= 1;
		this->y2 -= 1;
	}
}

void 				Player::moveLeft( void ) {
	if (this->x1 > 1) {
		this->x1 -= 1;
		this->x2 -= 1;
	}
}

void 				Player::moveRight( void ) {
	if (this->x2 < Game::width - 1) {
		this->x1 += 1;
		this->x2 += 1;
	}
}

void 				Player::moveDown( void ) {
	if (this->y2 < Game::height - 1) {
		this->y1 += 1;
		this->y2 += 1;
	}
}

Player &			Player::operator=( Player const & rhs ) {
	this->init(rhs.x1, rhs.x2, rhs.y1, rhs.y2, rhs.life, 'D');
	return *this;
}
