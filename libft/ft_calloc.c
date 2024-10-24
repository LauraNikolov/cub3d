/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:40:50 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/21 16:09:05 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*ptr;

	len = (nmemb * size);
	if (len == 0)
	{
		ptr = (void *)malloc(0);
		return (ptr);
	}
	else if (len / size != nmemb)
		return (0);
	ptr = malloc(len);
	ft_bzero(ptr, len);
	return (ptr);
}

/*int main()
{

}*/