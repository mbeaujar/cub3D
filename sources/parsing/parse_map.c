/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:01:45 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 14:45:32 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		caracter_valid(char c)
{
	if (c == 'W' || c == 'S' || c == 'E' || c == 'N' || c == '1')
		return (1);
	if (c == '2' || c == ' ' || c == '0')
		return (1);
	if ((B_DOOR == 1 && c == '5') || (B_DOOR == 1 && c == '9'))
		return (1);
	if (BONUS_SPRITES == 1 && c == '3')
		return (1);
	if (BONUS_ENEMY == 1 && c == '4')
		return (1);
	return (0);
}

int		string_valid(char *str, t_parsing *parsing)
{
	static int empty_line = 0;
	static int map_after = 0;

	if (!str)
		return (1);
	if (*str == 0)
		empty_line = 1;
	while (*str)
	{
		if (!caracter_valid(*str))
			quit_parsing(parsing, "Error : caracter invalid in the map.\n");
		if (empty_line == 1)
			map_after = 1;
		str++;
	}
	if (map_after == 1)
		quit_parsing(parsing, "Error : string empty in the map.\n");
	return (1);
}

int		map_is(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\n')
			return (1);
		str++;
	}
	return (0);
}

void	call_function(t_parsing *parsing, char *str)
{
	close(parsing->fd);
	parsing->free_temp = 0;
	parsing->free_map = 1;
	if (map_is(str) == 0)
	{
		free(str);
		quit_parsing(parsing, "Error : no map.\n");
	}
	free(str);
	parsing->new = copying_map(parsing);
	parse_player(parsing);
	treat_map(parsing);
	treat_sprite(parsing);
	if (B_DOOR == 1)
		treat_door(parsing);
	parsing->free_new = 0;
	free_map(parsing->map);
	parsing->map = parsing->new;
	parsing->new = NULL;
}

void	parse_map(t_parsing *parsing)
{
	char	*str;
	int		ret;

	ret = 1;
	str = ft_calloc(sizeof(char), 1);
	str = ft_strjoin_free(str, parsing->temp);
	while (ret)
	{
		if ((ret = get_next_line(parsing->fd, &parsing->temp)) == -1)
			quit_parsing(parsing, "Error : function read return -1.\n");
		string_valid(parsing->temp, parsing);
		str = ft_strjoin_free(str, parsing->temp);
	}
	parsing->map = ft_split(str, '\n');
	call_function(parsing, str);
}
