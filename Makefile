NAME =cub3d
CC = clang
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
UNAME=$(shell uname)


ifeq ($(UNAME), Darwin)
	MLX = -D MAC=1 -Imlx -Llibft -lft -Lminilibx-opengl -lmlx -framework OpenGL -framework Appkit
	SRCS = ./sources/events/mouse_mac.c
	SRCS += ./sources/raycasting/resolution_mac.c
endif
ifeq ($(UNAME), Linux)
	MLX = -D LINUX=1 -Lminilibx-linux -lmlx_Linux -Llibft -lft -L/usr/lib -Imlx_linux -lXext -lX11 -lm
	SRCS = ./sources/events/mouse_linux.c 
	SRCS += ./sources/raycasting/resolution_linux.c 
endif

RM = rm -f
SRCS += sources/raycasting/weapon.c \
	sources/raycasting/ray.c \
	sources/raycasting/enemy.c \
	sources/raycasting/music_color.c \
	sources/raycasting/floor_ceiling.c \
	sources/raycasting/sprites.c \
	sources/raycasting/fps_counter.c \
	sources/raycasting/finish.c \
	sources/raycasting/door_action.c \
	sources/raycasting/hud.c \
	sources/raycasting/door.c \
	sources/raycasting/door_refresh.c \
	sources/raycasting/algo_dda.c \
	sources/raycasting/params_game.c \
	sources/raycasting/sprites_sort.c \
	sources/raycasting/wall.c \
	sources/raycasting/quit_game.c \
	sources/raycasting/sprites_draw.c \
	sources/raycasting/health.c \
	sources/utils/ft_strjoin_free.c \
	sources/utils/parsing_utils.c \
	sources/utils/ft_biggest_str.c \
	sources/utils/ft_big_strlen.c \
	sources/cub3d.c \
	sources/parsing/treat_sprite.c \
	sources/parsing/treat_door.c \
	sources/parsing/parse_player.c \
	sources/parsing/treat_map.c \
	sources/parsing/bitmap.c \
	sources/parsing/textures.c \
	sources/parsing/parse_map.c \
	sources/parsing/copying_map.c \
	sources/parsing/fill_map.c \
	sources/parsing/player_dir.c \
	sources/parsing/treat_id_bonus.c \
	sources/parsing/treat_textures.c \
	sources/parsing/treat_res.c \
	sources/parsing/parse_file.c \
	sources/parsing/arguments.c \
	sources/parsing/treat_ceiling.c \
	sources/parsing/treat_id.c \
	sources/parsing/treat_floor.c \
	sources/events/manage_key.c \
	sources/events/movement.c \
	sources/events/rotation.c \
	sources/events/action.c \

OBJS = $(SRCS:.c=.o)
DEF = -D BONUS_SPRITES=1
DEF += -D BONUS_ENEMY=1
DEF += -D WEAPON=1
DEF += -D BONUS_FLOOR=1
DEF += -D BONUS_CEILING=1
DEF += -D HUD=1
DEF += -D BONUS_SHADOW=1
DEF += -D BONUS_HEALTH=1
DEF += -D MOUSE=1
DEF += -D SOUND=1
DEF += -D BONUS_JUMP=1
DEF += -D BONUS_CROUCH=1
DEF += -D BONUS_VIEW=1
DEF += -D B_DOOR=1

all : $(NAME)

$(NAME) :
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(SRCS) $(MLX) -o $(NAME)

clean : 
	@$(RM) $(NAME)

fclean : clean
	@$(MAKE) fclean -C ./libft

bonus : 
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(DEF) $(SRCS) $(MLX) -o $(NAME)

re : fclean all 

rebonus : fclean bonus

.PHONY : bonus all re fclean rebonus
