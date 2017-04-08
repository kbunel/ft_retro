/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlory-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:14:59 by nlory-ma          #+#    #+#             */
/*   Updated: 2017/04/08 19:24:04 by nlory-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Rock.class.hpp"
#include "../includes/Game.class.hpp"


Rock::Rock(int ship) {

  if (ship == STAR) {

  this->_rock = STAR_SPRITE;
  this->_height = STAR_HEIGHT;
  this->_width = STAR_WIDTH;

  }

  else if (ship == TREE) {

    this->_rock = TREE_SPRITE;
		this->_height = TREE_HEIGHT;
		this->_width = TREE_WIDTH;

  }
}

Rock::Rock( std::string pattern, int height, int width ) {

    this->_rock = pattern;
    this->_height = height;
    this->_width = width;
}


/* OPERATORS */

Rock		&Rock::operator=(Rock const & rhs)
{
	this->_rock = rhs.getRock();
	this->_rock = rhs.getHeight();
	this->_rock = rhs.getWidth();
	return (*this);
}

/* DESTRUCTOR  */

Rock::~Rock( void ) {

}


/* GETTERS */

std::string     Rock::getRock(void) const { return (this->_rock); }
int             Rock::getHeight(void) const { return (this->_height); }
int             Rock::getWidth(void) const { return (this->_width); }

/* SETTERS */
void			Rock::setRock(std::string value) { this->_rock = value; }
void			Rock::setHeight(int value) { this->_height = value; }
void			Rock::setWidth(int value) { this->_width = value; }
