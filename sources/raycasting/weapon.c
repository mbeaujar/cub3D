/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:01:07 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/18 12:01:58 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_weapon(t_image *w, t_image *win, int x, int y)
{
	unsigned int	i;
	unsigned int	j;
	char			*color;

	i = 0;
	while ((int)i < w->width)
	{
		j = 0;
		while ((int)j < w->height)
		{
			color = w->addr + ((4 * w->width * j) + (4 * i));
			if (*(unsigned int *)color != NONE)
				my_mlx_pixel_put(win, i + x, j + y, *(unsigned int *)color);
			j++;
		}
		i++;
	}
}

void	params_image_weapon(t_weapon *w, t_game *game)
{
	w->fire = 0;
	w->ammo = 100;
	w->frame = 0;
	w->slot = 2;
	w->free_gun = 0;
	if (!(w->gun = malloc(sizeof(t_image) * 5)))
		quit_game(game, "Error : malloc struct gun return NULL.\n");
	w->free_gun = 1;
	w->gun[0].path = "./textures/weapon/gun1.xpm";
	w->gun[1].path = "./textures/weapon/gun2.xpm";
	w->gun[2].path = "./textures/weapon/gun3.xpm";
	w->gun[3].path = "./textures/weapon/gun4.xpm";
	w->gun[4].path = "./textures/weapon/gun5.xpm";
	open_xpm(w->gun, game);
	w->free_knife = 0;
	if (!(w->knife = malloc(sizeof(t_image) * 5)))
		quit_game(game, "Error : malloc struct gun return NULL.\n");
	w->free_knife = 1;
	w->knife[0].path = "./textures/weapon/knife1.xpm";
	w->knife[1].path = "./textures/weapon/knife2.xpm";
	w->knife[2].path = "./textures/weapon/knife3.xpm";
	w->knife[3].path = "./textures/weapon/knife4.xpm";
	w->knife[4].path = "./textures/weapon/knife5.xpm";
	open_xpm(w->knife, game);
}

void	gun(t_wall *wall, t_weapon *w, t_game *g)
{
	if (w->frame == 4)
		w->frame = 0;
	if (w->frame > 0)
	{
		w->fire = 0;
		draw_weapon(&w->gun[w->frame], &g->win, wall->resolutionx / 2 -
				(w->gun[w->frame].width / 2),
				wall->resolutiony - w->gun[w->frame].height);
		w->frame++;
	}
	else
		draw_weapon(&w->gun[0], &g->win, wall->resolutionx / 2 -
				(w->gun[0].width / 2), wall->resolutiony - w->gun[0].height);
}

void	knife(t_wall *wall, t_weapon *w, t_game *g)
{
	if (w->frame == 4)
		w->frame = 0;
	if (w->frame > 0)
	{
		w->fire = 0;
		draw_weapon(&w->knife[w->frame], &g->win,
				wall->resolutionx / 2 - (w->knife[w->frame].width / 2),
				wall->resolutiony - w->knife[w->frame].height);
		w->frame++;
	}
	else
		draw_weapon(&w->knife[0], &g->win,
				wall->resolutionx / 2 - (w->knife[0].width / 2),
				wall->resolutiony - w->knife[0].height);
}

void	weapon(t_game *game, t_weapon *w)
{
	int pid;

	pid = -1;
	my_mlx_pixel_put(&game->win, game->wall.resolutionx / 2,
			game->wall.resolutiony / 2, 0xFFFFFF);
	if (w->fire == 1)
	{
		if (w->slot == 1 && w->ammo > 0)
		{
			if (SOUND == 1)
			{
				pid = fork();
				if (OS == 1)
					(pid == 0) ? system("afplay ./textures/sound/shot.wav") : 0;
				else
					(pid == 0) ? system("aplay ./textures/sound/shot.wav") : 0;
				(pid == 0) ? exit(0) : 0;
			}
		}
		w->frame = 1;
	}
	if (w->slot == 1)
		gun(&game->wall, w, game);
	if (w->slot == 2)
		knife(&game->wall, w, game);
}
