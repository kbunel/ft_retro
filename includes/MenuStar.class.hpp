#ifndef MENUSTAR_CLASS_HPP
#define MENUSTAR_CLASS_HPP

#include "ft_retro.h"
#include "Game.class.hpp"
class MenuStar {

private:

	int x;
	int y;
	bool activated;

public:

	MenuStar( void );
	MenuStar(MenuStar const & game);
	~MenuStar();
	MenuStar & 		operator=(MenuStar const & src);

	void loop();
	void activate();
	bool isActivated();

};

#endif