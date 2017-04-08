
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
}

Game::~Game()
{
	endwin();
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