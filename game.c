/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:38:53 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/12 15:38:56 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
    t_game	game;

    if (argc != 2)
        print_error("Usage: ./so_long <map.ber>");
    if (!read_map(argv[1], &game))
        print_error("Failed to read map.");

    game.player_count = 0;
    game.exit_count = 0;
    game.collectible_count = 0;

    validate_map(&game);
    write(1, "Map is valid ✅\n", 16);
    free_map(game.map);
    return (0);
}
