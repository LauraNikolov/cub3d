/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:07:56 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/11 18:30:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	init_img(t_cub *cub, t_game *g)
{
	g->img = malloc(sizeof(t_img)); //PROTECT
	g->img->img_p = mlx_new_image(g->mlx, S_W, S_H);
    g->img->addr = mlx_get_data_addr(g->img->img_p, &g->img->bpp, &g->img->size_line, &g->img->endian);
    g->img->f_rgb = (cub->F_R << 16 | cub->F_G << 8 | cub->F_B);
    g->img->c_rgb = (cub->C_R << 16 | cub->C_G << 8 | cub->C_B);
}

static void init_textures(t_cub *cub, t_game *g)
{
	int i;

	// i = -1;
	// while (++i < 4)
	// {
	// 	g->textures[i].width = T_SIZE;
	// 	g->textures[i].height = T_SIZE;
	// }
	g->textures[0].img_p = mlx_xpm_file_to_image(g->mlx, cub->NO, &g->textures[0].width, &g->textures[0].height);
	g->textures[1].img_p = mlx_xpm_file_to_image(g->mlx, cub->SO, &g->textures[1].width, &g->textures[1].height);
	g->textures[2].img_p = mlx_xpm_file_to_image(g->mlx, cub->WE, &g->textures[2].width, &g->textures[2].height);
	g->textures[3].img_p = mlx_xpm_file_to_image(g->mlx, cub->EA, &g->textures[3].width, &g->textures[3].height);
	i = -1;
	while (++i < 4)
	{	
		if (!g->textures[i].img_p) //LEAKS
		{	
			printf("Error : textures loading failed.\n");
			clear_images(g);
			mlx_destroy_display(g->mlx);
			free(g->mlx);
			free(cub);
			free(g->player);
			free(g->img);
			free(g->ray);
			exit(0);
		}
		g->textures[i].addr = mlx_get_data_addr(g->textures[i].img_p, &g->textures[i].bpp, &g->textures[i].size_line, &g->textures[i].endian);
	}
}

static void init_game(t_cub *cub, t_game *game) //use gc & protect memory
{
	game->w_map = 30; //TEST
	game->h_map = 14; //TEST -> retrieve from parsing
	game->p_x = cub->player_x;
	game->p_y = cub->player_y;
	game->player = malloc(sizeof(t_player));//PROTECT
	game->ray = malloc(sizeof(t_ray));//PROTECT
	game->cub = cub;
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
	init_img(cub, &game);
	init_textures(cub, &game);
	display_all(game);
}
