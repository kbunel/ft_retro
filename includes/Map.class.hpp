#ifndef MAP_H
#define MAP_H

#include "../includes/Entity.class.hpp"

class Map {

	public:
		Map( void );
		Map( Map const & missileInliine );
		~Map( void );

		void					addReference( Entity const & entity, std::string ref );
		void					putReference( int x, int y, std::string ref );
		void					loop( void );
		
		std::string				**map;

	private:

		Map & 					operator=(Map const & src);
};

#endif
