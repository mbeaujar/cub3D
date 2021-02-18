/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:30:57 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 13:47:34 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include <unistd.h>

# ifndef LINUX
#  include "../minilibx-opengl/mlx.h"
#  define LEFT 0
#  define RIGHT 2
#  define FORWARD 13
#  define BACKWARD 1
#  define ROTATE_LEFT 123
#  define ROTATE_RIGHT 124
#  define ESC 53
#  define SPACE 49
#  define JUMP 15
#  define CROUCH 17
#  define PISTOL 18
#  define KNIFE 19
#  define LOOK_TOP 126
#  define LOOK_DOWN 125
#  define LOOSE_HP 9
#  define GAIN_HP 11
#  define OS 1
#  define USE 14
#  define UNUSE 12
# endif

# ifndef MAC
#  include "../minilibx-linux/mlx.h"
#  define LEFT 97
#  define RIGHT 100
#  define FORWARD 119
#  define BACKWARD 115
#  define ROTATE_LEFT 65361
#  define ROTATE_RIGHT 65363
#  define ESC 65307
#  define SPACE 32
#  define JUMP 116
#  define CROUCH 114
#  define PISTOL 49
#  define KNIFE 50
#  define LOOK_TOP 65362
#  define LOOK_DOWN 65364
#  define LOOSE_HP 118
#  define GAIN_HP 98
#  define OS 0
#  define USE 101
#  define UNUSE 113
# endif

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include "structs.h"
# include <time.h>
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define SPRITE 4
# define CEILING 5
# define FLOOR 6

# define NONE 0xFF000000
# define BLACK 0x00000000

# ifndef BONUS_CEILING
#  define BONUS_CEILING 0
# endif

# ifndef BONUS_SPRITES
#  define BONUS_SPRITES 0
# endif

# ifndef BONUS_SHADOW
#  define BONUS_SHADOW 0
# endif

# ifndef BONUS_FLOOR
#  define BONUS_FLOOR 0
# endif

# ifndef BONUS_HEALTH
#  define BONUS_HEALTH 0
# endif

# ifndef BONUS_ENEMY
#  define BONUS_ENEMY 0
# endif

# ifndef MOUSE
#  define MOUSE 0
# endif

# ifndef HUD
#  define HUD 0
# endif

# ifndef WEAPON
#  define WEAPON 0
# endif

# ifndef SOUND
#  define SOUND 0
# endif

# ifndef B_DOOR
#  define B_DOOR 0
# endif

# ifndef BONUS_JUMP
#  define BONUS_JUMP 0
# endif

# ifndef BONUS_CROUCH
#  define BONUS_CROUCH 0
# endif

# ifndef BONUS_VIEW
#  define BONUS_VIEW 0
# endif

#endif
