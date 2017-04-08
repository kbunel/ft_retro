/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlory-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:22:28 by nlory-ma          #+#    #+#             */
/*   Updated: 2017/04/08 19:22:30 by nlory-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_CLASS_HPP

# define SHIP_CLASS_HPP

# define UP 42
# define DOWN 43
# define LEFT 44
# define RIGHT 45

# include <iostream>
# include "Rock.class.hpp"

class		Ship {

public:

	Ship(void);
	Ship(Rock *sp, int size, int life, int x, int y, int dam, int armor);
	Ship(Ship const & obj);
	~Ship(void);

	Ship	&operator=(Ship const & obj);

	Rock			*getRock(void) const;
	int				getStatus(void) const;
	int				getSize(void) const;
	int				getLife(void) const;
	int				getPosX(void) const;
	int				getPosY(void) const;
	int				getArmor(void) const;
	int				getDamage(void) const;


	void			setRock(Rock *sp);
	void			setStatus(int value);
	void			setSize(int value);
	void			setLife(int value);
	void			setPosX(int value);
	void			setPosY(int value);
	void			setArmor(int value);
	void			setDamage(int value);

	void			move(int way);
	void			takeDamage(int amount);

	void			shoot(Ship const & target) const;


protected:


	Rock			*_sprite;
	int				_status;
	int				_size;
	int				_life;
	int				_posX;
	int				_posY;
	int				_armor;
	int				_damage;

};

#endif
