/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:43 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/08 15:12:25 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int clean_exit(char *msg, t_garbage_collector *gc, t_cub *cub)
{
    int i;

    i = ft_strlen(msg);
    write(1, msg, i);
    gc_free(gc);
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

	cmp = ft_itoa(ft_atol(str));
	if (ft_strlen(cmp) == ft_strlen(str) && !ft_strncmp(str, cmp,
			ft_strlen(cmp)))
		return (free(cmp), 0);
	else
		return (free(cmp), 1);
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