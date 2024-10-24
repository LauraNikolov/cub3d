/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:33:23 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/24 19:50:09 by lnicolof         ###   ########.fr       */
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

static int	add_f(t_cub *cub)
{
	if (!is_overflow(cub->f[0]))
		cub->f_r = ft_atoi(cub->f[0]);
	else
		clean_exit("Error: Wrong RGB\n", cub->garbage_collector, cub);
	if (!is_overflow(cub->f[1]))
		cub->f_g = ft_atoi(cub->f[1]);
	else
		clean_exit("Error: Wrong RGB\n", cub->garbage_collector, cub);
	if (!is_overflow(cub->f[2]))
		cub->f_b = ft_atoi(cub->f[2]);
	else
		clean_exit("Error: Wrong RGB\n", cub->garbage_collector, cub);
	return (0);
}

static int	add_c(t_cub *cub)
{
	if (!is_overflow(cub->c[0]))
		cub->c_r = ft_atoi(cub->c[0]);
	else
		clean_exit("Error: Wrong RGB\n", cub->garbage_collector, cub);
	if (!is_overflow(cub->c[1]))
		cub->c_g = ft_atoi(cub->c[1]);
	else
		clean_exit("Error: Wrong RGB\n", cub->garbage_collector, cub);
	if (!is_overflow(cub->c[2]))
		cub->c_b = ft_atoi(cub->c[2]);
	else
		clean_exit("Error: Wrong RGB\n", cub->garbage_collector, cub);
	return (0);
}

static void	check_rgb_len(t_cub *cub)
{
	int		i;
	char	**c;
	char	**f;

	if (!cub->f || !cub->c)
		clean_exit("Error: invalid RGB\n", cub->garbage_collector, cub);
	i = -1;
	f = cub->f;
	c = cub->c;
	while (cub->f[++i])
	{
		if (!cub->f[i][0])
			clean_exit("Error: invalid RGB\n", cub->garbage_collector, cub);
	}
	if (i != 3)
		clean_exit("Error: invalid RGB\n", cub->garbage_collector, cub);
	i = -1;
	while (cub->c[++i])
	{
		if (!cub->c[i][0])
			clean_exit("Error: invalid RGB\n", cub->garbage_collector, cub);
	}
	if (i != 3)
		clean_exit("Error: invalid RGB\n", cub->garbage_collector, cub);
}

int	add_rgb(t_cub *cub, char *str)
{
	check_rgb_len(cub);
	if (ft_strncmp(str, "F", 1))
		add_f(cub);
	else if (ft_strncmp(str, "C", 1))
		add_c(cub);
	return (0);
}
