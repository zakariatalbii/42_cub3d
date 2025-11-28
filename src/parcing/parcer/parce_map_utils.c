/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:45:31 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/28 16:30:48 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	only_spaces(char *s)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			space = 1;
		if (s[i] == '\n' && !space)
			return (0);
		i++;
	}
	return (1);
}

int	handle_end_map(int fd, char *line, int cont)
{
	if (check_fd(fd))
	{
		free_ptr(line);
		close(fd);
		return (-1);
	}
	free_ptr(line);
	close(fd);
	return (return_cont(cont));
}

int	get_cont_line(char *file)
{
	int		fd;
	int		cont;
	int		in_map;
	char	*line;

	cont = 0;
	in_map = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line) || (in_map && only_spaces(line)))
		{
			in_map = 1;
			cont++;
		}
		else if (in_map && !only_spaces(line))
			return (handle_end_map(fd, line, cont));
		free_ptr(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (return_cont(cont));
}

int	fill(char **map, t_point p, int height, int width)
{
	if (p.x < 0 || p.y < 0 || p.y >= height || p.x >= width)
		return (0);
	if (map[p.y][p.x] == '0' || is_player(map[p.y][p.x]))
		return (1);
	if (map[p.y][p.x] == ' ')
	{
		map[p.y][p.x] = 'V';
		if (fill(map, (t_point){p.x - 1, p.y}, height, width)
			|| fill(map, (t_point){p.x + 1, p.y}, height, width)
			|| fill(map, (t_point){p.x, p.y - 1}, height, width)
			|| fill(map, (t_point){p.x, p.y + 1}, height, width))
			return (1);
	}
	return (0);
}

int	flood_fill(char **map, t_point p, int height, int width)
{
	return (fill(map, p, height, width));
}
