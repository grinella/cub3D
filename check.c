#include "include/cub3d.h"

void	check_zero_nswe(t_game *game, int r, int c)
{
	if (game->map[r][c] == '0' || game->map[r][c] == 'N'
		|| game->map[r][c] == 'S' || game->map[r][c] == 'W'
		|| game->map[r][c] == 'E')
	{
		if (game->map[r - 1][c] == ' ' || game->map[r - 1][c] == '\0'
			|| game->map[r + 1][c] == ' ' || game->map[r + 1][c] == '\0'
			|| game->map[r][c - 1] == ' ' || game->map[r][c - 1] == '\0'
			||game->map[r][c + 1] == ' ' || game->map[r][c + 1] == '\0')
		{
			printf("Error: mappa non valida, ");
			exit(printf("'%c' non circondato\n", game->map[r][c]));
		}
	}
}

// controlla se il carattere analizzato fa o
// non fa parte di una certa sezione (1, 2 o 3)
void	valid_char(t_game *game, int r, int c, int x)
{
	if (x == 1)
	{
		if (game->map[r][c] != ' ' && game->map[r][c] != '1'
			&& game->map[r][c] != '0' && game->map[r][c] != '\0'
			&& game->map[r][c] != 'N' && game->map[r][c] != 'S'
			&& game->map[r][c] != 'W' && game->map[r][c] != 'E')
			exit(printf("Error: carattere '%c' non valido\n", game->map[r][c]));
	}
	if (x == 2)
	{
		if (game->map[r][c] == '0' || game->map[r][c] == 'N'
			|| game->map[r][c] == 'S' || game->map[r][c] == 'W'
			|| game->map[r][c] == 'E')
			check_zero_nswe(game, r, c);
	}
	if (x == 3)
	{
		if (game->map[r][c] != '\0' && game->map[r][c] != ' '
					&& game->map[r][c] != '1')
			exit(printf("Error: mappa non valida\n"));
	}
}

void	check_mappa(t_game *g, int r, int c)
{
	while (g->map[r] != NULL)
	{
		if (r == 0)
		{
			while (g->map[r][c] != '\0')
			{
				c++;
				valid_char(g, r, c, 3); //va fatta una funzione che freea e esce dal programma
			}
			r++;
			c = 0;
		}
		valid_char(g, r, c, 1);
		while (g->map[r + 1] == NULL)
		{
			c++;
			valid_char(g, r, c, 3); //va fatta una funzione che freea e esce dal programma
			if (g->map[r][c] == '\0')
				return ;
		}
		valid_char(g, r, c, 2);
		c++;
		if (g->map[r][c] == '\0' && r++)
			c = 0;
	}
}

void	check_variabili(t_game *game, int i)
{
	if (ft_strncmp(game->tex.no, "./texture/NO.xpm", 18) != 0)
		exit (printf("NO TEXTURE NO\n"));
	if (ft_strncmp(game->tex.so, "./texture/SO.xpm", 18) != 0)
		exit (printf("NO TEXTURE SO\n"));
	if (ft_strncmp(game->tex.we, "./texture/WE.xpm", 18) != 0)
		exit (printf("NO TEXTURE WE\n"));
	if (ft_strncmp(game->tex.ea, "./texture/EA.xpm", 18) != 0)
		exit (printf("NO TEXTURE EA\n"));
	while (i <= 2)
	{
		if (game->tex.f[i] >= 255 || game->tex.c[i] >= 255)
			exit(printf("Error: rgb non valido"));
		i++;
	}
}

void	check_rgb(char **tmp1, int i, int j)
{
	while (tmp1[i] != NULL)
	{
		if (ft_isdigit(tmp1[i][j]) == 0)
			exit(printf("RGB Error\n"));
		j++;
		if (tmp1[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
}
