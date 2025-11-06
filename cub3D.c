/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:32:58 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/06 02:10:05 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	Map[25][50] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int ft_iswall(double x, double y)
{
  if ((Map[(int)y][(int)(x + .1)] == 1) || (Map[(int)y][(int)(x - .1)] == 1)
      || (Map[(int)(y + .1)][(int)(x + .1)] == 1) || (Map[(int)(y + .1)][(int)(x - .1)] == 1)
      || (Map[(int)(y - .1)][(int)(x + .1)] == 1) || (Map[(int)(y - .1)][(int)(x - .1)] == 1)
      || (Map[(int)(y + .1)][(int)x] == 1) || (Map[(int)(y - .1)][(int)x] == 1))
    return (1);
  return (0);
}

void	ft_hook(void *param)
{ 
	t_data	*data;
  double  tmp;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
  {
    if (!ft_iswall(data->player.pos.x + .1 * data->player.dir.x, data->player.pos.y))
      data->player.pos.x += .1 * data->player.dir.x;
    if (!ft_iswall(data->player.pos.x, data->player.pos.y - .1 * data->player.dir.y))
      data->player.pos.y -= .1 * data->player.dir.y;
  }
  if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
    if (!ft_iswall(data->player.pos.x - .1 * data->player.dir.x, data->player.pos.y))
      data->player.pos.x -= .1 * data->player.dir.x;
    if (!ft_iswall(data->player.pos.x, data->player.pos.y + .1 * data->player.dir.y))
      data->player.pos.y += .1 * data->player.dir.y;
  }
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
  {
    if (!ft_iswall(data->player.pos.x + .1 * data->player.dir.y, data->player.pos.y))
      data->player.pos.x += .1 * data->player.dir.y;
    if (!ft_iswall(data->player.pos.x, data->player.pos.y + .1 * data->player.dir.x))
      data->player.pos.y += .1 * data->player.dir.x;
  }
  if (mlx_is_key_down(data->mlx, MLX_KEY_A))
  {
    if (!ft_iswall(data->player.pos.x - .1 * data->player.dir.y, data->player.pos.y))
      data->player.pos.x -= .1 * data->player.dir.y;
    if (!ft_iswall(data->player.pos.x, data->player.pos.y - .1 * data->player.dir.x))
      data->player.pos.y -= .1 * data->player.dir.x;
  }
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
    tmp = data->player.dir.x;
    data->player.dir.x = data->player.dir.x * cos(PI / 36.) - data->player.dir.y * sin(PI / 36.);
    data->player.dir.y = data->player.dir.y * cos(PI / 36.) + tmp * sin(PI / 36.);
    tmp = data->player.plane.x;
    data->player.plane.x = data->player.plane.x * cos(PI / 36.) - data->player.plane.y * sin(PI / 36.);
    data->player.plane.y = data->player.plane.y * cos(PI / 36.) + tmp * sin(PI / 36.);
  }
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
    tmp = data->player.dir.x;
    data->player.dir.x = data->player.dir.x * cos(-PI / 36.) - data->player.dir.y * sin(-PI / 36.);
    data->player.dir.y = data->player.dir.y * cos(-PI / 36.) + tmp * sin(-PI / 36.);
    tmp = data->player.plane.x;
    data->player.plane.x = data->player.plane.x * cos(-PI / 36.) - data->player.plane.y * sin(-PI / 36.);
    data->player.plane.y = data->player.plane.y * cos(-PI / 36.) + tmp * sin(-PI / 36.);
  }
}

int	main(void)
{
	t_data	data;

	ft_player(&data.player);

	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 1);

	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
  
	mlx_image_to_window(data.mlx, data.img, 0, 0);

	data.tex[NO] = mlx_load_png("./textures/wall.png");
	data.tex[SO] = mlx_load_png("./textures/wall.png");
	data.tex[WE] = mlx_load_png("./textures/wall1.png");
	data.tex[EA] = mlx_load_png("./textures/wall1.png");

	mlx_loop_hook(data.mlx, ft_cub, &data);

  mlx_loop_hook(data.mlx, ft_hook, &data);
  
	mlx_loop(data.mlx);

	mlx_terminate(data.mlx);

	return (EXIT_SUCCESS);
}
