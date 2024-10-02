/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:43 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/02 20:01:12 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *truncate_space(char *src, t_cub *cub)
{
    int i = 0;
    char *dest;

    while(src && src[i] >= 'A' && src[i] <= 'Z')
        i++;
    while(src && (src[i] == ' ' || src[i] == ' '))
        i++;
    dest = gc_alloc(cub->garbage_collector, ft_strlen(&src[i]) - 1);
    ft_strlcpy(dest, &src[i], ft_strlen(&src[i]) - 1);
    return(dest);
    
}