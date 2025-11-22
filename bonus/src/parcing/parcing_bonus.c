/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:17:51 by aaboudra          #+#    #+#             */
/*   Updated: 2025/11/22 17:15:20 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_config *parcing(int ac, char **av)
{
    t_config *map_conf;

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
        }
    }
    else
        printf("error\n");
    //you do free_all(); after don with staruct;
    return (map_conf);
}
