/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlory-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:23:03 by nlory-ma          #+#    #+#             */
/*   Updated: 2017/04/08 19:23:05 by nlory-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP

# define ENEMY_CLASS_HPP

# include <iostream>
# include <stdlib.h>
# include "Ship.Class.hpp"
#include "Rock.class.hpp"

class		Enemy : public Ship {

public:

	Enemy(void);
	Enemy(Rock *sprite, int size, int life, int x, int y, int dam, int armor);
	Enemy(Enemy const & obj);
	~Enemy(void);

	Enemy	&operator=(Enemy const & obj);

	void        respawn(int win_width, int win_height);

};

#endif /* ENEMY_CLASS_HPP */
