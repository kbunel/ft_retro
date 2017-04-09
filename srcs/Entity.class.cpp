#include "../includes/Entity.class.hpp"
#include "../includes/Map.class.hpp"
#include "../includes/Game.class.hpp"
#include <unistd.h>

Entity::Entity( void ) {
	std::stringstream  	address;

	address << this;
	this->init(-1, -1, -1, -1, 0, ' ');
	this->address = address.str();
	Game::map->addReference(*this, this->address);
	return;
}

Entity::Entity( int x1, int x2, int y1, int y2, int life, char dispChar ) {
	std::stringstream  	address;

	address << this;
	this->init(x1, x2, y1, y2, life, dispChar);
	this->address = address.str();
	return;
}

Entity::~Entity() {
	return;
}

void		Entity::loop( void ) {
	
}

void		Entity::display( void ) {
int			i = 0;
	int			j;
		
	while (i <= y2 - y1 - 1) {
		j = 0;
		while (j <= x2 - x1 - 1) {
			mvprintw( this->y1 + i, this->x1 + j, this->dispChars[i][j].c_str() );
			j++;
		}
		i++;
	}
}

bool		Entity::checkColision( void ) {
	int		i = this->x1;
	int		j;
	
	while (i < this->x2 && i >= 0 && i < Game::width) {
		j = this->y1;
		while (j < this->y2 && j >= 0 && j < Game::height) {
			if (Game::map->map[i][j] != "X" && Game::map->map[i][j] != this->address)
				exit(1);
			j++;
		}
		i++;
	}
	return false;
}

void		Entity::init( int x1, int x2, int y1, int y2, int life, char dispChar) {
	this->x1 		= x1;
	this->x2 		= x2;
	this->y1 		= y1;
	this->y2 		= y2;
	this->life	 	= life;
	this->generateDispChars(dispChar);
}

void		Entity::init( int x, int y, int life, std::string file) {
	std::ifstream fichier(file, std::ios::in);

	this->x1 = x;
	this->y1 = y;
	this->y2 = y;
	this->x2 = 0;

	if (fichier)
	{
		std::string line;
		while (std::getline(fichier, line))
		{
			this->y2++;
			if (this->x2 != 0 && this->x2 != (int)(x + std::strlen(line.c_str())))
			{
				Game::error("Erreur de format d'un fichier d'entitee");
			}
			this->x2 = x + std::strlen(line.c_str());
		}
		fichier.close();
	}
	int i = 0;
	int j;
 	std::ifstream fichier2(file, std::ios::in);
	if (fichier2)
	{
		this->dispChars = new std::string*[this->y2 - this->y1];
		std::string line;
		while (std::getline(fichier2, line))
		{
			j = 0;
			dispChars[i] = new std::string[this->x2 - this->x1];
			while (j <= this->x2 - this->x1) {
				dispChars[i][j] = line[j];
			    j++;
			}
			i++;
		}
		fichier2.close();
	}
	this->life	 	= life;
}


void Entity::generateDispChars(char dispChar)
{
	int				i = 0;
	int				j;

	this->dispChars = new std::string*[this->y2 - this->y1 + 1];
	while (i <= this->y2 - this->y1) {
		j = 0;
		dispChars[i] = new std::string[this->x2 - this->x1 + 1];
		while (j <= this->x2 - this->x1) {
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