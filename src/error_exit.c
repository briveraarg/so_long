/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:00:22 by brivera           #+#    #+#             */
/*   Updated: 2025/02/19 17:30:46 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(char *message)
{
	ft_putendl_fd("Error", 2);
	perror(message);
	exit(1);
}

void	msg_and_exit(char *message)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Oops, there's a mistake!\n", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

void	error_map_free(char *message, char *map_line, char **map_array)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	if (map_line)
		free(map_line);
	if (map_array)
		free_matrix(map_array);
	exit(1);
}

void	error_and_free_struct(t_game *game, char *message)
{
	if (game->map)
		free_matrix(game->map);
	if (game)
		free(game);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

void	error_mlx_and_free_struct(t_game *game, char *message)
{
	if (game->sprites->background)
		mlx_delete_image(game->mlx, game->sprites->background);
	if (game->sprites->collectible)
		mlx_delete_image(game->mlx, game->sprites->collectible);
	if (game->sprites->down)
		mlx_delete_image (game->mlx, game->sprites->down);
	if (game->sprites->left)
		mlx_delete_image (game->mlx, game->sprites->left);
	if (game->sprites->right)
		mlx_delete_image (game->mlx, game->sprites->right);
	if (game->sprites->up)
		mlx_delete_image (game->mlx, game->sprites->up);
	if (game->sprites->player)
		mlx_delete_image (game->mlx, game->sprites->player);
	if (game->sprites->exit)
		mlx_delete_image (game->mlx, game->sprites->exit);
	if (game->sprites->wall)
		mlx_delete_image (game->mlx, game->sprites->wall);
	if (game->sprites->exit_open)
		mlx_delete_image (game->mlx, game->sprites->exit_open);
	if (game->sprites)
		free (game->sprites);
	mlx_terminate(game->mlx);
	error_and_free_struct(game, message);
}
