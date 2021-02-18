/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:35:36 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/09 16:11:13 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	header_bmp(t_wall *wall, t_bmp *bmp)
{
	bmp->file_size = bmp->pixel_data_offset + (wall->resolutionx *
			wall->resolutiony * 4);
	write(bmp->fd, "BM", 2);
	write(bmp->fd, &bmp->file_size, 4);
	write(bmp->fd, "\0\0\0\0", 4);
	write(bmp->fd, &bmp->pixel_data_offset, 4);
}

void	info_img_bmp(t_wall *wall, t_bmp *bmp, t_image *win)
{
	bmp->img_size = wall->resolutionx * wall->resolutiony;
	write(bmp->fd, &bmp->header_size, 4);
	write(bmp->fd, &wall->resolutionx, 4);
	write(bmp->fd, &wall->resolutiony, 4);
	write(bmp->fd, &bmp->plane, 2);
	write(bmp->fd, &win->bits_per_pixel, 2);
	write(bmp->fd, "\0\0\0\0", 4);
	write(bmp->fd, &bmp->img_size, 4);
	write(bmp->fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	fill_bmp(t_wall *wall, t_bmp *bmp, t_image *win)
{
	int tab[3];
	int x;
	int y;

	y = wall->resolutiony - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < wall->resolutionx)
		{
			tab[0] = win->addr[y * win->line_length +
				x * win->bits_per_pixel / 8];
			tab[1] = win->addr[y * win->line_length +
				x * win->bits_per_pixel / 8 + 1];
			tab[2] = win->addr[y * win->line_length +
				x * win->bits_per_pixel / 8 + 2];
			write(bmp->fd, &tab[0], 1);
			write(bmp->fd, &tab[1], 1);
			write(bmp->fd, &tab[2], 1);
			write(bmp->fd, "\0", 1);
			x++;
		}
		y--;
	}
}

void	file_bmp(t_game *game)
{
	game->bmp.pixel_data_offset = 54;
	game->bmp.header_size = 40;
	game->bmp.plane = 1;
	if ((game->bmp.fd = open("save.bmp", O_CREAT | O_RDWR, S_IRWXU)) == -1)
		error_message("Error : can't create file bmp.\n");
	header_bmp(&game->wall, &game->bmp);
	info_img_bmp(&game->wall, &game->bmp, &game->win);
	fill_bmp(&game->wall, &game->bmp, &game->win);
	close(game->bmp.fd);
}
