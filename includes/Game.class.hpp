#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "ft_retro.h"
#include "Wall.class.hpp"
#include "Player.class.hpp"
#define MAX_SHIPENEMY 10

#define MIN_SIZE_WALL 2
#define MAX_SIZE_WALL 20

#define SIZE_INTERFACE 5

class Game {

	private:

		int			x;

		int 		width;
		int 		height;

		bool 		stop;

		Player* 	player;

		//ShipEnemy ens[];
		Wall 		*walls;

		void 		initWall();

	public:

		Game( void );
		Game(Game const & game);
		~Game();

		Game & 		operator=(Game const & src);

		void 		input();
		void 		loop();
		void 		aff();

		int 		getWidth();
		int 		getHeight();
		bool 		isStop();
};

#endif
