
#include "../includes/Game.class.hpp"
#include <unistd.h>
int Game::width = 0;
int Game::height = 0;

Game::Game(void) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	this->stop = false;
	usq = 0;
	getmaxyx(stdscr, Game::height, Game::width);
	initWall();
	test.init(10, 10, 5, "test.file");
}

Game::Game(Game const & src)
{
  *this = src;
}

Game::~Game()
{
	delete [] this->walls;
	endwin();
}

Game & Game::operator=(Game const & rhs)
{
  (void)rhs;
  return *this;
}

void Game::initWall()
{
	this->walls = new Wall[Game::width];
	for (int i = 0; i < Game::width; ++i)
	{
		walls[i].init(i);
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
}

void Game::loop(void) {
	std::clock_t start;
    double duration;

    start = std::clock();
	aff();
	input();
	if (!usq)
	{
		for (int i = 1; i < Game::width; ++i)
		{
			walls[i-1].move(walls[i]);
		}
		walls[Game::width-1].generate(walls[Game::width-2]);
	}
	usq++;
	if (usq == 4)
		usq = 0;
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	while (duration <= (double) 1 / FPS) {
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	}

	return ;
}

void Game::aff(void) {
	clear();
	attron(A_REVERSE);
	for (int i = 0; i < Game::width; ++i)
		this->walls[i].display();
	attroff(A_REVERSE);
	test.display();
	refresh();
}

bool Game::isStop(void) {
	return stop;
}
