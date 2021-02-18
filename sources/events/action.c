/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:06:54 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/15 10:58:41 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	up(t_wall *wall)
{
	wall->pitch += 200 * wall->movespeed;
	if (wall->pitch > 200)
		wall->pitch = 200;
}

void	down(t_wall *wall)
{
	wall->pitch -= 200 * wall->movespeed;
	if (wall->pitch < -200)
		wall->pitch = -200;
}

void	jump(t_wall *wall)
{
	wall->posz = 200;
}

void	crouch(t_wall *wall)
{
	wall->posz = -200;
}
