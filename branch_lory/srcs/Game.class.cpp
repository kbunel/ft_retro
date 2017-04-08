
#include "../includes/Game.class.hpp"
#include "../includes/Rock.class.hpp"
#include "../includes/Enemy.class.hpp"
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

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


	Rock			*enemy_ship = new Rock(2);

	Enemy			enemy1(enemy_ship, 4, 100, 20, 20, 20, 5);
	Enemy			enemy2(enemy_ship, 4, 100, 40, 20, 20, 5);
	Enemy			enemy3(enemy_ship, 4, 100, 60, 20, 20, 5);
	Enemy			enemy4(enemy_ship, 4, 100, 80, 20, 20, 5);
	Enemy			enemy5(enemy_ship, 4, 100, 80, 20, 20, 5);
	Enemy			enemy6(enemy_ship, 4, 100, 80, 20, 20, 5);
	Enemy			enemy7(enemy_ship, 4, 100, 80, 20, 20, 5);

	Enemy			*enemys = new Enemy[7];

	enemys[0] = enemy1;
	enemys[1] = enemy2;
	enemys[2] = enemy3;
	enemys[3] = enemy4;
	enemys[4] = enemy5;
	enemys[5] = enemy6;
	enemys[6] = enemy7;
	enemys[0].respawn(Game::width, Game::height);
	enemys[1].respawn(Game::width, Game::height);
	enemys[2].respawn(Game::width, Game::height);
	enemys[3].respawn(Game::width, Game::height);
	enemys[4].respawn(Game::width, Game::height);
	enemys[5].respawn(Game::width, Game::height);
	enemys[6].respawn(Game::width, Game::height);
	//std::cout << "width = " << Game::width << "et height = " << Game::height << '\n';


	/*  start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_WHITE, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		init_pair(5, COLOR_CYAN, COLOR_BLACK);*/





		// enemys
	for (int j = 0 ; j < 7 ; j++)
	{
			if (enemys[j].getStatus() == 1)
			{
				attron(COLOR_PAIR(4));
				enemys[j].move(LEFT);
				this->renderRock(enemys[j].getRock(), enemys[j].getPosX(), enemys[j].getPosY());
			}
			if (enemys[j].getPosX() <= (rand() % 50) * -1)
			{
				enemys[j].respawn(Game::width, Game::height);
			}
	}



	this->walls = new Wall[Game::height];
	for (int i = 0; i < Game::height; ++i)
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

			duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
			while (duration <= (double) 1 / FPS) {
				duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
			}

	aff();
	input();
	for (int i = 1; i < Game::height; ++i)
	{
		walls[i-1] = walls[i];
	}
	walls[Game::height - 1].move(walls[Game::height - 2]);
	if (x < 70)
		x++;
	else
		x = 10;

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


bool	Game::checkBorderCollision(int x, int y)
{
	if (x >= this->width -3)
		return (true);
	if (x <= 0)
		return (true);
	if (y >= this->height)
		return (true);
	if (y <= 0)
		return (true);
	return (false);
}

void    Game::renderRock(Rock *ps, int x, int y)
{
	std::string p = ps->getRock();
	int			w = ps->getWidth() + 5;
	int			h = ps->getHeight() + 8;

	int			i = 0;
	int			y_mod = -(h/2) * -1;
	int			x_mod = -h * -1;

	if (!checkBorderCollision(x, y))
	{
		while (i <= 8000)
		{
			/*attron(COLOR_PAIR(4));
			mvprintw(4 , x, "*");
			mvprintw(5, x, "<<");
			mvprintw(6, x, "<<");
			mvprintw(7, x, "<<");*/
			//mvprintw(ps->getHeight(), ps->getWidth(), "*");
			mvprintw(y + y_mod, x + x_mod, p.substr(i * (w + 1), w + 1).c_str());
			y_mod++;
			i++;
		}
		refresh();
	}
}

bool Game::isStop(void) {
	return stop;
}
