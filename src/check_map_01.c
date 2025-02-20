/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:39:59 by brivera           #+#    #+#             */
/*   Updated: 2025/02/17 16:04:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_line_empty(char *map_line)
{
	int	i;

	if (!map_line || !map_line[0] || map_line[0] == '\n')
		return (FALSE);
	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == '\n' && map_line[i + 1] == '\n')
			return (FALSE);
		if (map_line[i] == '\n' && map_line[i + 1] == '\0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	check_map_content(char *map_line)
{
	int		i;
	int		player;
	int		exit;
	int		collectible;

	if (check_map_line_empty(map_line) == FALSE)
		error_map_free("OMG! The map has empty parts", map_line, 0);
	i = 0;
	player = 0;
	exit = 0;
	collectible = 0;
	while (map_line[i])
	{
		if (map_line[i] == PLAYER)
			player++;
		if (map_line[i] == EXIT)
			exit++;
		if (map_line[i] == COLLECTIBLE)
			collectible++;
		else if (!(ft_strchr("01PEC\n", map_line[i])))
			error_map_free("Listen, this map is invalid", map_line, 0);
		i++;
	}
	if (player != 1 || exit != 1 || collectible < 1)
		error_map_free("Hey! this map is invalid", map_line, 0);
}
