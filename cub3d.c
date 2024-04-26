#include "include/cub3d.h"

void	init_struct()
{
	// init structs
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
	{
		printf("Error: wrong number of arguments\n");
		return (-1);
	}
	init(argv[1], game);
	create_window(game);
	return (0);
}
