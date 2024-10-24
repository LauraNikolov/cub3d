/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:36:48 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/03 16:51:56 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countchar(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_putnbr(long n, char *str, size_t counter)
{
	size_t	i;

	str[counter] = '\0';
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i = 1;
	}
	while (counter-- > i)
	{
		str[counter] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	long	nb;
	char		*str;
	size_t		len;

	nb = n;
	len = ft_countchar(nb);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_putnbr(n, str, len);
	return (str);
}

/*int main()
{
	int n;
	char *str;

	n = 42;
	str = ft_itoa(n);
	printf("%s", str);
}*/