/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:57:07 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/12 15:57:09 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

typedef struct s_game
{
    char	**map;
    int		width;
    int		height;
    int		player_count;
    int		exit_count;
    int		collectible_count;
}	t_game;

int		read_map(char *file, t_game *game);
int		validate_map(t_game *game);
void	free_map(char **map);
void	print_error(char *msg);
size_t	    ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

#endif
