#ifndef MAP_H
#define MAP_H

#include "../includes/Entity.class.hpp"

class Map {

	public:
		Map( void );
		Map( Map const & missileInliine );
		~Map( void );

		void					addReference( Entity const & entity, Entity* ref );
		void					loop( void );
		
		Entity*					**map;

	private:

		Map & 					operator=(Map const & src);
};

#endif
