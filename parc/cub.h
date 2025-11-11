/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:02:13 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/09 12:10:54 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <unistd.h>
#include  <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
#include <ctype.h>
   
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct	s_point
{
	int x;
	int y;
} t_point;

typedef struct s_gc
{
    void			*ptr;
    struct s_gc		*next;
}	t_gc;

typedef struct s_textures
{
    char *no;
    char *so;
    char *we;
    char *ea;
} t_textures;

typedef struct s_color
{
    int r;
    int g;
    int b;
} t_color;


typedef struct s_config
{
    t_textures tex;
    t_color floor;
    t_color ceil;
    char **map;
    int player_x;
    int player_y;
    //int rows;
    //int cols;
    //char player_dir;
} t_config;

//malloc_free;
void	*gc_malloc(size_t size);
void free_ptr(void *ptr);
void	free_all(void);
char *gc_strndup(const char *line, int start, int end);
char	*ft_strdup(char *s1);

//parcing
int main_parce(char **cub_file, t_config *data);
void	data_init(t_config *conf);
int parce_line(char **file, int fd,t_config *data);
int assign_config(char *start,char *line, int i, t_config *data);
// int assign_map(char *line, t_config *data);
int is_map(char *line);
int negative_map_position(t_config *data);
int only_spaces(char *s);
int get_cont_line(char *file);
char *get_start(char *line, int i);
char *get_value(char *line, int i);

//utils
int	ft_isdigit(int v);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(char *s1, char *s2);
int is_space(char c);


    //validation
int validation(t_config *data);
int is_player(char c);
int	flood_fill(char **map, t_point p, int height, int width);
int validation_char_map(char **map);
char **prepar_map(char **map);
int get_long(char **map);
int get_h(char**map);
int	fill_inside(char **map, t_point p, int height, int width);
int check_inside(char **map, t_config *data);
void assing_position(int y, int x, t_config *data);


//grtnext_line
char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);





#endif