#include "cub3d.h"

int	valid_file(char *str, t_cub *cub)
{
	int	i;
	int	fd;

	fd = 0;
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
	fd = open(cub->file, O_RDONLY);
	if (fd <= 1)
		return (-1);
	else
		return (fd);
}

char	**check_rgb(t_cub *cub, char *str)
{
	char	**strs;
	int		i;
	int		y;

	i = 0;
	strs = ft_split(str, ',');
	if (!strs)
		return (NULL);
	gc_double_add(cub->garbage_collector, (void **)strs);
	while (strs && strs[i])
	{
		y = 0;
		while (strs[i] && strs[i][y])
		{
			if (ft_isdigit(strs[i][y]))
				y++;
			else
			{
				gc_free(cub->garbage_collector);
				exit(0);
			}
		}
		i++;
	}
	if (str)
		free(str);
	return (strs);
}


int add_rgb(t_cub *cub, char *str)
{
    if(ft_strncmp(str, "F", 1))
    {
        if(!is_overflow(cub->F[0]))
            cub->F_R = ft_atoi(cub->F[0]);
        else
            clean_exit("int overflow on F RGB\n", cub->garbage_collector, cub);
        if(!is_overflow(cub->F[1]))
            cub->F_G = ft_atoi(cub->F[1]);
        else
            clean_exit("int overflow on F RGB\n", cub->garbage_collector, cub);
        if(!is_overflow(cub->F[2]))
            cub->F_B = ft_atoi(cub->F[2]);
        else
           clean_exit("int overflow on F RGB\n", cub->garbage_collector, cub);
    }

    else if(ft_strncmp(str, "C", 1))
    {
        if(!is_overflow(cub->C[0]))
            cub->C_R = ft_atoi(cub->C[0]);
        else
            clean_exit("int overflow on C RGB\n", cub->garbage_collector, cub);
        if(!is_overflow(cub->C[1]))
            cub->C_G = ft_atoi(cub->C[1]);
        else
            clean_exit("int overflow on C RGB\n", cub->garbage_collector, cub);
        if(!is_overflow(cub->C[2]))
            cub->C_B = ft_atoi(cub->C[2]);
        else
            clean_exit("int overflow on C RGB\n", cub->garbage_collector, cub);
    }
    return(0);
}

void	collect_data(t_cub *cub, char *str)
{
	if (!cub->NO && !ft_strncmp("NO", str, 2))
		cub->NO = truncate_space(str, cub);
	else if (!cub->SO && !ft_strncmp("SO", str, 2))
		cub->SO = truncate_space(str, cub);
	else if (!cub->WE && !ft_strncmp("WE", str, 2))
		cub->WE = truncate_space(str, cub);
	else if (!cub->EA && !ft_strncmp("EA", str, 2))
		cub->EA = truncate_space(str, cub);
	else if (!cub->C && !ft_strncmp("C", str, 1))
    {
		cub->C = check_rgb(cub, ft_substr(truncate_space(str, cub), 0,
					ft_strlen(str) - 1));
    }
        
	else if (!cub->F && !ft_strncmp("F", str, 1))
	{
		cub->F = check_rgb(cub, ft_substr(truncate_space(str, cub), 0,
					ft_strlen(str) - 1));
	}
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
		line = get_next_line(fd);
		if (!line)
			break ;
		collect_data(cub, line);
	}
    add_rgb(cub, "F");
}

void	init_data(t_cub *cub, int ac, char **av)
{
	int fd;
	(void)ac;
	fd = valid_file(av[1], cub);
	read_file(cub, fd);
}