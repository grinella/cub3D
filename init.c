#include "include/cub3d.h"

void	check_file_map(int fd)
{
	char	*str;

	str = get_next_line(fd);
	printf("str [%s] \n", str);
}

void	check_extention(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (s[i - 1] != 'b' && s[i - 2] != 'u' && s[i - 3] != 'c'
			&& s[i - 4] != '.')
	{
		printf("Error: mappa non giocabile\n");
		exit(1);
	}
}

void	init(char *s)
{
	int	fd;

	check_extention(s);
	fd = open(s, O_RDONLY);
	check_file_map(fd);
}
