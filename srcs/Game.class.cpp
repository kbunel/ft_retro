#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"
#include "../includes/Console.class.hpp"
#include <unistd.h>

int 				Game::width = 0;
int 				Game::height = 0;
Map*  				Game::map;
std::string  		Game::mapChar = "init";
Console*			Game::console = new Console;
bool**				Game::carte;

Game::Game(void) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	this->stop = false;
	ust = 0;
	usq = 0;
	enemiesFrequency = 700;
	getmaxyx(stdscr, Game::height, Game::width);
	Game::map = new Map();
	initCarte();
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

void		Game::initCarte( void ) {
	int		i = 0;
	int		j;


	Game::carte = new bool*[Game::width];
	while (i <= Game::width) {
		j = 0;
		Game::carte[i] = new bool[Game::height];
		while (j < Game::height) {
			Game::carte[i][j] = new bool(false);
			//std::cout << Game::carte[i][j] << std::endl;
			j++;
		}
		i++;
	}
}

void 		Game::initEnemies( void )
{
	int		x;
	int		y;
	this->enemies = new Enemy[NB_ENEMIES];
	for (int i = 0; i < NB_ENEMIES; ++i) {
		y = std::rand() % (Game::height / 2);
		x = std::rand() % this->enemiesFrequency;
		y *= (y % 2 == 0) ? 1 : -1; 
		y = (Game::height / 2 ) + y ;
		enemies[i].init(Game::width + x, y,  1, "enemy.file" );
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
		this->enemies[i].loop(ust);

	if (!usq)
	{
		for (int i = 1; i < Game::width; ++i)
			wallsH[i-1].loop(wallsH[i]);
		wallsH[Game::width-1].generate(wallsH[Game::width-2]);
		for (int i = 1; i < Game::width; ++i)
			wallsB[i-1].loop(wallsB[i]);
		wallsB[Game::width-1].generate(wallsB[Game::width-2]);
	}
	usq = (usq == 4) ? 0 : usq + 1;
	ust = (ust == 3) ? 0 : ust + 1;
	frame++;
	if (frame > MIN_ENEMIES_FREQUENCY * 2) {
		this->enemiesFrequency -= 25;
		frame = 0;
		Game::console->addLevel();
	}
	Game::console->loop( this->player->getLife() );

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	while (duration <= (double) 1 / FPS)
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	return ;
}

void		Game::clear( void ) {
	int		i = 0;
	int		j;
	while (i <= Game::width) {
		j = 0;
		while (j < Game::height) {
			if (Game::carte[i][j] == true) {
				mvprintw( j, i, " " );
			}
			j++;
		}
		i++;
	}
}

void 		Game::aff( void ) {
	MissileInline* 		p_missiles;
	MissileInline* 		e_missiles;

	this->clear();
	
	p_missiles = this->player->getMissiles();

	for (int i = 0; i < Game::width; ++i)
		this->wallsH[i].display();
	for (int i = 0; i < Game::width; ++i)
		this->wallsB[i].display();
	this->player->display();

	for (int i = 0; i < MAX_MISSILES_IN_SLOT ; i++) {
		if (p_missiles[i].activated) {
			p_missiles[i].display();
		}
	}

	for (int i = 0; i < NB_ENEMIES ; i++) {
		this->enemies[i].display();
		e_missiles = this->enemies[i].getMissiles();
		for (int j = 0; j < ENEMIES_MISSILES ; j++) {
			if (e_missiles[j].activated) {
				e_missiles[j].display();
			}
		}
	}
	Game::console->display();
	refresh();
}

void		Game::activateEnemies( void ) {
	for (int i = 0; i < NB_ENEMIES ; i++) {
		if (this->enemies[i].activated == false) {
			this->enemies[i].activated = true;
			break;
		}
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

Player const &			Game::getPlayer( void ) {
	return *this->player;
}
