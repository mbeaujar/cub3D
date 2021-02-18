/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:22:35 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:38:33 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_step(t_door *d, t_wall *w, int x)
{
	d->hit = 0;
	d->angle = (2 * x / (double)w->resolutionx) - 1;
	d->raydirx = w->dirx + w->planex * d->angle;
	d->raydiry = w->diry + w->planey * d->angle;
	d->rayposx = (int)w->posx;
	d->rayposy = (int)w->posy;
	d->deltadistx = fabs(1 / d->raydirx);
	d->deltadisty = fabs(1 / d->raydiry);
}

void	set_step(t_door *d, t_wall *w, int x)
{
	init_step(d, w, x);
	if (d->raydirx < 0)
	{
		d->stepx = -1;
		d->sidedistx = (w->posx - d->rayposx) * d->deltadistx;
	}
	else
	{
		d->stepx = 1;
		d->sidedistx = (d->rayposx + 1.0 - w->posx) * d->deltadistx;
	}
	if (d->raydiry < 0)
	{
		d->stepy = -1;
		d->sidedisty = (w->posy - d->rayposy) * d->deltadisty;
	}
	else
	{
		d->stepy = 1;
		d->sidedisty = (d->rayposy + 1.0 - w->posy) * d->deltadisty;
	}
}

void	door_dda(t_door *d, char **map)
{
	if (d->sidedistx < d->sidedisty)
	{
		d->sidedistx += d->deltadistx;
		d->rayposx += d->stepx;
	}
	else
	{
		d->sidedisty += d->deltadisty;
		d->rayposy += d->stepy;
	}
	if (map[d->rayposx][d->rayposy] == '5' ||
			map[d->rayposx][d->rayposy] == '6')
	{
		d->hit = 1;
		d->is_door = 1;
	}
	if (map[d->rayposx][d->rayposy] == '1' ||
			map[d->rayposx][d->rayposy] == '7' ||
			map[d->rayposx][d->rayposx] == '8')
	{
		d->is_door = 0;
		d->hit = 1;
	}
}

void	set_offset(t_game *game, int indice)
{
	int i;

	i = ((game->wall.angle_camera + 1) * game->wall.resolutionx) / 2;
	game->d.is_door = 1;
	game->d.e[indice].offset = 0;
	while (game->d.is_door == 1)
	{
		set_step(&game->d, &game->wall, i);
		while (game->d.hit == 0)
		{
			door_dda(&game->d, game->parsing.map);
		}
		i++;
		game->d.e[indice].offset++;
	}
}

void	door(t_game *g, int x)
{
	int		j;
	int		trgb;
	double	percent;

	j = g->wall.drawstart;
	percent = (((double)g->wall.offset / (double)recup_offset(&g->d))) * 100;
	g->wall.texx = g->wall.image[g->wall.index].width -
		(g->wall.image[g->wall.index].width * percent) / 100;
	while (j < g->wall.drawend)
	{
		g->wall.texy = (int)g->wall.texpos &
			(g->wall.image[g->wall.index].height - 1);
		g->wall.texpos += g->wall.step;
		trgb = *(unsigned int *)(g->wall.image[g->wall.index].addr +
				(4 * g->wall.image[g->wall.index].width * g->wall.texy) +
				(4 * (g->wall.texx)));
		trgb = (trgb >> 1) & 8355711;
		my_mlx_pixel_put(&g->win, x, j,
				shade(g, g->wall.perpwalldist > g->wall.shadedist ?
					g->wall.perpwalldist : g->wall.shadedist, trgb));
		j++;
	}
	g->wall.offset++;
}
