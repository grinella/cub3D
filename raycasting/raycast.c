#include "../include/cub3d.h"

//CALCOLO DIREZIONE RAGGI
void	raycast(t_game *game, int *x)
{
	game->ray.camera_x = 2 * (*x) / (double)WIN_WIDTH - 1;
	game->ray.dir.x = game->player.dir.x + game->player.cam_plane.x * game->ray.camera_x;
	game->ray.dir.y = game->player.dir.y + game->player.cam_plane.y * game->ray.camera_x;
	game->ray.map_x = (int)game->player.pos.x;
	game->ray.map_y = (int)game->player.pos.y;
	if(game->ray.dir.x == 0)
		game->ray.delta_dist.x = 1e30;
	else
		game->ray.delta_dist.x = fabs(1 / game->ray.dir.x);
	if(game->ray.dir.y == 0)
		game->ray.delta_dist.y = 1e30;
	else
		game->ray.delta_dist.y = fabs(1 / game->ray.dir.y);
}

//CALCOLO DISTANZA DAL PROSSIMO QUADRATO
void	set_step_and_dist(t_game *game)
{
	if (game->ray.dir.x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist.x = (game->player.pos.x - game->ray.map_x) * game->ray.delta_dist.x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist.x = (game->ray.map_x + 1.0 - game->player.pos.x) * game->ray.delta_dist.x;
	}
	if (game->ray.dir.y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist.y = (game->player.pos.y - game->ray.map_y) * game->ray.delta_dist.y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist.y = (game->ray.map_y + 1.0 - game->player.pos.y) * game->ray.delta_dist.y;
	}
}

//RICERCA MURO
void	perform_DDA(t_game *game)
{
	game->ray.hit = 0;
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist.x < game->ray.side_dist.y)
		{
			game->ray.side_dist.x += game->ray.delta_dist.x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;

		}
		else
		{
			game->ray.side_dist.y += game->ray.delta_dist.y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map[game->ray.map_x][game->ray.map_y] == '1')
			game->ray.hit = 1;
	}
}

//CALCOLO ALTEZZA MURO
void	set_wall_height(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = (game->ray.side_dist.x - game->ray.delta_dist.x);
	else
		game->ray.perp_wall_dist = (game->ray.side_dist.y - game->ray.delta_dist.y);
	game->ray.line_height = WIN_HEIGHT / game->ray.perp_wall_dist;
	game->ray.draw_start = -game->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.draw_end >= WIN_HEIGHT)
		game->ray.draw_end = WIN_HEIGHT - 1; 
}

void	start_raycast(t_game *game)
{
	int	x;

	x = 0;
	while(x < WIN_WIDTH)
	{
		raycast(game, &x);
		set_step_and_dist(game);
		perform_DDA(game);
		set_wall_height(game);
		floor_ceiling_render(game, x);
		while(game->ray.draw_start <= game->ray.draw_end)
		{
			if (game->ray.side == 0)
				my_mlx_pixel_put(game, x, game->ray.draw_start, create_trgb(0, 200, 200, 200));
			else
				my_mlx_pixel_put(game, x, game->ray.draw_start, create_trgb(0, 255, 255, 255));
			game->ray.draw_start++;
		}
		x++;
	}
}
