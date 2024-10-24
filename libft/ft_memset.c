/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:26:18 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/21 16:13:47 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t			i;
	unsigned char	*prout;

	i = 0;
	prout = (unsigned char *)ptr;
	while (i < len)
	{
		prout[i] = c;
		i++;
	}
	return (prout);
}

/*int	main(void)
{
	unsigned char buffer[10];
	int c = 25;
	size_t len = sizeof(buffer);

	memset(buffer, c, len);

	printf("Contenu du buffer après memset :\n");
	for (size_t i = 0; i < len; i++)
	{
		printf("%d ", buffer[i]);
	}
	printf("\n");

	unsigned char bouffer[10];

	ft_memset(bouffer, c, len);

	printf("contenu du tableau apres memset est:\n");
	for (size_t a = 0; a < len; a++)
	{
		printf("%d", buffer[a]);
	}
	printf("\n");

	return (0);
}*/

/*int main(void)
{
	unsigned int buffer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int c = 25;
	size_t len = sizeof(buffer);

	memset(buffer, c, len);

	printf("Contenu du buffer après memset :\n");
	for (size_t i = 0; i < len; i++)
	{
		printf("%d ", buffer[i]);
	}
	printf("\n");

	unsigned int bouffer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	ft_memset(bouffer, c, len);

	printf("contenu du tableau apres memset est:\n");
	for (size_t a = 0; a < len; a++)
	{
		printf("%d", buffer[a]);
	}
	printf("\n");

	return (0);
}*/
