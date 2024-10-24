/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:04:03 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/22 16:52:04 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	if (!s1 || !s2)
		return (0);
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	while (string1[i] == string2[i] && i < n && string1[i])
		i++;
	if (i == n)
		return (0);
	return (string1[i] - string2[i]);
}
