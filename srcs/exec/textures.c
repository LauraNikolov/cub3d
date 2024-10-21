/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:02:30 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/21 17:13:44 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture(t_game *game, t_point pos, int x, int y)
{
	int	color;

	int tex_x = pos.x; 
	int tex_y = pos.y;
	if (tex_x >= 0 && tex_x < game->textures[game->ray->tex_id].width
		&& tex_y >= 0 && tex_y < game->textures[game->ray->tex_id].height)
	{
		color = *(unsigned int *)(game->textures[game->ray->tex_id].addr
				+ (tex_y * game->textures[game->ray->tex_id].size_line + tex_x
					* (game->textures[game->ray->tex_id].bpp / 8)));
		set_pixel(color, game, x, y);
	}
}

void	select_texture(t_game *game)
{
	if (game->ray->h_flg)
	{
		if (game->dda->ray_dir.y < 0)
			game->ray->tex_id = T_NO;
		else
			game->ray->tex_id = T_SO;
	}
	else
	{
		if (game->dda->ray_dir.x < 0)
			game->ray->tex_id = T_WE;
		else
			game->ray->tex_id = T_EA;
	}
}

static void	get_tex_addr(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!g->textures[i].img_p)
			print_error("Texture creation failed.\n", g);
		g->textures[i].addr = mlx_get_data_addr(g->textures[i].img_p,
				&g->textures[i].bpp, &g->textures[i].size_line,
				&g->textures[i].endian);
	}
}

void	init_textures(t_cub *cub, t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		g->textures[i].width = T_SIZE;
		g->textures[i].height = T_SIZE;
	}
	g->textures[0].img_p = mlx_xpm_file_to_image(g->mlx, cub->NO,
			&g->textures[0].width, &g->textures[0].height);
	g->textures[1].img_p = mlx_xpm_file_to_image(g->mlx, cub->SO,
			&g->textures[1].width, &g->textures[1].height);
	g->textures[2].img_p = mlx_xpm_file_to_image(g->mlx, cub->WE,
			&g->textures[2].width, &g->textures[2].height);
	g->textures[3].img_p = mlx_xpm_file_to_image(g->mlx, cub->EA,
			&g->textures[3].width, &g->textures[3].height);
	get_tex_addr(g);
}
