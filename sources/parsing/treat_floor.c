/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:31:03 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 13:52:35 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			recup_path_floor(char *tmp, int *i, t_parsing *m)
{
	int len;

	len = 0;
	while (tmp[(*i) + len] != ' ' && tmp[(*i) + len])
		len++;
	m->floor = ft_substr(tmp, *i, len);
	if (read_file_with_return(m->floor) == 0)
	{
		(*i) += len;
		free(m->floor);
		return (0);
	}
	m->free_floor = 1;
	(*i) += len;
	return (1);
}

int			recup_rgb_floor(char *tmp, int *i, t_parsing *m)
{
	int tab[3];

	tab[0] = recup_nb(tmp, i);
	if (tmp[*i] != ',')
		return (*i);
	else
		(*i)++;
	tab[1] = recup_nb(tmp, i);
	if (tmp[*i] != ',')
		return (*i);
	else
		(*i)++;
	tab[2] = recup_nb(tmp, i);
	normi_friendly(tab, m);
	if (tmp[(*i)] != ' ' && tmp[(*i)] != 0)
		return (*i);
	m->trgb_floor = create_rgb(0, tab[0], tab[1], tab[2]);
	return (-1);
}

int			check_rgb_floor(char *tmp, t_parsing *m)
{
	int i;
	int value;

	i = 2;
	value = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ')
			value = recup_rgb_floor(tmp, &i, m);
		if (tmp[i] != ' ' && tmp[i] != 0)
			return (0);
		if (tmp[i])
			i++;
	}
	if (value == -1)
		return (1);
	return (0);
}

int			check_path_floor(char *tmp, t_parsing *m)
{
	int i;
	int value;

	i = 2;
	value = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ')
			value = recup_path_floor(tmp, &i, m);
		if (tmp[i] != ' ' && tmp[i] != 0)
			return (0);
		if (tmp[i])
			i++;
	}
	if (value == 1)
		return (1);
	return (0);
}

void		parsing_floor(char *tmp, t_parsing *m)
{
	int rgb;
	int path;

	rgb = check_rgb_floor(tmp, m);
	path = check_path_floor(tmp, m);
	if (path == 0 && rgb == 0)
		quit_parsing(m, "Error : floor invalid.\n");
	if (path == 1)
		m->free_floor = 1;
	if (rgb == 1 && path == 1)
		m->trgb_floor = -1;
}
