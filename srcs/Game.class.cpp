
#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"
#include <unistd.h>

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
	this->stop = false;
	usq = 0;
	getmaxyx(stdscr, Game::height, Game::width);
	Game::map = new Map();
	initWall();
	initEnemies();
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
	delete Game::map;
	endwin();
}

Game & 		Game::operator=(Game const & rhs)
{
  (void)rhs;
  return *this;
}

void 		Game::initWall( void )
{
	this->walls = new Wall[Game::width];
	for (int i = 0; i < Game::width; ++i)
		walls[i].init(i);
}

void 		Game::initEnemies( void )
{
	this->enemies = new Enemy[NB_ENEMIES];
	for (int i = 0; i < 1; ++i)
		enemies[i].init(Game::width + 10, Game::height / 2,  30, "enemy.file" );
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

	

	for (int i = 0; i < NB_ENEMIES; i++)
		this->enemies[i].moveLeft();
	

	if (!usq)
	{
		for (int i = 1; i < Game::width; ++i)
		{
			walls[i-1].loop(walls[i]);
		}
		walls[Game::width-1].generate(walls[Game::width-2]);
	}
	usq++;
	if (usq == 4)
		usq = 0;
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	while (duration <= (double) 1 / FPS)
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	return ;
}

void 		Game::aff(void) {
	clear();
	attron(A_REVERSE);
	for (int i = 0; i < Game::width; ++i)
		this->walls[i].display();
	attroff(A_REVERSE);
	this->player->loop();
	for (int i = 0; i < NB_ENEMIES ; ++i)
		this->enemies[i].loop();
	this->player->loop();
	refresh();
}

bool 		Game::isStop(void) {
	return stop;
}
