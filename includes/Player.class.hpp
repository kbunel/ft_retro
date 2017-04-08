#ifndef PLAYER_H
#define PLAYER_H

#include "ft_retro.h"
#include "../includes/Entity.class.hpp"

class Player : public Entity {
	
	public:

		Player( void );
		Player( const Player & player);
		~Player( void );

		void				shoot( void );

	private:

		Player &			operator=( Player const & rhs );
};

#endif
