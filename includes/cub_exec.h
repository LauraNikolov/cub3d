/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/10 17:45:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

/* ------------  MACROS  --------------------------------------------------- */
# define S_W 1900
# define S_H 1000
# define T_SIZE 40 //tile size
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

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

typedef enum		e_texture
{
	T_NO,
	T_SO,
	T_WE,
	T_EA,
}					t_texture;

typedef struct s_player
{
	int x; // in px
	int y; // in px
	double				angle;
	float				fov_rd;
	// int         rot; // rotation flag
	// int         l_r; // left right flag
	// int         u_d; // up down flag
}						t_player;

typedef struct s_ray
{
	double				angle;
	double				dist;
	int					h_flg;
}						t_ray;

typedef struct s_game
{
	int					p_x;
	int					p_y;
	int					w_map; //need this
	int					h_map; //need this
	void				*win;
	void				*mlx;
	t_ray				*ray;
	t_player			*player;
	t_cub				*cub;
}						t_game;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* GAME */
int						clear_game(t_game *game);
void					start_game(t_cub *cub);

/* RENDER */
void					render_map(t_game *game);
void					get_wall_distance(t_game **game);
int						unit_circle(float angle, char c);
double					norm_angle(double x);

/* HANDLE MOVES */
int						on_keypress(int keysym, t_game *game);

#endif //CUB_H