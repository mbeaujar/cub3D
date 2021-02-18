/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:11:44 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:51:43 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	left(t_wall *d, char **map)
{
	if (key_here(d, LEFT))
	{
		if (case_valid(map[(int)(d->posx - d->planex *
					(d->movespeed + 0.15))][(int)d->posy]))
			d->posx -= d->planex * d->movespeed;
		if (case_valid(map[(int)d->posx][(int)(d->posy - d->planey *
					d->movespeed)]))
			d->posy -= d->planey * d->movespeed;
	}
}

void	right(t_wall *d, char **map)
{
	if (key_here(d, RIGHT))
	{
		if (case_valid(map[(int)(d->posx + d->planex *
					(d->movespeed + 0.15))][(int)d->posy]))
			d->posx += d->planex * d->movespeed;
		if (case_valid(map[(int)d->posx][(int)(d->posy + d->planey *
					d->movespeed)]))
			d->posy += d->planey * d->movespeed;
	}
}

void	forward(t_wall *d, char **map)
{
	if (key_here(d, FORWARD))
	{
		if (case_valid(map[(int)(d->posx + d->dirx *
					(d->movespeed + 0.15))][(int)d->posy]))
			d->posx += d->dirx * d->movespeed;
		if (case_valid(map[(int)d->posx][(int)(d->posy + d->diry *
					d->movespeed)]))
			d->posy += d->diry * d->movespeed;
	}
}

void	backward(t_wall *d, char **map)
{
	if (key_here(d, BACKWARD))
	{
		if (case_valid(map[(int)(d->posx - d->dirx *
					(d->movespeed + 0.15))][(int)d->posy]))
			d->posx -= d->dirx * d->movespeed;
		if (case_valid(map[(int)d->posx][(int)(d->posy - d->diry *
					d->movespeed)]))
			d->posy -= d->diry * d->movespeed;
	}
}

int		key(t_wall *d, char **map, t_game *game)
{
	if (key_here(d, ESC))
		close_the_game(game);
	if (BONUS_VIEW == 1 && key_here(d, LOOK_TOP))
		up(d);
	if (BONUS_JUMP == 1 && key_here(d, JUMP))
		jump(d);
	if (BONUS_CROUCH == 1 && key_here(d, CROUCH))
		crouch(d);
	if (BONUS_VIEW == 1 && key_here(d, LOOK_DOWN))
		down(d);
	forward(d, map);
	backward(d, map);
	left(d, map);
	right(d, map);
	if (key_here(d, ROTATE_LEFT))
		rotation_left(d);
	if (key_here(d, ROTATE_RIGHT))
		rotation_right(d);
	if (d->posz > 0)
		d->posz = d->posz - 100 * d->movespeed;
	if (d->posz < 0)
		d->posz = d->posz + 100 * d->movespeed;
	return (1);
}
