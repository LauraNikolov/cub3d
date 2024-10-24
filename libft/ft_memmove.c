/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:45:12 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/21 16:13:39 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char		*d;
	unsigned const char	*s;

	d = ((unsigned char *)dest);
	s = ((unsigned const char *)src);
	if (d < s)
	{
		i = 0;
		while ((size_t)i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (s < d && n != 0)
	{
		i = n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (d);
}

/*int	main(void)
{
	char	s[] = {65, 66, 67, 68, 69, 0, 45};
	char	s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char	sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char	sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char	sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	printf("%s\n", ((char *)memmove(sResult + 1, sResult, 2)));
	printf("%s\n", ((char *)ft_memmove(sResult + 1, sResult, 2)));
}



	size_t		n;
	char	src[] = "petitkaka";
	char	*dest = src - 2;

	size_t		n1;
	char	src1[] = "petitkaka";
	char	*dest1 = src1 - 2;

	n = sizeof(src);
	n1 = sizeof(src1);
	printf("%s", ((char *)ft_memmove(dest, src, n)));
	printf("\n");
	printf("%s", ((char *)memmove(dest1, src1, n1)));*/
