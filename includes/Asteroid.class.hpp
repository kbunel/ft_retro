#ifndef Asteroid_H
#define Asteroid_H

#include "ft_retro.h"
#include "../includes/Entity.class.hpp"
#include "../includes/MissileInline.class.hpp"

class Asteroid : public Entity {
	
	public:

		Asteroid( void );
		Asteroid( const Asteroid & Asteroid);
		~Asteroid( void );

		void				loop( void );
		void				repop( void );
		void 				moveLeft( void );

		bool				isActivated();

	private:

		bool				activated;

		Asteroid &				operator=( Asteroid const & rhs );
};

#endif
