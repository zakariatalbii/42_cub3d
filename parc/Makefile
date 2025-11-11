NAME = cub
SRC =   main.c \
		parcer/main_p.c\
		parcer/parce_utils.c\
		memori_manage/gc_malloc.c\
		memori_manage/memory_util.c\
		errors/error_handel.c\
		get_next_line/get_next_line.c\
		parcer/parce_map.c\
		parcer/parce_1_.c\
		parcer/validation_map.c\
		parcer/parce_map_utils.c\
		parcer/parce_coler.c\
		parcer/validation_helper.c
CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
OBJ = $(SRC:.c=.o)
HEADER = cub.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "Compilation of $(NAME) is complete!"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS)  -c $< -o $@
	@echo "Compiled $< into $@"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean al
