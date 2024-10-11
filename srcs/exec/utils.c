/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:44:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/11 18:18:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_images(t_game *game)
{
	int i;

	i = -1;
	while (game->textures[++i].img_p && i < 4)
		mlx_destroy_image(game->mlx, game->textures[i].img_p);
	mlx_destroy_image(game->mlx, game->img->img_p);
}

int	clear_game(t_game *game)
{
	// gc_free(game->cub->garbage_collector); //TEST
	mlx_destroy_window(game->mlx, game->win);
	clear_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clear_tab(game->cub->maps); //TEST (valgrind error)
	free(game->cub);
	free(game->player);
	free(game->img);
	free(game->ray);
	exit(0);
	return (0);
}

//check pos of angle on unit circle to adjust step
int	unit_circle(float angle, char c)
{
	if (c == 'x' && (angle > 0 && angle < M_PI))
		return (1);
	if (c == 'y' && (angle > (M_PI / 2) && angle < (3 * M_PI / 2)))
		return (1);
	return (0);
}

//normalize angles between 0 and 2π
double	norm_angle(double x)
{
	x = fmod(x, 2 * M_PI);
	if (x < 0)
		x += 2 * M_PI;
	return (x);
}
