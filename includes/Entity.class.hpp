
#include "ft_retro.h"

class Entity {

	public:
		Entity( int x1, int x2, int y1, int y2, int life );
		~Entity( void );

		void		loop( void );
		void		display( void );
		bool		checkColision( int x, int y);
		int			getLife( void );

		int			getX1( void );
		int			getX2( void );
		int			getY1( void );
		int			getY2( void );
		void		setY1( int x1 );
		void		setY2( int x2 );
		void		setX1( int y1 );
		void		setX2( int y2 );

	protected:
		int			life;
		int			x1;
		int			x2;
		int			y1;
		int			y2;
};
