/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:46:23 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 15:09:43 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_struct(t_parsing *parsing, int i, int j, int *count)
{
	if (parsing->new[i][j] == '5' && parsing->map[i][j] == 'x')
	{
		parsing->e[*count].x = i;
		parsing->e[*count].y = j;
		parsing->e[*count].offset = 0;
		parsing->e[*count].draw = 0;
		parsing->e[*count].action = 5;
		(*count)++;
	}
	if (parsing->new[i][j] == '9' && parsing->map[i][j] == 'x')
	{
		parsing->e[*count].x = i;
		parsing->e[*count].y = j;
		parsing->e[*count].offset = 0;
		parsing->e[*count].draw = 0;
		parsing->e[*count].action = 9;
		(*count)++;
	}
}

void	fill_door(t_parsing *parsing)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (parsing->new[i])
	{
		j = 0;
		while (parsing->new[i][j])
		{
			fill_struct(parsing, i, j, &count);
			j++;
		}
		i++;
	}
}

int		count_door(t_parsing *parsing)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (parsing->new[i])
	{
		j = 0;
		while (parsing->new[i][j])
		{
			if (parsing->new[i][j] == '5' && parsing->map[i][j] == 'x')
				count++;
			if (parsing->new[i][j] == '9' && parsing->map[i][j] == 'x')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	treat_door(t_parsing *parsing)
{
	parsing->number_entity = count_door(parsing);
	if (!(parsing->e = malloc(sizeof(t_entity) * parsing->number_entity)))
		quit_parsing(parsing, "Error : malloc door returned NULL.\n");
	parsing->free_entity = 1;
	fill_door(parsing);
}
