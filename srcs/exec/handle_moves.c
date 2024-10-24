/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:31:51 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/24 19:09:22 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = -game->plane.x;
	new_y = -game->plane.y;
	new_x = game->pos.x + MOVE_SPEED * new_x;
	new_y = game->pos.y + MOVE_SPEED * new_y;
	if (!hit_box(game, new_x, new_y))
	{
		game->pos.x = new_x;
		game->pos.y = new_y;
	}
}

static void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->plane.x;
	new_y = game->plane.y;
	new_x = game->pos.x + MOVE_SPEED * new_x;
	new_y = game->pos.y + MOVE_SPEED * new_y;
	if (!hit_box(game, new_x, new_y))
	{
		game->pos.x = new_x;
		game->pos.y = new_y;
	}
}

static void	rotate_right(t_game *game)
{
	double	old_dir;
	double	old_plane;

	old_dir = game->dir.x;
	old_plane = game->plane.x;
	game->dir.x = game->dir.x * cos(-ROTATION_SPEED) - game->dir.y
		* sin(-ROTATION_SPEED);
	game->dir.y = old_dir * sin(-ROTATION_SPEED) + game->dir.y
		* cos(-ROTATION_SPEED);
	game->plane.x = game->plane.x * cos(-ROTATION_SPEED) - game->plane.y
		* sin(-ROTATION_SPEED);
	game->plane.y = old_plane * sin(-ROTATION_SPEED) + game->plane.y
		* cos(-ROTATION_SPEED);
}

static void	rotate_left(t_game *game)
{
	double	old_dir;
	double	old_plane;

	old_dir = game->dir.x;
	old_plane = game->plane.x;
	game->dir.x = game->dir.x * cos(ROTATION_SPEED) - game->dir.y
		* sin(ROTATION_SPEED);
	game->dir.y = old_dir * sin(ROTATION_SPEED) + game->dir.y
		* cos(ROTATION_SPEED);
	game->plane.x = game->plane.x * cos(ROTATION_SPEED) - game->plane.y
		* sin(ROTATION_SPEED);
	game->plane.y = old_plane * sin(ROTATION_SPEED) + game->plane.y
		* cos(ROTATION_SPEED);
}

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		clear_game(game);
	if (keysym == XK_Left)
		rotate_left(game);
	if (keysym == XK_Right)
		rotate_right(game);
	if (keysym == XK_w)
		move_up(game);
	if (keysym == XK_s)
		move_down(game);
	if (keysym == XK_a)
		move_left(game);
	if (keysym == XK_d)
		move_right(game);
	render_map(game);
	return (0);
}
