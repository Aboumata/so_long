/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:08:54 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/12 16:08:56 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(t_game *game)
{
    int	i;
    int	width;

    width = ft_strlen(game->map[0]);
    i = 1;
    while (game->map[i])
    {
        if (ft_strlen(game->map[i]) != width)
            return (0);
        i++;
    }
    game->width = width;
    return (1);
}

static int	is_surrounded(t_game *game)
{
    int	i;

    i = 0;
    while (i < game->width)
    {
        if (game->map[0][i] != WALL || game->map[game->height - 1][i] != WALL)
            return (0);
        i++;
    }
    i = 0;
    while (i < game->height)
    {
        if (game->map[i][0] != WALL || game->map[i][game->width - 1] != WALL)
            return (0);
        i++;
    }
    return (1);
}

static int	check_contents(t_game *game)
{
    int	x;
    int	y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            char c = game->map[y][x];
            if (c == PLAYER)
                game->player_count++;
            else if (c == EXIT)
                game->exit_count++;
            else if (c == COLLECTIBLE)
                game->collectible_count++;
            else if (c != WALL && c != FLOOR)
                return (0);
            x++;
        }
        y++;
    }
    return (game->player_count == 1
        && game->exit_count >= 1
        && game->collectible_count >= 1);
}

void	validate_map(t_game *game)
{
    if (!is_rectangular(game))
        exit_with_error(game, "Map is not rectangular.");
    if (!is_surrounded(game))
        exit_with_error(game, "Map must be surrounded by walls.");
    if (!check_contents(game))
        exit_with_error(game, "Map must have 1P, ≥1E, ≥1C and valid characters.");
}
