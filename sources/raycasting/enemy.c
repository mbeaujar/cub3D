/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:00:12 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 16:38:53 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_sprite(t_position *s, int number)
{
	int i;

	i = 0;
	while (i < number)
	{
		if (s[i].index == 8 && s[i].hp != -1 && s[i].hp != 100)
		{
			ft_printf("hp : %d pos x : %f pos y : %f\n", s[i].hp,
					s[i].x, s[i].y);
		}
		i++;
	}
}

void	enemy(int x, int y, t_game *g)
{
	int i;

	i = 0;
	while (i < g->parsing.number)
	{
		if (g->parsing.position[i].index >= 8 &&
				(int)g->sprite.sp[i].x == x &&
				(int)g->sprite.sp[i].y == y &&
				g->sprite.sp[i].hp != -1 && g->gun.hitbox == 1)
		{
			if (g->gun.slot == 2 &&
					fabs(g->wall.posx - x) <= 1.3 &&
					fabs(g->wall.posy - y) <= 1.3)
				g->sprite.sp[i].hp -= 50;
			else if (g->gun.slot == 1)
				g->sprite.sp[i].hp -= 33;
			if (g->sprite.sp[i].hp <= 0)
			{
				g->parsing.me.score += 200;
				g->parsing.map[x][y] = '0';
				g->sprite.sp[i].hp = -1;
			}
		}
		i++;
	}
}

void	clear_enemy(t_position *s, int number)
{
	int i;

	i = 0;
	while (i < number)
	{
		if (s[i].index == 10)
			s[i].index = 8;
		s[i].seen = 0;
		i++;
	}
}

void	text_enemy(t_position *s, int number, t_player *me)
{
	int i;
	int pid;

	i = 0;
	pid = -1;
	while (i < number)
	{
		if (s[i].seen == 1 && s[i].frame == 1)
		{
			if (time(NULL) - s[i].fire >= 2)
			{
				s[i].index = 10;
				me->hp -= 10;
				if (SOUND == 1)
					music();
				s[i].frame = 0;
			}
		}
		i++;
	}
}

void	seen_enemy(t_sprite *d, int x, int y, double dist)
{
	int i;

	i = 0;
	while (i < d->number)
	{
		if (d->sp[i].hp != -1 && d->sp[i].index >= 8)
		{
			if ((int)d->sp[i].x == x && (int)d->sp[i].y == y)
			{
				d->sp[i].seen = 1;
				if (d->sp[i].frame == 0 && d->sp[i].seen == 1)
				{
					if (dist <= 4.5)
						d->sp[i].frame = 1;
					d->sp[i].fire = time(NULL);
				}
			}
		}
		i++;
	}
}
