/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_struc_04.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:44:08 by brivera           #+#    #+#             */
/*   Updated: 2025/02/19 18:00:24 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_exit_open_texture(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/god.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	game->sprites->exit_open = mlx_texture_to_image(game->mlx, imagen);
	if (!game->sprites->exit_open)
		error_mlx_and_free_struct(game, "Problem with load_png");
	mlx_delete_texture (imagen);
}

void	load_icon(t_game *game)
{
	mlx_texture_t	*imagen;

	imagen = mlx_load_png("./textures/icon.png");
	if (!imagen)
		error_mlx_and_free_struct(game, "Problem with load_png");
	mlx_set_icon(game->mlx, imagen);
	mlx_delete_texture (imagen);
}
