/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:17:51 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/06 15:27:17 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// char **complit_map(char **map)
// {
//     int longer_len;
// 	char **squar_map;
// 	int i;

// 	longer_len = get_long(map);
// 	i = 0;
// 	while (map[i])
// 		i++;
// 	squar_map = gc_malloc(sizeof (char *) * (i + 1));
// 	if (!squar_map)
// 		return (NULL);
// 	i = 0;
// 	while (map[i])
// 	{
// 		squar_map[i] = gc_malloc(sizeof(char) * (longer_len + 1));
// 		if (!squar_map[i])
// 			return (NULL);
// 		memset(squar_map[i], '1', longer_len);
//         memcpy(squar_map[i], map[i], ft_strlen(map[i]));
//         squar_map[i][longer_len] = '\0';
//         i++;
// 	}
// 	squar_map[i] = NULL;
//     free_ptr(map);
// 	return(squar_map);
// }
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
        printf("]");
		printf("\n");
		i++;
	}
	
}
int main(int ac, char **av)
{
    t_config *map_conf;

    map_conf = gc_malloc(sizeof(t_config));
    if (!map_conf)
        return (1);
    data_init(map_conf);
    if (ac == 2)
    {
        if (main_parce(av, map_conf))
            printf("error :\n");
        else
        {
            // map_conf->map = complit_map(map_conf->map);
            print(map_conf->map);
            printf("go to raycasting\n");
        }
    }
    else
        printf("Error :Use-> ./cub3d <file.cub>\n");
    free_all();
    return (0);
}
