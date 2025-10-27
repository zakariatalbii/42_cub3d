/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:44:19 by zatalbi           #+#    #+#             */
/*   Updated: 2025/10/27 20:48:47 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_rad(double deg)
{
	return (deg * (PI / 180.));
}

void	ft_player(t_player *player)
{
	player->pos.x = 22.9;
	player->pos.y = 22.9;
	player->dir.x = -cos(PI / 4);
	player->dir.y = sin(PI /4);
	player->plane.x = tan(ft_rad(30.)) * sin(PI /4);
	player->plane.y = tan(ft_rad(30.)) * cos(PI / 4);
}

double	ft_perpWallDist(t_player *player, t_ray *ray)
{
	t_xy	deltaDist;
	t_xy	sideDist;
	int		mapX;
	int		mapY;
	int stepX;
    int stepY;

	deltaDist.x = 1. / fabs(ray->dir.x);
	deltaDist.y = 1. / fabs(ray->dir.y);

	mapX = (int)player->pos.x;
	mapY = (int)player->pos.y;

	if (ray->dir.x < 0.)
	{
		sideDist.x = (player->pos.x - mapX) * deltaDist.x;
		stepX = -1;
	}
	else
	{
		sideDist.x = (mapX - player->pos.x + 1.) * deltaDist.x;
		stepX = 1;
	}
	if (ray->dir.y > 0.)
	{
		sideDist.y = (player->pos.y - mapY) * deltaDist.y;
		stepY = -1;
	}
	else
	{
		sideDist.y = (mapY - player->pos.y + 1.) * deltaDist.y;
		stepY = 1;
	}
	while (1)
	{
		if (sideDist.x < sideDist.y)
		{
			sideDist.x += deltaDist.x;
			mapX += stepX;
			ray->side = 0;
		}
		else
		{
			sideDist.y += deltaDist.y;
			mapY += stepY;
			ray->side = 1;
		}
		if (Map[mapY][mapX] == 1)
			break ;
	}
	if(ray->side == 0)
		return (sideDist.x - deltaDist.x);
	return (sideDist.y - deltaDist.y);
}

void	ft_cub(void *param)
{
	t_data		*data;
	t_ray		ray;
	t_draw_line	line;
	int			x;
	int			y;
	int			col;

	data = (t_data *)param;
	x = 0;
	while (x < WIDTH)
	{
		ray.cameraX = 2. * x / WIDTH - 1.;
		ray.dir.x = data->player.dir.x + data->player.plane.x * ray.cameraX;
		ray.dir.y = data->player.dir.y + data->player.plane.y * ray.cameraX;
		ray.perpWallDist = ft_perpWallDist(&data->player, &ray);
		
		line.height = (int)(HEIGHT / ray.perpWallDist);

		line.start = -line.height / 2 + HEIGHT / 2;
		if(line.start < 0)
			line.start = 0;
		line.end = line.height / 2 + HEIGHT / 2;
		if(line.end >= HEIGHT)
			line.end = HEIGHT - 1;

		if (ray.side == 0)
			col = 0x34EBDEAF;
		else
			col = 0xEBA134AF;
		y = line.start;
		while (y < line.end + 1)
		{
			mlx_put_pixel(data->img, x, y, col);
			y++;
		}
		x++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
