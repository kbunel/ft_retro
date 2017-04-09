#include "../includes/Player.class.hpp"
#include "../includes/Enemy.class.hpp"
#include "../includes/Game.class.hpp"


Enemy::Enemy( void ) {
	this->init(30, Game::height / 2, 1, "enemy.file" );
	this->activated = false;
	return;
}

Enemy::Enemy( Enemy const & enemy ) {
	*this = enemy;
	return;
}

Enemy::~Enemy( void ) {
	return;
}

void 				Enemy::activateMissiles( void ) {
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

void				Enemy::loop( void ) {
	int			i = 0;

	if (this->activated) {
		this->moveLeft();
		while (i < ENEMIES_MISSILES)
			missiles[i++].loop( ENEMY );
	}
}

void				Enemy::repop( void ) {
	Game::map->addReference(*this, NULL);
	this->x1 += Game::width + 10;
	this->x2 += Game::width + 10;
	this->life = 1;
}

void 				Enemy::moveUp( void ) {
	Game::map->addReference(*this, NULL);
	if (this->y1 > 0) {
		this->y1 -= 1;
		this->y2 -= 1;
	}
	if (this->checkColision())
		this->repop();
	Game::map->addReference(*this, this);
}

void 				Enemy::moveLeft( void ) {
	Game::map->addReference(*this, NULL);
	if (this->x2 < 0) {
		this->repop();
	}
	else {
		this->x1 -= 1;
		this->x2 -= 1;
		if (this->checkColision())
			this->repop();
		Game::map->addReference(*this, this);
	}
}

void 				Enemy::moveRight( void ) {
	Game::map->addReference(*this, NULL);
	if (this->x2 < Game::width - 1) {
		this->x1 += 1;
		this->x2 += 1;
	}
	if (this->checkColision())
		this->repop();
	Game::map->addReference(*this, this);
}

void 				Enemy::moveDown( void ) {
	Game::map->addReference(*this, NULL);
	if (this->y2 < Game::height - 1) {
		this->y1 += 1;
		this->y2 += 1;
	}
	if (this->checkColision())
		this->repop();
	Game::map->addReference(*this, this);
}

MissileInline*		Enemy::getMissiles( void ) {
	return this->missiles;
}

Enemy &				Enemy::operator=( Enemy const & rhs ) {
	this->init(rhs.x1, rhs.x2, rhs.y1, rhs.y2, rhs.life, 'D');
	return *this;
}
