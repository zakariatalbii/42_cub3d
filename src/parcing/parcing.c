/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:17:51 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/28 16:33:00 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_fd(int fd)
{
	char	*line;
	int		result;
	int		i;

	result = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '\n')
			{
				result = 1;
				free_ptr(line);
				return (result);
			}
			i++;
		}
		free_ptr(line);
		line = get_next_line(fd);
	}
	return (result);
}

void	find_and_replace_player(char **map, t_config *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
			{
				data->player_dir = map[i][j];
				map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

t_config	*parcing(int ac, char **av)
{
	t_config	*map_conf;

	map_conf = gc_malloc(sizeof(t_config));
	if (!map_conf)
		return (NULL);
	data_init(map_conf);
	if (ac == 2)
	{
		if (main_parce(av, map_conf))
		{
			free_all();
			printf("error\n");
			return (NULL);
		}
	}
	else
	{
		free_all();
		printf("error\n");
		return (NULL);
	}
	return (map_conf);
}
