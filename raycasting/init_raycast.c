#include "../include/cub3d.h"

void	start_raycast(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		raycast(game, &x);
		set_step_and_dist(game);
		perform_dda(game);
		set_wall_height(game);
		floor_ceiling_render(game, x);
		if (game->ray.side == 0)
			game->tex.wall_x = game->player.pos.y + game->ray.perp_wall_dist
				* game->ray.dir.y;
		else
			game->tex.wall_x = game->player.pos.x + game->ray.perp_wall_dist
				* game->ray.dir.x;
		game->tex.wall_x -= (int)(game->tex.wall_x);
		game->tex.x = (int)(game->tex.wall_x * (double)64);
		game->tex.x = 64 - game->tex.x;
		render_wall(game, x);
		x++;
	}
}

void	init_raycast(t_game *game)
{
	init_ray_info(game);
	init_graphic_info(game);
	set_pixel(game);
}
