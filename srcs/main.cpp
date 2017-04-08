
#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"

int			main() {
	Game g;

	std::srand(std::time(0));
	while (!g.isStop())
	{
		g.loop();
	}
}
