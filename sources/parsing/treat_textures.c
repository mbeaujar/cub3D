/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:30:03 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/16 17:01:17 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	texture_mandatory(t_wall *wall, t_vars *vars, t_parsing *parsing)
{
	int i;

	i = 0;
	while (i < 5)
	{
		wall->image[i].text = mlx_xpm_file_to_image(vars->mlx,
				wall->image[i].path, &wall->image[i].width,
				&wall->image[i].height);
		if (wall->image[i].text == NULL)
			quit_parsing(parsing, "Error : textures can't read.\n");
		wall->image[i].addr = mlx_get_data_addr(wall->image[i].text,
				&wall->image[i].bits_per_pixel, &wall->image[i].line_length,
				&wall->image[i].endian);
		i++;
	}
}

void	texture_bonus(t_wall *wall, t_vars *vars, t_parsing *parsing, int index)
{
	wall->image[index].text = mlx_xpm_file_to_image(vars->mlx,
			wall->image[index].path, &wall->image[index].width,
			&wall->image[index].height);
	if (wall->image[index].text == NULL)
		quit_parsing(parsing, "Error : textures can't read.\n");
	wall->image[index].addr = mlx_get_data_addr(wall->image[index].text,
			&wall->image[index].bits_per_pixel, &wall->image[index].line_length,
			&wall->image[index].endian);
}

void	set_path(t_parsing *parsing)
{
	if (parsing->free_ceiling == 1)
	{
		free(parsing->ceiling);
		parsing->trgb_ceiling = -1;
		parsing->free_ceiling = 0;
	}
	if (parsing->free_floor == 1)
	{
		free(parsing->floor);
		parsing->trgb_floor = -1;
		parsing->free_floor = 0;
	}
	free(parsing->north);
	free(parsing->south);
	free(parsing->west);
	free(parsing->east);
	free(parsing->sprite);
	parsing->free_north = 0;
	parsing->free_west = 0;
	parsing->free_east = 0;
	parsing->free_south = 0;
	parsing->free_sprite = 0;
}

void	set_textures_enemy(t_wall *wall, t_vars *vars, t_parsing *parsing)
{
	wall->image[8].path = parsing->enemy;
	texture_bonus(wall, vars, parsing, 8);
	wall->image[9].path = "./textures/hud/health.xpm";
	texture_bonus(wall, vars, parsing, 9);
	wall->image[10].path = "./textures/bonus/enemy2.xpm";
	texture_bonus(wall, vars, parsing, 10);
	wall->image[11].path = "./textures/hud/numbers.xpm";
	texture_bonus(wall, vars, parsing, 11);
	wall->image[12].path = "./textures/bonus/door.xpm";
	texture_bonus(wall, vars, parsing, 12);
	free(parsing->enemy);
	parsing->free_enemy = 0;
}

void	set_textures(t_wall *wall, t_vars *vars, t_parsing *parsing)
{
	if (!(wall->image = malloc(sizeof(t_image) * 13)))
		quit_parsing(parsing, "Error : malloc for textures return NULL.\n");
	set_text(wall);
	get_path(wall, parsing);
	texture_mandatory(wall, vars, parsing);
	if (parsing->free_ceiling == 1)
		wall->image[5].path = parsing->ceiling;
	if (parsing->free_ceiling == 1)
		texture_bonus(wall, vars, parsing, 5);
	if (parsing->free_objects == 1 && !(--parsing->free_objects))
	{
		wall->image[7].path = parsing->objects;
		texture_bonus(wall, vars, parsing, 7);
		free(parsing->objects);
	}
	if (parsing->free_enemy == 1)
		set_textures_enemy(wall, vars, parsing);
	if (parsing->free_floor == 1)
		wall->image[6].path = parsing->floor;
	if (parsing->free_floor == 1)
		texture_bonus(wall, vars, parsing, 6);
	set_path(parsing);
}
