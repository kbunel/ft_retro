#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "ft_retro.h"
#include "Wall.class.hpp"
#include "Player.class.hpp"
#include "Map.class.hpp"

#define MAX_SHIPENEMY 10

#define MIN_SIZE_WALL 2
#define MAX_SIZE_WALL 20

#define SIZE_INTERFACE 5

#define FPS 60

class Game {

	private:

		void 		initWall();

		int			x;
		bool 		stop;
		Player* 	player;
		//ShipEnemy ens[];
		Wall 		*walls;

	public:
		
		Game( void );
		Game(Game const & game);
		~Game();

		void 		input();
		void 		loop();
		void 		aff();
		int 		getWidth();
		int 		getHeight();
		bool 		isStop();
		
		static int 			width;
		static int 			height;
		static Map*  		map;
		static std::string  		mapChar;

		Game & 		operator=(Game const & src);

};

#endif
