/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:14:30 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/24 19:53:54 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_f_c(t_cub *cub, char *str)
{
	if (!cub->c && !ft_strncmp("C", str, 1))
	{
		cub->c = check_rgb(cub, ft_substr(truncate_space(str, cub), 0,
					ft_strlen(str) - 1));
		if (!cub->c)
		{
			free(str);
			get_next_line(0, 2);
			clean_exit("Error: parse C\n", cub->garbage_collector, cub);
		}
	}
	else if (!cub->f && !ft_strncmp("F", str, 1))
	{
		cub->f = check_rgb(cub, ft_substr(truncate_space(str, cub), 0,
					ft_strlen(str) - 1));
		if (!cub->f)
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
		cub->no = truncate_space(str, cub);
		cub->count_no++;
	}
	else if (!ft_strncmp("SO ", str, 3))
	{
		cub->so = truncate_space(str, cub);
		cub->count_so++;
	}
	else if (!ft_strncmp("WE ", str, 3))
	{
		cub->we = truncate_space(str, cub);
		cub->count_we++;
	}
	else if (!ft_strncmp("EA ", str, 3))
	{
		cub->ea = truncate_space(str, cub);
		cub->count_ea++;
	}
}

static void	check_valid_data(t_cub *cub, char *str)
{
	if (ft_strncmp("NO ", str, 3) && ft_strncmp("SO ", str, 3)
		&& ft_strncmp("EA ", str, 3) && ft_strncmp("WE ", str, 3)
		&& ft_strncmp("F ", str, 2) && ft_strncmp("C ", str, 2))
	{
		if (cub->count_no == 1 && cub->count_ea == 1 && cub->count_so == 1
			&& cub->count_we == 1 && cub->count_c == 1 && cub->count_f == 1
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
			cub->count_f++;
		if (!ft_strncmp("C", str, 1))
			cub->count_c++;
		check_comas(cub, str);
		parse_f_c(cub, str);
	}
	if (cub->count_ea > 1 || cub->count_no > 1 || cub->count_we > 1
		|| cub->count_we > 1)
	{
		free(str);
		get_next_line(0, 2);
		close(cub->fd);
		clean_exit("Error: please enter one path\n", cub->garbage_collector,
			cub);
	}
}
