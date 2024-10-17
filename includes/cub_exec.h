/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/17 16:00:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

/* ------------  MACROS  --------------------------------------------------- */
# define S_W 1500
# define S_H 1000
# define T_SIZE 32
# define FOV 60
# define ROTATION_SPEED 0.045
# define MOVE_SPEED 4

/* ------------  LIBRARIES  ------------------------------------------------ */
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft_src/libft.h"
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

typedef enum		e_textype
{
	T_NO,
	T_SO,
	T_WE,
	T_EA,
}					t_textype;

typedef struct s_point
{
	float					x;
	float					y;
}						t_point;

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
	double				angle;
	float				fov_rd;
}						t_player;

typedef struct s_ray
{
	float				x_inter;
	float				y_inter;
	double				angle;
	double				dist;
	int					h_flg;
}						t_ray;

typedef struct s_game
{
	int					p_x;
	int					p_y;
	int					w_map; //need this from parsing
	int					h_map; //need this from parsing
	void				*win;
	void				*mlx;
	t_texture			textures[4];
	t_img				*img;
	t_ray				*ray;
	t_player			*player;
	t_cub				*cub;
}						t_game;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* GAME */
void					start_game(t_cub *cub);

/* TEXTURES */
int						get_texture_color(t_texture texture, int x, int y);
int						select_texture(t_game *game);
void					init_textures(t_cub *cub, t_game *g);

/* RENDER */
void					render_map(t_game *game);
void					get_wall_distance(t_game **game);
int						unit_circle(float angle, char c);
double					norm_angle(double x);

/* HANDLE MOVES */
int						on_keypress(int keysym, t_game *game);

/* UTILS */
void					clear_images(t_game *game);
void					clear_all(t_game *game);
int						clear_game(t_game *game);

#endif //CUB_H