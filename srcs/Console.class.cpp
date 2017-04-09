#include "../includes/Console.class.hpp"
#include "../includes/Game.class.hpp"

Console::Console( void ) {
	this->life = LIFE_START;
	this->score = 0;
	return;
}

Console::Console( Console const & console ) {
	*this = console;
	return;
}

Console::~Console( void ) {
	return;
}

void				Console::display( void ) {
	int			mid;

	mid = Game::width / 2;
	mvprintw( Game::height - 3, mid - 26, "Life:" );
	mvprintw( Game::height - 3, mid - 20, std::to_string(this->life).c_str() );

	mvprintw( Game::height - 3, mid, "Level:" );
	mvprintw( Game::height - 3, mid + 7, std::to_string(this->level).c_str() );

	mvprintw( Game::height - 3, mid + 20, "Score:" );
	mvprintw( Game::height - 3, mid + 27, std::to_string(this->score).c_str() );
}

void				Console::loop( int life ) {
	this->life = life;
}

void				Console::addScore( int points ) {
	this->score += points;
}

void				Console::addLevel( void ) {
	this->level++;
}

Console &			Console::operator=( Console const & rhs ) {
	this->score = rhs.score;
	this->level = rhs.level;
	return *this;
}
