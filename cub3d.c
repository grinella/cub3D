#include "include/cub3d.h"

void	player_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(game->map[x])
	{
		while(game->map[x][y])
		{
			if (game->map[x][y] == 'N' || game->map[x][y] == 'S' || game->map[x][y] == 'E' || game->map[x][y] == 'W')
			{
				game->pcoords.x = x;
				game->pcoords.y = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	init_struct(t_game *game)
{
	player_pos(game);

}

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

void	mlx_keys(t_game *game)
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
	mlx_keys(&game);
	print_matrix(game.map);
	printf("pl_coords: %f, %f\n", game.pcoords.x, game.pcoords.y);
	mlx_loop(game.graphic.mlx_pointer);
	return (0);
}
