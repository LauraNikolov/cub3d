/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/21 16:16:48 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	cpy = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i] && i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		cpy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < (ft_strlen(s2) + ft_strlen(s1)))
	{
		cpy[i++] = s2[j++];
	}
	cpy[i] = '\0';
	return (cpy);
}

/*int main()
{
	char const *s1
}*/
