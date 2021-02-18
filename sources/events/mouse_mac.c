/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:01:16 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 15:37:25 by mbeaujar         ###   ########.fr       */
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

void	mouse_horizontal(t_game *game, int diffx)
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
}

void	mouse_vertical(t_game *game, int diffy)
{
	int speed;

	speed = 30;
	if (diffy > 0)
	{
		while (diffy > 0)
		{
			if (game->wall.pitch + speed < 300)
				game->wall.pitch += speed * game->wall.movespeed;
			diffy -= speed;
		}
	}
	else if (diffy < 0)
	{
		while (diffy < 0)
		{
			if (game->wall.pitch - speed > -300)
				game->wall.pitch -= speed * game->wall.movespeed;
			diffy += speed;
		}
	}
}

int		mouse(int x, int y, t_game *game)
{
	int		diffx;
	int		diffy;
	double	temp;

	mlx_mouse_get_pos(game->vars.win, &x, &y);
	diffx = (game->wall.resolutionx / 2) - x;
	diffy = (game->wall.resolutiony / 2) - y;
	temp = game->wall.rotspeed;
	game->wall.rotspeed /= 5;
	mouse_horizontal(game, diffx);
	mouse_vertical(game, diffy);
	mlx_mouse_move(game->vars.win, game->wall.resolutionx / 2,
			game->wall.resolutiony / 2);
	game->wall.rotspeed = temp;
	return (1);
}

void	hook_mouse(t_game *game)
{
	mlx_mouse_hide();
	mlx_hook(game->vars.win, 6, 0x40, mouse, game);
	mlx_hook(game->vars.win, 4, 0x4, mouse_press, game);
}
