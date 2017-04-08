#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "ft_retro.h"
#include "Wall.class.hpp"
#include "Player.class.hpp"
#include "Map.class.hpp"
#include "Enemy.class.hpp"

#define MAX_SHIP_ENEMY 10

#define SIZE_INTERFACE 5

#define FPS 60

class Game {

	private:

		void 		initWall();
		void 		initEnemies();

		int usq;
		bool 		stop;
		Player* 	player;
		Enemy 		*enemies;
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
