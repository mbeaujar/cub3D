/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:01:42 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/18 14:25:32 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

void	set_player(t_parsing *parsing, int i, int j, int *count)
{
	parsing->me.posx = (double)i + 0.5;
	parsing->me.posy = (double)j + 0.5;
	parsing->me.direction = parsing->map[i][j];
	parsing->me.hp = 100;
	parsing->me.score = 0;
	(*count)++;
}

void	parse_player(t_parsing *parsing)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (parsing->map[i])
	{
		j = 0;
		while (parsing->map[i][j])
		{
			if (is_player(parsing->map[i][j]))
				set_player(parsing, i, j, &count);
			j++;
		}
		i++;
	}
	if (count != 1)
		quit_parsing(parsing, "Error : wrong number of player.\n");
}
