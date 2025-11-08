/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:40:14 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/08 03:09:44 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_miniPlayer(t_data *data)
{
	int cx;
	int cx0;
	int cy;
	int cy0;
	int r;

	r = 8;
	cx0 = data->imgMM->width / 2;
	cy0 = data->imgMM->height / 2;
	cy = cy0 - r;
	while (cy >= 0 && cy <= cy0 + r)
	{
		int dy = cy - cy0;
		int dxMax = (int)sqrt(r * r - dy * dy);
		cx = cx0 - dxMax;
		while (cx >= 0 && cx <= cx0 + dxMax)
		{
			if (pow(cy - cy0 + data->player.dir.y * r / 2, 2)
				+ pow(cx - cx0 - data->player.dir.x * r / 2, 2) <= pow(r / 2, 2))
				mlx_put_pixel(data->imgMM, cx, cy, 0xFFB4DCFF);
			else
				mlx_put_pixel(data->imgMM, cx, cy, 0xC8325AFF);
			cx++;
		}
		cy++;
	}
}

void	ft_miniMap(void *param)
{
	t_data	*data;

	int mapW = 50;
	int mapH = 25;

	double	tileS = 32.;

	int x;
	int y;
	
	int X;
	int Y;
	
	int w;
	int h;

	data = (t_data *)param;
	mlx_resize_image(data->imgMM, data->mlx->width / 4, data->mlx->height / 4);
	data->imgMM->instances->x = data->mlx->width - data->mlx->width / 4;
	data->imgMM->instances->y = data->mlx->height - data->mlx->height / 4;

	h = (int)data->imgMM->height;
	w = (int)data->imgMM->width;
	y = 0;
	while (y < h)
	{
		x  = 0;
		while (x < w)
		{
			X = x / tileS + (data->player.pos.x - w / (2 * tileS));
			Y = y / tileS + (data->player.pos.y - h / (2 * tileS));
			if (X < 0 || X >= mapW || Y < 0 || Y >= mapH)
				mlx_put_pixel(data->imgMM, x, y, 0x141419FF);
			else if (Map[Y][X] == 1)
				mlx_put_pixel(data->imgMM, x, y, 0x2D2D37FF);
			else
				mlx_put_pixel(data->imgMM, x, y, 0x649B64FF);
			x++;
		}
		y++;
	}
	ft_miniPlayer(data);
}
