/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:21:19 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/02/19 18:38:34 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_matrix(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

int	check_file(char *map)
{
	if (open("./textures/flowers.png", O_RDONLY) == -1
		|| open("./textures/god.png", O_RDONLY) == -1
		|| open("./textures/icon.png", O_RDONLY) == -1
		|| open("./textures/maradona_down.png", O_RDONLY) == -1
		|| open("./textures/maradona_left.png", O_RDONLY) == -1
		|| open("./textures/maradona_right.png", O_RDONLY) == -1
		|| open("./textures/maradona_up.png", O_RDONLY) == -1
		|| open("./textures/messi.png", O_RDONLY) == -1
		|| open("./textures/pelotita.png", O_RDONLY) == -1
		|| open("./textures/trail.png", O_RDONLY) == -1
		|| open (map, O_RDONLY) == -1)
	{
		perror("File");
		return (FALSE);
	}
	return (TRUE);
}
