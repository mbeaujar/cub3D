/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:05:50 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 22:16:09 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_position
{
	double		x;
	double		y;
	int			index;
	int			hp;
	int			frame;
	int			seen;
	time_t		fire;
}				t_position;

typedef struct	s_entity
{
	int			offset;
	int			action;
	int			draw;
	int			x;
	int			y;
	int			max_offset;
}				t_entity;

typedef struct	s_player
{
	double		posx;
	double		posy;
	int			direction;
	int			hp;
	int			score;
}				t_player;

typedef struct	s_image
{
	void		*text;
	int			height;
	int			width;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*path;
	char		*addr;
}				t_image;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_vars;

typedef struct	s_bmp
{
	int			file_size;
	int			pixel_data_offset;
	int			header_size;
	int			plane;
	int			img_size;
	int			fd;
}				t_bmp;

typedef struct	s_parsing
{
	int			resolutionx;
	int			resolutiony;
	int			free_north;
	int			free_west;
	int			free_east;
	int			free_south;
	int			free_sprite;
	int			free_ceiling;
	int			free_floor;
	char		*north;
	char		*west;
	char		*east;
	char		*south;
	char		*sprite;
	char		*ceiling;
	char		*floor;
	int			trgb_ceiling;
	int			trgb_floor;
	int			free_map;
	char		**map;
	int			free_new;
	char		**new;
	int			fd;
	int			free_temp;
	char		*temp;
	int			number;
	int			free_position;
	int			free_objects;
	char		*objects;
	int			free_enemy;
	char		*enemy;
	int			free_entity;
	int			number_entity;
	t_player	me;
	t_position	*position;
	t_entity	*e;
}				t_parsing;

typedef struct	s_wall
{
	int			resolutionx;
	int			resolutiony;
	int			hit;
	int			side;
	double		movespeed;
	double		rotspeed;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		olddir;
	double		oldplane;
	double		planex;
	double		planey;
	double		angle_camera;
	double		raydirx;
	double		raydiry;
	int			rayposx;
	int			rayposy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	double		step;
	double		wallx;
	int			texx;
	int			texy;
	double		texpos;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			free_zbuffer;
	double		*zbuffer;
	int			index;
	double		pitch;
	double		posz;
	int			tab[10];
	double		floorxwall;
	double		floorywall;
	double		distwall;
	double		distplayer;
	double		currentdist;
	double		weight;
	double		currfloorx;
	double		currfloory;
	int			floortexy;
	int			floortexx;
	double		shadefog_r;
	double		shadefog_g;
	double		shadefog_b;
	double		shadedist;
	int			is_door;
	int			offset;
	t_image		*image;
}				t_wall;

typedef struct	s_sprite
{
	int			resolutionx;
	int			resolutiony;
	int			free_dist;
	double		*dist;
	int			xstripe;
	int			ystripe;
	double		spritex;
	double		spritey;
	double		transformx;
	double		transformy;
	int			drawstartx;
	int			drawstarty;
	int			drawendx;
	int			drawendy;
	int			spritescreenx;
	double		inv_det;
	int			spriteh;
	int			spritew;
	int			ytext;
	int			xtext;
	int			color;
	int			movescreen;
	int			number;
	t_position	*sp;
}				t_sprite;

typedef struct	s_minimap
{
	int			len_squarre;
	int			x;
	int			y;
	int			xpixel;
	int			ypixel;
	int			i;
	int			j;
	int			color;
	char		*north;
	char		*west;
	char		*east;
	char		*south;
}				t_minimap;

typedef struct	s_floor
{
	double		raydirx0;
	double		raydiry0;
	double		raydirx1;
	double		raydiry1;
	double		posz;
	double		rowdistance;
	double		floorstepx;
	double		floorstepy;
	double		floorx;
	double		floory;
	int			tx_floor;
	int			ty_floor;
	int			tx_ceiling;
	int			ty_ceiling;
	int			cellx;
	int			celly;
}				t_floor;

typedef struct	s_weapon
{
	int			frame;
	int			fire;
	int			ammo;
	int			slot;
	int			free_gun;
	int			free_knife;
	int			hitbox;
	t_image		*gun;
	t_image		*knife;
}				t_weapon;

typedef struct	s_door
{
	double		angle;
	double		sidedistx;
	double		sidedisty;
	int			rayposx;
	int			rayposy;
	double		deltadistx;
	double		deltadisty;
	double		raydirx;
	double		raydiry;
	int			stepx;
	int			stepy;
	int			hit;
	int			is_door;
	int			offset;
	int			free_e;
	int			number;
	t_entity	*e;
}				t_door;

typedef struct	s_game
{
	t_parsing	parsing;
	t_wall		wall;
	t_sprite	sprite;
	t_image		win;
	t_vars		vars;
	t_bmp		bmp;
	t_minimap	m;
	t_weapon	gun;
	t_floor		floor;
	int			file_bmp;
	time_t		s;
	time_t		frame;
	t_door		d;
	int			x;
	int			y;
}				t_game;

#endif
