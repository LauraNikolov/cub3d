/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:31:51 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/17 16:58:12 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/********************************* */ //FOR TESTS
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

static void	move_up(t_player *player, t_point *target_pos)
{
    target_pos->x = player->x + cos(player->angle) * MOVE_SPEED;
    target_pos->y = player->y + sin(player->angle) * MOVE_SPEED;
}

static void	move_down(t_player *player, t_point *target_pos)
{
    target_pos->x = player->x + cos(player->angle) * MOVE_SPEED;
    target_pos->y = player->y + sin(player->angle) * MOVE_SPEED;
}

static void	move_left(t_player *player, t_point *target_pos)
{
    target_pos->x = player->x - sin(player->angle) * MOVE_SPEED;
    target_pos->y = player->y + cos(player->angle) * MOVE_SPEED;
}

static void	move_right(t_player *player, t_point *target_pos)
{
    target_pos->x = player->x + sin(player->angle) * MOVE_SPEED;
    target_pos->y = player->y - cos(player->angle) * MOVE_SPEED;
}
/********************************* */

static void update_game(t_game *game, t_point target_pos)
{
    int x;
    int y;
    
    x = target_pos.x / T_SIZE;
    y = target_pos.y / T_SIZE;
    
    if (game->cub->maps[y][x] != '1')
    {
        game->player->x = target_pos.x;
        game->player->y = target_pos.y;
    }
	render_map(game);
}

int	on_keypress(int keysym, t_game *game)
{
    t_point target_pos;
    
	if (keysym == XK_Escape)
		clear_game(game);
	if (keysym == XK_Left)
    	rotate_left(game);
	if (keysym == XK_Right)
    	rotate_right(game);
	if (keysym == XK_w)
		move_up(game->player, &target_pos);
	if (keysym == XK_s)
		move_down(game->player, &target_pos);
	if (keysym == XK_a)
		move_left(game->player, &target_pos);
	if (keysym == XK_d, &target_pos)
		move_right(game->player, &target_pos);
    update_game(game, target_pos);
	return (0);
}
