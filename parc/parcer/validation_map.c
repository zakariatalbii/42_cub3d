/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:34:46 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/11 14:49:14 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int check_the_top(char **map)
{
    int i;
    t_point p;    
    i = 0;
    while (map[0][i])
    {
        if (map[0][i] == '0' || is_player(map[0][i]))  // Fixed: Only check '0' or player
        {
            p.x = i;
            p.y = 0;
            if (fill_inside(map, p, get_h(map), get_long(map)))
                return (1);
        }
        i++;
    }
    return (0);
}
int check_the_bottom(int width, int height, char **map)
{
    int i;
    t_point p;
    
    i = 0;
    while (i < width)
    {
        if (map[height - 1][i] == '0' || is_player(map[height - 1][i]))  // Fixed
        {
            p.x = i;
            p.y = height - 1;
            if (fill_inside(map, p, height, width))
                return (1);
        }
        i++;
    }
    return (0);
}
int check_the_left(int height, char **map)
{
    t_point p;
    int i;
    
    i = 0;
    while (i < height)
    {
        if (map[i][0] == '0' || is_player(map[i][0]))  // Fixed
        {
            p.x = 0;
            p.y = i;
            if (fill_inside(map, p, height, get_long(map)))
                return (1);
        }
        i++;
    }
    return (0);
}
int check_the_right(int width, int height, char **map)
{
    t_point p;
    int i;
    
    i = 0;
    while (i < height)
    {
        if (map[i][width - 1] == '0' || is_player(map[i][width - 1]))  // Fixed
        {
            p.x = width - 1;
            p.y = i;
            if (fill_inside(map, p, height, width))
                return (1);
        }
        i++;
    }
    return (0);
}

void print(char **map)
{
	int i = 0;
	int j = 0;
	if (map == NULL)
	{
		printf("epmtymap\n");
		exit(1);		
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j == 0)
				printf("[");
			printf("%c", map[i][j]);
            
			j++;
		}
		printf("\n");
		i++;
	}
	
}
int validation(t_config *data)
{
	char **s_map;
	
	if (validation_char_map(data->map))
		return (1);
	s_map = prepar_map(data->map);
	if (!s_map)
		return (1);
	if (check_the_top(s_map))
		return (printf("map leak from the top: "),1);
	if (check_the_left(get_h(s_map), s_map))
		return (printf("map leak from the left: "),1);
	if (check_the_right(get_long(data->map), get_h(s_map), s_map))
		return (printf("map leak from the right:"),1);
	if (check_the_bottom(get_long(data->map), get_h(s_map), s_map))
		return (printf("map leak from the bottom:"),1);
	if (check_inside(s_map, data))
		return (printf("map leak from inside:"), 1);
    print(data->map);
	return (0);
}
