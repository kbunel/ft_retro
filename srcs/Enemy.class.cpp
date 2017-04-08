#include "../includes/Player.class.hpp"
#include "../includes/Enemy.class.hpp"
#include "../includes/Game.class.hpp"

Enemy::Enemy( void ) {
	return;
}

Enemy::Enemy( Enemy const & enemy ) {
	*this = enemy;
	return;
}

Enemy::~Enemy( void ) {
	return;
}

Enemy &			Enemy::operator=( Enemy const & rhs ) {
	this->init(rhs.x1, rhs.x2, rhs.y1, rhs.y2, rhs.life, 'D');
	return *this;
}
