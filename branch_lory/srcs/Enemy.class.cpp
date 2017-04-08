/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlory-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:23:53 by nlory-ma          #+#    #+#             */
/*   Updated: 2017/04/08 19:23:55 by nlory-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Enemy.Class.hpp"

/* CONSTRUCTORS */

Enemy::Enemy(void)
{
	this->_status = 0;
	this->_sprite = NULL;
	this->_size = 0;
	this->_life = 0;
	this->_posX = 0;
	this->_posY = 0;
	this->_armor = 0;
	this->_damage = 0;
}

Enemy::Enemy(Rock *sprite, int size, int life, int x, int y, int dam, int armor) : Ship(sprite, size, life, x, y, dam, armor)
{
	this->_status = 1;
	this->_sprite = sprite;
	this->_size = size;
	this->_life = life;
	this->_posX = x;
	this->_posY = y;
	this->_armor = armor;
	this->_damage = dam;
}

Enemy::Enemy(Enemy const & obj) : Ship(obj)
{
	*this = obj;
}

/* DECONSTRUCTOR */

Enemy::~Enemy(void)
{

}

/* OPERATORS */

Enemy	&Enemy::operator=(Enemy const & obj)
{
	this->_status = obj.getStatus();
	this->_sprite = obj.getRock();
	this->_size = obj.getSize();
	this->_life = obj.getLife();
	this->_posX = obj.getPosX();
	this->_posY = obj.getPosY();
	this->_armor = obj.getArmor();
	this->_damage = obj.getDamage();
	return (*this);
}

/* METHODS */

void		Enemy::respawn(int win_w, int win_h)
{
	setPosX( win_w + (rand() % ((win_w / 8) * 3)) );
	setPosY( 5 + (rand() % (win_h -10)) );
	setStatus(1);
}
