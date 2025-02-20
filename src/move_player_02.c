/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:20:03 by brivera           #+#    #+#             */
/*   Updated: 2025/02/19 12:02:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_game *game)
{
	game->sprites->exit->instances[0].enabled = false;
	game->map[game->exit_y][game->exit_x] = EXIT_OPEN;
	if (game->sprites->exit_open->count == 0)
		mlx_image_to_window(game->mlx, game->sprites->exit_open,
			game->exit_x * PIXELS, game->exit_y * PIXELS);
	game->sprites->exit = game->sprites->exit_open;
	game->sprites->exit->instances[0].enabled = true;
}

void	print_moves(t_game *game)
{
	game->moves++;
	ft_printf("That's it, don't stop! Keep going! Moves: %d\n", game->moves);
}

void	print_final_exit(t_game *game)
{
	game->sprites->player->instances[0].enabled = false;
	if (game->sprites->down->count == 0)
		mlx_image_to_window(game->mlx, game->sprites->down,
			game->player_x * PIXELS, game->player_y * PIXELS);
	game->sprites->player = game->sprites->down;
	game->sprites->player->instances[0].x = game->player_x * PIXELS;
	game->sprites->player->instances[0].y = game->player_y * PIXELS;
	game->sprites->player->instances[0].enabled = true;
	ft_printf("\nResounding success!\nYou've earned eternal glory.\n");
	mlx_close_window(game->mlx);
}
