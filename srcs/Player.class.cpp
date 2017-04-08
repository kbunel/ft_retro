#include "../includes/Player.class.hpp"

Player::Player( void ) {
	this->init(2, 4, Game::height / 2 - 2, Game::height / 2 + 2, 100, 'D' );
	return;
}

Player::Player( Player const & player ) {
	*this = player;
	return;
}

Player::~Player( void ) {
	return;
}

void				Player::shoot( void ) {
	
}

Player &			Player::operator=( Player const & rhs ) {
	this->init(rhs.x1, rhs.x2, rhs.y1, rhs.y2, rhs.life, 'D');
	return *this;
}
