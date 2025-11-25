/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:32:58 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/25 23:02:44 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_anime_zero(t_anime *anime)
{
	int	i;

	i = 0;
	while (i < FRAMES)
		anime->frames[i++] = NULL;
	anime->img = NULL;
	anime->frame_count = 0;
	anime->frame_delay = 2;
}

static void	ft_anime_terminate(t_data *data, t_anime *anime)
{
	int	i;

	i = 0;
	while (i < FRAMES)
	{
		if (anime->frames[i])
			mlx_delete_texture(anime->frames[i]);
		i++;
	}
	if (anime->img)
		mlx_delete_image(data->mlx, anime->img);
}

static void	ft_cub_zero(t_data *data)
{
	data->mlx = NULL;
	data->cub_img = NULL;
	data->mm_img = NULL;
	data->tex[NO] = NULL;
	data->tex[SO] = NULL;
	data->tex[WE] = NULL;
	data->tex[EA] = NULL;
	ft_anime_zero(&data->anime);
}

static void	ft_cub_terminate(t_data *data)
{
	ft_anime_terminate(data, &data->anime);
	if (data->tex[NO])
		mlx_delete_texture(data->tex[NO]);
	if (data->tex[SO])
		mlx_delete_texture(data->tex[SO]);
	if (data->tex[WE])
		mlx_delete_texture(data->tex[WE]);
	if (data->tex[EA])
		mlx_delete_texture(data->tex[EA]);
	if (data->cub_img)
		mlx_delete_image(data->mlx, data->cub_img);
	if (data->mm_img)
		mlx_delete_image(data->mlx, data->mm_img);
	if (data->mlx)
		mlx_terminate(data->mlx);
	free_all();
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_cub_zero(&data);
	if (ft_cub_init(&data, argc, argv))
		return (ft_cub_terminate(&data), EXIT_FAILURE);
	if (ft_cub_loop(&data))
		return (ft_cub_terminate(&data), EXIT_FAILURE);
	ft_cub_terminate(&data);
	return (EXIT_SUCCESS);
}
