/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:30:37 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/12 13:21:18 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			recup_path_ceiling(char *tmp, int *i, t_parsing *m)
{
	int len;

	len = 0;
	while (tmp[(*i) + len] != ' ' && tmp[(*i) + len])
		len++;
	m->ceiling = ft_substr(tmp, *i, len);
	if (read_file_with_return(m->ceiling) == 0)
	{
		(*i) += len;
		free(m->ceiling);
		return (0);
	}
	m->free_ceiling = 1;
	(*i) += len;
	return (1);
}

int			recup_rgb_ceiling(char *tmp, int *i, t_parsing *m)
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
	m->trgb_ceiling = create_rgb(0, tab[0], tab[1], tab[2]);
	return (-1);
}

int			check_rgb_ceiling(char *tmp, t_parsing *m)
{
	int i;
	int value;
	int ok;

	i = 2;
	value = 0;
	ok = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ')
		{
			value = recup_rgb_ceiling(tmp, &i, m);
			ok++;
		}
		if (tmp[i] != ' ' && tmp[i] != 0)
			return (0);
		if (tmp[i])
			i++;
	}
	if (ok != 1)
		return (0);
	if (value == -1)
		return (1);
	return (0);
}

int			check_path_ceiling(char *tmp, t_parsing *m)
{
	int i;
	int value;

	i = 2;
	value = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ')
			value = recup_path_ceiling(tmp, &i, m);
		if (tmp[i] != ' ' && tmp[i] != 0)
			return (0);
		if (tmp[i])
			i++;
	}
	if (value == 1)
		return (1);
	return (0);
}

void		parsing_ceiling(char *tmp, t_parsing *m)
{
	int rgb;
	int path;

	rgb = check_rgb_ceiling(tmp, m);
	path = check_path_ceiling(tmp, m);
	if (path == 0 && rgb == 0)
		quit_parsing(m, "Error : ceiling invalid.\n");
	if (path == 1)
		m->free_ceiling = 1;
	if (path == 1 && rgb == 1)
		m->trgb_ceiling = -1;
}
