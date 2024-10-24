/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:37:55 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/21 16:16:52 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	copy_len;
	size_t	i;

	if ((!dst || !src) && size == 0)
		return (0);
	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dst_len == size)
		return (dst_len + src_len);
	copy_len = size - dst_len - 1;
	i = 0;
	while (i < copy_len && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*int main(void)
{
	char src[]= "pzoubizoubizoubi";
	char dst[10]= "c\0";
	size_t size;

	size = 3;


	//char src1[]= "pzoubizoubizoubi";
	//char dst1[10]= "c\0";
	//size_t size1;

	//size1 = 3;

	printf("%zu\n", ft_strlcat(dst, src, size));
	printf("%s", dst);
	//printf("\n%d\n", strlcat(dst1, dst1, size1));
	//printf("%s", dst1);
}*/