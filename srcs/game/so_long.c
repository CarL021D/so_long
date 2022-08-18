/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 02:50:19 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/18 20:58:58 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;		
	t_game	game;

	if (argc != 2 || file_name_extension_error(argv[1]))
		return (0);
	game.movement_count = 0;
	game.coin_counter = 0;
	game.enemy_counter_anim = 0;
	game.enemy_counter_move = 0;
	game.enemy_direction = 1;
	mlx.game = &game;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (0);
	game.map = set_map(argv[1], &game);
	if (!game.map)
		return (0);
	if (!check_map_errors(&game))
		free_mlx_and_map(&mlx);
	if (!init_images(&mlx) || !init_images2(&mlx))
		return (0);
	mlx.window = mlx_new_window(mlx.mlx,
			game.map_width * 32, game.map_height * 32, "so_long");
	display_images(&mlx);
	player_animation(&mlx, 1);
	mlx_hook(mlx.window, 17, (1L<<17), free_all, &mlx); 
	mlx_key_hook(mlx.window, init_player_movement, &mlx);
	mlx_loop_hook(mlx.mlx, looping_func, &mlx);
	mlx_loop(mlx.mlx);
}


// Creer fichier pour mlx hook
// Creer fichier free 
// clean norminette
// clean header
// animate enemies
// foot step error when coliding with walls