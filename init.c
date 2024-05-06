#include "include/cub3d.h"

// void	check_mappa(char **mtr)
// {
// 	int	r;
// 	int	c;

// 	r = 6;
// 	c = 0;
// 	while (mtr[r] != NULL)
// 	{
// 		if (r == 6)
// 		{
// 			while (mtr[r][c] != '\0')
// 			{
// 				printf("mtr[%i][%i] = [%c]\n", r, c, mtr[r][c]);
// 				if (mtr[r][c] == '1' || mtr[r][c] == ' ')
// 					c++;
// 				else
// 					exit (printf("Errore: mappa non giocabile\n"));
// 			}
// 			r++;
// 		}
// 		while (r > 6)
// 		{
// 			if (mtr[r][c] == '1')
// 				c++;
// 			else if (mtr[r][c] == '0')
// 				check_zero_valid();
// 		}
// 	}
// }

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

// info per rgb cielo e pavimento
void	ft_split_atoi_f_c(char *str, t_game *game, char c)
{
	char	**tmp;
	char	**tmp1;

	tmp = ft_split(str, ' ');
	tmp1 = ft_split(tmp[1], ',');
	check_rgb(tmp1, 0, 0);
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

	game->tex.no = '\0';
	game->tex.so = '\0';
	game->tex.we = '\0';
	game->tex.ea = '\0';
	while (i < 6)
	{
		str = (char *)malloc(21);
		str = ft_one_space(game->map[i], 0, 0);
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
	}
	printf("c[0] = %i\n", game->tex.c[0]);
	printf("c[1] = %i\n", game->tex.c[1]);
	printf("c[2] = %i\n", game->tex.c[2]);
	printf("f[0] = %i\n", game->tex.f[0]);
	printf("f[1] = %i\n", game->tex.f[1]);
	printf("f[2] = %i\n", game->tex.f[2]);
	check_variabili(game, 0);
	// check_mappa(mtr);
	player_pos(game);
}

//check
char	*check_file_map(int fd)
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

//inizializzazione
void	init(char *s, t_game *game)
{
	int		fd;
	int		r;
	char	*str;

	// init_struct(game);
	check_extention(s);
	fd = open(s, O_RDONLY);
	str = check_file_map(fd);
	r = ft_count_line(str, '\n');
	game->map = malloc(sizeof(char) * r);
	game->map = ft_split(str, '\n');
	ft_sorting_struct(game, 0);
	free(str);
	close(fd);
}
