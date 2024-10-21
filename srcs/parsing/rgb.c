/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:33:23 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/18 14:23:24 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**check_rgb(t_cub *cub, char *str)
{
	char	**strs;
	int		i;
	int		y;

	i = 0;
	strs = ft_split(str, ',');
	if (!strs)
		return (NULL);
	gc_double_add(cub->garbage_collector, (void **)strs);
	while (strs && strs[i])
	{
		y = 0;
		while (strs[i] && strs[i][y])
		{
			if (ft_isdigit(strs[i][y]) || strs[i][y] == ' ')
				y++;
			else
				return (free(str), NULL);
		}
		i++;
	}
	if (str)
		free(str);
	return (strs);
}

static int	add_F(t_cub *cub)
{
	if (!is_overflow(cub->F[0]))
		cub->F_R = ft_atoi(cub->F[0]);
	else
		clean_exit("int overflow on F RGB\n", cub->garbage_collector, cub);
	if (!is_overflow(cub->F[1]))
		cub->F_G = ft_atoi(cub->F[1]);
	else
		clean_exit("int overflow on F RGB\n", cub->garbage_collector, cub);
	if (!is_overflow(cub->F[2]))
		cub->F_B = ft_atoi(cub->F[2]);
	else
		clean_exit("int overflow on F RGB\n", cub->garbage_collector, cub);
    return(0);
}

static int	add_C(t_cub *cub)
{
	if (!is_overflow(cub->C[0]))
		cub->C_R = ft_atoi(cub->C[0]);
	else
		clean_exit("int overflow on C RGB\n", cub->garbage_collector, cub);
	if (!is_overflow(cub->C[1]))
		cub->C_G = ft_atoi(cub->C[1]);
	else
		clean_exit("int overflow on C RGB\n", cub->garbage_collector, cub);
	if (!is_overflow(cub->C[2]))
		cub->C_B = ft_atoi(cub->C[2]);
	else
		clean_exit("int overflow on C RGB\n", cub->garbage_collector, cub);
    return(0);
}

int	add_rgb(t_cub *cub, char *str)
{
	if (ft_strncmp(str, "F", 1))
        add_F(cub);
	else if (ft_strncmp(str, "C", 1))
        add_C(cub);
	return (0);
}
