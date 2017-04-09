
#ifndef MENU_CLASS_HPP
#define MENU_CLASS_HPP

#include "ft_retro.h"
#include "Game.class.hpp"
class Menu {

private:

	int selected;
	bool stop;

public:

		Menu( void );
		Menu(Menu const & game);
		~Menu();
		Menu & 		operator=(Menu const & src);
		void loop(Game g);
		void input(Game g);
		void affTitle();

		bool isStop();
};

#endif