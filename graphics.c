#include "include/cub3d.h"

void	create_window(t_game *game)
{
	game->graphic.mlx_pointer = mlx_init();
	game->graphic.mlx_window = mlx_new_window(game->graphic.mlx_pointer,
			WIN_WIDTH, WIN_HEIGHT, "Er_Cubo");
}

//unica funzione il cui il programma esce
int	close_window(t_game *game)
{
	mlx_destroy_window(game->graphic.mlx_pointer, game->graphic.mlx_window);
	//free_all
	exit(0);
	return (0);
}