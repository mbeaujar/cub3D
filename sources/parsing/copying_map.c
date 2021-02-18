/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copying_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:45:44 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/12 18:48:54 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	quit_parsing_part_2(t_parsing *parsing, char *str)
{
	if (parsing->fd >= 0)
		close(parsing->fd);
	if (parsing->free_position == 1)
		free(parsing->position);
	if (parsing->free_map == 1)
		free_map(parsing->map);
	if (parsing->free_new == 1)
		free_map(parsing->new);
	if (parsing->free_objects == 1)
		free(parsing->objects);
	if (SOUND == 1 && OS == 1)
		system("killall afplay");
	if (SOUND == 1 && OS == 0)
		system("killall aplay");
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		read_file_with_return(char *str)
{
	int fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	close(fd);
	return (1);
}

void	my_mlx_pixel_put(t_image *d, int x, int y, unsigned int color)
{
	char *dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

char	**copying_map(t_parsing *parsing)
{
	char	**new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(char*) * (ft_big_strlen(parsing->map) + 1))))
		quit_parsing(parsing, "Error : malloc copying map return NULL.\n");
	while (parsing->map[i])
	{
		if (!(new[i] = malloc(sizeof(char) *
						((int)ft_strlen(parsing->map[i]) + 1))))
			quit_parsing(parsing, "Error : malloc copying map return NULL.\n");
		ft_strlcpy(new[i], parsing->map[i], ft_strlen(parsing->map[i]) + 1);
		i++;
	}
	new[i] = 0;
	parsing->free_new = 1;
	return (new);
}
