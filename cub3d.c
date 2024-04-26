#include "include/cub3d.h"

void	init_struct()
{
	// init structs
}

int	main(int argc, char **argv)
{
	t_tex	*tex;

	tex = malloc(1 * (sizeof(t_tex)));
	if (argc != 2)
	{
		printf("Error: wrong number of arguments\n");
		return (-1);
	}
	init(argv[1], tex);
	return (0);
}
