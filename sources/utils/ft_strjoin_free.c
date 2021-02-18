/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:04:28 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:53:30 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		y;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	if (!(tab = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 2))))
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	y = -1;
	while (s2[++y])
		tab[i + y] = s2[y];
	free((void *)s1);
	free((void *)s2);
	tab[i + y] = '\n';
	tab[i + y + 1] = '\0';
	return (tab);
}
