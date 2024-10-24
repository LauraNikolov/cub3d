/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/24 19:14:29 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_ray(t_game **game, int x)
{
	(*game)->dda->camera_x = 2 * x / (double)S_W - 1;
	(*game)->dda->ray_dir.x = (*game)->dir.x + (*game)->plane.x
		* (*game)->dda->camera_x;
	(*game)->dda->ray_dir.y = (*game)->dir.y + (*game)->plane.y
		* (*game)->dda->camera_x;
	(*game)->dda->map.x = (int)(*game)->pos.x;
	(*game)->dda->map.y = (int)(*game)->pos.y;
	(*game)->dda->delta_dist.x = fabs(1 / (*game)->dda->ray_dir.x);
	(*game)->dda->delta_dist.y = fabs(1 / (*game)->dda->ray_dir.y);
}

static void	set_step(t_game **game)
{
	if ((*game)->dda->ray_dir.x < 0)
	{
		(*game)->dda->step.x = -1;
		(*game)->dda->side_dist.x = ((*game)->pos.x - (*game)->dda->map.x)
			* (*game)->dda->delta_dist.x;
	}
	else
	{
		(*game)->dda->step.x = 1;
		(*game)->dda->side_dist.x = ((*game)->dda->map.x + 1.0 - (*game)->pos.x)
			* (*game)->dda->delta_dist.x;
	}
	if ((*game)->dda->ray_dir.y < 0)
	{
		(*game)->dda->step.y = -1;
		(*game)->dda->side_dist.y = ((*game)->pos.y - (*game)->dda->map.y)
			* (*game)->dda->delta_dist.y;
	}
	else
	{
		(*game)->dda->step.y = 1;
		(*game)->dda->side_dist.y = ((*game)->dda->map.y + 1.0 - (*game)->pos.y)
			* (*game)->dda->delta_dist.y;
	}
}

static void	get_distance(t_game **game)
{
	while (1)
	{
		if ((*game)->dda->side_dist.x < (*game)->dda->side_dist.y)
		{
			(*game)->dda->side_dist.x += (*game)->dda->delta_dist.x;
			(*game)->dda->map.x += (*game)->dda->step.x;
			(*game)->ray->h_flg = 0;
		}
		else
		{
			(*game)->dda->side_dist.y += (*game)->dda->delta_dist.y;
			(*game)->dda->map.y += (*game)->dda->step.y;
			(*game)->ray->h_flg = 1;
		}
		if ((*game)->cub->maps[(int)(*game)->dda->map.y] \
				[(int)(*game)->dda->map.x] == '1')
			break ;
	}
}

void	get_wall_distance(t_game **game, int x)
{
	set_ray(game, x);
	set_step(game);
	get_distance(game);
	if ((*game)->ray->h_flg == 0)
		(*game)->ray->dist = ((*game)->dda->map.x - (*game)->pos.x + (1
					- (*game)->dda->step.x) / 2) / (*game)->dda->ray_dir.x;
	else
		(*game)->ray->dist = ((*game)->dda->map.y - (*game)->pos.y + (1
					- (*game)->dda->step.y) / 2) / (*game)->dda->ray_dir.y;
}
