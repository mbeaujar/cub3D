/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:58:07 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:40:15 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	open_xpm(t_image *file, t_game *game)
{
	int i;

	i = 0;
	while (i < 5)
	{
		file[i].text = mlx_xpm_file_to_image(game->vars.mlx,
				file[i].path,
				&file[i].width,
				&file[i].height);
		if (file[i].text == NULL)
			quit_game(game, "Error : can't read textures weapon.\n");
		file[i].addr = mlx_get_data_addr(file[i].text,
				&file[i].bits_per_pixel,
				&file[i].line_length,
				&file[i].endian);
		i++;
	}
}

void	music(void)
{
	int pid;

	pid = -1;
	pid = fork();
	if (OS == 1)
		(pid == 0) ? system("afplay ./textures/sound/shot.wav") : 0;
	else
		(pid == 0) ? system("aplay ./textures/sound/shot.wav") : 0;
	(pid == 0) ? exit(0) : 0;
}

int		shadecolor(t_wall *p, double dist, int color)
{
	int r;
	int g;
	int b;

	r = ((color >> 16) & 0xFF) * (1 / dist * p->shadedist) * p->shadefog_r;
	g = ((color >> 8) & 0xFF) * (1 / dist * p->shadedist) * p->shadefog_g;
	b = (color & 0xFF) * (1 / dist * p->shadedist) * p->shadefog_b;
	r = ((r > 255) ? 255 : r);
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	color = (r << 16);
	color += (g << 8);
	color += b;
	return (color);
}

int		shade(t_game *g, double dist, int color)
{
	if (BONUS_SHADOW == 1)
	{
		if (g->gun.fire == 1 && g->gun.slot == 1)
			return (shadecolor_fire(&g->wall, dist, color));
		else
			return (shadecolor(&g->wall, dist, color));
	}
	return (color);
}

int		shadecolor_fire(t_wall *p, double dist, int color)
{
	int r;
	int g;
	int b;

	r = ((color >> 16) & 0xFF) * (1 / dist * p->shadedist * 1.5);
	g = ((color >> 8) & 0xFF) * (1 / dist * p->shadedist * 1.5);
	b = (color & 0xFF) * (1 / dist * p->shadedist * 1.5);
	r = ((r > 255) ? 255 : r);
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	color = (r << 16);
	color += (g << 8);
	color += b;
	return (color);
}
