/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:28:16 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 13:47:43 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	door_close(t_game *g, int i, double dist)
{
	if (g->d.e[i].action == 5)
	{
		g->wall.hit = 1;
		g->wall.is_door = 1;
		if (key_here(&g->wall, USE) && dist < 3)
		{
			set_offset(g, i);
			g->parsing.map[g->wall.rayposx][g->wall.rayposy] = '7';
			g->d.e[i].action = 7;
			g->wall.offset = 0;
		}
	}
}

void	door_opening(t_game *g, int i)
{
	if (g->d.e[i].action == 7)
	{
		if (g->wall.offset < g->d.e[i].offset)
		{
			g->wall.hit = 1;
			g->d.e[i].draw = 1;
			g->wall.is_door = 1;
		}
		if (g->d.e[i].offset <= 0)
		{
			g->d.e[i].action = 6;
			g->parsing.map[g->wall.rayposx][g->wall.rayposy] = '6';
		}
	}
}

void	door_open(t_game *g, int i, double dist)
{
	if (g->d.e[i].action == 6)
	{
		if (key_here(&g->wall, USE) && dist < 3)
		{
			set_offset(g, i);
			g->d.e[i].max_offset = g->d.e[i].offset;
			g->parsing.map[g->wall.rayposx][g->wall.rayposy] = '8';
			g->d.e[i].action = 8;
			g->wall.offset = 0;
			g->d.e[i].offset = 0;
		}
	}
}

void	door_closing(t_game *g, int i)
{
	if (g->d.e[i].action == 8)
	{
		if (g->wall.offset < g->d.e[i].offset)
		{
			g->wall.hit = 1;
			g->d.e[i].draw = 1;
			g->wall.is_door = 1;
		}
		if (g->d.e[i].offset >= g->d.e[i].max_offset)
		{
			g->d.e[i].action = 5;
			g->parsing.map[g->wall.rayposx][g->wall.rayposy] = '5';
		}
	}
}

void	secret_door(t_game *g, int i, double dist)
{
	if (g->d.e[i].action == 10)
	{
		g->wall.hit = 0;
		if (key_here(&g->wall, UNUSE) && dist < 2)
		{
			g->d.e[i].action = 9;
			g->parsing.map[g->wall.rayposx][g->wall.rayposy] = '9';
		}
	}
	if (g->d.e[i].action == 9)
	{
		g->wall.hit = 1;
		if (key_here(&g->wall, USE) && dist < 2)
		{
			g->d.e[i].action = 10;
			g->parsing.map[g->wall.rayposx][g->wall.rayposy] = '0';
		}
	}
}
