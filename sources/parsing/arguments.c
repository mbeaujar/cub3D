/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:53:31 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/14 22:00:42 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_message(char *str)
{
	ft_printf("%s", str);
	if (SOUND == 1 && OS == 1)
		system("killall afplay");
	if (SOUND == 1 && OS == 0)
		system("killall aplay");
	exit(EXIT_FAILURE);
}

void	quit_parsing(t_parsing *parsing, char *str)
{
	if (parsing->free_ceiling == 1)
		free(parsing->ceiling);
	if (parsing->free_floor == 1)
		free(parsing->floor);
	if (parsing->free_north == 1)
		free(parsing->north);
	if (parsing->free_west == 1)
		free(parsing->west);
	if (parsing->free_east == 1)
		free(parsing->east);
	if (parsing->free_south == 1)
		free(parsing->south);
	if (parsing->free_temp == 1)
		free(parsing->temp);
	if (parsing->free_sprite == 1)
		free(parsing->sprite);
	if (parsing->free_entity == 1)
		free(parsing->e);
	quit_parsing_part_2(parsing, str);
}

void	read_path(char *str, t_parsing *parsing)
{
	int fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		quit_parsing(parsing, "Error : Cannot read the file in id.\n");
	close(fd);
}

void	read_file(char *str)
{
	int fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		error_message("Error : Cannot read the file in arguments\n");
	close(fd);
}

void	arguments(int argc, char **argv, t_game *game)
{
	if (argc != 2 && argc != 3)
		error_message("Error : Bad number of arguments\n");
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub",
				ft_strlen(argv[1] - 4)) != 0)
		error_message("Error : First argument is not a .cub\n");
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) != 0)
			error_message("Error : Second argument is not valid\n");
		game->file_bmp = 1;
	}
	read_file(argv[1]);
}
