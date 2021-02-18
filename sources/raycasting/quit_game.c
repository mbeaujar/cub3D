/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:25:39 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/18 14:02:06 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		close_the_game(t_game *game)
{
	quit_game(game, "");
	return (1);
}

void	clear_mlx_part_2(t_game *game)
{
	if (BONUS_HEALTH == 1)
		mlx_destroy_image(game->vars.mlx, game->wall.image[9].text);
	if (BONUS_ENEMY == 1)
		mlx_destroy_image(game->vars.mlx, game->wall.image[10].text);
	if (BONUS_ENEMY == 1)
		mlx_destroy_image(game->vars.mlx, game->wall.image[8].text);
	if (game->wall.image[6].text != NULL)
		mlx_destroy_image(game->vars.mlx, game->wall.image[6].text);
	if (game->wall.image[7].text != NULL)
		mlx_destroy_image(game->vars.mlx, game->wall.image[7].text);
	if (game->wall.image[5].text != NULL)
		mlx_destroy_image(game->vars.mlx, game->wall.image[5].text);
	if (game->wall.image[11].text != NULL)
		mlx_destroy_image(game->vars.mlx, game->wall.image[11].text);
	if (game->wall.image[12].text != NULL)
		mlx_destroy_image(game->vars.mlx, game->wall.image[12].text);
	//mlx_loop_end(game->vars.mlx);
	//mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
}

void	clear_mlx(t_game *game)
{
	static int i = 0;

	if (game->vars.img != NULL)
		mlx_destroy_image(game->vars.mlx, game->vars.img);
	if (game->vars.win != NULL)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	while (WEAPON == 1 && i < 5)
		mlx_destroy_image(game->vars.mlx, game->gun.gun[i++].text);
	i = 0;
	while (WEAPON == 1 && i < 5)
		mlx_destroy_image(game->vars.mlx, game->gun.knife[i++].text);
	i = 0;
	while (i < 5)
		mlx_destroy_image(game->vars.mlx, game->wall.image[i++].text);
	clear_mlx_part_2(game);
}

void	quit_game(t_game *game, char *str)
{
	clear_mlx(game);
	if (game->parsing.free_map == 1)
		free_map(game->parsing.map);
	free(game->parsing.position);
	if (game->sprite.free_dist == 1)
		free(game->sprite.dist);
	if (WEAPON == 1 && game->gun.free_gun == 1)
		free(game->gun.gun);
	if (WEAPON == 1 && game->gun.free_knife == 1)
		free(game->gun.knife);
	free(game->wall.image);
	if (game->wall.free_zbuffer == 1)
		free(game->wall.zbuffer);
	if (game->d.free_e == 1)
		free(game->d.e);
	ft_printf("%s", str);
	if (SOUND == 1 && OS == 1)
		system("killall afplay");
	if (SOUND == 1 && OS == 0)
		system("killall aplay");
	exit(EXIT_FAILURE);
}
