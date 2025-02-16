/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:48:01 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/16 15:30:26 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H


#include "/home/ylagzoul/Desktop/include/mlx/mlx.h"
#include "/home/ylagzoul/Desktop/get_next/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct game
{
    char **map;
}           t_game;

// void    loading_map(void);
void print_error();

#endif