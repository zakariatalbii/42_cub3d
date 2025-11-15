MLX_REPO = https://github.com/codam-coding-college/MLX42.git

MLX = $(HOME)/MLX42

MLX_LIB = $(MLX)/lib/libmlx42.a

MLX_H_DIR = $(MLX)/include/MLX42

SRCS = src/cub3D.c src/ft_cub_init.c src/ft_cub_loop.c src/ft_cub.c src/ft_draw.c src/ft_move_player.c src/utils.c

OBJS= $(SRCS:.c=.o)

NAME = cub3D

SRCS_B = bonus/src/cub3D_bonus.c bonus/src/ft_cub_init_bonus.c bonus/src/ft_cub_loop_bonus.c bonus/src/ft_cub_bonus.c \
			bonus/src/ft_draw_bonus.c bonus/src/ft_move_player_bonus.c bonus/src/utils_bonus.c bonus/src/ft_mini_map_bonus.c \
			bonus/src/ft_mouse_bonus.c

OBJS_B= $(SRCS_B:.c=.o)

NAME_B = cub3D_bonus

CC = cc -Wall -Wextra -Werror

RM = rm -f

%.o: %.c include/cub3D.h
	$(CC) -c $< -Iinclude -I$(MLX_H_DIR) -o $@

%_bonus.o: %_bonus.c bonus/include/cub3D_bonus.h
	$(CC) -c $< -Ibonus/include -I$(MLX_H_DIR) -o $@

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) -Iinclude $(MLX_LIB) -I$(MLX_H_DIR) -ldl -lglfw -pthread -lm -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(MLX_LIB) $(OBJS_B)
	$(CC) $(OBJS_B) -Ibonus/include $(MLX_LIB) -I$(MLX_H_DIR) -ldl -lglfw -pthread -lm -o $(NAME_B)

$(MLX_LIB): $(MLX)
	cmake $(MLX) -B $(MLX)/lib && make -C $(MLX)/lib -j4

$(MLX):
	git clone $(MLX_REPO) $(MLX)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all

rebonus: fclean bonus

cleanall: fclean
	$(RM) -r $(MLX)