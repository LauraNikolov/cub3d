#include "cub3d.h"


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
		if (!ft_is_empty(line))
			continue ;
		else
			collect_data(cub, line);
	}
	close(cub->fd);
	add_rgb(cub, "F");
	add_rgb(cub, "C");
}

void	init_data(t_cub *cub, int ac, char **av)
{
	(void)ac;
	cub->fd = valid_file(av[1], cub);
	read_file(cub, cub->fd);
	gc_double_add(cub->garbage_collector, (void **)cub->maps);
	map_is_valid(cub);
	// printf("NO = %s\n, SO = %s\n, EA = %s\n, WE = %s\n", cub->NO, cub->SO,
	// 	cub->EA, cub->WE);
	// printf("F = %d, %d, %d and C = %d, %d, %d\n", cub->F_R, cub->F_G, cub->F_B,
	// 	cub->C_R, cub->C_G, cub->C_B);
}