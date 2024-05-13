#include "include/cub3d.h"

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
	mlx_loop(game.graphic.mlx_pointer);
	return (0);
}
