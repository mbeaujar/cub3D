/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:18:38 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/13 22:14:29 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw(t_game *g, int nb)
{
	g->sprite.xstripe = g->sprite.drawstartx;
	while (g->sprite.xstripe < g->sprite.drawendx)
	{
		g->sprite.xtext = (int)(256 *
		(g->sprite.xstripe - (-g->sprite.spritew / 2 +
		g->sprite.spritescreenx)) *
		g->wall.image[g->sprite.sp[nb].index].width /
		g->sprite.spritew) / 256;
		if (g->sprite.transformy > 0 && g->sprite.xstripe > 0 &&
		g->sprite.xstripe < g->wall.resolutionx &&
		g->sprite.transformy < g->wall.zbuffer[g->sprite.xstripe])
		{
			calculate_ystripe(g, nb);
		}
		g->sprite.xstripe = g->sprite.xstripe + 1;
	}
}

void	calculate_sprite_2(t_sprite *d)
{
	d->drawstarty = -d->spriteh / 2 + d->resolutiony / 2 + d->movescreen;
	if (d->drawstarty < 0)
		d->drawstarty = 0;
	d->drawendy = d->spriteh / 2 + d->resolutiony / 2 + d->movescreen;
	if (d->drawendy >= d->resolutiony)
		d->drawendy = d->resolutiony;
	d->drawstartx = -d->spritew / 2 + d->spritescreenx;
	if (d->drawstartx < 0)
		d->drawstartx = 0;
	d->drawendx = d->spritew / 2 + d->spritescreenx;
	if (d->drawendx >= d->resolutionx)
		d->drawendx = d->resolutionx - 1;
}

void	calculate_sprite_1(t_sprite *d, int i, t_wall *wall)
{
	d->spritex = d->sp[i].x - wall->posx;
	d->spritey = d->sp[i].y - wall->posy;
	d->inv_det = 1.0 / (wall->planex * wall->diry -
			wall->dirx * wall->planey);
	d->transformx = d->inv_det * (wall->diry * d->spritex -
			wall->dirx * d->spritey);
	d->transformy = d->inv_det * (-wall->planey * d->spritex +
			wall->planex * d->spritey);
	d->spritescreenx = (int)((d->resolutionx / 2) *
			(1 + d->transformx / d->transformy));
	d->movescreen = (int)(0.0 / d->transformy) + wall->pitch +
		wall->posz / d->transformy;
	d->spriteh = fabs((double)(int)(d->resolutiony / (d->transformy))) / 1;
	d->spritew = fabs((double)(int)(d->resolutiony / (d->transformy))) / 1;
}

int		sprites(t_game *game, int nb)
{
	int i;

	i = 0;
	game->gun.hitbox = 0;
	sprites_dist(game, game->parsing.number);
	while (i < nb)
	{
		if (!(game->sprite.sp[i].hp == -1 &&
					game->sprite.sp[i].index >= 8))
		{
			calculate_sprite_1(&game->sprite, i, &game->wall);
			calculate_sprite_2(&game->sprite);
			ft_draw(game, i);
		}
		i++;
	}
	return (1);
}
