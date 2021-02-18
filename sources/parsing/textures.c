/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:55:00 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 17:00:06 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_text(t_wall *wall)
{
	int i;

	i = 0;
	while (i < 13)
	{
		wall->image[i].text = NULL;
		i++;
	}
}

void	get_path(t_wall *wall, t_parsing *parsing)
{
	wall->image[0].path = parsing->north;
	wall->image[1].path = parsing->west;
	wall->image[2].path = parsing->east;
	wall->image[3].path = parsing->south;
	wall->image[4].path = parsing->sprite;
}
