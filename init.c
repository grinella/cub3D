/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:07:22 by grinella          #+#    #+#             */
/*   Updated: 2024/05/24 15:07:23 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

// info per rgb cielo e pavimento
void	ft_split_atoi_f_c(char *str, t_game *game, char c)
{
	char	**tmp;
	char	**tmp1;

	tmp = ft_split(str, ' ');
	tmp1 = ft_split(tmp[1], ',');
	check_rgb(game, tmp1, 0, 0);
	if (tmp1[0] != NULL && tmp1[1] != NULL
		&& tmp1[2] != NULL && tmp1[3] == NULL)
	{
		if (c == 'f')
		{
			game->tex.f[0] = ft_atoi(tmp1[0]);
			game->tex.f[1] = ft_atoi(tmp1[1]);
			game->tex.f[2] = ft_atoi(tmp1[2]);
		}
		else if (c == 'c')
		{
			game->tex.c[0] = ft_atoi(tmp1[0]);
			game->tex.c[1] = ft_atoi(tmp1[1]);
			game->tex.c[2] = ft_atoi(tmp1[2]);
		}
	}
	free_matrix(tmp);
	free_matrix(tmp1);
}

// smistameento informazioni
void	ft_sorting_struct(t_game *game, int i)
{
	char	*str;

	while (i < 6)
	{
		str = ft_one_space(game->cub_file[i], 0, 0);
		if (ft_strncmp(str, "NO ./texture/NO.xpm", 20) == 0)
			game->tex.no = ft_substr(str, 3, 16);
		else if (ft_strncmp(str, "SO ./texture/SO.xpm", 20) == 0)
			game->tex.so = ft_substr(str, 3, 16);
		else if (ft_strncmp(str, "WE ./texture/WE.xpm", 20) == 0)
			game->tex.we = ft_substr(str, 3, 16);
		else if (ft_strncmp(str, "EA ./texture/EA.xpm", 20) == 0)
			game->tex.ea = ft_substr(str, 3, 16);
		if (ft_strncmp(str, "F ", 2) == 0)
			ft_split_atoi_f_c(str, game, 'f');
		else if (ft_strncmp(str, "C ", 2) == 0)
			ft_split_atoi_f_c(str, game, 'c');
		i++;
		free(str);
		str = NULL;
	}
	free(str);
	check_variabili(game, 0);
	check_mappa(game, 0, 0);
	player_pos(game, 0);
}

//check
char	*cubfile(int fd)
{
	char	*str;
	char	*tmp;

	tmp = get_next_line(fd);
	str = ft_strdup("\0");
	while (tmp != NULL)
	{
		str = ft_strjoin_free(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	return (str);
}

void	init_images(t_game *game)
{
	int	x;
	int	y;
	int	z;

	game->tex.wall_n = mlx_xpm_file_to_image(game->graphic.mlx_pointer,
			game->tex.no, &game->tex.size, &game->tex.size);
	game->tex.wall_s = mlx_xpm_file_to_image(game->graphic.mlx_pointer,
			game->tex.so, &game->tex.size, &game->tex.size);
	game->tex.wall_e = mlx_xpm_file_to_image(game->graphic.mlx_pointer,
			game->tex.ea, &game->tex.size, &game->tex.size);
	game->tex.wall_w = mlx_xpm_file_to_image(game->graphic.mlx_pointer,
			game->tex.we, &game->tex.size, &game->tex.size);
	game->tex.stored_t[0] = mlx_get_data_addr(game->tex.wall_n, &x, &y, &z);
	game->tex.stored_t[1] = mlx_get_data_addr(game->tex.wall_s, &x, &y, &z);
	game->tex.stored_t[2] = mlx_get_data_addr(game->tex.wall_e, &x, &y, &z);
	game->tex.stored_t[3] = mlx_get_data_addr(game->tex.wall_w, &x, &y, &z);
}

//inizializzazione
void	init(char *s, t_game *game)
{
	int		fd;
	int		r;
	char	*str;

	game->tex.size = 64;
	game->tex.no = '\0';
	game->tex.so = '\0';
	game->tex.we = '\0';
	game->tex.ea = '\0';
	check_extention(s);
	fd = open(s, O_RDONLY);
	str = cubfile(fd);
	check_validity(game, str, 0);
	r = ft_count_line(str, '\n');
	game->cub_file = ft_split(str, '\n');
	game->map = game->cub_file + 6;
	ft_sorting_struct(game, 0);
	free(str);
	close(fd);
	player_info(game);
}
