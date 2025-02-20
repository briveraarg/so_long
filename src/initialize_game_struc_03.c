/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_struc_03.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:18:22 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/02/19 18:00:11 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_texture(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/maradona_down.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->player = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->player)
		error_mlx_and_free_struct(game, "Problem with load_png");
	mlx_delete_texture (imagen);
}

void	load_player_direction_up(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/maradona_up.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->up = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->up)
		error_mlx_and_free_struct(game, "Problem with load_png");
	mlx_delete_texture (imagen);
}

void	load_player_direction_down(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/maradona_down.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->down = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->down)
		error_mlx_and_free_struct(game, "Problem with load_png");
	mlx_delete_texture (imagen);
}

void	load_player_direction_rigt(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/maradona_right.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->right = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->right)
		error_mlx_and_free_struct(game, "Problem with load_png");
	mlx_delete_texture (imagen);
}

void	load_player_direction_left(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/maradona_left.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->left = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->left)
		error_mlx_and_free_struct(game, "Problem with load_png");
	mlx_delete_texture (imagen);
}
