MLX_REPO = https://github.com/codam-coding-college/MLX42.git

MLX = $(HOME)/MLX42

MLX_LIB = $(MLX)/lib/libmlx42.a

MLX_H_DIR = $(MLX)/include/MLX42

SRCS = cub3D.c ft_cub.c

OBJS= $(SRCS:.c=.o)

NAME = cub3D

CC = cc -Wall -Wextra -Werror

RM = rm -f

%.o: %.c cub3D.h
	$(CC) -c $< -I$(MLX_H_DIR) -o $@

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(MLX_LIB) -I$(MLX_H_DIR) -ldl -lglfw -pthread -lm -o $(NAME)


$(MLX_LIB): $(MLX)
	cmake $(MLX) -B $(MLX)/lib && make -C $(MLX)/lib -j4

$(MLX):
	git clone $(MLX_REPO) $(MLX)

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C $(MLX)/lib clean
	$(RM) $(NAME)

re: fclean all

cleanall: fclean
	$(RM) -r $(MLX)

reall: cleanall all