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
# include "minilibx-linux/mlx.h"

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char	**map;
    int		width;
    int		height;
    int		player_count;
    int		exit_count;
    int		collectible_count;
    int     title;
    void    *img_wall;
    void    *img_floor;
    void    *img_player;
    void    *img_exit;
    void    *img_collectible;

}	t_game;

int		read_map(char *file, t_game *game);
void	validate_map(t_game *game);
void	free_map(char **map);
void	print_error(char *msg);
int	    ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *string, int c);

#endif
