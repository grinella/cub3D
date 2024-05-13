#include "include/cub3d.h"

int	raycast_loop(t_game *game)
{
	start_raycast(game);
	fps_counter(game);
	//FUNZIONE DI MLX, DOPO AVER SETTATO I PIXEL QUESTA LI RENDERIZZA SULLA FINESTRA
	mlx_put_image_to_window(game->graphic.mlx_pointer, game->graphic.mlx_window, game->data.img, 0, 0);
	mlx_string_put(game->graphic.mlx_pointer, game->graphic.mlx_window,  15, 10, create_trgb(0, 0, 255, 0), game->graphic.fps);
	free(game->graphic.fps);
	return(0);
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
	mlx_loop_hook(game.graphic.mlx_pointer, raycast_loop, &game);
	mlx_loop(game.graphic.mlx_pointer);
	return (0);
}
