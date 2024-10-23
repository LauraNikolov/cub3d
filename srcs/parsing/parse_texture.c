/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:14:30 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/23 15:32:32 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_f_c(t_cub *cub, char *str)
{
	if (!cub->C && !ft_strncmp("C", str, 1))
	{
		cub->C = check_rgb(cub, ft_substr(truncate_space(str, cub), 0,
					ft_strlen(str) - 1));
		if (!cub->C)
		{
			free(str);
			get_next_line(0, 2);
			clean_exit("Error: parse C\n", cub->garbage_collector, cub);
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
			clean_exit("Error: parse F\n", cub->garbage_collector, cub);
		}
	}
}

static void	parse_cardinal(t_cub *cub, char *str)
{
	if (!ft_strncmp("NO ", str, 3))
	{
		cub->NO = truncate_space(str, cub);
		cub->count_NO++;
	}
	else if (!ft_strncmp("SO ", str, 3))
	{
		cub->SO = truncate_space(str, cub);
		cub->count_SO++;
	}
	else if (!ft_strncmp("WE ", str, 3))
	{
		cub->WE = truncate_space(str, cub);
		cub->count_WE++;
	}
	else if (!ft_strncmp("EA ", str, 3))
	{
		cub->EA = truncate_space(str, cub);
		cub->count_EA++;
	}
}

static void	check_valid_data(t_cub *cub, char *str)
{
	if (ft_strncmp("NO ", str, 3) && ft_strncmp("SO ", str, 3)
		&& ft_strncmp("EA ", str, 3) && ft_strncmp("WE ", str, 3)
		&& ft_strncmp("F ", str, 2) && ft_strncmp("C ", str, 2))
	{
		if (cub->count_NO == 1 && cub->count_EA == 1 && cub->count_SO == 1
			&& cub->count_WE == 1 && cub->count_C == 1 && cub->count_F == 1
			&& cub->new_line_maps == 1)
		{
			collect_maps(cub, str);
		}
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

static void	check_comas(t_cub *cub, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		free(str);
		get_next_line(0, 2);
		close(cub->fd);
		clean_exit("Error: invalid format for RGB\n", cub->garbage_collector,
			cub);
	}
}

void	collect_data(t_cub *cub, char *str)
{
	check_valid_data(cub, str);
	if (!ft_strncmp("NO ", str, 3) || !ft_strncmp("SO ", str, 3)
		|| !ft_strncmp("EA ", str, 3) || !ft_strncmp("WE ", str, 3))
		parse_cardinal(cub, str);
	if (!ft_strncmp("F ", str, 2) || !ft_strncmp("C ", str, 2))
	{
		if (!ft_strncmp("F", str, 1))
			cub->count_F++;
		if (!ft_strncmp("C", str, 1))
			cub->count_C++;
		check_comas(cub, str);
		parse_f_c(cub, str);
	}
	if (cub->count_EA > 1 || cub->count_NO > 1 || cub->count_WE > 1
		|| cub->count_WE > 1)
	{
		free(str);
		get_next_line(0, 2);
		close(cub->fd);
		clean_exit("Error: please enter one path\n", cub->garbage_collector,
			cub);
	}
}
