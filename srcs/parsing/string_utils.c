/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:43 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/21 15:28:03 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void free_tab(char **strs)
{
	if(!strs)
		return ;
	int i;

	i = 0;
	while(strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
}



int	clean_exit(char *msg, t_garbage_collector *gc, t_cub *cub)
{
	int	i;

	i = ft_strlen(msg);
	write(1, msg, i);
	if (gc)
		gc_free(gc);
	if(cub->maps)
		free_tab(cub->maps);
	free(cub);
	exit(1);
}

long	ft_atol(char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 7 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

int	is_overflow(char *str)
{
	char	*cmp;
	char	*new_str;

	if (!str)
		return (1);
	cmp = ft_itoa(ft_atol(str));
	new_str = ft_itoa(ft_atoi(str));
	if (ft_strlen(cmp) == ft_strlen(new_str) && !ft_strncmp(new_str, cmp,
			ft_strlen(cmp)))
	{
		return (free(cmp), free(new_str), 0);
	}
	else
	{
		printf("resulat de atol et resultat de atoi : (%s) et (%s)\n", cmp,
			new_str);
		return (free(cmp), free(new_str), 1);
	}
}

char	*truncate_space(char *src, t_cub *cub)
{
	int i = 0;
	char *dest;

	while (src && src[i] >= 'A' && src[i] <= 'Z')
		i++;
	while (src && (src[i] == ' ' || src[i] == ' '))
		i++;
	dest = gc_alloc(cub->garbage_collector, ft_strlen(&src[i]));
	ft_strlcpy(dest, &src[i], ft_strlen(&src[i]));
	return (dest);
}