/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:36:15 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/27 06:45:45 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_texture_to_image(mlx_image_t *img, mlx_texture_t *tex)
{
	t_u_int	color;
	t_i_xy	tex_xy;
	t_i_xy	xy;

	xy.y = 0;
	while (xy.y < (int)img->height)
	{
		tex_xy.y = xy.y * tex->height / (int)img->height;
		xy.x = 0;
		while (xy.x < (int)img->width)
		{
			tex_xy.x = xy.x * tex->width / (int)img->width;
			color = ft_color(tex->pixels[(tex_xy.x + tex_xy.y * tex->width)
					* tex->bytes_per_pixel],
					tex->pixels[(tex_xy.x + tex_xy.y * tex->width)
					* tex->bytes_per_pixel + 1],
					tex->pixels[(tex_xy.x + tex_xy.y * tex->width)
					* tex->bytes_per_pixel + 2],
					tex->pixels[(tex_xy.x + tex_xy.y * tex->width)
					* tex->bytes_per_pixel + 3]);
			mlx_put_pixel(img, xy.x, xy.y, color);
			xy.x++;
		}
		xy.y++;
	}
}

static int	ft_load_frame(t_anime *anime, int id)
{
	char	path[256];

	snprintf(path, 256, "%s/frame%d.png", FRAMES_DIR, id + 1);
	anime->frames[id] = mlx_load_png(path);
	if (!anime->frames[id])
		return (1);
	return (0);
}

static int	ft_load_frames(t_anime *anime)
{
	int	i;

	i = 0;
	while (i < FRAMES)
	{
		if (ft_load_frame(anime, i))
			return (1);
		i++;
	}
	return (0);
}

int	ft_anime_init(t_data *data, t_anime *anime)
{
	anime->img
		= mlx_new_image(data->mlx, data->mlx->width, data->mlx->height);
	if (!anime->img)
		return (1);
	if (mlx_image_to_window(data->mlx, anime->img, 0, 0) < 0)
		return (1);
	if (ft_load_frames(anime))
		return (1);
	return (0);
}

void	ft_animation(void *param)
{
	t_anime	*anime;

	anime = (t_anime *)param;
	if (!anime->enabled)
		return ;
	if (anime->frame_delay)
	{
		anime->frame_delay--;
		return ;
	}
	ft_texture_to_image(anime->img, anime->frames[anime->frame_count]);
	anime->frame_count++;
	if (anime->frame_count == FRAMES)
	{
		anime->frame_count = 0;
		ft_texture_to_image(anime->img, anime->frames[anime->frame_count]);
		anime->enabled = 0;
		anime->img->enabled = 0;
	}
	anime->frame_delay = 2;
}
