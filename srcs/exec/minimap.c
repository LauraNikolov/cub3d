
#include "cub3d.h"


void draw_circle(int center_x, int center_y, int radius, int color, t_game *game)
{
    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if (sqrt(x * x + y * y) <= radius)
            {
                set_pixel(color, game, center_x + x, center_y + y);
            }
        }
    }
}

void draw_rectangle(int x, int y, int color, t_game *game)
{
    int width = CELL_SIZE; 
    int height = CELL_SIZE;
    
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            set_pixel(color, game, x + i, y + j);
        }
    }
}

void draw_minimap(t_game *game)
{
    int x, y;
    int mini_x, mini_y;

    for (y = 0; y < MAP_HEIGHT; y++)
    {
        for (x = 0; x < MAP_WIDTH; x++)
        {
            mini_x = x * CELL_SIZE;
            mini_y = y * CELL_SIZE;

            if (game->cub->maps[y][x] == '1')
                draw_rectangle(mini_x, mini_y, WALL_COLOR, game);
            else
                draw_rectangle(mini_x, mini_y, FLOOR_COLOR, game);
        }
    }
    int player_mini_x = (int)(game->pos.x * CELL_SIZE);
    int player_mini_y = (int)(game->pos.y * CELL_SIZE);
    draw_circle(player_mini_x + CELL_SIZE / 2, player_mini_y + CELL_SIZE / 2, CELL_SIZE / 4, PLAYER_COLOR, game);
}

