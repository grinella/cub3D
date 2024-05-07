#include "../include/cub3d.h"

void	set_player_info2(t_game *game, char dir)
{
	if (dir == 'E')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
		game->player.cam_plane.x = 0;
		game->player.cam_plane.y = 0.66;
	}
	if (dir == 'W')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.cam_plane.x = 0;
		game->player.cam_plane.y = -0.66;	
	}
}

void	set_player_info(t_game *game, char dir, int x, int y)
{
	game->player.pos.x = x;
	game->player.pos.y = y;
	if (dir == 'N')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
		game->player.cam_plane.x = 0.66;
		game->player.cam_plane.y = 0;
	}
	if (dir == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
		game->player.cam_plane.x = -0.66;
		game->player.cam_plane.y = 0;
	}
	set_player_info2(game, dir);
}

void	player_info(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(game->map[x])
	{
		while(game->map[x][y])
		{
			if (game->map[x][y] == 'N')
				set_player_info(game, 'N', x, y);
			else if (game->map[x][y] == 'S')
				set_player_info(game, 'S', x, y);
			else if (game->map[x][y] == 'E')
				set_player_info(game, 'E', x, y);
			else if (game->map[x][y] == 'W')
				set_player_info(game, 'W', x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

// void	init_ray_info(t_game *game)
// {

// }

void	init_raycast(t_game *game)
{
	player_info(game);
	//init_ray_info(game);
}