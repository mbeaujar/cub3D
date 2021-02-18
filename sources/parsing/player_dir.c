/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:47:51 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/18 14:08:19 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	set_dirx(char orientation)
{
	if (orientation == 'E')
		return (0);
	if (orientation == 'W')
		return (0);
	if (orientation == 'S')
		return (1);
	if (orientation == 'N')
		return (-1);
	return (0);
}

double	set_diry(char orientation)
{
	if (orientation == 'E')
		return (1);
	if (orientation == 'W')
		return (-1);
	if (orientation == 'S')
		return (0);
	if (orientation == 'N')
		return (0);
	return (0);
}

double	set_planx(char orientation)
{
	if (orientation == 'E')
		return (0.66);
	if (orientation == 'W')
		return (-0.66);
	if (orientation == 'S')
		return (0);
	if (orientation == 'N')
		return (0);
	return (0);
}

double	set_plany(char orientation)
{
	if (orientation == 'E')
		return (0);
	if (orientation == 'W')
		return (0);
	if (orientation == 'S')
		return (-0.66);
	if (orientation == 'N')
		return (0.66);
	return (0);
}

void	player_dir(t_wall *wall, t_player *player)
{
	wall->dirx = set_dirx(player->direction);
	wall->diry = set_diry(player->direction);
	wall->planex = set_planx(player->direction);
	wall->planey = set_plany(player->direction);
}
