/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:10 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/08 17:05:28 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// int map_is_valid(t_cub *cub)
// {
//     //est-elle fermee par des murs

//     //a-telle uniquement que lescaraceres demande?
    
//     //a t'on specifie le position du joueur
// }




void collect_maps(t_cub *cub, char *str)
{
    //reallouer la taille du tableau
    cub->maps = realloc_tab(cub->maps, str);
    if(!cub->maps)
    {
        close(cub->fd);
        get_next_line(0, 2);
        free(str);
        clean_exit("error\n", cub->garbage_collector, cub);
    }
    
    // ajouter la ligne au tableau
}