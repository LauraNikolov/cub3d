/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:52:51 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/18 16:48:56 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"




int tab_len(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
        i++;
    return(i);
}


char **realloc_tab(char **old, char *new, t_cub *cub)
{
    int size;
    int i;
    char **new_tab;

    i = 0;
    (void)cub;
    if (!old)
    {
        new_tab = (char **)malloc(sizeof(char *) * 2);
        if (!new_tab)
            return NULL;
        new_tab[0] = ft_strdup(new); 
        new_tab[1] = NULL; 
        return new_tab;
    }
    size = tab_len(old);
    new_tab = malloc(sizeof(char *) * (size + 2));
    if (!new_tab)
        return NULL;
    while(i < size)
    {
        new_tab[i] = old[i];
        i++;
    }
    new_tab[i] = ft_strdup(new);
    new_tab[i + 1] = NULL;
    free(old);
    return new_tab;
}