/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/21 19:09:07 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

/* ------------  MACROS  --------------------------------------------------- */
# define S_W 1500
# define S_H 1000
# define T_SIZE 32
# define FOV 66
# define ROTATION_SPEED 0.08
# define MOVE_SPEED 0.4
# define COLLISION 0.4
# define MAP_WIDTH 10      // Largeur de la carte
# define MAP_HEIGHT 10     // Hauteur de la carte
# define MINI_MAP_SIZE 200 // Taille de la minimap (en pixels)
# define CELL_SIZE (MINI_MAP_SIZE / S_W)
# define WALL_COLOR 0x0000FF
# define FLOOR_COLOR 0xFF0000
# define PLAYER_COLOR 0xFFA500 // Taille d'une cellule dans la minimap

/* ------------  LIBRARIES  ------------------------------------------------ */
//# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* ------------  STRUCTS  -------------------------------------------------- */
typedef struct s_cub	t_cub;

typedef enum e_textype
{
	T_NO,
	T_SO,
	T_WE,
	T_EA,
}						t_textype;

typedef struct s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct s_dda
{
	t_point				ray_dir;
	t_point				map;
	t_point				side_dist;
	t_point				delta_dist;
	t_point				step;
	double				camera_x;
}						t_dda;

typedef struct s_img
{
	unsigned int		f_rgb;
	unsigned int		c_rgb;
	void				*img_p;
	char				*addr;
	int					bpp;
	int					endian;
	int					size_line;
}						t_img;
typedef struct s_textures
{
	void				*img_p;
	char				*addr;
	int					bpp;
	int					endian;
	int					size_line;
	int					width;
	int					height;
}						t_texture;

typedef struct s_player
{
	int					x;
	int					y;
}						t_player;

typedef struct s_ray
{
	double				dist;
	int					h_flg;
	t_textype			tex_id;
}						t_ray;

typedef struct s_game
{
	void				*win;
	void				*mlx;
	t_point				pos;
	t_point				dir;
	t_point				plane;
	t_dda				*dda;
	t_texture			textures[4];
	t_img				*img;
	t_ray				*ray;
	t_player			*player;
	t_cub				*cub;
}						t_game;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* UTILS */
void					print_error(char *str, t_game *game);
void					clear_images(t_game *game);
void					clear_all(t_game *game);
int						clear_game(t_game *game);

/* TEXTURES */
void					set_texture(t_game *game, t_point pos, int x, int y);
void					select_texture(t_game *game);
void					init_textures(t_cub *cub, t_game *g);

/* RENDER */
void					set_pixel(int color, t_game *game, int x, int y);
void					render_map(t_game *game);
int						wall_hit(float x, float y, t_game *game);
void					get_wall_distance(t_game **game, int x);

/* HANDLE MOVES */
int						on_keypress(int keysym, t_game *game);

/* GAME */
void					start_game(t_cub *cub);
void					normalize_direction(t_game *game);
void					draw_minimap(t_game *game);

#endif // CUB_H