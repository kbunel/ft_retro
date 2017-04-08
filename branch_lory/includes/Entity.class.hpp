
#include "ft_retro.h"

class Entity {

	public:
		Entity( void );
		Entity( int x1, int x2, int y1, int y2, int life, char dispChar );
		Entity( Entity const & src );
		~Entity( void );

		void				loop( void );
		void				display( void );
		bool				checkColision( int x, int y);
		void				init( int x1, int x2, int y1, int y2, int life, char dispChar);

		int					getLife( void ) const;
		int					getX1( void ) const;
		int					getX2( void ) const;
		int					getY1( void ) const;
		int					getY2( void ) const;
		std::string**		getDispChars( void ) const;

	protected:
		int					life;
		int					x1;
		int					x2;
		int					y1;
		int					y2;
		std::string			**dispChars;

	private:

		Entity &			operator=( Entity const & rhs );
};
