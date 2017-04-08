#include "../includes/Entity.class.hpp"

Entity::Entity( void ) {
this->init(-1, -1, -1, -1, 0, ' ');
}

Entity::Entity( int x1, int x2, int y1, int y2, int life, char dispChar ) {
	this->init(x1, x2, y1, y2, life, dispChar);
}

Entity::~Entity() {

}

void		Entity::loop( void ) {
	
}

void		Entity::display( void ) {
	int			i = 0;
	int			j;
	while (i <= x2 - x1) {
		j = 0;
		while (j <= y2 - y1) {
			mvprintw( this->y1 + j, this->x1 + i, this->dispChars[i][j].c_str() );
			j++;
		}
		i++;
	}
}

bool		Entity::checkColision( int x, int y) {
	return (x >= this->x1 && x <= this->x2 && y >= this->y1 && y <= this->y2);
}

void		Entity::init( int x1, int x2, int y1, int y2, int life, char dispChar) {
	this->x1 		= x1;
	this->x2 		= x2;
	this->y1 		= y1;
	this->y2 		= y2;
	this->life	 	= life;
	int				i = 0;
	int				j;

	this->dispChars = new std::string*[this->x2 - this->x1 + 1];
	while (i <= x2 - x1) {
		j = 0;
		dispChars[i] = new std::string[this->y2 - this->y1 + 1];
		while (j <= y2 - y1) {
			dispChars[i][j] = dispChar;
			j++;
		}
		i++;
	}
}

int			Entity::getLife( void ) const {
	return this->life;
}

int			Entity::getX1( void ) const {
	return this->x1;
}

int			Entity::getX2( void ) const {
	return this->x2;
}

int			Entity::getY1( void ) const {
	return this->y1;
}

int			Entity::getY2( void ) const {
	return this->y2;
}

std::string**			Entity::getDispChars( void ) const {
	return this->dispChars;
}

Entity &			Entity::operator=( Entity const & rhs ) {
	this->x1 		= rhs.getX1();
	this->x2 		= rhs.getX2();
	this->y1 		= rhs.getY1();
	this->y2 		= rhs.getY2();
	this->life	 	= rhs.getLife();
	this->dispChars	= rhs.getDispChars();
	return *this;
}
