/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:15:59 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 17:10:52 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	start_end_wall(t_wall *d)
{
	d->lineheight = (int)(d->resolutiony / d->perpwalldist);
	d->drawstart = -d->lineheight / 2 + d->resolutiony / 2 +
		d->pitch + (d->posz / d->perpwalldist);
	d->drawend = d->lineheight / 2 + d->resolutiony / 2 +
		d->pitch + (d->posz / d->perpwalldist);
	if (d->drawstart < 0)
		d->drawstart = 0;
	if (d->drawend >= d->resolutiony || d->drawend < 0)
		d->drawend = d->resolutiony - 1;
	if (d->side == 0)
		d->wallx = d->posy + d->perpwalldist * d->raydiry;
	else
		d->wallx = d->posx + d->perpwalldist * d->raydirx;
	set_wall(d);
}

void	draw_wall(t_game *g, int x)
{
	int	begin;

	begin = 0;
	while (g->parsing.trgb_ceiling != -1 && begin < g->wall.drawstart)
	{
		my_mlx_pixel_put(&g->win, x, begin, g->parsing.trgb_ceiling);
		begin++;
	}
	if (B_DOOR == 1 && is_draw(g))
		door(g, x);
	else
		drawing_wall(g, x);
	while (g->parsing.trgb_floor != -1 && g->wall.drawend < g->wall.resolutiony)
	{
		my_mlx_pixel_put(&g->win, x, g->wall.drawend, g->parsing.trgb_floor);
		g->wall.drawend++;
	}
}

void	wall(t_game *game)
{
	int x;

	x = 0;
	while (x < game->wall.resolutionx)
	{
		ray_direction(game, x);
		start_end_wall(&game->wall);
		param_textures(game);
		draw_wall(game, x);
		game->wall.zbuffer[x] = game->wall.perpwalldist;
		if (game->parsing.trgb_ceiling == -1 || game->parsing.trgb_floor == -1)
			fast(game, x);
		x += 1;
	}
}

void	param_textures(t_game *g)
{
	g->wall.wallx -= floor((g->wall.wallx));
	g->wall.texx = (int)(g->wall.wallx *
			(double)(g->wall.image[g->wall.index].width));
	if (g->wall.side == 0 && g->wall.raydirx > 0)
		g->wall.texx = g->wall.image[g->wall.index].width - g->wall.texx - 1;
	if (g->wall.side == 1 && g->wall.raydiry < 0)
		g->wall.texx = g->wall.image[g->wall.index].width - g->wall.texx - 1;
	g->wall.step = 1.0 * g->wall.image[g->wall.index].height /
		g->wall.lineheight;
	g->wall.texpos = (g->wall.drawstart - g->wall.pitch -
			(g->wall.posz / g->wall.perpwalldist) -
			g->wall.resolutiony / 2 + g->wall.lineheight / 2) *
		g->wall.step;
}

void	drawing_wall(t_game *g, int x)
{
	int j;
	int trgb;

	j = g->wall.drawstart;
	while (j < g->wall.drawend)
	{
		g->wall.texy = (int)g->wall.texpos &
			(g->wall.image[g->wall.index].height - 1);
		g->wall.texpos += g->wall.step;
		trgb = *(unsigned int *)(g->wall.image[g->wall.index].addr +
				(4 * g->wall.image[g->wall.index].width * g->wall.texy) +
				(4 * g->wall.texx));
		trgb = (trgb >> 1) & 8355711;
		my_mlx_pixel_put(&g->win, x, j,
				shade(g, g->wall.perpwalldist > g->wall.shadedist ?
					g->wall.perpwalldist : g->wall.shadedist, trgb));
		j++;
	}
}
