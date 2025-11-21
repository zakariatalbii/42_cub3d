/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:32:58 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/21 15:47:23 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_cub_init(&data, argc, argv);
	ft_cub_loop(&data);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
