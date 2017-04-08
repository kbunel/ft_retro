
#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"
int			main() {
	Game g;

	while (!g.isStop())
	{
		g.loop();
	}
}
