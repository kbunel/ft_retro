#include "../includes/Entity.class.hpp"

Entity::Entity( int x1, int x2, int y1, int y2, int life ) : life(life), x1(x1), x2(x2), y1(y1), y2(y2) {

}

Entity::~Entity() {

}

void		Entity::loop( void ) {
	
}

void		Entity::display( void ) {
	
}

bool		Entity::checkColision( int x, int y) {
	return (x >= this->x1 && x <= this->x2 && y >= this->y1 && y <= this->y2);
}

int			Entity::getLife( void ) {
	return this->life;
}

int			Entity::getX1( void ) {
	return this->x1;
}

int			Entity::getX2( void ) {
	return this->x2;
}

int			Entity::getY1( void ) {
	return this->y1;
}

int			Entity::getY2( void ) {
	return this->y2;
}

void		Entity::setX1( int x1) {
	this->x1 = x1;
}

void		Entity::setX2( int x2 ) {
	this->x2 = x2;
}

void		Entity::setY1( int y1) {
	this->y1 = y1;
}

void		Entity::setY2( int y2 ) {
	this->y2 = y2;
}
