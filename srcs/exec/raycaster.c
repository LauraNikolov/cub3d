/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/18 17:23:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if ray hits wall
int	wall_hit(float x, float y, t_game *game)
{
	t_point pos;

	pos.x = floor(x / T_SIZE);
	pos.y = floor(y / T_SIZE);
	if (x <= 0 || y <= 0 || pos.x < 0 || pos.y < 0 || pos.y >= game->h_map)
		return (1);
	if (game->cub->maps[(int)pos.y] && pos.x < (int)ft_strlen(game->cub->maps[(int)pos.y])
		&& game->cub->maps[(int)pos.y][(int)pos.x] == '1')
		return (1);
	return (0);
}

// Adjust step according to angle
static int	adjust_step(float angle, float *inter, float *step, char c) //check this 
{
	if ((c == 'h' && (angle > 0 && angle < M_PI))
		|| (c == 'v' && (!(angle > (M_PI / 2) && angle < (3 * M_PI / 2)))))
	{
			*inter += T_SIZE;
			return (-1);
	}
	*step *= -1;
	return (1);
}

// Get vertical intersection point
static float	get_v_inter(t_game *game, float angle)
{
	t_point inter;
	t_point step;
	int		pix;

	inter.x = floor(game->player->x / T_SIZE) * T_SIZE;
	inter.y = game->player->y + (inter.x - game->player->x) * tan(angle);
	step.x = T_SIZE;
    step.y = T_SIZE * tan(angle);
    // if (angle == M_PI / 2 || angle == 3 * M_PI / 2)
    //     	inter.y = game->player->y;
	pix = adjust_step(angle, &inter.x, &step.x, 'v');
	if ((step.y > 0 && unit_circle(angle, 'x'))
		|| (step.y < 0 && !unit_circle(angle, 'x')))
		step.y *= -1;
	while (!wall_hit(inter.x - pix, inter.y, game))
	{
		inter.x += step.x;
		inter.y += step.y;
	}
	game->ray->x_v_inter = inter.x;
	game->ray->y_v_inter = inter.y;
	return (sqrt(pow(inter.x - game->player->x, 2) + pow(inter.y - game->player->y, 2)));
}

// Get horizontal intersection point
static float	get_h_inter(t_game *game, float angle)
{
	t_point inter;
	t_point step;
	int		pix;

	inter.y = floor(game->player->y / T_SIZE) * T_SIZE;
	inter.x = game->player->x + (inter.y - game->player->y) / tan(angle);
	step.y = T_SIZE;
	step.x = T_SIZE / tan(angle);
	// if (angle == 0 || angle == M_PI)
    // 	inter.x = game->player->x;
	pix = adjust_step(angle, &inter.y, &step.y, 'h');
	if ((step.x > 0 && unit_circle(angle, 'y'))
		|| (step.x < 0 && !unit_circle(angle, 'y')))
		step.x *= -1;
	while (!wall_hit(inter.x, inter.y - pix, game))
	{
		inter.x += step.x;
		inter.y += step.y;
	}
	game->ray->x_h_inter = inter.x;
	game->ray->y_h_inter = inter.y;
	return (sqrt(pow(inter.x - game->player->x, 2) + pow(inter.y - game->player->y, 2)));
}

//Calculate distance from wall
void	get_wall_distance(t_game **game)
{
	double	h_inter;
	double	v_inter;

	(*game)->ray->h_flg = 0;
	h_inter = get_h_inter((*game), (*game)->ray->angle);
	v_inter = get_v_inter((*game), (*game)->ray->angle);
	if (v_inter <= h_inter)
	{	
		(*game)->ray->dist = v_inter;
		(*game)->ray->h_flg = 0;
	}
	else
	{
		(*game)->ray->dist = h_inter;
		(*game)->ray->h_flg = 1;
	}
}

// void	get_wall_distance(t_game **game, int x)
// {
// 	double posX = (*game)->cub->player_x;
//   	double posY = (*game)->cub->player_y;
// 	double dirX = -1, dirY = 0; //initial direction vector
//   	double planeX = 0, planeY = 0.66;
	  
// 	  double cameraX = 2*x/S_W - 1; //x-coordinate in camera space
//       double rayDirX = dirX + planeX*cameraX;
//       double rayDirY = dirY + planeY*cameraX;

//       //which box of the map we're in
//       int mapX = (*game)->cub->player_x;
//       int mapY = (*game)->cub->player_y;

//       //length of ray from current position to next x or y-side
//       double sideDistX;
//       double sideDistY;

//       //length of ray from one x or y-side to next x or y-side
//       double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
//       double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
//       double perpWallDist;

//       //what direction to step in x or y-direction (either +1 or -1)
//       int stepX;
//       int stepY;

//       int hit = 0; //was there a wall hit?
//       int side; //was a NS or a EW wall hit?

//       //calculate step and initial sideDist
//       if (rayDirX < 0)
//       {
//         stepX = -1;
//         sideDistX = (posX - mapX) * deltaDistX;
//       }
//       else
//       {
//         stepX = 1;
//         sideDistX = (mapX + 1.0 - posX) * deltaDistX;
//       }
//       if (rayDirY < 0)
//       {
//         stepY = -1;
//         sideDistY = (posY - mapY) * deltaDistY;
//       }
//       else
//       {
//         stepY = 1;
//         sideDistY = (mapY + 1.0 - posY) * deltaDistY;
//       }
// 	    while (hit == 0)
//       {
//         //jump to next map square, either in x-direction, or in y-direction
//         if (sideDistX < sideDistY)
//         {
//           sideDistX += deltaDistX;
//           mapX += stepX;
//           side = 0;
//         }
//         else
//         {
//           sideDistY += deltaDistY;
//           mapY += stepY;
//           side = 1;
//         }
//         //Check if ray has hit a wall
//         if (wall_hit(mapX, mapY, *game)) 
// 			hit = 1;
//       }

//       //Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
//       if(side == 0)
// 	  {	perpWallDist = (sideDistX - deltaDistX);
// 	  (*game)->ray->h_flg = 1;
// 	  }
//       else
// 	  	{perpWallDist = (sideDistY - deltaDistY);
// 		(*game)->ray->h_flg = 0;}
// 	  (*game)->ray->dist = perpWallDist;
//     //   //Calculate height of line to draw on screen
//     //   int lineHeight = (int)(S_H / perpWallDist);

//     //   //calculate lowest and highest pixel to fill in current stripe
//     //   int drawStart = -lineHeight / 2 + h / 2;
//     //   if(drawStart < 0) drawStart = 0;
//     //   int drawEnd = lineHeight / 2 + h / 2;
//     //   if(drawEnd >= h) drawEnd = h - 1;
// }
