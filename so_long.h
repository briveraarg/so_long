/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:56:51 by brivera           #+#    #+#             */
/*   Updated: 2025/02/19 18:38:24 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// libs42
# include "libs/MLX42/include/MLX42/MLX42.h" 
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

# define KEY_ESC MLX_KEY_ESCAPE
# define ARROW_UP MLX_KEY_UP
# define ARROW_DOWN MLX_KEY_DOWN
# define ARROW_LEFT MLX_KEY_LEFT
# define ARROW_RIGHT MLX_KEY_RIGHT

# define FALSE		0
# define TRUE		1

# define PIXELS 64

// Character map
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define EXIT_OPEN 'e'
# define VERIFIED 'V'

typedef struct s_sprites
{
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*exit_open;
	mlx_image_t	*background;
	mlx_image_t	*up;
	mlx_image_t	*down;
	mlx_image_t	*left;
	mlx_image_t	*right;

}	t_sprites;

typedef struct s_game
{
	mlx_t		*mlx;
	t_sprites	*sprites;
	char		**map;
	size_t		map_width;
	size_t		map_height;
	size_t		player_x;
	size_t		player_y;
	size_t		exit_x;
	size_t		exit_y;
	size_t		collectibles;
	size_t		collect;
	size_t		moves;
}	t_game;

void	msg_and_exit(char *message);
void	error_and_exit(char *message);
char	**free_matrix(char **array);
int		check_file(char *map);
void	error_and_free_struct(t_game *game, char *message);
void	error_mlx_and_free_struct(t_game *game, char *message);
void	error_map_free(char *message, char *map_line, char **map_array);
void	check_map_content(char *map_line);
void	check_map_wall(char **map_array);
void	check_map_shape(char **map_array);
char	**check_map(char *map);
t_game	*initialize_struct(char **mapa);
int		check_map_final(t_game *game);
void	load_exit_open_texture(t_game *game);
void	load_player_texture(t_game *game);
void	load_player_direction_left(t_game *game);
void	load_player_direction_rigt(t_game *game);
void	load_player_direction_down(t_game *game);
void	load_player_direction_up(t_game *game);
void	load_icon(t_game *game);
void	initialize_struct_img(t_game *game);
void	remove_collectible(t_game *game);
void	open_exit(t_game *game);
void	print_moves(t_game *s_game);
void	print_final_exit(t_game *game);
void	move_player_up(t_game *game, int d_x, int d_y);
void	move_player_down(t_game *game, int d_x, int d_y);
void	move_player_left(t_game *game, int d_x, int d_y);
void	move_player_right(t_game *game, int d_x, int d_y);
void	my_keyfuncion(mlx_key_data_t keydata, void *data);
void	fill_background(t_game *game);
void	fill_map(t_game *game);

#endif