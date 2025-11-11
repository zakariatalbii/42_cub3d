/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:32:58 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/11 15:11:01 by aaboudra         ###   ########.fr       */
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

	data = (t_data *)param;
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

void  ft_cursor(double xpos, double ypos, void* param)
{
  static  double  x;
  t_data	*data;
  double  tmp;

  (void)ypos;
	data = (t_data *)param;
  if (data->mouse == 0)
    return ;
  if (xpos < x)
  {
    tmp = data->player.dir.x;
    data->player.dir.x = data->player.dir.x * cos(PI / 36.) - data->player.dir.y * sin(PI / 36.);
    data->player.dir.y = data->player.dir.y * cos(PI / 36.) + tmp * sin(PI / 36.);
    tmp = data->player.plane.x;
    data->player.plane.x = data->player.plane.x * cos(PI / 36.) - data->player.plane.y * sin(PI / 36.);
    data->player.plane.y = data->player.plane.y * cos(PI / 36.) + tmp * sin(PI / 36.);
  }
  if (xpos > x)
  {
    tmp = data->player.dir.x;
    data->player.dir.x = data->player.dir.x * cos(-PI / 36.) - data->player.dir.y * sin(-PI / 36.);
    data->player.dir.y = data->player.dir.y * cos(-PI / 36.) + tmp * sin(-PI / 36.);
    tmp = data->player.plane.x;
    data->player.plane.x = data->player.plane.x * cos(-PI / 36.) - data->player.plane.y * sin(-PI / 36.);
    data->player.plane.y = data->player.plane.y * cos(-PI / 36.) + tmp * sin(-PI / 36.);
  }
  
  x = xpos;
}

void  ft_mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
  t_data	*data;

  (void)mods;
	data = (t_data *)param;
  if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
  {
    if (data->mouse == 1)
    {
      mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
      data->mouse = 0;
    }
    else
    {
      mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
      data->mouse = 1;
    }
  }
}

int	main(void)
{
	t_data	data;

	ft_player(&data.player);

	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 1);

	data.imgCub = mlx_new_image(data.mlx, WIDTH, HEIGHT);
  
	data.imgMM = mlx_new_image(data.mlx, WIDTH / 4, HEIGHT / 4);
  
  mlx_image_to_window(data.mlx, data.imgCub, 0, 0);
            
	mlx_image_to_window(data.mlx, data.imgMM, data.mlx->width - data.mlx->width / 4,
                      data.mlx->height - data.mlx->height / 4);

	data.tex[NO] = mlx_load_png("./textures/wall.png");
	data.tex[SO] = mlx_load_png("./textures/wall.png");
	data.tex[WE] = mlx_load_png("./textures/wall1.png");
	data.tex[EA] = mlx_load_png("./textures/wall1.png");

	mlx_loop_hook(data.mlx, ft_cub, &data);
  
	mlx_loop_hook(data.mlx, ft_miniMap, &data);
  
  data.mouse = 1;
  mlx_set_cursor_mode(data.mlx, MLX_MOUSE_DISABLED);
  mlx_cursor_hook(data.mlx, ft_cursor, &data);
  mlx_mouse_hook(data.mlx, ft_mouse, &data);

  mlx_loop_hook(data.mlx, ft_hook, &data);
  
	mlx_loop(data.mlx);

	mlx_terminate(data.mlx);

	return (EXIT_SUCCESS);
}
