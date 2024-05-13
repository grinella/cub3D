#include "include/cub3d.h"

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