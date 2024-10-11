/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:41:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/11 18:43:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/********************************* */ //FOR TESTS
static void	move_up(t_game *game)
{
	int pos_x;
	int pos_y;

	pos_x = game->p_x - 1;
	pos_y = game->p_y;
	game->p_x = pos_x;
	game->p_y = pos_y;
}

static void	move_down(t_game *game)
{
	int pos_x;
	int pos_y;

	pos_x = game->p_x + 1;
	pos_y = game->p_y;
	game->p_x = pos_x;
	game->p_y = pos_y;
}

static void	move_left(t_game *game)
{
	int pos_x;
	int pos_y;

	pos_x = game->p_x;
	pos_y = game->p_x - 1;
	game->p_x = pos_x;
	game->p_y = pos_y;
}

static void	move_right(t_game *game)
{
	int pos_x;
	int pos_y;

	pos_x = game->p_x;
	pos_y  = game->p_y + 1;
	game->p_x = pos_x;
	game->p_y = pos_y;
}
/********************************* */

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		clear_game(game);
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

// HANDLE OUT OF BOUNDS MOVEMENT TO AVOID SEGFAULTS