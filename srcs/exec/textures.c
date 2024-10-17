/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:02:30 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/17 19:13:05 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_texture_color(t_texture texture, int x, int y)
{
    char    *dst;

    dst = texture.addr + (y * texture.size_line + x * (texture.bpp / 8));
    return (*(unsigned int*)dst);
}

int select_texture(t_game *game)
{
    if (game->ray->h_flg)
    {
        if (game->ray->angle > 0 && game->ray->angle < M_PI)
            return (T_NO);
        return (T_SO);
    }
    if (game->ray->angle > M_PI / 2 && game->ray->angle < 3 * M_PI / 2)
        return (T_WE);
    return (T_EA);
}

static void get_tex_addr(t_game *g)
{
    int i;
    
    i = -1;
	while (++i < 4)
	{
		if (!g->textures[i].img_p) //LEAKS
		{	
			ft_putstr_fd("Error : textures loading failed.\n", 2);
			clear_all(g);
		}
		g->textures[i].addr = mlx_get_data_addr(g->textures[i].img_p, &g->textures[i].bpp, &g->textures[i].size_line, &g->textures[i].endian);
	}
}

void init_textures(t_cub *cub, t_game *g)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		g->textures[i].width = T_SIZE;
		g->textures[i].height = T_SIZE;
	}
	g->textures[0].img_p = mlx_xpm_file_to_image(g->mlx, cub->NO, &g->textures[0].width, &g->textures[0].height);
	g->textures[1].img_p = mlx_xpm_file_to_image(g->mlx, cub->SO, &g->textures[1].width, &g->textures[1].height);
	g->textures[2].img_p = mlx_xpm_file_to_image(g->mlx, cub->WE, &g->textures[2].width, &g->textures[2].height);
	g->textures[3].img_p = mlx_xpm_file_to_image(g->mlx, cub->EA, &g->textures[3].width, &g->textures[3].height);
	get_tex_addr(g);
}
