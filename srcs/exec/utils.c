/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:44:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/21 17:23:50 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_error(char *str, t_game *game)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	clear_all(game);
}

void	clear_images(t_game *game)
{
	int	i;

	i = -1;
	while (game->textures[++i].img_p && i < 4)
		mlx_destroy_image(game->mlx, game->textures[i].img_p);
	if (game->img->img_p)
		mlx_destroy_image(game->mlx, game->img->img_p);
}

void	clear_all(t_game *game)
{
	clear_images(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	//clear_tab(game->cub->maps); //TEST
	free(game->cub);
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
	// gc_free(game->cub->garbage_collector);
	mlx_destroy_window(game->mlx, game->win);
	clear_all(game);
	return (0);
}
