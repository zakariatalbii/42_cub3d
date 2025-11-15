/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:32:58 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/15 14:09:44 by zatalbi          ###   ########.fr       */
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

static int	ft_tex_init(t_data *data)
{
	data->tex[NO] = mlx_load_png("./textures/wall.png");
	if (!data->tex[NO])
		return (1);
	data->tex[SO] = mlx_load_png("./textures/wall.png");
	if (!data->tex[SO])
		return (1);
	data->tex[WE] = mlx_load_png("./textures/wall1.png");
	if (!data->tex[WE])
		return (1);
	data->tex[EA] = mlx_load_png("./textures/wall1.png");
	if (!data->tex[EA])
		return (1);
	return (0);
}

int	ft_cub_init(t_data *data)
{
	ft_player(&data->player);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!data->mlx)
		return (1);
	data->cub_img
		= mlx_new_image(data->mlx, data->mlx->width, data->mlx->height);
	if (!data->cub_img)
		return (1);
	if (mlx_image_to_window(data->mlx, data->cub_img, 0, 0) < 0)
		return (1);
	if (ft_tex_init(data))
		return (1);
	return (0);
}
