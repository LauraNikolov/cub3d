/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:05:00 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/21 16:08:51 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s || n == 0)
		return ;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	unsigned char   buffer[100] = "blougiboulga\0";
	unsigned char   bouffer[10];
	size_t n;

	n = 0;
	printf("%s", buffer);
	ft_bzero(buffer, n);
	printf("%s", bouffer);
	//bzero(bouffer, n);
	//printf("\n");
	//printf("%s", bouffer);
}*/