MLX_I = ./MLX42/include

ifeq ($(shell uname -s), Linux)
	MLX_L = ./MLX42/lib/linux/libmlx42.a
	LIBS = -ldl -lglfw -pthread -lm
else
	MLX_L = ./MLX42/lib/macOS/libmlx42.a
	LIBS = -L./MLX42/glfw/lib -lglfw -lm
endif

SRC = src/cub3D.c src/ft_cub_init.c src/ft_cub_loop.c src/ft_cub.c src/ft_draw.c src/ft_move_player.c src/utils.c \
		src/parcing/get_next_line/get_next_line.c src/parcing/memori_manage/gc_malloc.c \
		src/parcing/memori_manage/memory_util.c src/parcing/parcer/main_p.c src/parcing/parcer/parce_1_.c \
		src/parcing/parcer/parce_coler.c src/parcing/parcer/parce_map_utils.c src/parcing/parcer/parce_map.c \
		src/parcing/parcer/parce_utils.c src/parcing/parcer/validation_helper.c src/parcing/parcer/validation_map.c \
		src/parcing/parcing.c src/parcing/get_next_line/get_utils.c

OBJ = $(SRC:.c=.o)

NAME = cub3D

SRC_B = bonus/src/cub3D_bonus.c bonus/src/ft_cub_init_bonus.c bonus/src/ft_cub_loop_bonus.c \
		bonus/src/ft_cub_bonus.c bonus/src/ft_draw_bonus.c bonus/src/ft_move_player_bonus.c bonus/src/utils_bonus.c \
		bonus/src/ft_mini_map_bonus.c bonus/src/ft_mouse_bonus.c bonus/src/ft_animation_bonus.c bonus/src/ft_door_bonus.c \
		bonus/src/parcing/gc_malloc_bonus.c bonus/src/parcing/get_next_line_bonus.c bonus/src/parcing/parcing_bonus.c \
		bonus/src/parcing/main_p_bonus.c bonus/src/parcing/memory_util_bonus.c bonus/src/parcing/parce_1_bonus.c \
		bonus/src/parcing/parce_coler_bonus.c bonus/src/parcing/parce_map_bonus.c bonus/src/parcing/parce_map_utils_bonus.c \
		bonus/src/parcing/parce_utils_bonus.c bonus/src/parcing/validation_helper_bonus.c \
		bonus/src/parcing/validation_map_bonus.c 

OBJ_B = $(SRC_B:.c=.o)

NAME_B = cub3D_bonus

CC = cc -Wall -Wextra -Werror

RM = rm -f

%_bonus.o: %_bonus.c bonus/include/cub3D_bonus.h
	$(CC) -c $< -Ibonus/include -I$(MLX_I) -o $@

%.o: %.c include/cub3D.h
	$(CC) -c $< -Iinclude -I$(MLX_I) -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_L) $(LIBS) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(OBJ_B) $(MLX_L) $(LIBS) -o $(NAME_B)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all