/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_imag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:51:04 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/28 11:37:19 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void count_height_width(t_game *game)
{
    int x;
    int y;
    
    y = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x])
            x++;
        y++;
    }
    game->size_height = y * 64;
    game->size_width = x * 64;
}
void ft_mlx_imag(t_game *game)
{
    int x;
    int y;

    count_height_width(game);
    game->ptr = mlx_init();
    if(!game->ptr)
        //free map
    game->win = mlx_new_window(game->ptr, game->size_width, game->size_height, "so_long");
    if(!game->win)
        //free map or free game->ptr
    
    game->wall = mlx_xpm_file_to_image(game->ptr,"textures/wall_imag.xpm",&x,&x);
    game->player = mlx_xpm_file_to_image(game->ptr,"textures/player.xpm",&x,&x);
    game->collectible = mlx_xpm_file_to_image(game->ptr,"textures/collectible_imag.xpm",&x,&x);
    game->exit = mlx_xpm_file_to_image(game->ptr,"textures/exit_imag.xpm",&x,&x);
    game->bg = mlx_new_image(game->ptr, SIZE, SIZE);
    if (!game->player || !game->win || !game->wall || !game->collectible)
        return(ft_free_strct(game));
    y = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            if(game->map[y][x] == '1')
                mlx_put_image_to_window(game->ptr, game->win, game->wall, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'P')
                mlx_put_image_to_window(game->ptr, game->win, game->player, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'C')
                mlx_put_image_to_window(game->ptr, game->win, game->collectible, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'E')
                mlx_put_image_to_window(game->ptr, game->win, game->exit, x * SIZE, y * SIZE);
            x++;
        }
        y++;
    }
}

void ft_mlx_imag1(t_game *game)
{
    int x;
    int y;

    count_height_width(game);
    game->player = mlx_xpm_file_to_image(game->ptr,"textures/player.xpm",&x,&x);
    if (!game->player || !game->win || !game->wall || !game->collectible)
        return(ft_free_strct(game));
    y = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            if(game->map[y][x] == '1')
                mlx_put_image_to_window(game->ptr, game->win, game->wall, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'P')
                mlx_put_image_to_window(game->ptr, game->win, game->player, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'C')
                mlx_put_image_to_window(game->ptr, game->win, game->collectible, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'E')
                mlx_put_image_to_window(game->ptr, game->win, game->exit, x * SIZE, y * SIZE);
            x++;
        }
        y++;
    }
}