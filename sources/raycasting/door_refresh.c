/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_refresh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:02:50 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:46:30 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	refresh_door(t_door *d)
{
	int i;

	i = 0;
	while (i < d->number)
	{
		if (d->e[i].action == 7 && d->e[i].offset > 0)
			d->e[i].offset -= 5;
		if (d->e[i].action == 8 && d->e[i].offset < d->e[i].max_offset)
			d->e[i].offset += 5;
		if ((d->e[i].offset < 0))
			d->e[i].offset = 0;
		i++;
	}
}

int		recup_offset(t_door *d)
{
	int i;

	i = 0;
	while (i < d->number)
	{
		if (d->e[i].draw == 1)
			return (d->e[i].offset);
		i++;
	}
	return (128);
}

void	clean_draw(t_door *d)
{
	int i;

	i = 0;
	while (i < d->number)
	{
		d->e[i].draw = 0;
		i++;
	}
}

int		is_draw(t_game *g)
{
	int i;

	i = 0;
	while (i < g->d.number)
	{
		if (g->d.e[i].draw == 1 && g->wall.is_door == 1)
		{
			if (g->wall.offset < g->d.e[i].offset)
				return (1);
		}
		i++;
	}
	return (0);
}

void	dooring(t_game *g)
{
	int		i;
	double	dist;

	i = 0;
	dist = g->wall.sidedistx > g->wall.sidedisty ?
		g->wall.sidedistx : g->wall.sidedisty;
	while (i < g->d.number)
	{
		if (g->d.e[i].x == g->wall.rayposx && g->d.e[i].y == g->wall.rayposy)
		{
			door_close(g, i, dist);
			door_opening(g, i);
			door_open(g, i, dist);
			door_closing(g, i);
			secret_door(g, i, dist);
		}
		i++;
	}
}
