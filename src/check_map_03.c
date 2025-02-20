/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:15:02 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/02/15 16:31:39 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	size_t	j;

	copy = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	j = 0;
	while (j < game->map_height)
	{
		copy[j] = ft_strdup(game->map[j]);
		if (!copy[j])
		{
			free_matrix(copy);
			perror("Error\n");
			return (NULL);
		}
		j++;
	}
	copy[j] = NULL;
	return (copy);
}

void	flood_fill(char **map_copy, t_game *game, size_t x, size_t y)
{
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width)
		return ;
	if (map_copy[y][x] == EXIT)
		map_copy[y][x] = EXIT_OPEN;
	if (map_copy[y][x] == WALL || map_copy[y][x] == VERIFIED ||
		map_copy[y][x] == EXIT || map_copy[y][x] == EXIT_OPEN)
		return ;
	map_copy[y][x] = VERIFIED;
	flood_fill(map_copy, game, x + 1, y);
	flood_fill(map_copy, game, x - 1, y);
	flood_fill(map_copy, game, x, y + 1);
	flood_fill(map_copy, game, x, y - 1);
}

static int	control_map_fill(t_game	*game, char **map_copy)
{
	size_t	j;
	size_t	i;

	j = 0;
	if (map_copy[game->exit_y][game->exit_x] == EXIT)
		return (FALSE);
	while (map_copy[j])
	{
		i = 0;
		while (map_copy[j][i])
		{
			if (map_copy[j][i] == COLLECTIBLE)
				return (FALSE);
			i++;
		}
		j++;
	}
	return (TRUE);
}

int	check_map_final(t_game *game)
{
	char	**map_copy;
	size_t	x;
	size_t	y;

	map_copy = copy_map(game);
	if (!map_copy)
		return (FALSE);
	x = game->player_x;
	y = game->player_y;
	flood_fill(map_copy, game, x, y);
	if (control_map_fill(game, map_copy) == FALSE)
	{
		free_matrix(map_copy);
		return (FALSE);
	}
	free_matrix(map_copy);
	return (TRUE);
}
