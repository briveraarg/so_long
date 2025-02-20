/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_struc_01.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:36:07 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/02/17 18:20:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_background(t_game *game)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (mlx_image_to_window(game->mlx, game->sprites->background,
					x * PIXELS, y * PIXELS) < 0)
				error_and_exit("Couldn't show the image, but we keep going!");
			x++;
		}
		y++;
	}
}

void	render_imagen_select(t_game *game, size_t y, size_t x)
{
	if (game->map[y][x] == WALL)
		if (mlx_image_to_window(game->mlx, game->sprites->wall,
				x * PIXELS, y * PIXELS) < 0)
			error_and_exit("Couldn't show the image, but we keep going!");
	if (game->map[y][x] == EXIT)
		if (mlx_image_to_window(game->mlx, game->sprites->exit,
				x * PIXELS, y * PIXELS) < 0)
			error_and_exit("Couldn't show the image, but we keep going!");
	if (game->map[y][x] == PLAYER)
		if (mlx_image_to_window(game->mlx, game->sprites->player,
				x * PIXELS, y * PIXELS) < 0)
			error_and_exit("Couldn't show the image, but we keep going!");
	if (game->map[y][x] == COLLECTIBLE)
		if (mlx_image_to_window(game->mlx, game->sprites->collectible,
				x * PIXELS, y * PIXELS) < 0)
			error_and_exit("Couldn't show the image, but we keep going!");
}

void	fill_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_imagen_select(game, y, x);
			x++;
		}
		y++;
	}
}
