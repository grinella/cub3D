#include "include/cub3d.h"

void	create_window(t_game game)
{
	game.graphic.mlx_pointer = mlx_init();
	game.graphic.mlx_window = mlx_new_window(game.graphic.mlx_pointer,
			1280, 720, "Er_Cubo");
	mlx_loop(game.graphic.mlx_pointer);
}
