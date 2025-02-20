/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:44:55 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/02/15 16:33:23 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_shape(char **map_array)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(map_array[0]);
	i = 1;
	while (map_array[i])
	{
		if (ft_strlen(map_array[i]) != len)
			error_map_free("Map is not a rectangle", 0, map_array);
		i++;
	}
}

static void	check_top_bottom_walls(char **map_array)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map_array[0][i])
	{
		if (map_array[0][i] != WALL)
			error_map_free("OMG, this map has no walls!", 0, map_array);
		i++;
	}
	j = 0;
	while (map_array[j])
		j++;
	i = 0;
	j = j - 1;
	while (map_array[j][i])
	{
		if (map_array[j][i] != WALL)
			error_map_free("OMG, this map has no walls!", 0, map_array);
		i++;
	}
}

static void	check_side_walls(char **map_array)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (map_array[j])
	{
		if (map_array[j][0] != WALL)
			error_map_free("OMG, this map has no walls!", 0, map_array);
		j++;
	}
	i = ft_strlen(map_array[0]) - 1;
	j = 0;
	while (map_array[j])
	{
		if (map_array[j][i] != WALL)
			error_map_free("OMG, this map has no walls!", 0, map_array);
		j++;
	}
}

void	check_map_wall(char **map_array)
{
	check_top_bottom_walls(map_array);
	check_side_walls(map_array);
}
