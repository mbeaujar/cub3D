/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:56:21 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/15 12:15:46 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	jump_void(t_parsing *parsing)
{
	int ret;

	ret = 1;
	while (ret && valid_line(parsing->temp))
	{
		if (parsing->temp != NULL)
		{
			free(parsing->temp);
			parsing->free_temp = 0;
		}
		if ((ret = get_next_line(parsing->fd, &parsing->temp)) == -1)
			quit_parsing(parsing, "Error : function read return -1.\n");
		parsing->free_temp = 1;
	}
}

void	print_map(char **str)
{
	int i;

	i = 0;
	write(1, "\n", 1);
	while (str[i])
	{
		ft_printf("%d : %s\n", i, str[i]);
		i++;
	}
}

void	read_id(t_parsing *m, char *path, int which)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		quit_parsing(m, which_message(which));
	close(fd);
}

void	treat_map_down(t_parsing *parsing)
{
	int i;
	int j;

	i = 0;
	while (parsing->map[i])
	{
		j = 0;
		while (parsing->map[i][j])
		{
			if (parsing->map[i][j] == 'x')
				fill_cross(parsing, i, j);
			j++;
		}
		i++;
	}
}

void	treat_map_up(t_parsing *parsing)
{
	int			i;
	int			j;
	static int	reload = 0;

	i = ft_big_strlen(parsing->map) - 1;
	while (i >= 0)
	{
		j = (int)ft_strlen(parsing->map[i]);
		while (j >= 0)
		{
			if (parsing->map[i][j] == 'x')
			{
				if (fill_cross(parsing, i, j) > 0)
					reload = 1;
			}
			j--;
		}
		i--;
		if (i == 0 && reload == 1)
		{
			reload = 0;
			treat_map_down(parsing);
			i = ft_big_strlen(parsing->map) - 1;
		}
	}
}
