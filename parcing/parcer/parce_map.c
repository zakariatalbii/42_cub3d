/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 08:19:57 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/11 14:44:44 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub.h"

int is_map(char *line)
{
    int i;

	i = 0;
    while (is_space(line[i]))
        i++;
    if (line[i] == '\0')
        return (0);
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' &&
            line[i] != 'E' && line[i] != 'W' && !is_space(line[i]))
            return (0);
        i++;
    }
    return (1);
}

int get_long(char **map)
{
	int len;
	int max;
	int i;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
char **prepar_map(char **map)
{
	int longer_len;
	char **squar_map;
	int i;

	longer_len = get_long(map);
	i = 0;
	while (map[i])
		i++;
	squar_map = gc_malloc(sizeof (char *) * (i + 1));
	if (!squar_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		squar_map[i] = gc_malloc(sizeof(char) * (longer_len + 1));
		if (!squar_map[i])
			return (NULL);
		memset(squar_map[i], ' ', longer_len);
        memcpy(squar_map[i], map[i], ft_strlen(map[i]));
        squar_map[i][longer_len] = '\0';
        i++;
	}
	squar_map[i] = NULL;
	return(squar_map);
}
int get_h(char**map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int validation_char_map(char **map)
{
	int i;
	int j;
	int fond_player;
	
	i = 0;
	j = 0;
	fond_player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' '
					&& !is_player(map[i][j]))
					return (printf("map char no valid: "), 1);
			if (is_player(map[i][j]) && !fond_player)
				fond_player = 1;
			else if(is_player(map[i][j]) && fond_player)
					return (printf("More than one player: "), 1);
			j++;	
		}
		i++;
	}
	return (!fond_player ? 1 : 0);
}

