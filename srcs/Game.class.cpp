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
	delete [] this->wallsH;
	delete [] this->wallsB;
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
	{
		this->wallsH = new Wall[Game::width];
		for (int i = 0; i < Game::width; ++i)
			wallsH[i].init(i, TRUE);
	}
	{
		this->wallsB = new Wall[Game::width];
		for (int i = 0; i < Game::width; ++i)
			wallsB[i].init(i, FALSE);
	}

}

void 		Game::initEnemies( void )
{
	int		y;
	this->enemies = new Enemy[NB_ENEMIES];
	for (int i = 0; i < NB_ENEMIES; ++i) {
		y = std::rand() % 4;
		y *= (y % 2 == 0) ? 1 : -1; 
		y = (Game::height / 2 ) + y ;
		enemies[i].init(Game::width + 10, y,  1, "enemy.file" );
	}
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

	this->activateEnemies();	
	this->player->loop();

	for (int i = 0; i < NB_ENEMIES ; ++i)
		this->enemies[i].loop();

	if (!usq)
	{
		for (int i = 1; i < Game::width; ++i)
		{
			wallsH[i-1].loop(wallsH[i]);
		}
		wallsH[Game::width-1].generate(wallsH[Game::width-2]);
		for (int i = 1; i < Game::width; ++i)
		{
			wallsB[i-1].loop(wallsB[i]);
		}
		wallsB[Game::width-1].generate(wallsB[Game::width-2]);
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
	MissileInline* 		p_missiles;
	MissileInline* 		e_missiles;





	/*
    mvprintw( 10, 10, this->mapChar.c_str() );
    mvprintw( this->player->getY1(), this->player->getX1() - 2, "-" );

    int i = 0;
    int j;
    while (i < this->width) {
        j = 0;
        while(j < this->height) {
            if (Game::map->map[i][j] != NULL)
                mvprintw( j, i, "O" );
                //mvprintw( j, i, Game::map->map[i][j].c_str() );
            j++;
        }
        i++;
    }
	*/

	clear();


	mvprintw( 10, 10, "Life: ");
	mvprintw( 10, 17, (std::to_string(this->player->getLife())).c_str());
	p_missiles = this->player->getMissiles();


	for (int i = 0; i < Game::width; ++i)
		this->wallsH[i].display();
	for (int i = 0; i < Game::width; ++i)
		this->wallsB[i].display();
	this->player->display();
	p_missiles = this->player->getMissiles();

	for (int i = 0; i < MAX_MISSILES_IN_SLOT ; i++) {
		if (p_missiles[i].activated)
			p_missiles[i].display();
	}

	for (int i = 0; i < NB_ENEMIES ; i++) {
		this->enemies[i].display();
		e_missiles = this->enemies[i].getMissiles();
		for (int j = 0; j < ENEMIES_MISSILES ; j++) {
			if (e_missiles[j].activated)
				e_missiles[j].display();
		}
	}
	refresh();
}

void		Game::activateEnemies( void ) {
	for (int i = 0; i < NB_ENEMIES ; i++) {
		if (this->enemies[i].activated == false && std::rand() % 4 == 2)
			this->enemies[i].activated = true;
	}
}

bool 		Game::isStop(void) {
	return stop;
}

void Game::error(std::string err)
{
	endwin();
	std::cerr << err << std::endl;
	exit(1);
}
