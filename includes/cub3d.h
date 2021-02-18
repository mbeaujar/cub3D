/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:15:37 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/02/17 11:10:00 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "key.h"

void		arguments(int argc, char **argv, t_game *game);
void		error_message(char *str);
void		quit_parsing(t_parsing *parsing, char *str);
int			read_file_with_return(char *str);
void		normi_friendly(int *tab, t_parsing *m);
void		parsing_ceiling(char *tmp, t_parsing *m);
void		parsing_floor(char *tmp, t_parsing *m);
char		*ft_strjoin_free(char const *s1, char const *s2);
int			ft_big_strlen(char **str);
char		**copying_map(t_parsing *parsing);
void		parse_map(t_parsing *parsing);
void		print_map(char **str);
void		treat_map(t_parsing *parsing);
void		parse_file(char *str, t_parsing *parsing);
int			create_rgb(int t, int r, int g, int b);
void		resolution(char *tmp, t_parsing *m);
void		id(char *tmp, t_parsing *m, int which);
void		read_id(t_parsing *m, char *path, int which);
char		*which_message(int which);
void		parse_player(t_parsing *parsing);
void		treat_map_up(t_parsing *parsing);
void		treat_map_down(t_parsing *parsing);
void		treat_sprite(t_parsing *parsing);
void		treat_room(t_parsing *parsing);
int			fill_cross(t_parsing *parsing, int i, int j);
int			ft_biggest_str(char **str);
void		player_dir(t_wall *wall, t_player *player);
void		file_bmp(t_game *game);
void		ray_direction(t_game *g, int x);
void		param_textures(t_game *g);
void		wall(t_game *game);
void		my_mlx_pixel_put(t_image *d, int x, int y, unsigned int color);
void		set_textures(t_wall *wall, t_vars *vars, t_parsing *parsing);
int			key(t_wall *d, char **map, t_game *game);
int			key_here(t_wall *d, int keycode);
int			clear_key(int keycode, t_game *d);
int			add_key(int keycode, t_game *d);
void		print_tab(t_wall *d);
void		rotation_left(t_wall *d);
void		rotation_right(t_wall *d);
void		free_map(char **map);
void		quit_game(t_game *game, char *str);
int			sprites(t_game *game, int number);
int			close_the_game(t_game *game);
void		draw_dir(t_game *game);
void		read_path(char *str, t_parsing *parsing);
void		bonus_sprites(char *tmp, t_parsing *m, int which);
void		floor_ceiling(t_game *g, int x);
int			shadecolor(t_wall *p, double dist, int color);
int			shadecolor_fire(t_wall *p, double dist, int color);
int			shade(t_game *g, double dist, int color);
void		params_image_weapon(t_weapon *w, t_game *game);
void		weapon(t_game *game, t_weapon *w);
void		enemy(int x, int y, t_game *g);
void		hud(t_game *game);
void		view_enemy(t_position *s, t_game *game, t_player *me);
void		seen_enemy(t_sprite *d, int x, int y, double dist);
void		health(t_image *number, t_image *win, t_player *me);
void		clear_enemy(t_position *s, int number);
void		text_enemy(t_position *s, int number, t_player *me);
void		player(t_player *me, t_game *game);
void		mlx_create_image(t_game *game);
int			single_frame(t_game *game);
int			mouse(int x, int y, t_game *game);
int			mouse_press(int button, int x, int y, t_game *game);
void		time_frame(t_game *game);
void		up(t_wall *wall);
void		down(t_wall *wall);
void		jump(t_wall *wall);
void		crouch(t_wall *wall);
void		quit_parsing_part_2(t_parsing *parsing, char *str);
void		jump_void(t_parsing *parsing);
int			recup_nb(char *tmp, int *i);
int			valid_line(char *tmp);
void		calculate_ystripe(t_game *g, int nb);
void		ceiling(t_game *g, int x);
void		sprites_dist(t_game *game, int nb);
void		set_wall(t_wall *d);
void		drawing_wall(t_game *g, int x);
void		rayon_dda(t_game *g);
void		set_struct(t_parsing *parsing);
void		set_game(t_wall *wall, t_parsing *parsing, t_sprite *sprite,
		t_game *game);
void		hook_mouse(t_game *game);
void		check_screensize(t_game *game);
void		music(void);
void		draw_weapon(t_image *w, t_image *win, int x, int y);
void		set_floor(t_game *g);
void		fast(t_game *g, int x);
void		show_fps(t_game *game);
void		open_xpm(t_image *file, t_game *game);
void		hud_to_image(t_game *game);
void		set_offset(t_game *game, int indice);
void		algorithm_dda(t_game *g);
void		door(t_game *g, int x);
void		treat_door(t_parsing *parsing);
void		refresh_door(t_door *d);
void		dooring(t_game *g);
void		clean_draw(t_door *d);
int			is_draw(t_game *g);
int			recup_offset(t_door *d);
void		door_close(t_game *g, int i, double dist);
void		door_opening(t_game *g, int i);
void		door_open(t_game *g, int i, double dist);
void		door_closing(t_game *g, int i);
void		secret_door(t_game *g, int i, double dist);
void		set_text(t_wall *wall);
void		get_path(t_wall *wall, t_parsing *parsing);
int			case_valid(char c);

#endif
