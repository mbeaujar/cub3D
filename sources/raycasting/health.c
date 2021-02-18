/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:56:27 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 15:15:22 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_health(t_image *win, t_player *me)
{
	int i;
	int j;

	i = 0;
	while (i < (me->hp * 2) - 8)
	{
		j = 0;
		while (j < 30)
		{
			my_mlx_pixel_put(win, i + 44, j + 20, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	health(t_image *number, t_image *win, t_player *me)
{
	unsigned int	i;
	unsigned int	j;
	char			*color;

	i = 0;
	fill_health(win, me);
	while ((int)i < number->width)
	{
		j = 0;
		while ((int)j < number->height)
		{
			color = number->addr + ((4 * number->width * j) + (4 * i));
			if (*(unsigned int *)color != NONE)
				my_mlx_pixel_put(win, i, j, *(unsigned int *)color);
			j++;
		}
		i++;
	}
}
