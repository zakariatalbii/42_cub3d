/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:32:58 by zatalbi           #+#    #+#             */
/*   Updated: 2025/11/26 23:49:52 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static t_time	ft_timeval_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
}

static int	ft_outdoor(t_data *data, t_i_xy *pos)
{
	if ((pos->y != (int)(data->player.pos.y + .2 * data->player.dir.y)
		&& pos->y != (int)(data->player.pos.y - .2 * data->player.dir.y)
		&& pos->y != (int)(data->player.pos.y + .2 * data->player.dir.x)
		&& pos->y != (int)(data->player.pos.y - .2 * data->player.dir.x))
		|| (pos->x != (int)(data->player.pos.x + .2 * data->player.dir.x)
		&& pos->x != (int)(data->player.pos.x - .2 * data->player.dir.x)
		&& pos->x != (int)(data->player.pos.x + .2 * data->player.dir.y)
		&& pos->x != (int)(data->player.pos.x - .2 * data->player.dir.y)))
		return (1);
	return (0);
}

static void	ft_open_door(t_data *data, t_i_xy *map)
{
	if (data->map[map->y][map->x] == 'd')
	{
		data->door[0].isopen = 0;
		data->map[map->y][map->x] = 'D';
	}
	else if (data->map[map->y][map->x] == 'D')
	{
		if (data->door[0].isopen)
			data->door[1] = data->door[0];
		data->door[0].isopen = 1;
		data->door[0].pos.x = map->x;
		data->door[0].pos.y = map->y;
		data->door[0].open_t = ft_timeval_ms();
		data->map[map->y][map->x] = 'd';
		data->anime.enabled = 1;
		data->anime.img->enabled = 1;
	}
}

void	ft_door_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->door[1].isopen && ft_outdoor(data, &data->door[1].pos))
	{
		data->door[1].isopen = 0;
		data->map[data->door[1].pos.y][data->door[1].pos.x] = 'D';
	}
	if (data->door[0].isopen && ft_outdoor(data, &data->door[0].pos)
		&& ft_timeval_ms() - data->door[0].open_t >= 3000.)
	{
		data->door[0].isopen = 0;
		data->map[data->door[0].pos.y][data->door[0].pos.x] = 'D';
	}
}

void	ft_door(t_data *data)
{
	t_dist	dist;
	t_i_xy	map;

	map.x = (int)(data->player.pos.x + .1 * data->player.dir.x);
	map.y = (int)(data->player.pos.y - .1 * data->player.dir.y);
	dist.delta.x = 1. / fabs(data->player.dir.x);
	dist.delta.y = 1. / fabs(data->player.dir.y);
	if (data->player.dir.x < 0.)
		dist.side.x = (data->player.pos.x - map.x) * dist.delta.x;
	else
		dist.side.x = (map.x - data->player.pos.x + 1.) * dist.delta.x;
	if (data->player.dir.y < 0.)
		dist.side.y = (map.y - data->player.pos.y + 1.) * dist.delta.y;
	else
		dist.side.y = (data->player.pos.y - map.y) * dist.delta.y;
	if (dist.side.x < dist.side.y)
		map.x -= 2 * (data->player.dir.x < 0.) - 1;
	else
		map.y += 2 * (data->player.dir.y < 0.) - 1;
	ft_open_door(data, &map);
}
