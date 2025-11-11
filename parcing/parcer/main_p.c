/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:22:08 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/11 15:02:22 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub.h"

int negative_map_position(t_config *data)
{
	if (!data->tex.no)
		return (printf("Negative map position or missing texture (NO):"), 1);
	if (!data->tex.so)
		return (printf("Negative map position or missing texture (SO):"), 1);
	if (!data->tex.we)
		return (printf("Negative map position or missing texture (WE):"), 1);
	if (!data->tex.ea)
		return (printf("Negative map position or missing texture (EA):"), 1);
	if (data->floor.b < 0)
		return (printf("Negative map position or missing floor color:"), 1);
	if (data->ceil.b < 0)
		return (printf("Negative map position or missing ceil color:"), 1);
	return (0);
}

char *get_start(char *line, int i)
{
	if (!ft_strncmp(&line[i], "NO ", 3))
		return("NO ");
	if (!ft_strncmp(&line[i], "SO ", 3))
		return ("SO ");
	if (!ft_strncmp(&line[i], "WE ", 3))
		return ("WE ");
	if (!ft_strncmp(&line[i], "EA ", 3))
		return ("EA ");
	if (!ft_strncmp(&line[i], "F ", 2))
		return ("F ");
	if (!ft_strncmp(&line[i], "C ", 2))
		return ("C ");
	else
		return (NULL);
}

char *get_value(char *line, int i)
{
	int begin;
	int end;

	if (!ft_strncmp(&line[i], "F ", 2) || !ft_strncmp(&line[i], "C ", 2))
		i += 2;
	else
		i += 3;
	while (is_space(line[i]))
		i++;
	begin = i;
	while (line[i] && !is_space(line[i]) && line[i] != '\n')
		i++;
	end = i;
	while (line[i])
	{
		if (!is_space(line[i]) && line[i] != '\n')
			return (NULL);
		i++;
	}
	return (gc_strndup(line, begin, end));
}



static int  valid_file_name(char *path)
{
	int len;
	int fd;
	
	fd = open(path, O_RDONLY);
	if (-1 == fd)
	{
		close(fd);
		perror("Error opening file");
		return (-1);
	}
	len = ft_strlen(path);
	if (len <= 4 || ft_strcmp(&path[len - 4], ".cub"))
	{
		close(fd);
		printf("Error Usage: </path/file_name.cub>\n");
		return (-1);
	}
	return (fd);
}

int main_parce(char **cub_file, t_config *data)
{
	int fd;

	fd = valid_file_name(cub_file[1]);
	if (fd > 0)
	{
		if (parce_line(cub_file, fd, data))
		{
		   close (fd);
		   return (1);
		}
		else
		{
			if (validation(data))
				return (close(fd), 1);
		}
	}
	else
		return (close(fd), 1);
	return (close(fd),0);
}
