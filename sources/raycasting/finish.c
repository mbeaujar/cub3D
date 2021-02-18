/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 21:36:14 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 13:49:16 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	black_screen(t_image *win, t_wall *d)
{
	int i;
	int j;

	i = 0;
	while (i < d->resolutionx)
	{
		j = 0;
		while (j < d->resolutiony)
		{
			my_mlx_pixel_put(win, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

void	finish(t_player *me, t_game *game)
{
	mlx_create_image(game);
	black_screen(&game->win, &game->wall);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->vars.img, 0, 0);
	if (me->hp <= 0)
		mlx_string_put(game->vars.mlx, game->vars.win,
				game->wall.resolutionx / 2 - 35,
				game->wall.resolutiony / 2, 0xFFFFFF, "Game Over !");
	else
		mlx_string_put(game->vars.mlx, game->vars.win,
				game->wall.resolutionx / 2 - 35,
				game->wall.resolutiony / 2, 0xFFFFFF, "Game finish !");
}

void	player(t_player *me, t_game *game)
{
	if (me->hp <= 0 || me->score >= 1500)
		finish(me, game);
}
