
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
	{}
	else if (ch == '3')
		this->stop = true;
}


void Menu::loop(Game & g)
{
	std::clock_t		start;
    double 				duration;
    start = std::clock();

	this->input(g);
	this->affTitle();
	for (int i = 0; i < NB_MENUSTAR; ++i)
	{
		if (!menuStar[i].isActivated())
		{
			menuStar[i].activate();
			break;
		}
	}
	this->aff();
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	while (duration <= (double) 1 / 60)
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
}

void Menu::aff()
{
	std::string str[3];
	str[0] = "1. Lancer le jeu.";
	str[1] = "2. High score.";
	str[2] = "3. Quiter.";
	clear();
	for (int i = 0; i < NB_MENUSTAR; ++i)
		menuStar[i].loop();
	for (int i = 0; i < 3; ++i)
		mvprintw((Game::height/2-20+(2*i)), Game::width/2-20, str[i].c_str());
	this->affTitle();
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

bool Menu::isStop() {
	return this->stop;
}