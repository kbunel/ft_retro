#ifndef MISSILE_INLINE_H
#define MISSILE_INLINE_H

#include "../includes/Entity.class.hpp"

class MissileInline : public Entity {

	public:
		MissileInline( void );
		MissileInline( MissileInline const & missileInliine );
		~MissileInline( void );

		void					loop( int from );
		void					initiate( int x, int y );

		bool					activated;

	private:

		MissileInline & 		operator=(MissileInline const & src);
};

#endif
