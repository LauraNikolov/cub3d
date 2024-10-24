/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:25:00 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/21 16:16:57 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*int	main(void)
{
	char	src[] = "bonjour";
	size_t	size;

	size = 0;
	char dest[10] = "AAAAAAAAA";

	char	src1[] = "bonjour";
	size_t	size1;

	size1 = 0;
	char dest1[10] = "AAAAAAAAA";




	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("\n%s", dest);

	//printf("%zu\n", strlcpy(dest1, src1, size1));
	//printf("%s", dest1);
}*/
/*-lbsd*/
