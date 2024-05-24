#include "../include/cub3d.h"

void	exit_free(t_game *game, int error)
{
	if (game->cub_file)
		free_matrix(game->cub_file);
	if (game->tex.no)
		free(game->tex.no);
	if (game->tex.so)
		free(game->tex.so);
	if (game->tex.we)
		free(game->tex.we);
	if (game->tex.ea)
		free(game->tex.ea);
	if (error == 1)
		printf("Almeno un path delle texture non valido\n");
	if (error == 2)
		printf("Punto di spawn non valido\n");
	if (error == 3)
		printf("Error: file non valido\n");
	exit(0);
}

void	check_extention(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (s[i - 1] != 'b' && s[i - 2] != 'u' && s[i - 3] != 'c'
		&& s[i - 4] != '.')
	{
		printf("Errore: estensione non corretta\n");
		exit(1);
	}
}

void	check_validity(t_game *game, char *str, int i)
{
	int	j;

	j = 0;
	while (j < 6)
	{
		while (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\n')
			i++;
		if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E'
			&& str[i] != 'F' && str[i] != 'C')
			exit_free(game, 3);
		while (str[i] != '\n')
			i++;
		j++;
	}
	if (str[i] != '\n' || str[i + 1] != '\n')
		exit_free(game, 3);
	i++;
	while (str[i] != '\0' && i++)
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			exit_free(game, 3);
	}
}

void	player_pos(t_game *game, int flag)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[x])
	{
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'N' || game->map[x][y] == 'S'
				|| game->map[x][y] == 'E' || game->map[x][y] == 'W')
			{
				if (flag == 1)
					exit_free(game, 2);
				flag = 1;
				game->player.pos.x = x;
				game->player.pos.y = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (flag != 1)
		exit_free(game, 2);
}
