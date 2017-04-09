#ifndef ENEMY_H
#define ENEMY_H

#include "ft_retro.h"
#include "../includes/Entity.class.hpp"
#include "../includes/MissileInline.class.hpp"

class Enemy : public Entity {
	
	public:

		Enemy( void );
		Enemy( const Enemy & enemy);
		~Enemy( void );

		void				loop( void );
		void 				activateMissiles( void );
		void				repop( void );
		void 				moveUp( void );
		void 				moveLeft( void );
		void 				moveRight( void );
		void 				moveDown( void );
		MissileInline* 		getMissiles( void );

		bool				activated;

	private:

		Enemy &				operator=( Enemy const & rhs );
		MissileInline		missiles[ENEMIES_MISSILES];
};

#endif
