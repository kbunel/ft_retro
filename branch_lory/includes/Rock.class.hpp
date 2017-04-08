/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlory-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:15:37 by nlory-ma          #+#    #+#             */
/*   Updated: 2017/04/08 15:15:40 by nlory-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ROCK_CLASS_HPP
# define ROCK_CLASS_HPP

# define STAR 9
# define STAR_SPRITE "      *     "
# define STAR_HEIGHT 3
# define STAR_WIDTH 3

# define TREE 7
# define TREE_SPRITE "  #   ### #####  #    #  "
# define TREE_HEIGHT 5
# define TREE_WIDTH 5

# define ENEMY_SHIP		2
# define ENEMY_SPRITE	"  /| <  <<  \\| "
# define ENEMY_HEIGHT	3
# define ENEMY_WIDTH	5



# include <iostream>
# include <ncurses.h>

class Rock {

private:

        Rock(void);

        std::string	_rock;
        int					_height;
        int					_width;


public:

        Rock (int ship);
      	Rock( Rock const & src );
      	Rock( std::string pattern, int height, int width );
        ~Rock ( void );

                /* Getters */

        std::string		getRock(void) const;
        int					  getHeight(void) const;
        int					  getWidth(void) const;

              /* Setters */
        void				setRock(std::string value);
        void				setHeight(int value);
        void				setWidth(int value);

        bool	      checkBorderCollision(int x, int y);
        void        renderRock(Rock *ps, int x, int y);

              /* Operator Overload */
        Rock &operator=(Rock const &rhs);
};

#endif
