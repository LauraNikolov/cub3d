/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:11:01 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/17 15:16:00 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	valid_file(char *str, t_cub *cub)
{
	int	i;
	int	fd;

	fd = 0;
	i = 0;
	i = ft_strlen(str);
	if (!ft_strncmp(&str[i - 4], ".cub", 4))
	{
		cub->garbage_collector = gc_init();
		cub->file = gc_alloc(cub->garbage_collector, ft_strlen(str) + 1);
		if (!cub->file)
			clean_exit("Error\n", cub->garbage_collector, cub);
	}
	else
		clean_exit("Error: invalid file\n", cub->garbage_collector, cub);
	ft_strlcpy(cub->file, str, i + 1);
	fd = open(cub->file, O_RDONLY);
	if (fd <= 1)
		return (-1);
	else
		return (fd);
}

int	ft_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
