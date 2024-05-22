#include "include/cub3d.h"

void	move_fw(t_game *game)
{
	if (game->map[(int)(game->player.pos.x + game->player.dir.x
			* game->move_speed)][(int)game->player.pos.y] != '1')
		game->player.pos.x += game->player.dir.x * game->move_speed;
	if (game->map[(int)game->player.pos.x][(int)(game->player.pos.y
		+ game->player.dir.y * game->move_speed)] != '1')
		game->player.pos.y += game->player.dir.y * game->move_speed;
}

void	move_bw(t_game *game)
{
	if (game->map[(int)(game->player.pos.x - game->player.dir.x
			* game->move_speed)][(int)game->player.pos.y] != '1')
		game->player.pos.x -= game->player.dir.x * game->move_speed;
	if (game->map[(int)game->player.pos.x][(int)(game->player.pos.y
		- game->player.dir.y * game->move_speed)] != '1')
		game->player.pos.y -= game->player.dir.y * game->move_speed;
}

void	move_r(t_game *game)
{
	if (game->map[(int)(game->player.pos.x + game->player.cam_plane.x
			* game->move_speed)][(int)game->player.pos.y] != '1')
		game->player.pos.x += game->player.cam_plane.x * game->move_speed;
	if (game->map[(int)game->player.pos.x][(int)(game->player.pos.y
		+ game->player.cam_plane.y * game->move_speed)] != '1')
		game->player.pos.y += game->player.cam_plane.y * game->move_speed;
}

void	move_l(t_game *game)
{
	if (game->map[(int)(game->player.pos.x - game->player.cam_plane.x
			* game->move_speed)][(int)game->player.pos.y] != '1')
		game->player.pos.x -= game->player.cam_plane.x * game->move_speed;
	if (game->map[(int)game->player.pos.x][(int)(game->player.pos.y
		- game->player.cam_plane.y * game->move_speed)] != '1')
		game->player.pos.y -= game->player.cam_plane.y * game->move_speed;
}

void	rot_l(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(game->rot_speed)
		- game->player.dir.y * sin(game->rot_speed);
	game->player.dir.y = old_dir_x * sin(game->rot_speed)
		+ game->player.dir.y * cos(game->rot_speed);
	old_plane_x = game->player.cam_plane.x;
	game->player.cam_plane.x = game->player.cam_plane.x * cos(game->rot_speed)
		- game->player.cam_plane.y * sin(game->rot_speed);
	game->player.cam_plane.y = old_plane_x * sin(game->rot_speed)
		+ game->player.cam_plane.y * cos(game->rot_speed);
}
