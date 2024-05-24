/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:06:43 by grinella          #+#    #+#             */
/*   Updated: 2024/05/24 15:06:44 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//TUTTO IL FILE SERVE A INIZIALIZZARE LE INFORMAZIONI PER IL RAYCAST
void	set_player_info2(t_game *game, char dir, int x, int y)
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
	game->player.pos.x = x + 0.1 * -game->player.dir.y;
	game->player.pos.y = y + 0.1 * -game->player.dir.x;
}

void	set_player_info(t_game *game, char dir, int x, int y)
{
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
	set_player_info2(game, dir, x, y);
}

void	player_info(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[x])
	{
		while (game->map[x][y])
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
	game->ray.camera_x = 0;
	game->ray.dir.x = 0;
	game->ray.dir.y = 0;
	game->ray.side_dist.x = 0;
	game->ray.side_dist.y = 0;
	game->ray.delta_dist.x = 0;
	game->ray.delta_dist.y = 0;
	game->ray.map_x = 0;
	game->ray.map_y = 0;
	game->ray.perp_wall_dist = 0;
	game->ray.step_x = 0;
	game->ray.step_y = 0;
	game->ray.hit = 0;
	game->ray.side = 0;
	game->ray.line_height = 0;
	game->ray.draw_start = 0;
	game->ray.draw_end = 0;
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
