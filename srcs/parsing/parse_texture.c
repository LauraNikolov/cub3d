/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:14:30 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/18 15:07:31 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void parse_f_c(t_cub *cub, char *str)
{
    if (!cub->C && !ft_strncmp("C", str, 1))
	{
		cub->C = check_rgb(cub, ft_substr(truncate_space(str, cub), 0,
					ft_strlen(str) - 1));
		if (!cub->C)
		{
			free(str);
			get_next_line(0, 2);
			clean_exit("Error: parse C\n", cub->garbage_collector,
				cub);
		}
	}
	else if (!cub->F && !ft_strncmp("F", str, 1))
	{
		cub->F = check_rgb(cub, ft_substr(truncate_space(str, cub), 0,
					ft_strlen(str) - 1));
		if (!cub->F)
		{
			free(str);
			get_next_line(0, 2);
            close(cub->fd);
			clean_exit("Error: parse F\n", cub->garbage_collector,
				cub);
		}
	}
}


static void parse_cardinal(t_cub *cub, char *str)
{
    if (!ft_strncmp("NO", str, 2))
	{
		cub->NO = truncate_space(str, cub);
		cub->count_NO++;
	}
	else if (!ft_strncmp("SO", str, 2))
	{
		cub->SO = truncate_space(str, cub);
		cub->count_SO++;
	}
	else if (!ft_strncmp("WE", str, 2))
	{
		cub->WE = truncate_space(str, cub);
		cub->count_WE++;
	}
	else if (!ft_strncmp("EA", str, 2))
	{
		cub->EA = truncate_space(str, cub);
		cub->count_EA++;
	}
}

static void check_valid_data(t_cub *cub, char *str)
{
    // * si ce n'est pas le nord, le sud, l'est, l'ouest ou F ou C
    if (ft_strncmp("NO", str, 2) && ft_strncmp("SO", str, 2) && ft_strncmp("EA",
			str, 2) && ft_strncmp("WE", str, 2) && ft_strncmp("F", str, 1)
		&& ft_strncmp("C", str, 1))
	{
        // * si tous les points cardinauc et le sol et le ciel ont ete collecte, c la map?
		if (cub->count_NO == 1 && cub->count_EA == 1 && cub->count_SO == 1
			&& cub->count_WE == 1 && cub->count_C == 1 && cub->count_F == 1 && cub->new_line_maps == 1)
        {
            collect_maps(cub, str);
        }
        // * sinon c de la merde
        else
        {
            free(str);
            get_next_line(0, 2);
            close(cub->fd);
            clean_exit("error clean exit\n", cub->garbage_collector, cub);
        }
		return ;
	}
}


void	collect_data(t_cub *cub, char *str)
{
    check_valid_data(cub, str);	
    // *si c un point cardinal
	if (!ft_strncmp("NO", str, 2) || !ft_strncmp("SO", str, 2) || !ft_strncmp("EA",
			str, 2) || !ft_strncmp("WE", str, 2))
        parse_cardinal(cub, str); 
    // * si c un sol ou un ciel
    if (!ft_strncmp("F", str, 1) || !ft_strncmp("C", str, 1)) 
    {
		if(!ft_strncmp("F", str, 1))
			cub->count_F++;
		if(!ft_strncmp("C", str, 1))
			cub->count_C++;
        parse_f_c(cub, str); 
    }
    // * si plusieurs donnes ont ete renseignee deux fois
	if (cub->count_EA > 1 || cub->count_NO > 1 || cub->count_WE > 1
		|| cub->count_WE > 1)
	{
		free(str);
		get_next_line(0, 2);
        close(cub->fd);
		clean_exit("Error\nplease enter one path\n", cub->garbage_collector,
			cub);
	}
}
