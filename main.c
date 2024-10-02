
#include "cub3d.h"


int ft_error(char *str)
{
    int i = ft_strlen(str);
    write(1, str, i);
    return(0);
}


int main(int ac, char **av)
{
    t_cub *cub;

    cub = malloc(sizeof(t_cub));
    if(!cub)
        return(0);
    memset(cub, 0, sizeof(t_cub));
    if(ac != 2)
    {
        printf("wrong arg\n");
        return(1);
    }
    init_data(cub, ac, av);
    gc_free(cub->garbage_collector);
    free(cub);
    return(0);
}