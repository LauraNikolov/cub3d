/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:18:56 by lnicolof          #+#    #+#             */
/*   Updated: 2024/10/10 14:54:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

char	*ft_extract_line(char **stash, int *readed)
{
	char	*tmp;
	char	*cpy;
	int		i;

	if (!*stash && *readed == 0)
		return (NULL);
	tmp = *stash;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	cpy = ft_strdup_gnl(tmp, i);
	*stash = ft_strdup_gnl(tmp + i, ft_strlen(tmp + i));
	if (!tmp[i])
	{
		free(*stash);
		*stash = NULL;
	}
	if (tmp)
		free(tmp);
	tmp = NULL;
	return (cpy);
}

char	*get_next_line(int fd, int flag)
{
	static char	*stash;
	char		*line;
	int			readed;

	
	if(flag == 2)
		return(free(stash), NULL);
	readed = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (readed > 0)
	{
		readed = read(fd, line, BUFFER_SIZE);
		line[readed] = '\0';
		stash = ft_strjoin_gnl(stash, line);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (ft_extract_line(&stash, &readed));
}
