/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:26:30 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:34:47 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	old_hud(t_game *game)
{
	char *str;

	str = ft_itoa(game->gun.ammo);
	mlx_string_put(game->vars.mlx, game->vars.win,
			game->wall.resolutionx - 25, game->wall.resolutiony - 15,
			0xFFFFFF, str);
	free(str);
	mlx_string_put(game->vars.mlx,
			game->vars.win, game->wall.resolutionx - 75,
			game->wall.resolutiony - 15, 0xFFFFFF, "ammo :");
	mlx_string_put(game->vars.mlx,
			game->vars.win, 5, game->wall.resolutiony - 15,
			0xFFFFFF, "Score :");
	str = ft_itoa(game->parsing.me.score);
	mlx_string_put(game->vars.mlx,
			game->vars.win, 55, game->wall.resolutiony - 15,
			0xFFFFFF, str);
	free(str);
}

void	hud(t_game *game)
{
	old_hud(game);
	show_fps(game);
}
