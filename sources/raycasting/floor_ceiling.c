/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:12:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:21:55 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fast_ceiling(t_game *g, int x, int y, int trgb)
{
	g->wall.currentdist = (g->wall.resolutiony - (2.0 * g->wall.posz)) /
		(g->wall.resolutiony - 2.0 * (y - g->wall.pitch));
	g->wall.weight = (g->wall.currentdist - g->wall.distplayer) /
		(g->wall.distwall - g->wall.distplayer);
	g->wall.currfloorx = g->wall.weight * g->wall.floorxwall +
		(1.0 - g->wall.weight) * g->wall.posx;
	g->wall.currfloory = g->wall.weight * g->wall.floorywall +
		(1.0 - g->wall.weight) * g->wall.posy;
	g->wall.floortexx = (int)(g->wall.currfloorx * g->wall.image[5].width) &
		(g->wall.image[5].width - 1);
	g->wall.floortexy = (int)(g->wall.currfloory * g->wall.image[5].height) &
		(g->wall.image[5].height - 1);
	trgb = *(unsigned int *)(g->wall.image[5].addr +
			(4 * g->wall.image[5].width * g->wall.floortexy) +
			(4 * g->wall.floortexx));
	trgb = (trgb >> 1) & 8355711;
	my_mlx_pixel_put(&g->win, x, y,
			shade(g, g->wall.currentdist > g->wall.shadedist ?
				g->wall.currentdist : g->wall.shadedist, trgb));
}

void	fast_floor(t_game *g, int x, int y, int trgb)
{
	g->wall.currentdist = (g->wall.resolutiony + (2.0 * g->wall.posz)) /
		(2.0 * (y - g->wall.pitch) - g->wall.resolutiony);
	g->wall.weight = (g->wall.currentdist - g->wall.distplayer) /
		(g->wall.distwall - g->wall.distplayer);
	g->wall.currfloorx = g->wall.weight * g->wall.floorxwall +
		(1.0 - g->wall.weight) * g->wall.posx;
	g->wall.currfloory = g->wall.weight * g->wall.floorywall +
		(1.0 - g->wall.weight) * g->wall.posy;
	g->wall.floortexx = (int)(g->wall.currfloorx * g->wall.image[6].width) &
		(g->wall.image[6].width - 1);
	g->wall.floortexy = (int)(g->wall.currfloory * g->wall.image[6].height) &
		(g->wall.image[6].height - 1);
	trgb = *(unsigned int *)(g->wall.image[6].addr +
			(4 * g->wall.image[6].width * g->wall.floortexy) +
			(4 * g->wall.floortexx));
	trgb = (trgb >> 1) & 8355711;
	my_mlx_pixel_put(&g->win, x, y,
			shade(g, g->wall.currentdist > g->wall.shadedist ?
				g->wall.currentdist : g->wall.shadedist, trgb));
}

void	fast(t_game *g, int x)
{
	int y;
	int trgb;
	int j;

	set_floor(g);
	g->wall.distwall = g->wall.perpwalldist;
	if (g->wall.drawend < 0)
		g->wall.drawend = g->wall.resolutiony;
	y = g->wall.drawend + 1;
	trgb = 0;
	j = 0;
	while ((y < g->wall.resolutiony) || (j < g->wall.drawstart))
	{
		if (y < g->wall.resolutiony)
			fast_floor(g, x, y, trgb);
		if (j < g->wall.drawstart)
			fast_ceiling(g, x, j, trgb);
		y++;
		j++;
	}
}

void	set_floor(t_game *g)
{
	if (g->wall.side == 0 && g->wall.raydirx > 0)
	{
		g->wall.floorxwall = g->wall.rayposx;
		g->wall.floorywall = g->wall.rayposy + g->wall.wallx;
	}
	else if (g->wall.side == 0 && g->wall.raydirx < 0)
	{
		g->wall.floorxwall = g->wall.rayposx + 1.0;
		g->wall.floorywall = g->wall.rayposy + g->wall.wallx;
	}
	else if (g->wall.side == 1 && g->wall.raydiry > 0)
	{
		g->wall.floorxwall = g->wall.rayposx + g->wall.wallx;
		g->wall.floorywall = g->wall.rayposy;
	}
	else
	{
		g->wall.floorxwall = g->wall.rayposx + g->wall.wallx;
		g->wall.floorywall = g->wall.rayposy + 1.0;
	}
}
