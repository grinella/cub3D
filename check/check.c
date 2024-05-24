/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:06:05 by grinella          #+#    #+#             */
/*   Updated: 2024/05/24 15:06:06 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// fa il check degli zeri e della posizione del player se é valida
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
			printf("'%c' non circondato\n", game->map[r][c]);
			exit_free(game, 0);
		}
	}
}

// controlla se il carattere analizzato fa o
// non fa parte di una certa sezione (1, 2 o 3)
void	valid_char(t_game *g, int r, int c, int x)
{
	if (x == 1)
	{
		if (g->map[r][c] != ' ' && g->map[r][c] != '1' && g->map[r][c]
			!= '0' && g->map[r][c] != '\0' && g->map[r][c] != 'N' &&
			g->map[r][c] != 'S' && g->map[r][c] != 'W' && g->map[r][c] != 'E')
		{
			printf("Error: carattere '%c' non valido\n", g->map[r][c]);
			exit_free(g, 0);
		}
	}
	if (x == 2)
	{
		if (g->map[r][c] == '0' || g->map[r][c] == 'N' || g->map[r][c]
			== 'S' || g->map[r][c] == 'W' || g->map[r][c] == 'E')
			check_zero_nswe(g, r, c);
	}
	while (x == 3 && g->map[r][c] != '\0' && c++)
	{
		if (g->map[r][c] != '\0' && g->map[r][c] != ' '
					&& g->map[r][c] != '1')
		{
			printf("Error: mappa non valida\n");
			exit_free(g, 0);
		}
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
				valid_char(g, r, c, 3);
				c++;
			}
			r++;
			c = 0;
		}
		valid_char(g, r, c, 1);
		while (g->map[r + 1] == NULL)
		{
			c++;
			valid_char(g, r, c, 3);
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
		exit_free(game, 1);
	if (ft_strncmp(game->tex.so, "./texture/SO.xpm", 18) != 0)
		exit_free(game, 1);
	if (ft_strncmp(game->tex.we, "./texture/WE.xpm", 18) != 0)
		exit_free(game, 1);
	if (ft_strncmp(game->tex.ea, "./texture/EA.xpm", 18) != 0)
		exit_free(game, 1);
	while (i <= 2 && i++)
	{
		if (game->tex.f[i] >= 255 || game->tex.c[i] >= 255)
		{
			printf("Error: rgb non valido");
			exit_free(game, 0);
		}
	}
}

void	check_rgb(t_game *game, char **tmp1, int i, int j)
{
	while (tmp1[i] != NULL)
	{
		if (ft_isdigit(tmp1[i][j]) == 0)
		{
			printf("RGB Error\n");
			exit_free(game, 0);
		}
		j++;
		if (tmp1[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
}
