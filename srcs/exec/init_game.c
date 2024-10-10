/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:07:56 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/10 17:26:40 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clear_game(t_game *game)
{
	// gc_free(game->cub->garbage_collector); //TEST
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clear_tab(game->cub->maps); //TEST (valgrind error)
	free(game->player);
	free(game->ray);
	free(game->cub);
	exit(0);
	return (0);
}

static void	display_all(t_game game)
{
	game.win = mlx_new_window(game.mlx, S_W, S_H, "CUB3D");
	// if (!game.win)
		// handle_error
	render_map(&game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &clear_game, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &on_keypress, &game);
	mlx_loop(game.mlx);
}

static double get_player_angle(t_cub *cub)
{
	double angle;
	
	angle = 0.0;
	if (cub->player_cardinal == 'N')
		angle = M_PI / 2;
	else if (cub->player_cardinal == 'S')
		angle = 3 * M_PI / 2;
	else if (cub->player_cardinal == 'E')
		angle = 0.0;
	else if (cub->player_cardinal == 'W')
		angle = M_PI;
	return (angle);
}

static void init_game(t_cub *cub, t_game *game) //use gc & protect memory
{
	game->w_map = 30; //TEST
	game->h_map = 14; //TEST -> retrieve from parsing
	game->p_x = cub->player_x;
	game->p_y = cub->player_y;
	game->cub = cub;
	game->ray = malloc(sizeof(t_ray)); //check if malloc needed
	game->player = malloc(sizeof(t_player));
	game->player->fov_rd = FOV * (M_PI /180.0);
	game->player->angle = get_player_angle(cub);
	game->player->x = (game->p_x * T_SIZE) + (T_SIZE / 2);
	game->player->y = (game->p_y * T_SIZE) + (T_SIZE / 2);
}

void	start_game(t_cub *cub)
{
	t_game game;

	init_game(cub, &game);
	game.mlx = mlx_init();
	// if (!game.mlx)
		// print_error("MLX initialization failed.", game.map, 0);
	display_all(game);
}
