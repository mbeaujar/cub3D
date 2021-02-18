/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:34:22 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 14:25:38 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		case_valid(char c)
{
	if (c == '0' || c == '6')
		return (1);
	return (0);
}

int		multi_key(int keycode, t_game *d)
{
	if (BONUS_HEALTH == 1 && keycode == GAIN_HP)
	{
		if (d->parsing.me.hp <= 90)
			d->parsing.me.hp += 10;
		return (1);
	}
	if (BONUS_HEALTH == 1 && keycode == LOOSE_HP)
	{
		if (d->parsing.me.hp >= 10)
			d->parsing.me.hp -= 10;
		return (1);
	}
	if (WEAPON == 1 && keycode == PISTOL)
	{
		d->gun.slot = 1;
		return (1);
	}
	if (WEAPON == 1 && keycode == KNIFE)
	{
		d->gun.slot = 2;
		return (1);
	}
	return (1);
}

int		add_key(int keycode, t_game *d)
{
	int i;

	i = 0;
	multi_key(keycode, d);
	if (WEAPON == 1 && keycode == SPACE && d->gun.frame == 0)
	{
		d->gun.fire = ((d->gun.slot == 1 && d->gun.ammo > 0) ||
				d->gun.slot == 2) ? 1 : 0;
		if (d->gun.slot == 1 && d->gun.ammo > 0)
			d->gun.ammo--;
		return (1);
	}
	if (keycode == ESC)
		close_the_game(d);
	while (i < 10)
	{
		if (d->wall.tab[i] == 1000)
		{
			d->wall.tab[i] = keycode;
			return (1);
		}
		i++;
	}
	return (1);
}

int		key_here(t_wall *d, int keycode)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (d->tab[i] == keycode)
			return (1);
		i++;
	}
	return (0);
}

int		clear_key(int keycode, t_game *d)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (d->wall.tab[i] == keycode)
			d->wall.tab[i] = 1000;
		i++;
	}
	return (1);
}
