/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:40:08 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/18 14:09:01 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotation_right(t_wall *d)
{
	d->olddir = d->dirx;
	d->dirx = d->dirx * cos(-d->rotspeed) - d->diry *
		sin(-d->rotspeed);
	d->diry = d->olddir * sin(-d->rotspeed) + d->diry *
		cos(-d->rotspeed);
	d->oldplane = d->planex;
	d->planex = d->planex * cos(-d->rotspeed) - d->planey *
		sin(-d->rotspeed);
	d->planey = d->oldplane * sin(-d->rotspeed) + d->planey *
		cos(-d->rotspeed);
}

void	rotation_left(t_wall *d)
{
	d->olddir = d->dirx;
	d->dirx = d->dirx * cos(d->rotspeed) - d->diry *
		sin(d->rotspeed);
	d->diry = d->olddir * sin(d->rotspeed) + d->diry *
		cos(d->rotspeed);
	d->oldplane = d->planex;
	d->planex = d->planex * cos(d->rotspeed) - d->planey *
		sin(d->rotspeed);
	d->planey = d->oldplane * sin(d->rotspeed) + d->planey *
		cos(d->rotspeed);
}
