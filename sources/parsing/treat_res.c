/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:31:11 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/12 13:14:47 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	normi_friendly(int *tab, t_parsing *m)
{
	int j;

	j = 0;
	while (j < 2)
	{
		if (tab[j] > 255)
			quit_parsing(m,
					"Error : color in rgb too high for ceiling or floor.\n");
		j++;
	}
}

int		create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	recup_nb_res(char *tmp, int *i, t_parsing *m, int *full_res)
{
	int nb;

	nb = 0;
	while (tmp[*i] >= '0' && tmp[*i] <= '9')
		nb = (nb * 10) + tmp[(*i)++] - '0';
	if (tmp[*i] == 0)
		(*i)--;
	if (*full_res == 0)
		m->resolutionx = nb;
	else
		m->resolutiony = nb;
}

void	parsing_resolution(char *tmp, t_parsing *m, int *full_res)
{
	int i;

	i = 1;
	while (tmp[i])
	{
		if (tmp[i] >= '0' && tmp[i] <= '9')
		{
			recup_nb_res(tmp, &i, m, full_res);
			(*full_res)++;
		}
		if ((tmp[i] < '0' || tmp[i] > '9') && tmp[i] != ' ' && tmp[i] != 0)
			quit_parsing(m, "Error : resolution not valid.\n");
		i++;
	}
}

void	resolution(char *tmp, t_parsing *m)
{
	static int	entry = 0;
	int			full_res;

	full_res = 0;
	if (entry != 0 || tmp[1] != ' ')
		quit_parsing(m, "Error : resolution not valid.\n");
	parsing_resolution(tmp, m, &full_res);
	if (full_res != 2)
		quit_parsing(m, "Error : resolution not valid.\n");
	entry++;
}
