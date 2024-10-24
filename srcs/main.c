/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:11:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/24 19:04:43 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av, char **env)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		return (0);
	ft_memset(cub, 0, sizeof(t_cub));
	if (ac != 2 || !env)
	{
		printf("Error: invalid argument or environnement\n");
		return (1);
	}
	init_data(cub, ac, av);
	start_game(cub);
	gc_free(cub->garbage_collector);
	free(cub);
	return (0);
}
