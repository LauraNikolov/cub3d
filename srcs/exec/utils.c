/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:44:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/23 15:03:27 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *str, t_game *game)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	clear_all(game);
}

void	clear_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!game->textures[i].img_p)
		{
			i++;
			continue ;
		}
		mlx_destroy_image(game->mlx, game->textures[i].img_p);
		i++;
	}
	if (game->img->img_p)
		mlx_destroy_image(game->mlx, game->img->img_p);
}

void	clear_all(t_game *game)
{
	gc_free(game->cub->garbage_collector);
	free(game->cub);
	clear_images(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->dda)
		free(game->dda);
	if (game->img)
		free(game->img);
	if (game->ray)
		free(game->ray);
	exit(0);
}

int	clear_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	clear_all(game);
	return (0);
}
