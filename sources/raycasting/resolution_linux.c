/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_linux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:06:50 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 13:55:11 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_screensize(t_game *game)
{
	int x;
	int y;

	mlx_get_screen_size(game->vars.mlx, &x, &y);
	if (game->wall.resolutionx > x)
		game->wall.resolutionx = x;
	if (game->wall.resolutiony > y)
		game->wall.resolutiony = y;
	if (game->wall.resolutionx < 800)
		game->wall.resolutionx = 800;
	if (game->wall.resolutiony < 600)
		game->wall.resolutiony = 600;
}
