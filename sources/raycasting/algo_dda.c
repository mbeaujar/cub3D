/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:06:00 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 09:58:27 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rayon_dda(t_game *g)
{
	if (g->wall.sidedistx < g->wall.sidedisty)
	{
		g->wall.sidedistx += g->wall.deltadistx;
		g->wall.rayposx += g->wall.stepx;
		g->wall.side = 0;
	}
	else
	{
		g->wall.sidedisty += g->wall.deltadisty;
		g->wall.rayposy += g->wall.stepy;
		g->wall.side = 1;
	}
	if (BONUS_ENEMY == 1 &&
			g->parsing.map[g->wall.rayposx][g->wall.rayposy] == '4')
		seen_enemy(&g->sprite,
				g->wall.rayposx,
				g->wall.rayposy, g->wall.side == 0 ?
				g->wall.sidedistx : g->wall.sidedisty);
	if (B_DOOR == 1)
		dooring(g);
}

void	algorithm_dda(t_game *g)
{
	int no_wallbang;

	no_wallbang = 0;
	if (B_DOOR == 1)
		clean_draw(&g->d);
	g->wall.is_door = 0;
	while (g->wall.hit == 0)
	{
		rayon_dda(g);
		if (WEAPON == 1 && g->gun.fire == 1 &&
				g->wall.angle_camera == 0 &&
				g->parsing.map[g->wall.rayposx][g->wall.rayposy] == '4' &&
				no_wallbang == 0)
		{
			no_wallbang++;
			enemy(g->wall.rayposx, g->wall.rayposy, g);
		}
		if (g->parsing.map[g->wall.rayposx][g->wall.rayposy] == '1')
			g->wall.hit = 1;
	}
}
