#include "include/cub3d.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (*matrix == NULL)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
	return ;
}

// void	controllo_mappa()
// {}

// void	controllo_variabili(t_tex *tex)
// {
// 	if (tex->)
// }

// info per rgb cielo e pavimento
void	ft_split_atoi_f_c(char *str, t_tex *tex, char c)
{
	char	**tmp;
	char	**tmp1;

	tmp = ft_split(str, ' ');
	tmp1 = ft_split(tmp[1], ',');
	if (tmp1[0] != NULL && tmp1[1] != NULL
		&& tmp1[2] != NULL && tmp1[3] == NULL)
	{
		if (c == 'f')
		{
			tex->f[0] = ft_atoi(tmp1[0]);
			tex->f[1] = ft_atoi(tmp1[1]);
			tex->f[2] = ft_atoi(tmp1[2]);
		}
		else if (c == 'c')
		{
			tex->c[0] = ft_atoi(tmp1[0]);
			tex->c[1] = ft_atoi(tmp1[1]);
			tex->c[2] = ft_atoi(tmp1[2]);
		}
	}
	else
		printf ("Error: rgb not complete");
	free_matrix(tmp);
	free_matrix(tmp1);
	return ;
}

// smistameento informazioni 
void	ft_sorting_struct(char **mtr, t_tex *tex, int i)
{
	while (i < 7)
	{
		if (ft_strncmp(mtr[i], "NO ./texture/NO.xpm", 20) == 0)
			tex->no = ft_substr(mtr[i], 3, 16);
		else if (ft_strncmp(mtr[i], "SO ./texture/SO.xpm", 20) == 0)
			tex->so = ft_substr(mtr[i], 3, 16);
		else if (ft_strncmp(mtr[i], "WE ./texture/WE.xpm", 20) == 0)
			tex->we = ft_substr(mtr[i], 3, 16);
		else if (ft_strncmp(mtr[i], "EA ./texture/EA.xpm", 20) == 0)
			tex->ea = ft_substr(mtr[i], 3, 16);
		else if (ft_strncmp(mtr[i], "F ", 2) == 0)
			ft_split_atoi_f_c(mtr[i], tex, 'f');
		else if (ft_strncmp(mtr[i], "C ", 2) == 0)
			ft_split_atoi_f_c(mtr[i], tex, 'c');
		i++;
	}
	// controllo_variabili(tex);
	// controllo_mappa(mtr);
}

//conteggio linee
int	ft_count_line(char *str, char c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			r++;
		i++;
	}
	r++;
	return (r);
}

//unione stringhe con free integrato
char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!(s1 && s2))
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
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

//funzione di print delle matrici
void	print_matrix(char **mtr)
{
	int	i;

	i = 0;
	while (mtr[i])
	{
		printf("%s", mtr[i]);
		printf("\n");
		i++;
	}
	printf("\n");
	return ;
}

//inizializzazione
void	init(char *s, t_tex *tex)
{
	int		fd;
	int		r;
	char	*str;
	char	**mtr;

	check_extention(s);
	fd = open(s, O_RDONLY);
	str = check_file_map(fd);
	r = ft_count_line(str, '\n');
	mtr = malloc(sizeof(char) * r);
	mtr = ft_split(str, '\n');
	ft_sorting_struct(mtr, tex, 0);
	free(str);
	print_matrix(mtr);
}
