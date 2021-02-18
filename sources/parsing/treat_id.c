/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:15:34 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/12 21:28:22 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*which_message(int which)
{
	if (which == NORTH)
		return ("Error : cant read id NO.\n");
	if (which == SOUTH)
		return ("Error : cant read id SO.\n");
	if (which == WEST)
		return ("Error : cant read id WE.\n");
	if (which == EAST)
		return ("Error : cant read id EA.\n");
	return ("Error : cant read id S.\n");
}

void	which_id(int which, char *path, t_parsing *m)
{
	read_id(m, path, which);
	if (which == NORTH)
		m->free_north = 1;
	if (which == NORTH)
		m->north = path;
	if (which == SOUTH)
		m->free_south = 1;
	if (which == SOUTH)
		m->south = path;
	if (which == EAST)
		m->free_east = 1;
	if (which == EAST)
		m->east = path;
	if (which == WEST)
		m->free_west = 1;
	if (which == WEST)
		m->west = path;
	if (which == SPRITE)
		m->free_sprite = 1;
	if (which == SPRITE)
		m->sprite = path;
}

char	*recup_path(char *tmp, int *i)
{
	int		len;
	char	*path;

	len = 0;
	while (tmp[(*i) + len] != ' ' && tmp[(*i) + len])
		len++;
	path = ft_substr(tmp, *i, len);
	(*i) += len;
	return (path);
}

void	id_already_set(int which, t_parsing *m)
{
	if (which == NORTH && m->free_north == 1)
		quit_parsing(m, which_message(which));
	if (which == SOUTH && m->free_south == 1)
		quit_parsing(m, which_message(which));
	if (which == WEST && m->free_west == 1)
		quit_parsing(m, which_message(which));
	if (which == EAST && m->free_east == 1)
		quit_parsing(m, which_message(which));
	if (which == SPRITE && m->free_sprite == 1)
		quit_parsing(m, which_message(which));
}

void	id(char *tmp, t_parsing *m, int which)
{
	int		i;
	char	*path;

	if (which == SPRITE)
		i = 2;
	else
		i = 3;
	path = NULL;
	id_already_set(which, m);
	while (tmp[i])
	{
		if (tmp[i] != ' ')
			path = recup_path(tmp, &i);
		if (tmp[i])
			i++;
		if (tmp[i] != ' ' && tmp[i] != 0 && path != NULL)
			quit_parsing(m, which_message(which));
	}
	which_id(which, path, m);
}
