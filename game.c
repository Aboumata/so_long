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
#include <stdlib.h>
#include <unistd.h>

void	loading_images(t_game *game)
{
	int	size;

	size = 64;
	game->title = size;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &size, &size);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &size, &size);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &size, &size);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &size, &size);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &size, &size);
}

void	check_images(t_game *game)
{
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collectible)
	{
		write(2, "Error\nFailed to load one or more textures.\n", 43);
		free_all(game);
		exit(1);
	}
}

void	render_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;
	void	*img;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			img = game->img_floor;
			if (tile == '1')
				img = game->img_wall;
			else if (tile == 'P')
				img = game->img_player;
			else if (tile == 'E')
				img = game->img_exit;
			else if (tile == 'C')
				img = game->img_collectible;
			mlx_put_image_to_window(game->mlx, game->win, img, x * game->title, y * game->title);
			x++;
		}
		y++;
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_all(game);
		exit(0);
	}
	return (0);
}

int	handle_destroy(t_game *game)
{
	free_all(game);
	exit(0);
}

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

	game.mlx = mlx_init();
	if (!game.mlx)
		print_error("Failed to initialize MLX.");
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
	if (!game.win)
		print_error("Failed to create window.");

	loading_images(&game);
	check_images(&game);
	render_map(&game);

	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, handle_destroy, &game);
	mlx_loop(game.mlx);
	return (0);
}
