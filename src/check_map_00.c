/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:34:47 by brivera           #+#    #+#             */
/*   Updated: 2025/02/17 18:12:58 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file(char *map_file)
{
	size_t	len;

	len = ft_strlen(map_file);
	if (len == 0)
		msg_and_exit("Example: ./so_long map.ber");
	if (ft_strncmp(&map_file[len - 4], ".ber", 4))
		msg_and_exit("Listen up, only files with the .ber extension, alright?");
}

char	*read_map(char *map_line)
{
	char	*line;
	char	*line_joined;
	char	*temp;
	int		fd;

	line_joined = ft_calloc(1, sizeof(char));
	if (!line_joined)
		error_and_exit("Memory");
	fd = open(map_line, O_RDONLY);
	if (fd == -1)
		return (free(line_joined), error_and_exit("What's up, champ!"), NULL);
	while (1)
	{
		line = get_next_line (fd);
		if (line)
		{
			temp = ft_strjoin(line_joined, line);
			free(line_joined);
			line_joined = temp;
			free(line);
		}
		else
			break ;
	}
	return (close(fd), line_joined);
}

char	**check_map(char *map)
{
	char	*map_line;
	char	**map_array;

	check_map_file(map);
	map_line = read_map(map);
	check_map_content(map_line);
	map_array = ft_split(map_line, '\n');
	if (!map_array)
		error_map_free("ft_split", map_line, 0);
	free(map_line);
	check_map_shape(map_array);
	check_map_wall(map_array);
	return (map_array);
}
