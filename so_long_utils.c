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

int	ft_strlen(const char *s)
{
    int	len;

    len = 0;
    while (s && s[len] && s[len] != '\n')
        len++;
    return (len);
}

char	*ft_strdup(const char *s1)
{
    int		len;
    char	*res;
    int		i;

    if (!s1)
        return (NULL);
    i = 0;
    len = ft_strlen(s1);
    res = malloc(len + 1);
    if (!res)
        return (NULL);
    while (i < len)
    {
        res[i] = s1[i];
        i++;
    }
    res[i] = 0;
    return (res);
}
