/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:17:14 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/09 17:13:39 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sprite_enemy(t_parsing *parsing, int i, int j, int number)
{
	parsing->position[number].x = i + 0.5;
	parsing->position[number].y = j + 0.5;
	parsing->position[number].index = 8;
	parsing->position[number].hp = 100;
	parsing->position[number].frame = 0;
	parsing->position[number].seen = 0;
}

void	sprite_objet(t_parsing *parsing, int i, int j, int *number)
{
	if (parsing->new[i][j] == '2' && parsing->map[i][j] == 'x')
	{
		parsing->position[*number].x = i + 0.5;
		parsing->position[*number].y = j + 0.5;
		parsing->position[*number].index = 4;
		parsing->position[*number].hp = -1;
		(*number)++;
	}
	if (BONUS_SPRITES == 1 && parsing->new[i][j] == '3' &&
			parsing->map[i][j] == 'x')
	{
		parsing->position[*number].x = i + 0.5;
		parsing->position[*number].y = j + 0.5;
		parsing->position[*number].index = 7;
		parsing->position[*number].hp = -1;
		(*number)++;
	}
}

void	fill_sprite(t_parsing *parsing, int i, int j, int number)
{
	while (parsing->new[i])
	{
		j = 0;
		while (parsing->new[i][j])
		{
			sprite_objet(parsing, i, j, &number);
			if (BONUS_ENEMY == 1 && parsing->new[i][j] == '4' &&
					parsing->map[i][j] == 'x')
			{
				sprite_enemy(parsing, i, j, number);
				number++;
			}
			j++;
		}
		i++;
	}
}

int		count_sprite(t_parsing *parsing)
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
			if (parsing->new[i][j] == '2' && parsing->map[i][j] == 'x')
				count++;
			if (BONUS_SPRITES == 1 && parsing->new[i][j] == '3' &&
					parsing->map[i][j] == 'x')
				count++;
			if (BONUS_ENEMY == 1 && parsing->new[i][j] == '4' &&
					parsing->map[i][j] == 'x')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	treat_sprite(t_parsing *parsing)
{
	int i;
	int j;
	int number;

	i = 0;
	j = 0;
	number = 0;
	parsing->number = count_sprite(parsing);
	if (!(parsing->position = malloc(sizeof(t_position) * parsing->number)))
		quit_parsing(parsing, "Error : malloc sprites return NULL.\n");
	fill_sprite(parsing, i, j, number);
}
