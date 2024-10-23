/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:20:33 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/23 15:47:10 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "cub_exec.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_collector_node
{
	void					*ptr;
	struct s_collector_node	*next;
}							t_collector_node;

typedef struct s_garbage_collector
{
	t_collector_node		*head;
}							t_garbage_collector;

typedef struct s_cub
{
	t_garbage_collector		*garbage_collector;
	char					*file;
	char					**maps;
	int						count_NO;
	int						count_SO;
	int						count_EA;
	int						count_WE;
	int						count_C;
	int						count_F;
	char					*NO;
	char					*SO;
	char					*WE;
	char					*EA;
	char					**F;
	char					**C;
	int						C_R;
	int						C_G;
	int						C_B;
	int						F_R;
	int						F_G;
	int						F_B;
	int						player_x;
	int						player_y;
	char					player_cardinal;
	int						fd;
	int						new_line_maps;
	int						new_line_in_maps;

}							t_cub;

// gnl
char						*ft_extract_line(char **stash, int *readed);
char						*ft_strdup_gnl(char *str, int len);
char						*get_next_line(int fd, int flag);
char						*ft_strjoin_gnl(char const *s1, char *s2);

// garbage_collector
t_garbage_collector			*gc_init(void);
void						*gc_alloc(t_garbage_collector *gc, size_t size);
void						gc_free(t_garbage_collector *gc);
void						gc_add(t_garbage_collector *gc, void *ptr);

// init data
void						init_data(t_cub *cub, int ac, char **av);
int							valid_file(char *str, t_cub *cub);
void						gc_double_add(t_garbage_collector *gc, void **ptr);
char						*truncate_space(char *src, t_cub *cub);
int							valid_file(char *str, t_cub *cub);
int							ft_is_empty(char *line, t_cub *cub);
void						free_tab(char **strs);
void						collect_data(t_cub *cub, char *str);
char						**check_rgb(t_cub *cub, char *str);
int							add_rgb(t_cub *cub, char *str);
char						**realloc_tab(char **old, char *new, t_cub *cub);
int							collect_all(t_cub *cub);

// parsing maps
void						collect_maps(t_cub *cub, char *str);
int							map_is_valid(t_cub *cub);

// str utils
int							is_overflow(char *str);
int							clean_exit(char *msg, t_garbage_collector *gc,
								t_cub *cub);
int							tab_len(char **tab);
#endif