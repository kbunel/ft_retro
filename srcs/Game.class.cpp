
#include "../includes/Game.class.hpp"
#include <iostream>

Game::Game(void) {

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	this->x = 10;
	this->stop = false;
	return ;
}

Game::~Game(void) {

	endwin();
	return ;
}

void Game::input(void) {

	int ch = wgetch(stdscr);

	if (ch == 27)
		this->stop = true;
	if (ch == KEY_UP)
		printw("Up arrow is pressed\n");
	if(ch == KEY_RIGHT)
		printw("Right arrow is pressed\n");
	if (ch == KEY_LEFT)
		printw("Left arrow is pressed\n");
	if (ch == KEY_DOWN)
		printw("Down arrow is pressed\n");
	if (ch == ' ')
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
	refresh();

	return ;
}

bool Game::isStop(void) {
	return stop;
}
