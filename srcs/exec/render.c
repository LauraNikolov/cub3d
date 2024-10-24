/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:46:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/24 19:44:19 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pixel(int color, t_game *game, int x, int y)
{
	char	*dst;

	dst = game->img->addr + (y * game->img->size_line + x * (game->img->bpp
				/ 8));
	*(unsigned int *)dst = color;
}

static void	get_pos_x(t_point *pos, t_game *game)
{
	double	hit_pos;

	if (!game->ray->h_flg)
		hit_pos = game->pos.y + game->ray->dist * game->dda->ray_dir.y;
	else
		hit_pos = game->pos.x + game->ray->dist * game->dda->ray_dir.x;
	hit_pos -= floor((hit_pos));
	pos->x = (int)(hit_pos * (double)T_SIZE);
	if ((!game->ray->h_flg && game->dda->ray_dir.x > 0) || (game->ray->h_flg
			&& game->dda->ray_dir.y < 0))
	{
		pos->x = T_SIZE - pos->x - 1;
	}
}

static void	draw_line(t_game *game, int draw_start, int draw_end, int x)
{
	t_point	pos;
	double	step;
	double	tex_pos;
	int		y;

	y = -1;
	step = 1.0 * T_SIZE / (S_H / game->ray->dist);
	tex_pos = (draw_start - S_H / 2 + (S_H / game->ray->dist) / 2) * step;
	get_pos_x(&pos, game);
	while (++y < S_H)
	{
		if (y < draw_start)
			set_pixel(game->img->c_rgb, game, x, y);
		else if (y >= draw_start && y < draw_end)
		{
			pos.y = (int)tex_pos & (T_SIZE - 1);
			tex_pos += step;
			set_texture(game, pos, x, y);
		}
		else
			set_pixel(game->img->f_rgb, game, x, y);
	}
}

static void	get_wall_height(t_game *game, int *draw_start, int *draw_end)
{
	int	wall_height;

	wall_height = S_H / game->ray->dist;
	*draw_start = -(wall_height / 2) + (S_H / 2);
	*draw_end = (wall_height / 2) + (S_H / 2);
	if (*draw_start < 0)
		*draw_start = 0;
	if (*draw_end >= S_H)
		*draw_end = S_H - 1;
}

void	render_map(t_game *game)
{
	int	x;
	int	draw_start;
	int	draw_end;

	x = -1;
	while (++x < S_W)
	{
		get_wall_distance(&game, x);
		select_texture(game);
		get_wall_height(game, &draw_start, &draw_end);
		draw_line(game, draw_start, draw_end, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_p, 0, 0);
}
