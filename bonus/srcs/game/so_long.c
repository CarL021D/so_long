/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 02:50:19 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/26 09:55:19 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;		
	t_game	game;

	if (argc != 2 || file_name_extension_error(argv[1]))
		return (0);
	mlx.game = &game;
	set_game_variable(&mlx);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (0);
	game.map = set_map(argv[1], &game);
	if (!game.map)
		return (0);
	if (!check_map_errors(&game))
		free_mlx_and_map(&mlx);
	if (!init_images(&mlx) || !init_images2(&mlx))
		free_mlx_and_map(&mlx);
	mlx.window = mlx_new_window(mlx.mlx,
			game.map_width * 32, game.map_height * 32, "so_long");
	display_images(&mlx);
	set_player_animation(&mlx, 1);
	mlx_hook(mlx.window, 17, (1L << 17), free_all, &mlx);
	mlx_key_hook(mlx.window, init_characters_movement, &mlx);
	mlx_loop_hook(mlx.mlx, animation_handler, &mlx);
	mlx_loop(mlx.mlx);
}
