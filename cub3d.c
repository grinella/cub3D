#include "include/cub3d.h"

void	init_struct()
{
	// init structs
}

void	close_window(t_game *game)
{
	mlx_destroy_window(game->graphic.mlx_pointer, game->graphic.mlx_window);
	exit(0);
	//free_all
}

void	mlx_keys(t_game *game)
{
	mlx_hook(game->graphic.mlx_window, 17, 0, close_window, game);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
	{
		printf("Error: wrong number of arguments\n");
		return (-1);
	}
	init(argv[1], game);
	create_window(&game);
	mlx_keys(&game);
	mlx_loop(game.graphic.mlx_pointer);
	return (0);
}
