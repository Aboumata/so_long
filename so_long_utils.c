/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:58:33 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/12 15:58:34 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
    write(2, "Error\n", 6);
    while (*msg)
        write(2, msg++, 1);
    write(2, "\n", 1);
    exit(1);
}

void	free_map(char **map)
{
    int	i;

    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}
