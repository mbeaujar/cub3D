/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:15:51 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/14 15:06:37 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_wall(t_wall *d)
{
	if (d->side == 1)
	{
		if (d->raydiry < 0)
			d->index = 2;
		else
			d->index = 1;
	}
	else
	{
		if (d->raydirx < 0)
			d->index = 0;
		else
			d->index = 3;
	}
	if (d->is_door == 1)
		d->index = 12;
}

void	step_and_initial_side_dist(t_wall *d)
{
	if (d->raydirx < 0)
	{
		d->stepx = -1;
		d->sidedistx = (d->posx - d->rayposx) * d->deltadistx;
	}
	else
	{
		d->stepx = 1;
		d->sidedistx = (d->rayposx + 1.0 - d->posx) * d->deltadistx;
	}
	if (d->raydiry < 0)
	{
		d->stepy = -1;
		d->sidedisty = (d->posy - d->rayposy) * d->deltadisty;
	}
	else
	{
		d->stepy = 1;
		d->sidedisty = (d->rayposy + 1.0 - d->posy) * d->deltadisty;
	}
}

void	ray_direction(t_game *g, int x)
{
	g->wall.hit = 0;
	g->wall.angle_camera = (2 * x / (double)g->wall.resolutionx) - 1;
	g->wall.raydirx = g->wall.dirx + g->wall.planex * g->wall.angle_camera;
	g->wall.raydiry = g->wall.diry + g->wall.planey * g->wall.angle_camera;
	g->wall.rayposx = (int)g->wall.posx;
	g->wall.rayposy = (int)g->wall.posy;
	g->wall.deltadistx = fabs(1 / g->wall.raydirx);
	g->wall.deltadisty = fabs(1 / g->wall.raydiry);
	step_and_initial_side_dist(&g->wall);
	algorithm_dda(g);
	if (g->wall.side == 0)
		g->wall.perpwalldist = (g->wall.rayposx - g->wall.posx +
				(1 - g->wall.stepx) / 2) / g->wall.raydirx;
	else
		g->wall.perpwalldist = (g->wall.rayposy - g->wall.posy +
				(1 - g->wall.stepy) / 2) / g->wall.raydiry;
}
