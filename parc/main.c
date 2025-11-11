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
            printf("go to raycasting\n");
    }
    else
        printf("Error :Use-> ./cub3d <file.cub>\n");
    free_all();
    return (0);
}
