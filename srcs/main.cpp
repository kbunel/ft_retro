
#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"
#include "../includes/Menu.class.hpp"

int			main() {
	Game g;
	Menu m;

	std::srand(std::time(0));
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	getmaxyx(stdscr, Game::height, Game::width);
//	g.run();
	while (!m.isStop())
	{
		if (g.isPause() || !g.isRunning())
			m.loop(g);
		else
			g.loop();
	}
	endwin();
}
