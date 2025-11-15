/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:32:58 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/15 18:27:39 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_mouse_hook(t_data *data)
{
	data->mouse = 1;
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(data->mlx, ft_mouse_rotate, data);
	mlx_mouse_hook(data->mlx, ft_mouse_mode, data);
}

int	ft_cub_loop(t_data *data)
{
	if (!mlx_loop_hook(data->mlx, ft_cub, data))
		return (1);
	if (!mlx_loop_hook(data->mlx, ft_mini_map, data))
		return (1);
	if (!mlx_loop_hook(data->mlx, ft_move_player, data))
		return (1);
	ft_mouse_hook(data);
	mlx_loop(data->mlx);
	return (0);
}
