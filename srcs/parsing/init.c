#include "cub3d.h"

int	collect_all(t_cub *cub)
{
	if (cub->count_NO == 1 && cub->count_EA == 1 && cub->count_SO == 1
		&& cub->count_WE == 1 && cub->count_C == 1 && cub->count_F == 1)
		return (1);
	else
		return (0);
}

void	read_file(t_cub *cub, int fd)
{
	char	*line;

	(void)cub;
	line = NULL;
	line = malloc(1);
	while (line)
	{
		free(line);
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		if (!ft_is_empty(line, cub) && cub->new_line_maps != 1)
		{
			if (collect_all(cub))
				cub->new_line_maps = 1;
			continue ;
		}
		else
			collect_data(cub, line);
	}
	close(cub->fd);
	gc_double_add(cub->garbage_collector, (void **)cub->maps);
	add_rgb(cub, "F");
	add_rgb(cub, "C");
}

void	init_data(t_cub *cub, int ac, char **av)
{
	(void)ac;
	cub->fd = valid_file(av[1], cub);
	if (cub->fd < 0)
		clean_exit("Error: invalid file\n", cub->garbage_collector, cub);
	read_file(cub, cub->fd);
	map_is_valid(cub);
}