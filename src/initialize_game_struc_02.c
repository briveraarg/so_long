/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_struc_02.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:38:59 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/02/19 18:32:12 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_background_texture(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/trail.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->background = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->background)
		error_mlx_and_free_struct(game, "Problem with texture_to_image");
	mlx_delete_texture (imagen);
}

void	load_exit_closed_texture(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/messi.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->exit = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->exit)
		error_mlx_and_free_struct(game, "Problem with texture_to_image");
	mlx_delete_texture (imagen);
}

void	load_wall_texture(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/flowers.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->wall = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->wall)
		error_mlx_and_free_struct(game, "Problem with texture_to_image");
	mlx_delete_texture (imagen);
}

void	load_collectible_texture(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/pelotita.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->collectible = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->collectible)
		error_mlx_and_free_struct(game, "Problem with texture_to_image");
	mlx_delete_texture (imagen);
}

void	initialize_struct_img(t_game *game)
{
	game->sprites = ft_calloc(1, sizeof(t_sprites));
	if (!game->sprites)
		error_and_exit("Problem ft_calloc");
	load_background_texture(game);
	load_exit_closed_texture(game);
	load_exit_open_texture(game);
	load_wall_texture(game);
	load_collectible_texture(game);
	load_player_texture(game);
	load_player_direction_left(game);
	load_player_direction_rigt(game);
	load_player_direction_down(game);
	load_player_direction_up(game);
	load_icon(game);
}
