/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:31:51 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/17 18:55:46 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_left(t_game *game)
{
    game->player->angle -= ROTATION_SPEED;
    game->player->angle = norm_angle(game->player->angle);
}

static void	rotate_right(t_game *game)
{
    game->player->angle += ROTATION_SPEED;
    game->player->angle = norm_angle(game->player->angle);
}

static void	move_up(t_game *game, t_point *target_pos)
{
    target_pos->x = game->player->x + cos(game->player->angle) * MOVE_SPEED;
    target_pos->y = game->player->y + sin(game->player->angle) * MOVE_SPEED;
}

static void	move_down(t_game *game, t_point *target_pos)
{
    target_pos->x = game->player->x - cos(game->player->angle) * MOVE_SPEED;
    target_pos->y = game->player->y - sin(game->player->angle) * MOVE_SPEED;
}

static void	move_left(t_game *game, t_point *target_pos)
{
    target_pos->x = game->player->x - sin(game->player->angle) * MOVE_SPEED;
    target_pos->y = game->player->y + cos(game->player->angle) * MOVE_SPEED;
}

static void	move_right(t_game *game, t_point *target_pos)
{
    target_pos->x = game->player->x + sin(game->player->angle) * MOVE_SPEED;
    target_pos->y = game->player->y - cos(game->player->angle) * MOVE_SPEED;
}

static void update_game(t_game *game, t_point *target_pos)
{
    if (!wall_hit(target_pos->x, target_pos->y, game))
    {
        game->player->x = target_pos->x;
        game->player->y = target_pos->y;
    }
	render_map(game);
}

int	on_keypress(int keysym, t_game *game)
{
    t_point target_pos;
    
    t_point target_pos;
    
	if (keysym == XK_Escape)
		clear_game(game);
	if (keysym == XK_Left)
    	rotate_left(game);
	if (keysym == XK_Right)
    	rotate_right(game);
	if (keysym == XK_Left)
    	rotate_left(game);
	if (keysym == XK_Right)
    	rotate_right(game);
	if (keysym == XK_w)
		move_up(game, &target_pos);
	if (keysym == XK_s)
		move_down(game, &target_pos);
	if (keysym == XK_a)
		move_left(game, &target_pos);
	if (keysym == XK_d)
		move_right(game, &target_pos);
    update_game(game, &target_pos);
	return (0);
}
