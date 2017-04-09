
#include "../includes/Menu.class.hpp"
#include <unistd.h>
Menu::Menu(void) {

	this->selected = 0;
	this->stop = false;
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

void 		Menu::input( Game g )
{
	int ch = wgetch(stdscr);

	if (ch == 27)
		this->stop = true;
	else if (ch == 'a')
		g.run();
	else if (ch == 'b')
	{}
	else if (ch == 'c')
		this->stop = true;
}


void Menu::loop(Game g)
{
	this->input(g);
	this->affTitle();
	mvprintw(Game::height/2-20, Game::width/2-20, "1. Lancer le jeu.");
	mvprintw(Game::height/2-18, Game::width/2-20, "2. High score.");
	mvprintw(Game::height/2-16, Game::width/2-20, "3. Quiter.");
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