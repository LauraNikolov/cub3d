/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:07:47 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/24 19:10:03 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_collision(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(new_x);
	map_y = (int)(new_y);
	if (game->cub->maps[map_y][map_x] == '1')
		return (true);
	return (false);
}

bool	hit_box(t_game *game, double x, double y)
{
	return (is_collision(game, x + COLLISION, y + COLLISION)
		|| is_collision(game, x - COLLISION, y - COLLISION)
		|| is_collision(game, x + COLLISION, y - COLLISION)
		|| is_collision(game, x - COLLISION, y + COLLISION));
}

void	move_down(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = -game->dir.x;
	new_y = -game->dir.y;
	new_x = game->pos.x + MOVE_SPEED * new_x;
	new_y = game->pos.y + MOVE_SPEED * new_y;
	if (!hit_box(game, new_x, new_y))
	{
		game->pos.x = new_x;
		game->pos.y = new_y;
	}
}

void	move_up(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos.x + MOVE_SPEED * game->dir.x;
	new_y = game->pos.y + MOVE_SPEED * game->dir.y;
	if (!hit_box(game, new_x, new_y))
	{
		game->pos.x = new_x;
		game->pos.y = new_y;
	}
}
