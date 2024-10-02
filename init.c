#include "cub3d.h"

int	valid_file(char *str, t_cub *cub)
{
	int	i;
	int	fd = 0;

	i = 0;
	i = ft_strlen(str);
	if (!ft_strncmp(&str[i - 4], ".cub", 4))
	{
		cub->garbage_collector = gc_init();
		cub->file = gc_alloc(cub->garbage_collector, ft_strlen(str) + 1);
		if (!cub->file)
			return (0); // ! Appeler ft_exit
	}
	else
		return (0); // ! Appeler ft_exit
	ft_strlcpy(cub->file, str, i + 1);
	fd = open("test.cub", O_RDONLY);
    if(fd <= 1)
        return(-1);
    else
	    return(fd);
}

void collect_data(t_cub *cub, char *str)
{
    // ! prevoir le cas ou deux nord ou deux south
    if(!cub->NO && !ft_strncmp("NO", str, 2))
        cub->NO = truncate_space(str, cub);
    else if(!cub->SO && !ft_strncmp("SO", str, 2))
        cub->SO = truncate_space(str, cub);
    else if(!cub->WE && !ft_strncmp("WE", str, 2))
        cub->WE = truncate_space(str, cub);
    else if(!cub->EA && !ft_strncmp("EA", str, 2))
        cub->EA = truncate_space(str, cub);
}

void read_file(t_cub *cub, int fd)
{
    char *line;
    (void)cub;

    line = NULL;
    while(1)
    {
        if(line)
            free(line);
        line = get_next_line(fd);
        if(!line)
            break;
        collect_data(cub, line);
    }
}

void	init_data(t_cub *cub, int ac, char **av)
{
	int fd;
    (void)ac;
	fd = valid_file(av[1], cub);
    read_file(cub, fd);
}