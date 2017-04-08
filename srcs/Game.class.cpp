
#include "../includes/Game.class.hpp"
#include <iostream>

Game::Game()
{
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
 	this->walls[i].init( this->height, this->height, 0, 2, 999999);
 }
}

void Game::input()
{
	int ch = wgetch(stdscr);
	if (ch == 27)
		this->stop = true;
}

void Game::loop()
{
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
	while (duration <= (double)1/120)
	{
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	}
}

void Game::aff()
{
	clear();
	mvprintw(30, x, "t");
	refresh();	
}

bool Game::isStop()
{
	return stop;
}