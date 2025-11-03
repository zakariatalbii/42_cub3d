/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:44:19 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/03 06:25:40 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_player(t_player *player)
{
	player->pos.x = 4.5;
	player->pos.y = 6.5;
	player->dir.x = 1.;
	player->dir.y = 0.;
	player->plane.x = 0.;
	player->plane.y = -tan(PI / 6);
}

double	ft_perpWallDist(t_player *player, t_ray *ray)
{
	t_xy	sideDist;
	t_xy	deltaDist;
	int		mapX;
	int		mapY;

	mapX = (int)player->pos.x;
	mapY = (int)player->pos.y;
	deltaDist.x = 1. / fabs(ray->dir.x);
	deltaDist.y = 1. / fabs(ray->dir.y);
	if (ray->dir.x < 0.)
		sideDist.x = (player->pos.x - mapX) * deltaDist.x;
	else
		sideDist.x = (mapX - player->pos.x + 1.) * deltaDist.x;
	if (ray->dir.y < 0.)
		sideDist.y = (mapY - player->pos.y + 1.) * deltaDist.y;
	else
		sideDist.y = (player->pos.y - mapY) * deltaDist.y;
	while (Map[mapY][mapX] == 0)
	{
		if (sideDist.x < sideDist.y)
		{
			sideDist.x += deltaDist.x;
			mapX -= 2 * (ray->dir.x < 0.) - 1;
			ray->side = 0;
		}
		else
		{
			sideDist.y += deltaDist.y;
			mapY += 2 * (ray->dir.y < 0.) - 1;
			ray->side = 1;
		}
	}
	if(ray->side == 0)
		return (sideDist.x - deltaDist.x);
	return (sideDist.y - deltaDist.y);
}

void	ft_setcol(t_data *data)
{
	int			x;
	int			y;

	x = 0;
	while (x < data->mlx->width)
	{
		y = 0;
		while (y < data->mlx->height / 2)
		{
			mlx_put_pixel(data->img, x, y, 0x004691CE);
			y++;
		}
		while (y < data->mlx->height)
		{
			mlx_put_pixel(data->img, x, y, 0xF5BC42AF);
			y++;
		}
		x++;
	}
}

void	ft_cub(void *param)
{
	t_data		*data;
	t_ray		ray;
	t_draw_line	line;
	int			x;
	int			y;
	int			col;
	double		wallX;
	int			texX;
	int			texY;
	 
	data = (t_data *)param;
	mlx_resize_image(data->img, data->mlx->width, data->mlx->height);
	ft_setcol(data);
	x = 0;
	while (x < data->mlx->width)
	{
		ray.cameraX = (2. * x - data->mlx->width) / data->mlx->height;
		ray.dir.x = data->player.dir.x + data->player.plane.x * ray.cameraX;
		ray.dir.y = data->player.dir.y + data->player.plane.y * ray.cameraX;
		ray.perpWallDist = ft_perpWallDist(&data->player, &ray);
		
		line.height = (int)(data->mlx->height / ray.perpWallDist);

		line.start = -line.height / 2 + data->mlx->height / 2;
		if(line.start < 0)
			line.start = 0;
		line.end = line.height / 2 + data->mlx->height / 2;
		if(line.end >= data->mlx->height)
			line.end = data->mlx->height - 1;


		if (ray.side == 0)
			wallX = data->player.pos.y - ray.dir.y * ray.perpWallDist;
		else
			wallX = data->player.pos.x + ray.dir.x * ray.perpWallDist;
		wallX -= (int)wallX;

		
		texX = (int)(wallX * data->tex->width);
    	if ((ray.side == 0 && ray.dir.x > 0) || (ray.side == 1 && ray.dir.y < 0))
			texX = data->tex->width - texX - 1;


		y = line.start;
		while (y < line.end + 1)
		{
			texY = (int)((y + line.height / 2. - data->mlx->height / 2.) * data->tex->height / line.height);
			col = (int)(data->tex->pixels[(texX + texY * data->tex->width) * data->tex->bytes_per_pixel] << 24)
				+ (int)(data->tex->pixels[(texX + texY * data->tex->width) * data->tex->bytes_per_pixel + 1] << 16)
				+ (int)(data->tex->pixels[(texX + texY * data->tex->width) * data->tex->bytes_per_pixel + 2] << 8)
				+ (int)data->tex->pixels[(texX + texY * data->tex->width) * data->tex->bytes_per_pixel + 3];
			mlx_put_pixel(data->img, x, y, col);
			y++;
		}
		x++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
