/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:31:51 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/18 19:48:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_up(t_game *game)
{
	int x;
	int y;

	x = game->pos.x + game->dir.x * MOVE_SPEED;
	y = game->pos.y + game->dir.y * MOVE_SPEED;
	if (game->cub->maps[(int)game->pos.y][x] != '1')
		game->pos.x += game->dir.x * MOVE_SPEED;
	if (game->cub->maps[y][(int)game->pos.x] != '1')
		game->pos.y += game->dir.y * MOVE_SPEED;
}

static void	move_down(t_game *game)
{
	int x;
	int y;

	x = game->pos.x - game->dir.x * MOVE_SPEED;
	y = game->pos.y - game->dir.y * MOVE_SPEED;
	if (game->cub->maps[(int)game->pos.y][x] != '1')
		game->pos.x -= game->dir.x * MOVE_SPEED;
	if (game->cub->maps[y][(int)game->pos.x] != '1')
		game->pos.y -= game->dir.y * MOVE_SPEED;
}

static void	move_right(t_game *game)
{
	int x;
	int y;

	x = game->pos.x + game->dir.y * MOVE_SPEED;
	y = game->pos.y - game->dir.x * MOVE_SPEED;
	if (game->cub->maps[(int)game->pos.y][x] != '1')
		game->pos.x += game->dir.y * MOVE_SPEED;
	if (game->cub->maps[y][(int)game->pos.x] != '1')
		game->pos.y -= game->dir.x * MOVE_SPEED;
}

static void	move_left(t_game *game)
{
	int x;
	int y;

	x = game->pos.x - game->dir.y * MOVE_SPEED;
	y = game->pos.y + game->dir.x * MOVE_SPEED;
	if (game->cub->maps[(int)game->pos.y][x] != '1')
		game->pos.x -= game->dir.y * MOVE_SPEED;
	if (game->cub->maps[y][(int)game->pos.x] != '1')
		game->pos.y += game->dir.x * MOVE_SPEED;
}

static void	rotate_right(t_game *game)
{
	double old_dir;
	double old_plane;
	
	old_dir = game->dir.x;
	old_plane = game->plane.x;
	game->dir.x = game->dir.x * cos(-ROTATION_SPEED) - game->dir.y * sin(-ROTATION_SPEED);
	game->dir.y = old_dir * sin(-ROTATION_SPEED) + game->dir.y * cos(-ROTATION_SPEED);
	game->plane.x = game->plane.x * cos(-ROTATION_SPEED) - game->plane.y * sin(-ROTATION_SPEED);
	game->plane.y = old_plane * sin(-ROTATION_SPEED) + game->plane.y * cos(-ROTATION_SPEED);
}

static void	rotate_left(t_game *game)
{
	double old_dir;
	double old_plane;
	
	old_dir = game->dir.x;
	old_plane = game->plane.x;
	game->dir.x = game->dir.x * cos(ROTATION_SPEED) - game->dir.y * sin(ROTATION_SPEED);
	game->dir.y = old_dir * sin(ROTATION_SPEED) + game->dir.y * cos(ROTATION_SPEED);
	game->plane.x = game->plane.x * cos(ROTATION_SPEED) - game->plane.y * sin(ROTATION_SPEED);
	game->plane.y = old_plane * sin(ROTATION_SPEED) + game->plane.y * cos(ROTATION_SPEED);
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
