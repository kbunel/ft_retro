
#include "../includes/Game.class.hpp"

Game::Game(void) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	this->x = 10;
	this->stop = false;
	getmaxyx(stdscr, this->width, this->height);
	initWall();
}

Game::Game(Game const & src)
{
  *this = src;
}

Game::~Game()
{
	delete [] this->walls;
	endwin();
	return ;
}

Game & Game::operator=(Game const & rhs)
{
  (void)rhs;
  return *this;
}

void Game::initWall()
{
 this->walls = new Wall[this->height];
 for (int i = 0; i < this->height; ++i)
 {
 	this->walls[i].init( i, i, 0, 2, 999999, 'a');
 }
}

void Game::input()
{
	int ch = wgetch(stdscr);

	if (ch == 27)
		this->stop = true;
	else if (ch == KEY_UP)
		printw("Up arrow is pressed\n");
	else if(ch == KEY_RIGHT)
		printw("Right arrow is pressed\n");
	else if (ch == KEY_LEFT)
		printw("Left arrow is pressed\n");
	else if (ch == KEY_DOWN)
		printw("Down arrow is pressed\n");
	else if (ch == ' ')
		printw("Space bar is pressed\n");

	return ;
}

void Game::loop(void) {
	std::clock_t start;
    double duration;

    start = std::clock();
	aff();
	input();
	if (x < 70)
		x++;
	else
		x = 10;
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	while (duration <= (double) 1 / 120) {
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	}

	return ;
}

void Game::aff(void) {
	clear();
	mvprintw(30, x, "t");
	for (int i = 0; i < this->height; ++i)
	{
		this->walls[i].display();
	}
	refresh();
}

bool Game::isStop(void) {
	return stop;
}
