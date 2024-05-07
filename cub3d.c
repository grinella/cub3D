#include "include/cub3d.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->graphic.mlx_pointer, game->graphic.mlx_window);
	//free_all
	exit(0);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == 65307)
		close_window(game);
}

void	set_keys(t_game *game)
{
	mlx_hook(game->graphic.mlx_window, 17, 0, close_window, game);
	mlx_hook(game->graphic.mlx_window, 2, 1L << 0, key_press, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error: wrong number of arguments\n");
		return (-1);
	}
	init(argv[1], &game);
	create_window(&game);
	set_keys(&game);
	print_matrix(game.map);
	init_raycast(&game);
	start_raycast(&game);
	printf("pl_coords: %f, %f\n", game.player.pos.x, game.player.pos.y);
	mlx_loop(game.graphic.mlx_pointer);
	return (0);
}
