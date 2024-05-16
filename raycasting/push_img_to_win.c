#include "../include/cub3d.h"

//FUNZIONE CHE SEMPLIFICA L'UTILIZZO DEGLI RGB
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//SETUP PER MY_PIXEL_PUT
void	set_pixel(t_game *game)
{
	game->data.img = mlx_new_image(game->graphic.mlx_pointer, WIN_WIDTH, WIN_HEIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img, &game->data.bits_per_pixel, &game->data.line_length, &game->data.endian);
}

//POSIZIONA UN PIXEL NEL PUNTO SPECIFICATO
void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data.addr + (y * game->data.line_length + x * (game->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	fps_counter(t_game *game)
{
	double	frame_time;

	frame_time = 0;
	game->graphic.old_time = game->graphic.time;
	game->graphic.time = get_time();
	frame_time = (game->graphic.time - game->graphic.old_time) / 1000.0;
	game->graphic.fps = ft_itoa(1.0 / frame_time);
	game->move_speed = 0.1;
	game->rot_speed = 0.08;
}