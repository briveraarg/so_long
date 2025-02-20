/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:10:10 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/02/20 15:15:07 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	char	**map;

	if (argc != 2)
		msg_and_exit("Example: ./so_long map.ber");
	if ((check_file(argv[1])) == FALSE)
		msg_and_exit("What's up, champ!");
	map = check_map(argv[1]);
	game = initialize_struct(map);
	if (check_map_final(game) == FALSE)
		error_and_free_struct(game, "This map has no chance of passing");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->map_width * PIXELS, game->map_height * PIXELS,
			"so_long", true);
	if (!game->mlx)
		error_and_free_struct(game, "MLX initialization failed");
	initialize_struct_img(game);
	fill_background(game);
	fill_map(game);
	mlx_key_hook(game->mlx, &my_keyfuncion, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	exit (0);
}
