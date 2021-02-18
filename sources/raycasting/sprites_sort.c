/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:21:21 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:34:28 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sort_sprites(t_sprite *sprite, int nb)
{
	int			i;
	double		tmp;
	t_position	temp;

	i = 1;
	if (nb == 1)
		return ;
	while (i < nb)
	{
		if (sprite->dist[i - 1] < sprite->dist[i])
		{
			tmp = sprite->dist[i - 1];
			sprite->dist[i - 1] = sprite->dist[i];
			sprite->dist[i] = tmp;
			temp = sprite->sp[i - 1];
			sprite->sp[i - 1] = sprite->sp[i];
			sprite->sp[i] = temp;
			i = 1;
		}
		else
		{
			i++;
		}
	}
}

void	sprites_dist(t_game *game, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		game->sprite.dist[i] = (game->wall.posx -
				game->sprite.sp[i].x) *
			(game->wall.posx - game->sprite.sp[i].x) *
			(game->wall.posy - game->sprite.sp[i].y) *
			(game->wall.posy - game->sprite.sp[i].y);
		i++;
	}
	sort_sprites(&game->sprite, game->parsing.number);
}
