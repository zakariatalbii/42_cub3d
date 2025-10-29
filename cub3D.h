/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:33:02 by zatalbi           #+#    #+#             */
/*   Updated: 2025/10/29 03:58:20 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"

# define WIDTH 800
# define HEIGHT 800

# define PI acos(-1.)

extern int Map[25][50];

typedef struct	s_xy
{
	double	x;
	double	y;
}	t_xy;

typedef struct	s_player
{
	t_xy	pos;
	t_xy	dir;
	t_xy	plane;
}	t_player;

typedef struct	s_ray
{
	t_xy	dir;
	double	cameraX;
	double	perpWallDist;
	int		side;
}	t_ray;

typedef struct	s_draw_line
{
	int	height;
	int	start;
	int	end;
}	t_draw_line;

typedef struct	s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	player;
}	t_data;

void	ft_player(t_player *player);
void	ft_cub(void *param);
double	ft_rad(double deg);

#endif