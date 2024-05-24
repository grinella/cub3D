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
	mlx_destroy_image(game->graphic.mlx_pointer, game->tex.wall_n);
	mlx_destroy_image(game->graphic.mlx_pointer, game->tex.wall_s);
	mlx_destroy_image(game->graphic.mlx_pointer, game->tex.wall_e);
	mlx_destroy_image(game->graphic.mlx_pointer, game->tex.wall_w);
	free(game->graphic.mlx_pointer);
	free_matrix(game->cub_file);
	free(game->tex.no);
	free(game->tex.so);
	free(game->tex.we);
	free(game->tex.ea);
	exit(0);
	return (0);
}

void	floor_ceiling_render(t_game *game, int x)
{
	int	y;

	y = 0;
	if (game->ray.draw_end < 0)
		game->ray.draw_end = WIN_HEIGHT;
	while (y < game->ray.draw_start)
	{
		my_mlx_pixel_put(game, x, y, create_trgb(0, game->tex.c[0],
				game->tex.c[1], game->tex.c[2]));
		y++;
	}
	y = game->ray.draw_end + 1;
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(game, x, y, create_trgb(0, game->tex.f[0],
				game->tex.f[1], game->tex.f[2]));
		y++;
	}
}
