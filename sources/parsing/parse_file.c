/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:18:05 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 14:49:12 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	not_valid_line(char *tmp, t_parsing *m)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ')
			quit_parsing(m,
					"Error : line between ID not empty or line corrupt\n");
		i++;
	}
}

int		valid_line(char *tmp)
{
	int i;

	i = 0;
	if (tmp == NULL)
		return (1);
	while (tmp[i] && tmp[i] == ' ')
		i++;
	if (i != (int)ft_strlen(tmp))
		return (0);
	return (1);
}

int		file_first_part(t_parsing *parsing)
{
	if (parsing->free_north == 0 || parsing->free_south == 0)
		return (0);
	if (parsing->free_west == 0 || parsing->free_east == 0)
		return (0);
	if (parsing->free_sprite == 0)
		return (0);
	if (parsing->resolutionx == -1 || parsing->resolutiony == -1)
		return (0);
	if (parsing->trgb_ceiling == -1 && parsing->ceiling == NULL)
		return (0);
	if (parsing->trgb_floor == -1 && parsing->floor == NULL)
		return (0);
	if (BONUS_SPRITES == 1 && parsing->free_objects == 0)
		return (0);
	return (1);
}

void	parse_id(char *temp, t_parsing *m)
{
	if (temp[0] == 'R')
		resolution(temp, m);
	else if (temp[0] == 'N' && temp[1] == 'O' && temp[2] == ' ')
		id(temp, m, NORTH);
	else if (temp[0] == 'S' && temp[1] == 'O' && temp[2] == ' ')
		id(temp, m, SOUTH);
	else if (temp[0] == 'W' && temp[1] == 'E' && temp[2] == ' ')
		id(temp, m, WEST);
	else if (temp[0] == 'E' && temp[1] == 'A' && temp[2] == ' ')
		id(temp, m, EAST);
	else if (temp[0] == 'S' && temp[1] == ' ')
		id(temp, m, SPRITE);
	else if (temp[0] == 'F' && temp[1] == ' ')
		parsing_floor(temp, m);
	else if (temp[0] == 'C' && temp[1] == ' ')
		parsing_ceiling(temp, m);
	else if (BONUS_SPRITES == 1 && temp[0] == 'S' && temp[1] == 'S' &&
			temp[2] == ' ')
		bonus_sprites(temp, m, 1);
	else if (BONUS_ENEMY == 1 && temp[0] == 'E' && temp[1] == 'N' &&
			temp[2] == ' ')
		bonus_sprites(temp, m, 2);
	else
		not_valid_line(temp, m);
}

void	parse_file(char *str, t_parsing *parsing)
{
	int ret;

	ret = 1;
	if ((parsing->fd = open(str, O_RDONLY)) == -1)
		error_message("Error : Cannot read the file in arguments.\n");
	while (ret && !file_first_part(parsing))
	{
		if ((ret = get_next_line(parsing->fd, &parsing->temp)) == -1)
			quit_parsing(parsing, "Error : function read return -1.\n");
		parsing->free_temp = 1;
		parse_id(parsing->temp, parsing);
		free(parsing->temp);
		parsing->temp = NULL;
	}
	if (!file_first_part(parsing))
		quit_parsing(parsing, "Error : not enough id.\n");
	jump_void(parsing);
	parse_map(parsing);
}
