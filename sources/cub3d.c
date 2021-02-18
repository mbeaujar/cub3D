/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:52:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 14:16:25 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_create_image(t_game *game)
{
	mlx_clear_window(game->vars.mlx, game->vars.win);
	if (B_DOOR == 1)
		refresh_door(&game->d);
	game->wall.offset = 0;
	if (OS == 1)
	{
		mlx_destroy_image(game->vars.mlx, game->vars.img);
		game->vars.img = mlx_new_image(game->vars.mlx,
				game->wall.resolutionx, game->wall.resolutiony);
		game->win.addr = mlx_get_data_addr(game->vars.img,
				&game->win.bits_per_pixel, &game->win.line_length,
				&game->win.endian);
	}
}

void	parsing(int argc, char **argv, t_game *game)
{
	game->file_bmp = 0;
	arguments(argc, argv, game);
	set_struct(&game->parsing);
	parse_file(argv[1], &game->parsing);
	player_dir(&game->wall, &game->parsing.me);
	game->vars.mlx = mlx_init();
	set_game(&game->wall, &game->parsing, &game->sprite, game);
	game->parsing.map[game->parsing.me.posx][game->parsing.me.posy] = '0';
	game->vars.img = mlx_new_image(game->vars.mlx,
			game->wall.resolutionx, game->wall.resolutiony);
	game->win.addr = mlx_get_data_addr(game->vars.img,
			&game->win.bits_per_pixel, &game->win.line_length,
			&game->win.endian);
	set_textures(&game->wall, &game->vars, &game->parsing);
	if (WEAPON == 1)
		params_image_weapon(&game->gun, game);
	if (game->file_bmp == 1)
		single_frame(game);
	game->vars.win = mlx_new_window(game->vars.mlx,
			game->wall.resolutionx, game->wall.resolutiony, "Cub3D");
}

int		single_frame(t_game *game)
{
	wall(game);
	sprites(game, game->parsing.number);
	file_bmp(game);
	ft_printf("file bmp created.\n");
	exit(0);
}

int		gameplay(t_game *game)
{
	player(&game->parsing.me, game);
	if (game->parsing.me.hp > 0 && game->parsing.me.score < 1500)
	{
		mlx_create_image(game);
		if (BONUS_ENEMY == 1)
			clear_enemy(game->parsing.position, game->parsing.number);
		key(&game->wall, game->parsing.map, game);
		wall(game);
		if (BONUS_ENEMY == 1)
			text_enemy(game->parsing.position,
					game->parsing.number, &game->parsing.me);
		sprites(game, game->parsing.number);
		if (BONUS_HEALTH == 1)
			health(&game->wall.image[9], &game->win, &game->parsing.me);
		if (WEAPON == 1)
			weapon(game, &game->gun);
		mlx_put_image_to_window(game->vars.mlx,
				game->vars.win, game->vars.img, 0, 0);
		if (HUD == 1)
			hud(game);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_game	game;
	int		pid;

	pid = -1;
	if (SOUND == 1)
	{
		pid = fork();
		if (OS == 1)
			(pid == 0) ? system("afplay ./textures/sound/music.mp3") : 0;
		else
			(pid == 0) ? system("aplay ./textures/sound/music.wav") : 0;
	}
	game.frame = time(NULL);
	if (pid != 0)
	{
		parsing(argc, argv, &game);
		mlx_hook(game.vars.win, 2, (1L << 0), add_key, &game);
		mlx_hook(game.vars.win, 3, (1L << 1), clear_key, &game);
		mlx_hook(game.vars.win, 33, 1L << 17, close_the_game, &game);
		if (MOUSE == 1)
			hook_mouse(&game);
		mlx_loop_hook(game.vars.mlx, gameplay, &game);
		mlx_loop(game.vars.mlx);
	}
	return (0);
}
