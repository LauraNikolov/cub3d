/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:10 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/24 19:26:17 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_position(char **maps, int i, int y, t_cub *cub)
{
	int	len_tab;

	len_tab = tab_len(maps) - 1;
	if (i - 1 < 0 || y > (int)ft_strlen(maps[i - 1]) - 1 || maps[i
			- 1][y] == ' ')
		return (clean_exit("maps error 1\n", cub->garbage_collector, cub));
	if (i + 1 > len_tab || y > (int)ft_strlen(maps[i + 1]) - 1 || maps[i
			+ 1][y] == ' ')
		return (clean_exit("maps error 2\n", cub->garbage_collector, cub));
	if (y + 1 > (int)ft_strlen(maps[i]) - 1 || maps[i][y + 1] == ' ')
		return (clean_exit("maps error 3\n", cub->garbage_collector, cub));
	if (y - 1 < 0 || maps[i][y - 1] == ' ')
		return (clean_exit("maps error 4\n", cub->garbage_collector, cub));
	return (0);
}

void	check_maps_char(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	if (!str)
		clean_exit("Error: invalid map string\n", cub->garbage_collector, cub);
	while (str[i])
	{
		if (str[i] == '\n')
			clean_exit("maps invalid: contains newline\n",
				cub->garbage_collector, cub);
		if (str[i] && str[i] != '0' && str[i] != '1' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
			clean_exit("maps invalid\n", cub->garbage_collector, cub);
		i++;
	}
}

static void	map_check_y(t_cub *cub, int i, int y, int *player)
{
	char	**tmp;

	tmp = cub->maps;
	if (tmp[i][y] == '0' || tmp[i][y] == 'N' || tmp[i][y] == 'S'
		|| tmp[i][y] == 'W' || tmp[i][y] == 'E')
	{
		check_position(tmp, i, y, cub);
		if (tmp[i][y] == 'N' || tmp[i][y] == 'S' || tmp[i][y] == 'W'
			|| tmp[i][y] == 'E')
		{
			cub->player_x = y;
			cub->player_y = i;
			cub->player_cardinal = tmp[i][y];
			*player += 1;
		}
	}
}

int	map_is_valid(t_cub *cub)
{
	char	**tmp;
	int		i;
	int		y;
	int		player;

	i = 0;
	y = 0;
	player = 0;
	tmp = cub->maps;
	while (tmp[i])
	{
		check_maps_char(tmp[i], cub);
		y = 0;
		while (tmp[i] && tmp[i][y])
		{
			map_check_y(cub, i, y, &player);
			y++;
		}
		i++;
	}
	if (player != 1)
		return (clean_exit("error player\n", cub->garbage_collector, cub));
	return (0);
}

void	collect_maps(t_cub *cub, char *str)
{
	remove_newline(str, cub);
	cub->maps = realloc_tab(cub->maps, str, cub);
	if (!cub->maps)
	{
		close(cub->fd);
		get_next_line(0, 2);
		free(str);
		clean_exit("error\n", cub->garbage_collector, cub);
	}
}
