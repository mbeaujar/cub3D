/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:24:40 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:59:17 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	hitbox(t_game *g, int trgb)
{
	if (g->sprite.xstripe == (g->wall.resolutionx / 2) &&
			g->sprite.ystripe == (g->wall.resolutiony / 2) &&
			(trgb & 0x00FFFFFF) != 0)
		g->gun.hitbox = 1;
}

void	calculate_ystripe_normi(t_game *g, int nb)
{
	char *i;

	g->sprite.color = (g->sprite.ystripe -
			g->sprite.movescreen) *
		256 -
		g->sprite.resolutiony * 128 + g->sprite.spriteh * 128;
	g->sprite.ytext = ((g->sprite.color *
				g->wall.image[g->sprite.sp[nb].index].height) /
			g->sprite.spriteh) /
		256;
	i = g->wall.image[g->sprite.sp[nb].index].addr +
	((4 * g->wall.image[g->sprite.sp[nb].index].width) * g->sprite.ytext) +
	(4 * g->sprite.xtext);
	g->sprite.color = *(unsigned int*)i;
	hitbox(g, g->sprite.color);
	g->sprite.color = (g->sprite.color >> 1) & 8355711;
}

void	calculate_ystripe(t_game *g, int nb)
{
	g->sprite.ystripe = g->sprite.drawstarty;
	while (g->sprite.ystripe < g->sprite.drawendy)
	{
		calculate_ystripe_normi(g, nb);
		if ((g->sprite.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&g->win, g->sprite.xstripe,
					g->sprite.ystripe,
					shade(g,
						g->sprite.dist[nb] > g->wall.shadedist ?
						g->sprite.dist[nb] : g->wall.shadedist,
						g->sprite.color));
		g->sprite.ystripe = g->sprite.ystripe + 1;
	}
}
