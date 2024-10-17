/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:46:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/17 15:35:19 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_pixel(int color, t_game *game, int x, int y)
{
    char    *dst;
    
    dst = game->img->addr + (y * game->img->size_line + x * (game->img->bpp / 8));
    *(unsigned int*)dst = color;
}

static void get_pos_y(int *pos_y, t_game *game, float draw_start, int y)
{
    float   pix_step;
    float   tex_pos;
    
    pix_step = T_SIZE / (S_H / game->ray->dist);
    tex_pos = (y - draw_start) * pix_step;
    *pos_y = (int)tex_pos & (T_SIZE - 1);
    // *pos_y %= T_SIZE;
    // pos_y = (y * pix_step) * T_SIZE / (S_H / game->ray->dist);
}

static void get_pos_x(int *pos_x, t_game *game)
{
    float   hit_pos;
    
    if (game->ray->h_flg)
        hit_pos = game->ray->x_inter - floor(game->ray->x_inter);
    else
        hit_pos = game->ray->y_inter - floor(game->ray->y_inter);
    *pos_x = hit_pos * T_SIZE;
    if (!game->ray->h_flg && game->ray->angle > M_PI) //check this & adjust
        *pos_x = T_SIZE - *pos_x - 1;
    *pos_x %= T_SIZE;
}

static void set_texture(int tex_id, t_game *game, int x, int y, float draw_start) //NORM
{
    int     pos_x;
    int     pos_y;
    int     color;
    
    get_pos_x(&pos_x, game);
    get_pos_y(&pos_y, game, draw_start, y);
    color = get_texture_color(game->textures[tex_id], pos_x, pos_y);
    set_pixel(color, game, x, y);
}

static void draw_line(t_game *game, float draw_start, float draw_end, int texture, int x) //NORM
{
    int y;

    y = -1;
    while(++y < S_H)
    {
        if (y < draw_start)
            set_pixel(game->img->c_rgb, game, x, y);
        else if (y >= draw_start && y < draw_end)
            set_texture(texture, game, x, y, draw_start);
        else
            set_pixel(game->img->f_rgb, game, x, y);
    }
}

static void get_wall_height(t_game *game, float *draw_start, float *draw_end)
{
    float   wall_height;
    
    wall_height = S_H / game->ray->dist;
    *draw_start = -(wall_height / 2) + (S_H / 2);
    *draw_end = (wall_height / 2) + (S_H / 2);
    if (*draw_start < 0)
        *draw_start = 0;
    if (*draw_end >= S_H)
        *draw_end = S_H - 1;
}

//correct fisheye effect
static void adjust_distance(t_game *game)
{
    float   angle_diff;

    angle_diff = game->player->angle - game->ray->angle;
    game->ray->dist *= cos(angle_diff);
}

void	render_map(t_game *game)
{
    int		x;
    int    texture;
    float   draw_start;
    float   draw_end;

	x = -1;
	// game->ray->angle = norm_angle(game->player->angle - (game->player->fov_rd / 2));
    game->ray->angle = game->player->angle - (game->player->fov_rd / 2) + (x / (float)S_W) * game->player->fov_rd;

	while (++x < S_W)
	{
        get_wall_distance(&game);
        adjust_distance(game);
        get_wall_height(game, &draw_start, &draw_end);
        texture = select_texture(game);
        draw_line(game, draw_start, draw_end, texture, x);
	}
    mlx_put_image_to_window(game->mlx, game->win, game->img->img_p, 0, 0);
}
