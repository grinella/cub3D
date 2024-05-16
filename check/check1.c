#include "../include/cub3d.h"

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

void	check_validity(char *str, int i)
{
	int	j;

	j = 0;
	while (j < 6)
	{
		printf("str[%i] == [%c]\n", i, str[i]);
		while (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\n')
			i++;
		if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E'
			&& str[i] != 'F' && str[i] != 'C')
			exit(printf("Error: file non valido\n"));
		while (str[i] != '\n')
			i++;
		j++;
	}
	if (str[i] != '\n' || str[i + 1] != '\n')
		exit(printf("Error: file non valido\n"));
	i++;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			exit(printf("Error: file non valido\n"));
		i++;
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
					exit(printf("Error: doppio punto di spawn\n"));//va sostituita con una funzione free_exit
				flag = 1;
				game->pcoords.x = x;
				game->pcoords.y = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (flag != 1)
		exit (printf("Error: nessun punto di spawn\n"));
}
