/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:57:43 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/02/17 18:55:28 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_collectible(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->sprites->collectible->count)
	{
		if ((size_t)game->sprites->collectible->instances[i].x
			== game->player_x * PIXELS
			&& (size_t)game->sprites->collectible->instances[i].y
			== game->player_y * PIXELS)
		{
			game->sprites->collectible->instances[i].enabled = false;
			game->map[game->player_y][game->player_x] = '0';
			game->collect += 1;
			break ;
		}
		i++;
	}
}

void	move_player_up(t_game *game, int d_x, int d_y)
{
	if (game->map[game->player_y + d_y][game->player_x + d_x] != WALL
		&& game->map[game->player_y + d_y][game->player_x + d_x] != EXIT)
	{
		game->sprites->player->instances[0].enabled = false;
		game->player_x += d_x;
		game->player_y += d_y;
		if (game->sprites->up->count == 0)
			mlx_image_to_window(game->mlx, game->sprites->up,
				game->player_x * PIXELS, game->player_y * PIXELS);
		game->sprites->player = game->sprites->up;
		game->sprites->player->instances[0].x = game->player_x * PIXELS;
		game->sprites->player->instances[0].y = game->player_y * PIXELS;
		game->sprites->player->instances[0].enabled = true;
		if (game->map[game->player_y][game->player_x] == COLLECTIBLE)
			remove_collectible(game);
		print_moves(game);
	}
}

void	move_player_down(t_game *game, int d_x, int d_y)
{
	if (game->map[game->player_y + d_y][game->player_x + d_x] != WALL
		&& game->map[game->player_y + d_y][game->player_x + d_x] != EXIT)
	{
		game->sprites->player->instances[0].enabled = false;
		game->player_x += d_x;
		game->player_y += d_y;
		if (game->sprites->down->count == 0)
			mlx_image_to_window(game->mlx, game->sprites->down,
				game->player_x * PIXELS, game->player_y * PIXELS);
		game->sprites->player = game->sprites->down;
		game->sprites->player->instances[0].x = game->player_x * PIXELS;
		game->sprites->player->instances[0].y = game->player_y * PIXELS;
		game->sprites->player->instances[0].enabled = true;
		if (game->map[game->player_y][game->player_x] == COLLECTIBLE)
			remove_collectible(game);
		print_moves(game);
	}
}

void	move_player_left(t_game *game, int d_x, int d_y)
{
	if (game->map[game->player_y + d_y][game->player_x + d_x] != WALL
		&& game->map[game->player_y + d_y][game->player_x + d_x] != EXIT)
	{
		game->sprites->player->instances[0].enabled = false;
		game->player_x += d_x;
		game->player_y += d_y;
		if (game->sprites->left->count == 0)
			mlx_image_to_window(game->mlx, game->sprites->left,
				game->player_x * PIXELS, game->player_y * PIXELS);
		game->sprites->player = game->sprites->left;
		game->sprites->player->instances[0].x = game->player_x * PIXELS;
		game->sprites->player->instances[0].y = game->player_y * PIXELS;
		game->sprites->player->instances[0].enabled = true;
		if (game->map[game->player_y][game->player_x] == COLLECTIBLE)
			remove_collectible(game);
		print_moves(game);
	}
}

void	move_player_right(t_game *game, int d_x, int d_y)
{
	if (game->map[game->player_y + d_y][game->player_x + d_x] != WALL
		&& game->map[game->player_y + d_y][game->player_x + d_x] != EXIT)
	{
		game->sprites->player->instances[0].enabled = false;
		game->player_x += d_x;
		game->player_y += d_y;
		if (game->sprites->right->count == 0)
			mlx_image_to_window(game->mlx, game->sprites->right,
				game->player_x * PIXELS, game->player_y * PIXELS);
		game->sprites->player = game->sprites->right;
		game->sprites->player->instances[0].x = game->player_x * PIXELS;
		game->sprites->player->instances[0].y = game->player_y * PIXELS;
		game->sprites->player->instances[0].enabled = true;
		if (game->map[game->player_y][game->player_x] == COLLECTIBLE)
			remove_collectible(game);
		print_moves(game);
	}
}
