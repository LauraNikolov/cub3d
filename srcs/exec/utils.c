/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:44:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/24 19:44:36 by lnicolof         ###   ########.fr       */
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

void	init_img(t_cub *cub, t_game *g)
{
	g->img = malloc(sizeof(t_img));
	if (!g->img)
		print_error("Memory allocation failed.\n", g);
	g->img->img_p = mlx_new_image(g->mlx, S_W, S_H);
	if (!g->img->img_p)
		print_error("Image creation failed.\n", g);
	g->img->addr = mlx_get_data_addr(g->img->img_p, &g->img->bpp,
			&g->img->size_line, &g->img->endian);
	g->img->f_rgb = (cub->f_r << 16 | cub->f_g << 8 | cub->f_b);
	g->img->c_rgb = (cub->c_r << 16 | cub->c_g << 8 | cub->c_b);
}
