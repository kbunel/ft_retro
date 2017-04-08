
#include "../includes/Game.class.hpp"

int Game::width = 0;
int Game::height = 0;

Game::Game(void) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	this->x = 10;
	this->stop = false;
	getmaxyx(stdscr, Game::width, Game::height);
	initWall();
	this->player = new Player;
}

Game::Game(Game const & src)
{
  *this = src;
}

Game::~Game()
{
	delete [] this->walls;
	delete this->player;
	endwin();
}

Game & 		Game::operator=(Game const & rhs)
{
  (void)rhs;
  return *this;
}

void 		Game::initWall()
{
	this->walls = new Wall[Game::height];
	for (int i = 0; i < Game::height; ++i)
	{
		walls[i].init(i);
	}
}

void 		Game::input()
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

void 		Game::loop(void) {
	std::clock_t		start;
    double 				duration;

    start = std::clock();
	aff();
	input();
	for (int i = 1; i < Game::height; ++i)
	{
		walls[i-1] = walls[i];
	}
	walls[Game::height-1].move(walls[Game::height-2]);
	if (x < 70)
		x++;
	else
		x = 10;
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	while (duration <= (double) 1 / FPS) {
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	}

	return ;
}

void 		Game::aff(void) {
	clear();
	mvprintw(30, x, "t");
	for (int i = 0; i < this->height; ++i)
		this->walls[i].display();
	this->player->display();
	refresh();
}

bool 		Game::isStop(void) {
	return stop;
}
