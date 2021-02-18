/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:59:21 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/18 11:36:34 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		mouse_press(int button, int x, int y, t_game *game)
{
	if (button == 1 && game->gun.fire == 0)
	{
		game->gun.fire = 1;
		if (game->gun.slot == 1)
			game->gun.ammo--;
	}
	if (x && y)
		return (1);
	return (1);
}

void	mouse_horizontal(t_game *game, int diffx, int x, int y)
{
	int speed;

	speed = 15;
	diffx = diffx > 6 ? 6 : diffx;
	diffx = diffx < -6 ? -6 : diffx;
	if (diffx > 0)
	{
		while (diffx-- > 0)
			rotation_left(&game->wall);
	}
	else if (diffx < 0)
	{
		while (diffx++ < 0)
			rotation_right(&game->wall);
	}
	if (x < (game->wall.resolutionx * 0.25) ||
	x > (game->wall.resolutionx * 0.85))
		mlx_mouse_move(game->vars.mlx, game->vars.win,
		game->wall.resolutionx / 2, y);
	game->x = x;
}

void	mouse_vertical(t_game *game, int diffy, int x, int y)
{
	if (diffy > 0)
	{
		while (diffy > 0)
		{
			if (game->wall.pitch + 30 < 300)
				game->wall.pitch += 30 * game->wall.movespeed;
			diffy -= 30;
		}
	}
	else if (diffy < 0)
	{
		while (diffy < 0)
		{
			if (game->wall.pitch - 30 > -300)
				game->wall.pitch -= 30 * game->wall.movespeed;
			diffy += 30;
		}
	}
	if (y < (game->wall.resolutiony * 0.25) ||
	y > (game->wall.resolutiony * 0.85))
		mlx_mouse_move(game->vars.mlx, game->vars.win, x,
		game->wall.resolutiony / 2);
	game->y = y;
}

int		mouse(int x, int y, t_game *game)
{
	int		diffx;
	int		diffy;
	double	temp;

	diffx = (game->x) - x;
	diffy = (game->y) - y;
	temp = game->wall.rotspeed;
	game->wall.rotspeed /= 5;
	mouse_horizontal(game, diffx, x, y);
	mouse_vertical(game, diffy, x, y);
	game->wall.rotspeed = temp;
	return (1);
}

void	hook_mouse(t_game *game)
{
	mlx_mouse_get_pos(game->vars.mlx, game->vars.win, &game->x, &game->y);
	mlx_mouse_hide(game->vars.mlx, game->vars.win);
	mlx_hook(game->vars.win, 6, 0x40, mouse, game);
	mlx_hook(game->vars.win, 4, 0x4, mouse_press, game);
}
