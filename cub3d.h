/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:20:33 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/02 19:57:06 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft/libft.h"
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
	char					*NO;
	char					*SO;
	char					*WE;
	char					*EA;
	char					**F;
	char					**C;
}							t_cub;

// gnl
char						*ft_extract_line(char **stash, int *readed);
char						*ft_strdup_gnl(char *str, int len);
char						*get_next_line(int fd);
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
#endif