
#ifndef MENU_CLASS_HPP
#define MENU_CLASS_HPP

#include "ft_retro.h"
#include "Game.class.hpp"
#include "MenuStar.class.hpp"

class Menu {

private:

	int selected;
	bool stop;
	MenuStar *menuStar;

public:

		Menu( void );
		Menu(Menu const & game);
		~Menu();
		Menu & 		operator=(Menu const & src);
		void loop(Game & g);
		void input(Game & g);
		void affTitle();
		void affPause();
		void affGameOver();
		void aff(Game & g);

		bool isStop();
};

#endif