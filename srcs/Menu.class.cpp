
#include "../includes/Menu.class.hpp"
#include <unistd.h>
Menu::Menu(void) {

	this->selected = 0;
	this->stop = false;
	this->menuStar = new MenuStar[NB_MENUSTAR];
}

Menu::Menu(Menu const & src)
{
  *this = src;
}

Menu::~Menu()
{
}

Menu & 		Menu::operator=(Menu const & rhs)
{
  (void)rhs;
  return *this;
}

void 		Menu::input(Game & g)
{
	int ch = wgetch(stdscr);

	if (ch == 27)
		this->stop = true;
	else if (ch == '1')
		g.run();
	else if (ch == '2')
		this->stop = true;
}


void Menu::loop(Game & g)
{
	std::clock_t		start;
    double 				duration;
    start = std::clock();

	this->input(g);
	for (int i = 0; i < NB_MENUSTAR; ++i)
	{
		if (!menuStar[i].isActivated())
		{
			menuStar[i].activate();
			break;
		}
	}
	this->aff(g);
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	while (duration <= (double) 1 / 60)
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
}

void Menu::aff(Game & g)
{
	std::string str[3];
	str[0] = "1. Lancer le jeu.";
	str[1] = "2. Quiter.";
	clear();
	for (int i = 0; i < NB_MENUSTAR; ++i)
		menuStar[i].loop();
	for (int i = 0; i < 3; ++i)
		mvprintw((Game::height/2-20+(2*i)), Game::width/2-20, str[i].c_str());
	mvprintw(Game::height/2-20+6, Game::width/2-20, "Score: %d", g.getScore());
	if (!g.isRunning() && g.getScore() == 0)
		this->affTitle();
	else if (g.isRunning() && g.isPause())
		this->affPause();
	else if (!g.isRunning() && g.getScore() != 0)
		this->affGameOver();
	refresh();
}

void Menu::affTitle()
{
	int i = -30;
	int j = -50;
	mvprintw(Game::height/2+i, Game::width/2+j, "            .-') _         _  .-')     ('-.   .-') _   _  .-')               ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "           (  OO) )       ( \\( -O )  _(  OO) (  OO) ) ( \\( -O )              ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "   ,------./     '._       ,------. (,------./     '._ ,------.  .-'),-----. ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "('-| _.---'|'--...__)      |   /`. ' |  .---'|'--...__)|   /`. '( OO'  .-.  '");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "(OO|(_\\    '--.  .--'      |  /  | | |  |    '--.  .--'|  /  | |/   |  | |  |");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "/  |  '--.    |  |  (`-.   |  |_.' |(|  '--.    |  |   |  |_.' |\\_) |  |\\|  |");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "\\_)|  .--'    |  | (OO  )_ |  .  '.' |  .--'    |  |   |  .  '.'  \\ |  | |  |");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "  \\|  |_)     |  |,------.)|  |\\  \\  |  `---.   |  |   |  |\\  \\    `'  '-'  '");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "   `--'       `--'`------' `--' '--' `------'   `--'   `--' '--'     `-----' ");

}

void Menu::affPause()
{
	int i = -30;
	int j = -28;
	mvprintw(Game::height/2+i, Game::width/2+j, " ____   ____  __ __  _____   ___ ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "|    \\ /    ||  |  |/ ___/  /  _]");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "|  o  )  o  ||  |  (   \\_  /  [_ ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "|   _/|     ||  |  |\\__  ||    _]");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "|  |  |  _  ||  :  |/  \\ ||   [_ ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "|  |  |  |  ||     |\\    ||     |");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "|__|  |__|__| \\__,_| \\___||_____|");
}

void Menu::affGameOver()
{
	int i = -30;
	int j = -40;
	mvprintw(Game::height/2+i, Game::width/2+j, "   _____                         ____                 ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "  / ____|                       / __ \\                ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, " | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, " | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, " | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   ");
	i++;
	mvprintw(Game::height/2+i, Game::width/2+j, "  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   ");
}


bool Menu::isStop() {
	return this->stop;
}