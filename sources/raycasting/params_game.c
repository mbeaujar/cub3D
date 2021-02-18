/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:36:03 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 13:56:40 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_game_part_2(t_wall *wall, t_parsing *parsing,
		t_sprite *sprite, t_game *game)
{
	sprite->number = parsing->number;
	sprite->sp = parsing->position;
	wall->resolutionx = parsing->resolutionx;
	wall->resolutiony = parsing->resolutiony;
	check_screensize(game);
	sprite->resolutionx = wall->resolutionx;
	sprite->resolutiony = wall->resolutiony;
	game->d.e = parsing->e;
	game->d.free_e = parsing->free_entity;
	game->d.number = parsing->number_entity;
	wall->free_zbuffer = 0;
	if (!(wall->zbuffer = malloc(sizeof(double) * wall->resolutionx)))
		quit_parsing(parsing, "Error : malloc for zbuffer return NULL.\n");
	wall->free_zbuffer = 1;
	sprite->free_dist = 0;
	if (!(sprite->dist = malloc(sizeof(double) * parsing->number)))
		quit_parsing(parsing, "Error : malloc for sprite return NULL.\n");
	sprite->free_dist = 1;
}

void	set_game(t_wall *wall, t_parsing *parsing,
		t_sprite *sprite, t_game *game)
{
	int i;

	i = 0;
	while (i < 10)
		wall->tab[i++] = 1000;
	wall->movespeed = 0.2;
	wall->rotspeed = 0.1;
	game->vars.win = NULL;
	game->vars.img = NULL;
	wall->index = 0;
	wall->pitch = 0;
	wall->posz = 0;
	wall->posx = parsing->me.posx;
	wall->posy = parsing->me.posy;
	wall->distplayer = 0.0;
	wall->shadefog_b = 1;
	wall->shadefog_r = 1;
	wall->shadefog_g = 1;
	wall->shadedist = 4;
	set_game_part_2(wall, parsing, sprite, game);
}

void	set_struct_part_2(t_parsing *parsing)
{
	parsing->sprite = NULL;
	parsing->trgb_ceiling = -1;
	parsing->trgb_floor = -1;
	parsing->map = NULL;
	parsing->fd = -1;
	parsing->temp = NULL;
	parsing->free_position = -1;
	parsing->new = NULL;
	parsing->free_map = 0;
	parsing->free_new = 0;
	parsing->free_temp = 0;
	parsing->free_objects = 0;
	parsing->objects = NULL;
	parsing->free_enemy = 0;
	parsing->enemy = NULL;
}

void	set_struct(t_parsing *parsing)
{
	parsing->resolutionx = -1;
	parsing->resolutiony = -1;
	parsing->free_ceiling = 0;
	parsing->free_floor = 0;
	parsing->free_north = 0;
	parsing->free_west = 0;
	parsing->free_east = 0;
	parsing->free_south = 0;
	parsing->free_sprite = 0;
	parsing->north = NULL;
	parsing->west = NULL;
	parsing->east = NULL;
	parsing->south = NULL;
	parsing->ceiling = NULL;
	parsing->floor = NULL;
	parsing->free_entity = 0;
	set_struct_part_2(parsing);
}
