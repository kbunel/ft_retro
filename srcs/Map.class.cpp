#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"
#include "../includes/Map.class.hpp"

Map::Map( void ) {
	int		i = 0;
	int		j;

	this->map = new Entity**[Game::width];
	while (i <= Game::width) {
		j = 0;
		this->map[i] = new Entity*[Game::height];
		while (j < Game::height)
			this->map[i][j++] = NULL;
		i++;
	}
	return;
}

Map::Map( Map const & map ) {
	*this = map;
	return;
}

Map::~Map( void ) {
	exit(1);
	return;
}

Map &			Map::operator=( Map const & rhs ) {
	this->map = rhs.map;
	return *this;
}

void			Map::addReference( Entity const & entity, Entity* ref ) {
	int			i = entity.getX1();
	int			j;

	while (i <= entity.getX2() && i >= 0 && i < Game::width) {
 		j = entity.getY1();
		while (j <= entity.getY2() && j >= 0 && j < Game::height) {
			this->map[i][j] = ref;
			j++;
		}
		i++;
	}
}

void					Map::loop( void ) {

}
