/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:45:31 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/28 16:13:15 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	is_texture_or_color(char *s)
{
	return (!ft_strncmp(s, "NO ", 3)
		|| !ft_strncmp(s, "SO ", 3)
		|| !ft_strncmp(s, "WE ", 3)
		|| !ft_strncmp(s, "EA ", 3)
		|| !ft_strncmp(s, "F ", 2)
		|| !ft_strncmp(s, "C ", 2));
}

int	only_spaces(char *s)
{
	int	i;
	int	space;

	space = 0;
	i = 0;
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
	if (check(fd))
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

int	is_player(char c)
{
	return (c == 'W' || c == 'E' || c == 'S' || c == 'N');
}
