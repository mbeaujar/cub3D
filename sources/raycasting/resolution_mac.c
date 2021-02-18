/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_mac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:45:56 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 15:09:01 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_screensize(t_game *game)
{
	if (game->wall.resolutionx > 1920)
		game->wall.resolutionx = 1920;
	if (game->wall.resolutiony > 1080)
		game->wall.resolutiony = 1080;
	if (game->wall.resolutionx < 800)
		game->wall.resolutionx = 800;
	if (game->wall.resolutiony < 600)
		game->wall.resolutiony = 600;
}
