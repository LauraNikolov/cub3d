/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:07:56 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/23 13:55:26 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_all(t_game game)
{
	game.win = mlx_new_window(game.mlx, S_W, S_H, "CUB3D");
	if (!game.win)
		print_error("MLX window creation failed.\n", &game);
	render_map(&game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &clear_game, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &on_keypress, &game);
	mlx_loop(game.mlx);
}

static void	init_img(t_cub *cub, t_game *g)
{
	g->img = malloc(sizeof(t_img));
	if (!g->img)
		print_error("Memory allocation failed.\n", g);
	g->img->img_p = mlx_new_image(g->mlx, S_W, S_H);
	if (!g->img->img_p)
		print_error("Image creation failed.\n", g);
	g->img->addr = mlx_get_data_addr(g->img->img_p, &g->img->bpp,
			&g->img->size_line, &g->img->endian);
	g->img->f_rgb = (cub->F_R << 16 | cub->F_G << 8 | cub->F_B);
	g->img->c_rgb = (cub->C_R << 16 | cub->C_G << 8 | cub->C_B);
}

static void	init_dir(t_game *game)
{
	if (game->cub->player_cardinal == 'N')
	{
		game->dir.x = 0.0;
		game->dir.y = -1.0;
		game->plane.x = -0.66;
		game->plane.y = 0.0;
	}
	else if (game->cub->player_cardinal == 'S')
	{
		game->dir.x = 0.0;
		game->dir.y = 1.0;
		game->plane.x = 0.66;
		game->plane.y = 0.0;
	}
	else if (game->cub->player_cardinal == 'W')
	{
		game->dir.x = -1.0;
		game->dir.y = 0.0;
		game->plane.x = 0.0;
		game->plane.y = 0.66;
	}
	else if (game->cub->player_cardinal == 'E')
	{
		game->dir.x = 1.0;
		game->dir.y = 0.0;
		game->plane.x = 0.0;
		game->plane.y = -0.66;
	}
}

static void	init_game(t_cub *cub, t_game *game)
{

	game->cub = cub;
	game->ray = ft_calloc(1, sizeof(t_ray));
	if (!game->ray)
		print_error("Memory allocation failed.\n", game);
	game->dda = ft_calloc(1, sizeof(t_dda));
	if (!game->dda)
		print_error("Memory allocation failed.\n", game);
	game->pos.x = game->cub->player_x;
	game->pos.y = game->cub->player_y;
}

void	start_game(t_cub *cub)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
	{
		gc_free(cub->garbage_collector);
		print_error("MLX initialization failed.\n", &game);
	}
	init_game(cub, &game);
	init_dir(&game);
	init_img(cub, &game);
	init_textures(cub, &game);
	display_all(game);
}
