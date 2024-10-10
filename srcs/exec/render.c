/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:46:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/10 17:56:46 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void draw_line(t_game *game, float draw_start, int texture)
// {
//     int y;
//     int pix_step;

//     y = -1;
//     pix_step = T_SIZE / (S_H / game->ray->dist);
//     while(++y < S_H)
//     {
//         // if (y < draw_start)
//         //     //draw floor
//         // else if ((y >= draw_start) && (y <= S_H - draw_start))
//         //     //draw wall >> adjust pixel drawing according to pix_step (start w/ pos_y = draw_start * step)
//         // else
//         //     //draw sky
//     }
// }

static int select_texture(t_game *game)
{
    if (game->ray->h_flg)
    {
        if (game->player->angle > 0 && game->player->angle < M_PI)
            return (T_NO);
        return (T_SO);
    }
    if (game->player->angle > M_PI / 2 && game->player->angle < 3 * M_PI / 2)
        return (T_WE);
    return (T_EA);
}

static float get_wall_height(t_game *game)
{
    float   draw_start;
    float   wall_height;
    
    draw_start = 0.0;
    wall_height = S_H / game->ray->dist;
    if (wall_height < 0)
        draw_start = 0;
    else if (wall_height > S_H)
        draw_start = S_H - 1;
    else
        draw_start = - (wall_height / 2) + (S_H / 2);
    return (draw_start);
}

void	render_map(t_game *game)
{
    int		i;
    int     texture;
    float   draw_start;

	i = -1;
	game->ray->angle = game->player->angle - (game->player->fov_rd / 2);
	while (++i < S_W)
	{
        get_wall_distance(&game);
        // printf("TEST : %f\n", game->ray->dist); //TEST
        draw_start = get_wall_height(game);
        texture = select_texture(game);
        // draw_line(game, draw_start, texture);
	}
}
 