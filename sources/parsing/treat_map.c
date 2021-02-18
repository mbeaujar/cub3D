/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:38:38 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 14:46:03 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		case_ok(char c)
{
	if (c == '0' || c == '2' || c == 'N' || c == 'S' || c == 'W')
		return (1);
	if (c == 'E' || c == '1' || c == 'x')
		return (1);
	if ((B_DOOR == 1 && c == '5') || (B_DOOR == 1 && c == '9'))
		return (1);
	if (BONUS_SPRITES == 1 && c == '3')
		return (1);
	if (BONUS_ENEMY == 1 && c == '4')
		return (1);
	return (0);
}

int		case_replace(char c)
{
	if (c == '0' || c == '2')
		return (1);
	if ((B_DOOR == 1 && c == '5') || (B_DOOR == 1 && c == '9'))
		return (1);
	if (BONUS_SPRITES == 1 && c == '3')
		return (1);
	if (BONUS_ENEMY == 1 && c == '4')
		return (1);
	return (0);
}

void	check_cross(t_parsing *parsing, int i, int j)
{
	if (i > 0 && !case_ok(parsing->map[i - 1][j]))
		quit_parsing(parsing, "Error 1 : case around a cross invalid.\n");
	if (i < ft_big_strlen(parsing->map) - 1 && !case_ok(parsing->map[i + 1][j]))
		quit_parsing(parsing, "Error 2 : case around a cross invalid.\n");
	if (j > 0 && !case_ok(parsing->map[i][j - 1]))
		quit_parsing(parsing, "Error 3 : case around a cross invalid.\n");
	if (j < (int)ft_strlen(parsing->map[i]) - 1 &&
			!case_ok(parsing->map[i][j + 1]))
		quit_parsing(parsing, "Error 4 : case around a cross invalid.\n");
	if (i == 0 && parsing->map[i][j] != '1')
		quit_parsing(parsing, "Error 5 : case around a cross invalid.\n");
	if (i == ft_big_strlen(parsing->map) - 1 && parsing->map[i][j] != '1')
		quit_parsing(parsing, "Error 6 : case around a cross invalid.\n");
	if (j == 0 && parsing->map[i][j] != '1')
		quit_parsing(parsing, "Error 7 : case around a cross invalid.\n");
	if (j == (int)ft_strlen(parsing->map[i]) - 1 && parsing->map[i][j] != '1')
		quit_parsing(parsing, "Error 8 : case around a cross invalid.\n");
}

int		fill_cross(t_parsing *parsing, int i, int j)
{
	int check;

	check = 0;
	check_cross(parsing, i, j);
	if (i > 0 && case_replace(parsing->map[i - 1][j]) && ++check)
		parsing->map[i - 1][j] = 'x';
	if (i < ft_big_strlen(parsing->map) - 1 &&
			case_replace(parsing->map[i + 1][j]) && ++check)
		parsing->map[i + 1][j] = 'x';
	if (j > 0 && case_replace(parsing->map[i][j - 1]) && ++check)
		parsing->map[i][j - 1] = 'x';
	if (j < (int)ft_strlen(parsing->map[i]) - 1 &&
			case_replace(parsing->map[i][j + 1]) && ++check)
		parsing->map[i][j + 1] = 'x';
	return (check);
}

void	treat_map(t_parsing *parsing)
{
	fill_cross(parsing, parsing->me.posx, parsing->me.posy);
	treat_map_down(parsing);
	treat_map_up(parsing);
}
