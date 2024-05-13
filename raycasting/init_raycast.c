#include "../include/cub3d.h"

//TUTTO IL FILE SERVE A INIZIALIZZARE LE INFORMAZIONI PER IL RAYCAST
void	set_player_info2(t_game *game, char dir)
{
	if (dir == 'E')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
		game->player.cam_plane.x = 0.66;
		game->player.cam_plane.y = 0;
	}
	if (dir == 'W')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
		game->player.cam_plane.x = -0.66;
		game->player.cam_plane.y = 0;	
	}
}

void	set_player_info(t_game *game, char dir, int x, int y)
{
	game->player.pos.x = x;
	game->player.pos.y = y;
	if (dir == 'N')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.cam_plane.x = 0;
		game->player.cam_plane.y = 0.66;
	}
	if (dir == 'S')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
		game->player.cam_plane.x = 0;
		game->player.cam_plane.y = -0.66;
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

void	init_ray_info(t_game *game)
{
	game->ray.cameraX = 0;
	game->ray.dir.x = 0;
	game->ray.dir.y = 0;
	game->ray.sideDist.x = 0;
	game->ray.sideDist.y = 0;
	game->ray.deltaDist.x = 0;
	game->ray.deltaDist.y = 0;
	game->ray.mapX = 0;
	game->ray.mapY = 0;
	game->ray.perpWallDist = 0;
	game->ray.stepX = 0;
	game->ray.stepY = 0;
	game->ray.hit = 0;
	game->ray.side = 0;
	game->ray.lineHeight = 0;
	game->ray.drawStart = 0;
	game->ray.drawEnd = 0;
}

void	init_graphic_info(t_game *game)
{
	game->data.img = 0;
	game->data.addr = 0;
	game->data.bits_per_pixel = 0;
	game->data.line_length = 0;
	game->data.endian = 0;
	game->graphic.old_time = 0;
	game->graphic.time = 0;
	game->graphic.fps = 0;
	game->move_speed = 0;
	game->rot_speed = 0;
}

void	init_raycast(t_game *game)
{
	init_ray_info(game);
	init_graphic_info(game);
	player_info(game);
	set_pixel(game);
}
