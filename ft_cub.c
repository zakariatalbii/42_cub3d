/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:44:19 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/04 03:17:47 by zatalbi          ###   ########.fr       */
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
	int			texID;
	 
	data = (t_data *)param;
	mlx_resize_image(data->img, data->mlx->width, data->mlx->height);
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

		if (ray.side == 1)
		{
			if (ray.dir.y < 0)
				texID = SO;
			else
				texID = NO;
		}
		else
		{
			if (ray.dir.x < 0)
				texID = WE;
			else
				texID = EA;
		}
		
		texX = (int)(wallX * data->tex[texID]->width);
    	if ((ray.side == 0 && ray.dir.x < 0) || (ray.side == 1 && ray.dir.y < 0))
			texX = data->tex[texID]->width - texX - 1;

		y = 0;
		while (y < line.start)
		{
			mlx_put_pixel(data->img, x, y, 0x87CEEBCE);
			y++;
		}
		while (y < line.end + 1)
		{
			texY = (int)((double)(y + line.height / 2 - data->mlx->height / 2) * (data->tex[texID]->height - 1) / line.height);
			col = (int)(data->tex[texID]->pixels[(texX + texY * data->tex[texID]->width) * data->tex[texID]->bytes_per_pixel] << 24)
				+ (int)(data->tex[texID]->pixels[(texX + texY * data->tex[texID]->width) * data->tex[texID]->bytes_per_pixel + 1] << 16)
				+ (int)(data->tex[texID]->pixels[(texX + texY * data->tex[texID]->width) * data->tex[texID]->bytes_per_pixel + 2] << 8)
				+ (int)data->tex[texID]->pixels[(texX + texY * data->tex[texID]->width) * data->tex[texID]->bytes_per_pixel + 3];
			mlx_put_pixel(data->img, x, y, col);
			y++;
		}
		while (y < data->mlx->height)
		{
			mlx_put_pixel(data->img, x, y, 0x444444FF);
			y++;
		}
		x++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
