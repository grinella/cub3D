#include "include/cub3d.h"

void	move_fw(t_game *game)
{
	if (game->map[(int)(game->player.pos.y + game->player.dir.y * game->move_speed)][(int)game->player.pos.y] != '1')
		game->player.pos.x += game->player.dir.x * game->move_speed;
	if (game->map[(int)game->player.pos.x][(int)(game->player.pos.y + game->player.dir.y * game->move_speed)] != '1')
		game->player.pos.y += game->player.dir.y * game->move_speed;
}

void	move_bw(t_game *game)
{
	if (game->map[(int)(game->player.pos.x - game->player.dir.x * game->move_speed)][(int)game->player.pos.y] != '1')
		game->player.pos.x -= game->player.dir.x * game->move_speed;
	if (game->map[(int)game->player.pos.x][(int)(game->player.pos.y - game->player.dir.y * game->move_speed)] != '1')
		game->player.pos.y -= game->player.dir.y * game->move_speed;
}

void	move_r(t_game *game)
{
	if (game->map[(int)(game->player.pos.x + game->player.cam_plane.x * game->move_speed)][(int)game->player.pos.y] != '1')
		game->player.pos.x += game->player.cam_plane.x * game->move_speed;
	if (game->map[(int)game->player.pos.x][(int)(game->player.pos.y + game->player.cam_plane.y * game->move_speed)] != '1')
		game->player.pos.y += game->player.cam_plane.y * game->move_speed;
}

void	move_l(t_game *game)
{
	if (game->map[(int)(game->player.pos.x - game->player.cam_plane.x * game->move_speed)][(int)game->player.pos.y] != '1')
		game->player.pos.x -= game->player.cam_plane.x * game->move_speed;
	if (game->map[(int)game->player.pos.x][(int)(game->player.pos.y - game->player.cam_plane.y * game->move_speed)] != '1')
		game->player.pos.y -= game->player.cam_plane.y * game->move_speed;
}

void	rot_l(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(game->rot_speed) - game->player.dir.y * sin(game->rot_speed);
	game->player.dir.y = old_dir_x * sin(game->rot_speed) + game->player.dir.y * cos(game->rot_speed);
	old_plane_x = game->player.cam_plane.x;
	game->player.cam_plane.x = game->player.cam_plane.x * cos(game->rot_speed) - game->player.cam_plane.y * sin(game->rot_speed);
	game->player.cam_plane.y = old_plane_x * sin(game->rot_speed) + game->player.cam_plane.y * cos(game->rot_speed);
}

void	rot_r(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(-game->rot_speed) - game->player.dir.y * sin(-game->rot_speed);
	game->player.dir.y = old_dir_x * sin(-game->rot_speed) + game->player.dir.y * cos(-game->rot_speed);
	old_plane_x = game->player.cam_plane.x;
	game->player.cam_plane.x = game->player.cam_plane.x * cos(-game->rot_speed) - game->player.cam_plane.y * sin(-game->rot_speed);
	game->player.cam_plane.y = old_plane_x * sin(-game->rot_speed) + game->player.cam_plane.y * cos(-game->rot_speed);
}

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	if (key == W)
		move_fw(game);
	if (key == A)
		move_l(game);
	if (key == S)
		move_bw(game);
	if (key == D)
		move_r(game);
	if (key == RT)
		rot_r(game);
	if (key == LT)
		rot_l(game);
	return(0);
}

void	set_keys(t_game *game)
{
	mlx_hook(game->graphic.mlx_window, 17, 0, close_window, game);
	mlx_hook(game->graphic.mlx_window, 2, 1L << 0, key_press, game);
}