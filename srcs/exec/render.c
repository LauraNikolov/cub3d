/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:46:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/11 18:35:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_pixel(int color, t_game *game, int x, int y)
{
    char    *dst;
    
    dst = game->img->addr + (y * game->img->size_line + x * (game->img->bpp / 8));
    *(unsigned int*)dst = color;
}

static int get_texture_color(t_texture texture, int x, int y)
{
    char    *dst;

    dst = texture.addr + (y * texture.size_line + x * (texture.bpp / 8));
    return (*(unsigned int*)dst);
}

static void set_texture(int tex_id, t_game *game, int x, int y) //draw_start needed?
{
    int pix_step;
    int pos_x;
    int pos_y;
    int color;
    
    pix_step = T_SIZE / (S_H / game->ray->dist); // 1.0 * texHeight / lineHeight;
    pos_x = x * T_SIZE;
    pos_x %= T_SIZE;
    pos_y = (y * pix_step) * T_SIZE / (S_H / game->ray->dist);
    color = get_texture_color(game->textures[tex_id], pos_x, pos_y);
    set_pixel(color, game, x, y);
}

static void draw_line(t_game *game, float draw_start, int texture, int x)
{
    int y;

    y = -1;
    (void)texture;
    while(++y < S_H)
    {
        if (y < draw_start)
            set_pixel(game->img->f_rgb, game, x, y);
        else if ((y >= draw_start) && (y <= S_H - draw_start))
            set_texture(texture, game, x, y);
        else
            set_pixel(game->img->c_rgb, game, x, y);
    }
}

static int select_texture(t_game *game)
{
    if (game->ray->h_flg)
    {
        if (game->ray->angle > 0 && game->ray->angle < M_PI)
            return (T_NO);
        return (T_SO);
    }
    if (game->ray->angle > M_PI / 2 && game->ray->angle < 3 * M_PI / 2)
        return (T_WE);
    return (T_EA);
}

static float get_wall_height(t_game *game)
{
    float   draw_start;
    float   wall_height;
    
    draw_start = 0.0;
    wall_height = S_H / game->ray->dist;
    if (wall_height < 0)
        draw_start = 0;
    else if (wall_height > S_H)
        draw_start = S_H - 1;
    else
        draw_start = - (wall_height / 2) + (S_H / 2);
    return (draw_start);
}

void	render_map(t_game *game)
{
    int		x;
    int    texture;
    float   draw_start;

	x = -1;
	game->ray->angle = game->player->angle - (game->player->fov_rd / 2);
	while (++x < S_W)
	{
        get_wall_distance(&game);
        draw_start = get_wall_height(game);
        texture = select_texture(game);
        draw_line(game, draw_start, texture, x);
	}
    mlx_put_image_to_window(game->mlx, game->win, game->img->img_p, 0, 0);
}


// /* mlx_get_data_addr

// Gets the memory address of the given image. Memory of images is weird. It will set the line size in your given pointer. To get or set the value of the pixel (5, 100) in an image size of (500, 500),
// we would need to locate the position as follows:

// int pos = (y * size_line + x * (bits_per_pixel / 8));

// Here we multiply size_line by y as we need to skip y lines (and yes, line size is not equal to the amount of pixels in a line).
// We then add the remaining x units multiplied by bits_per_pixel / 8 to align with the final location.

// To modify each pixel with the correct color, we need to do some more fancy stuff. As we need to align the bits before writing, we need to do the following for the best result:

// char *mlx_data_addr = mlx_get_data_addr();
// *(unsigned int *)mlx_data_addr = color;


// /* mlx_put_image_to_window

// Puts an image to the given window instance at location (x,y). This is the recommended way to write large amounts of graphical data in one go. 
// Do mind that when changing the memory of the locations, it will be displayed directly on the window.
//  */
// /*
// ** Put an image to the given window.
// **
// ** @param	void *mlx_ptr	the mlx instance;
// ** @param	void *win_ptr	the window instance;
// ** @param	int  x			the x location of where the image ought to be placed;
// ** @param	int  y			the y location of where the image ought to be placed;
// ** @return	int				has no return value (bc).
// */



// // int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);