/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:51:52 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/10 11:01:33 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_biggest_str(char **str)
{
	int i;
	int len;
	int strlen;

	i = 0;
	len = 0;
	strlen = 0;
	while (str[i])
	{
		strlen = (int)ft_strlen(str[i]);
		if (len < strlen)
			len = strlen;
		i++;
	}
	return (len);
}
