/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:22:39 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/14 16:22:41 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int height)
{
    int	i;

    if (!map)
        return ;
    i = 0;
    while (i < height)
        free(map[i++]);
    free(map);
}

void	free_all(t_game *game)
{
    if (game->img_wall)
        mlx_destroy_image(game->mlx, game->img_wall);
    if (game->img_floor)
        mlx_destroy_image(game->mlx, game->img_floor);
    if (game->img_player)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->img_exit)
        mlx_destroy_image(game->mlx, game->img_exit);
    if (game->img_collectible)
        mlx_destroy_image(game->mlx, game->img_collectible);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
    }
    free_map(game->map, game->height);
}
