/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlory-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:23:43 by nlory-ma          #+#    #+#             */
/*   Updated: 2017/04/08 19:23:44 by nlory-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ship.Class.hpp"


Ship::Ship(void)
{
	this->_sprite = NULL;
	this->_status = 0;
	this->_size = 0;
	this->_life = 0;
	this->_posX = 0;
	this->_posY = 0;
	this->_armor = 0;
	this->_damage = 0;
}

Ship::Ship(Rock *sp, int size, int life, int x, int y, int dam, int armor)
{
	this->_sprite = sp;
	this->_status = 1;
	this->_size = size;
	this->_life = life;
	this->_posX = x;
	this->_posY = y;
	this->_armor = armor;
	this->_damage = dam;
}

Ship::Ship(Ship const & obj)
{
	*this = obj;
}

Ship::~Ship(void)
{

}

Ship	&Ship::operator=(Ship const & obj)
{
	this->_sprite = obj.getRock();
	this->_status = 1;
	this->_size = obj.getSize();
	this->_life = obj.getLife();
	this->_posX = obj.getPosX();
	this->_posY = obj.getPosY();
	this->_armor = obj.getArmor();
	this->_damage = obj.getDamage();
	return (*this);
}

int				Ship::getSize(void) const { return (this->_size); }
int				Ship::getStatus(void) const { return (this->_status); }
Rock			*Ship::getRock(void) const { return (this->_sprite); }
int				Ship::getLife(void) const { return (this->_life); }
int				Ship::getPosX(void) const { return (this->_posX); }
int				Ship::getPosY(void) const { return (this->_posY); }
int				Ship::getArmor(void) const { return (this->_armor); }
int				Ship::getDamage(void) const { return (this->_damage); }

void			Ship::setRock(Rock *value) { this->_sprite = value; }
void			Ship::setStatus(int value) { this->_status = value; }
void			Ship::setSize(int value) { this->_size = value; }
void			Ship::setLife(int value) { this->_life = value; }
void			Ship::setPosX(int value) { this->_posX = value; }
void			Ship::setPosY(int value) { this->_posY = value; }
void			Ship::setArmor(int value) { this->_armor = value; }
void			Ship::setDamage(int value) { this->_damage = value; }


void		Ship::move(int way)
{
	if (way == UP)
		this->_posY = this->_posY - 1;
	if (way == DOWN)
		this->_posY = this->_posY + 1;
	if (way == LEFT)
		this->_posX = this->_posX - 1;
	if (way == RIGHT)
		this->_posX = this->_posX + 1;
}

void		Ship::takeDamage(int amount)
{
	// si l'attaque est assez puissante, pour ne pas heal la cible
	if (amount < this->_armor)
	{
		this->_life -= (amount - this->_armor);
	}
}

void		Ship::shoot(Ship const & target) const
{
	(void)target;
//	target.takeDamage(this->_damage);
//	target.takeDamage(this->getDamage());
}
