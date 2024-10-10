/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:39:10 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/10 11:54:29 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_newline(char *str)
{
    if (!str)
        return;
    
    size_t len = strlen(str);
    
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}


// int	check_position(char **maps, int i, int y, t_cub *cub)
// {
// 	int	y_bis;
// 	int	max_tab;
// 	int	max_len;

// 	max_tab = tab_len(maps) - 1;
// 	max_len = ft_strlen(maps[i]);
// 	if (i == 0)
// 		return (clean_exit("Maps error\n", cub->garbage_collector, cub));
// 	if (i == max_tab)
// 		return (clean_exit("Maps error\n", cub->garbage_collector, cub));
// 	if (y - 1 < max_len && y - 1 >= 0)
// 	{
// 		if (maps[i][y - 1] == ' ')
// 			return (clean_exit("Maps error\n", cub->garbage_collector, cub));
// 	}
// 	if (y + 1 < max_len && y + 1 >= 0)
// 	{
// 		if (maps[i][y + 1] == ' ')
// 			return (clean_exit("Maps error\n", cub->garbage_collector, cub));
// 	}
// 	if (i + 1 < max_tab && i + 1 >= 0)
// 	{
// 		y_bis = ft_strlen(maps[i + 1]);
// 		if (y > y_bis)
// 			return (clean_exit("Maps error\n", cub->garbage_collector, cub));
// 		else
// 		{
// 			if (maps[i + 1][y] == ' ')
// 				return (clean_exit("Maps error\n", cub->garbage_collector,
// 						cub));
// 		}
// 	}
// 	if (i - 1 <= max_tab && i - 1 >= 0)
// 	{
// 		y_bis = ft_strlen(maps[i - 1]);
// 		if (y > y_bis)
// 			return (clean_exit("Maps error\n", cub->garbage_collector, cub));
// 		else
// 		{
// 			if (maps[i - 1][y] == ' ')
// 				return (clean_exit("Maps error\n", cub->garbage_collector,
// 						cub));
// 		}
// 	}
// 	return (0);
// }

int	check_position(char **maps, int i, int y, t_cub *cub)
{
	int len_tab;

	len_tab = tab_len(maps) - 1;
	if(i - 1 < 0 || y > (int)ft_strlen(maps[i - 1]) - 1|| maps[i - 1][y] == ' ')
		return(clean_exit("maps error 1\n", cub->garbage_collector, cub));
	if(i + 1 > len_tab || y > (int)ft_strlen(maps[i + 1]) - 1|| maps[i + 1][y] == ' ')
		return(clean_exit("maps error 2\n", cub->garbage_collector, cub));
	if(y + 1 > (int)ft_strlen(maps[i]) - 1|| maps[i][y + 1] == ' ')
		return(clean_exit("maps error 3\n", cub->garbage_collector, cub));
	if(y - 1 < 0 || maps[i][y -1] == ' ')
		return(clean_exit("maps error 4\n", cub->garbage_collector, cub));
	return(0);
}

int	map_is_valid(t_cub *cub)
{
	char	**tmp;
	int		i;
	int		y;

	i = 0;
	y = 0;
	tmp = cub->maps;
	while (tmp[i])
	{
        y = 0;
		while (tmp[i] && tmp[i][y] == ' ')
			i++;
		while (tmp[i] && tmp[i][y])
		{
			if (tmp[i][y] == '0' || tmp[i][y] == 'N' || tmp[i][y] == 'S'
				|| tmp[i][y] == 'W' || tmp[i][y] == 'E')
			{
				check_position(tmp, i, y, cub);
			}
			y++;
		}
		i++;
	}
	return (0);
}
/*
1111111111111111111111111
			1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
			11110111111111011101010010001
			11000000110101011100000010001
			10000000000000001100000010001
			10000000000000001101010010001
			11000001110101011111011110N0111
111101111110101101111010001
111111111111111111111111111
*/

// *

void	collect_maps(t_cub *cub, char *str)
{
	// reallouer la taille du tableau
	remove_newline(str);
	cub->maps = realloc_tab(cub->maps, str);
	if (!cub->maps)
	{
		close(cub->fd);
		get_next_line(0, 2);
		free(str);
		clean_exit("error\n", cub->garbage_collector, cub);
	}

	// ajouter la ligne au tableau
}