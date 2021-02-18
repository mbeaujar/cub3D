/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_id_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:15:25 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/09 22:28:25 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	id_already_set_bonus(int which, t_parsing *parsing)
{
	if (which == 1 && parsing->free_objects == 1)
		quit_parsing(parsing, "Error : ID \"SS\" already set.\n");
	if (which == 2 && parsing->free_enemy == 1)
		quit_parsing(parsing, "Error : ID \"EN\" already set.\n");
}

void	which_id_bonus(int which, char *path, t_parsing *m)
{
	read_path(path, m);
	if (which == 1)
	{
		m->free_objects = 1;
		m->objects = path;
	}
	if (which == 2)
	{
		m->free_enemy = 1;
		m->enemy = path;
	}
}

char	*recup_path_bonus(char *tmp, int *i)
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

void	bonus_sprites(char *tmp, t_parsing *m, int which)
{
	int		i;
	char	*path;

	path = NULL;
	i = 3;
	id_already_set_bonus(which, m);
	while (tmp[i])
	{
		if (tmp[i] != ' ')
			path = recup_path_bonus(tmp, &i);
		if (tmp[i])
			i++;
		if (tmp[i] != ' ' && tmp[i] != 0 && path != NULL)
			quit_parsing(m, "Error : line sprites bonus invalid.\n");
	}
	which_id_bonus(which, path, m);
}
