/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:33:02 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/15 18:26:04 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include "MLX42.h"

# define WIDTH 1280
# define HEIGHT 720

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define PI 3.141593

typedef unsigned int	t_u_int;

typedef struct s_i_xy
{
	int	x;
	int	y;
}	t_i_xy;

typedef struct s_d_xy
{
	double	x;
	double	y;
}	t_d_xy;

typedef struct s_dist
{
	t_d_xy	side;
	t_d_xy	delta;
}	t_dist;

typedef struct s_tex
{
	int	x;
	int	y;
	int	id;
}	t_tex;

typedef struct s_player
{
	t_d_xy	pos;
	t_d_xy	dir;
	t_d_xy	plane;
}	t_player;

typedef struct s_line
{
	int	height;
	int	start;
	int	end;
}	t_line;

typedef struct s_ray
{
	t_d_xy	dir;
	double	cam_rate;
	double	perp_wall_dist;
	t_line	line;
	int		side;
}	t_ray;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*cub_img;
	mlx_image_t		*mm_img;
	mlx_texture_t	*tex[4];
	char			*tex_path[4];
	t_u_int			ceil;
	t_u_int			floor;
    char			**map;
	t_i_xy			map_size;
	t_player		player;
	int				mouse;
}	t_data;

int		ft_cub_init(t_data *data);
int		ft_cub_loop(t_data *data);

void	ft_cub(void *param);
void	ft_draw(t_data *data, t_ray *ray, t_i_xy *xy);

void	ft_mini_map(void *param);

void	ft_move_player(void *param);
void	ft_rotate1(t_data *data);
void	ft_rotate2(t_data *data);

void	ft_mouse_rotate(double xpos, double ypos, void *param);
void	ft_mouse_mode(mouse_key_t button, action_t action, modifier_key_t mods,
			void *param);

int		ft_iswall(double x, double y);
t_u_int	ft_color(t_u_int r, t_u_int g, t_u_int b, t_u_int a);

#endif