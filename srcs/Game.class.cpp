
#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"

int 				Game::width = 0;
int 				Game::height = 0;
Map*  				Game::map;
std::string  		Game::mapChar = "init";

Game::Game(void) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	this->x = 10;
	this->stop = false;
	getmaxyx(stdscr, Game::height, Game::width);
	Game::map = new Map();
	initWall();
	this->player = new Player();
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

void 		Game::initWall( void )
{
	this->walls = new Wall[Game::height];
	for (int i = 0; i < Game::height; ++i)
		walls[i].init(i);
}

void 		Game::input( void )
{
	int ch = wgetch(stdscr);

	if (ch == 27)
		this->stop = true;
	else if (ch == KEY_UP)
		this->player->moveUp();
	else if(ch == KEY_RIGHT)
		this->player->moveRight();
	else if (ch == KEY_LEFT)
		this->player->moveLeft();
	else if (ch == KEY_DOWN)
		this->player->moveDown();
	else if (ch == ' ')
		this->player->activateMissiles();
}

void 		Game::loop(void) {
	std::clock_t		start;
    double 				duration;

    start = std::clock();
	input(); 
	aff();

	mvprintw( 10, 10, this->mapChar.c_str() );
	mvprintw( this->player->getY1(), this->player->getX1() - 2, "-" );


	int i = 0;
	int j;
	while (i < this->width) {
		j = 0;
		while(j < this->height) {
			if (Game::map->map[i][j] != "X")
				mvprintw( j, i, Game::map->map[i][j].c_str() );
			j++;
		}
		i++;
	}





	for (int i = 1; i < Game::height; ++i)
		walls[i-1] = walls[i];
	walls[Game::height-1].loop(walls[Game::height-2]);
	x = (x < 70) ? x + 1 : 10;
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	while (duration <= (double) 1 / FPS)
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	return ;
}

void 		Game::aff(void) {
	clear();
	for (int i = 0; i < this->height; ++i)
		this->walls[i].display();
	this->player->loop();
	refresh();
}

bool 		Game::isStop(void) {
	return stop;
}
