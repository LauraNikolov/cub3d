/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:11:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/11 18:30:36 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void test_init(t_cub *cub)
{
    const char *map[] = {
        "111111111111111111111111111111",
        "1000000000110000000000000001",
        "101100000111000N000000000001",
        "1001000000000000000000000001",
        "1111111110110000011100000001",
        "1000000000110000011101111111",
        "1111011111111101110000001001",
        "1111011111111101110101001001",
        "1100000011010101110000001001",
        "1000000000000000110000001001",
        "1000000000000000110101001001",
        "1100000111010101111101111011",
        "1111011111110101101111010001",
        "1111111111111111111111111111"
    };
    cub->maps = malloc(sizeof(char *) * 14);
    if (cub->maps == NULL) {
        perror("Failed to allocate memory for maps");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 14; i++) {
        cub->maps[i] = malloc(sizeof(char) * (30 + 1));
        if (cub->maps[i] == NULL) {
            perror("Failed to allocate memory for a map row");
            exit(EXIT_FAILURE);
        }
        strcpy(cub->maps[i], map[i]);
    }
    cub->player_x = 16;
    cub->player_y = 3;
    cub->player_cardinal = 'N';
    cub->NO = ft_strdup("./textures/1.xpm");
    cub->SO = ft_strdup("./textures/2.xpm");
    cub->WE = ft_strdup("./textures/3.xpm");
    cub->EA = ft_strdup("./textures/4.xpm");
    cub->C_R = 220;
    cub->C_G = 220;
    cub->C_B = 33;
    cub->F_R = 60;
    cub->F_G = 179;
    cub->F_B = 110;
}

int	main(int ac, char **av)
{
	t_cub *cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		return (0);
	memset(cub, 0, sizeof(t_cub));
	// if (ac != 2)
	// {
	// 	printf("wrong arg\n");
	// 	return (1);
	// }
	// init_data(cub, ac, av); //TEST
    (void)av;
    (void)ac;
    test_init(cub); //TEST
	start_game(cub);
	return (0);
}
