/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:45:53 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/15 09:45:55 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
    int	    (new_x), new_y;
    char    next_tile;

    new_x = game->player_x + dx;
    new_y = game->player_y + dy;
    next_tile = game->map[new_y][new_x];

    if (next_tile == '1')
        return;
    if (next_tile == 'C')
        game->collectible_count--;
    if (next_tile == 'E')
    {
        if (game->collectible_count == 0)
        {
            write(1, "🎉 You win!\n", 12);
            exit(0);
        }
        return;
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[new_y][new_x] = 'P';
    game->player_x = new_x;
    game->player_y = new_y;
    game->steps++;
    printf("Steps: %d\n", game->steps);
    giver_map(game);
}
