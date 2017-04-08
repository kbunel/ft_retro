#ifndef PLAYER_H
#define PLAYER_H

#include "ft_retro.h"
#include "../includes/Entity.class.hpp"
#include "../includes/MissileInline.class.hpp"

class Player : public Entity {
	
	public:

		Player( void );
		Player( const Player & player);
		~Player( void );

		void				loop( void );
		void 				activateMissiles( void );
		void 				moveUp( void );
		void 				moveLeft( void );
		void 				moveRight( void );
		void 				moveDown( void );

	private:

		Player &			operator=( Player const & rhs );
		MissileInline		missiles[MAX_MISSILES_IN_SLOT];
};

#endif
