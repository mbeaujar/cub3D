/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:22:50 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 15:16:15 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	show_fps(t_game *game)
{
	static int	fps = 0;
	static int	frame = 0;
	char		*str;

	if (frame == 0)
		game->s = time(NULL);
	if (time(NULL) - game->s >= 1)
	{
		fps = frame;
		frame = 0;
		game->s = time(NULL);
	}
	mlx_string_put(game->vars.mlx, game->vars.win, 10, 10, 0xFFFFFF, "fps :");
	str = ft_itoa(fps);
	mlx_string_put(game->vars.mlx, game->vars.win, 55, 10, 0xFFFFFF,
			str);
	free(str);
	frame++;
}
