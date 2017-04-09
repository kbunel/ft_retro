#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "ft_retro.h"
#include "Wall.class.hpp"
#include "Player.class.hpp"
#include "Map.class.hpp"
#include "Enemy.class.hpp"
#include "Asteroid.class.hpp"

class Game {

	private:

		void 		initWall( void );
		void 		initEnemies( void );
		void 		initAsteroids( void );
		void		activateEnemies( void );

		int usq;
		bool 		running;
		bool		pause;
		Player* 	player;
		Enemy 		*enemies;
		Asteroid 	*asteroids;
		Wall 		*wallsH;
		Wall 		*wallsB;

	public:
		
		Game( void );
		Game(Game const & game);
		~Game();

		void 		input();
		void 		loop();
		void 		run();
		void 		aff();
		int 		getWidth();
		int 		getHeight();
		bool 		isRunning();
		bool 		isPause();
		void		setPause(bool p);
		static void error(std::string err);

		static int 			width;
		static int 			height;
		static Map*  		map;
		static std::string  		mapChar;

		Game & 		operator=(Game const & src);

};

#endif
