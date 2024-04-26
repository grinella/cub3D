#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
}			t_tex;

typedef struct	s_graphic
{
	void	*mlx_pointer;
	void	*mlx_window;
	//int		size_tile;
}			t_graphic;

typedef struct s_game
{
	t_tex		tex;
	t_graphic	graphic;
}			t_game;

void	init(char *s, t_game game);

//GRAPHIC
void	create_window(t_game game);

#endif
