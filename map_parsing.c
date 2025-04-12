/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:03:35 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/12 16:03:41 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file)
{
    int		fd;
    int		count;
    char	*line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    count = 0;
    line = get_next_line(fd);
    while (line)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (count);
}

int	read_map(char *file, t_game *game)
{
    int		(fd), i;
    char	*line;

    game->height = count_lines(file);
    if (game->height < 3)
        return (0);
    game->map = malloc(sizeof(char *) * (game->height + 1));
    if (!game->map)
        return (0);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    while (i < game->height)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        char *newline = ft_strchr(line, '\n');
        if (newline)
            *newline = '\0';
        game->map[i++] = line;
    }
    game->map[i] = NULL;
    close(fd);
    return (1);
}
