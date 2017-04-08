#ifndef ENEMY_H
#define ENEMY_H

#include "ft_retro.h"
#include "../includes/Entity.class.hpp"
#include "../includes/MissileInline.class.hpp"

class Enemy : public Player {
	
	public:

		Enemy( void );
		Enemy( const Enemy & enemy);
		~Enemy( void );

	private:

		Enemy &			operator=( Enemy const & rhs );
};

#endif
