#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "libft/libft.h"
# include "../minilibx-linux/mlx.h"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
}			t_tex;

typedef struct s_graphic
{
	void	*mlx_pointer;
	void	*mlx_window;
	//int		size_tile;
}			t_graphic;

typedef struct s_pcoords
{
	double	x;
	double	y;
}			t_pcoords;

typedef struct s_game
{
	t_tex		tex;
	t_graphic	graphic;
	t_pcoords	pcoords;
	char		**map; //puntatore all'allocazione di cub_file (guarda funzione init)
	char		**cub_file; //allocata
}			t_game;

void	init(char *s, t_game *game);

//GRAPHIC
void	create_window(t_game *game);

//UTILS
void	print_matrix(char **mtr);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_count_line(char *str, char c);
void	free_matrix(char **matrix);
void	init_struct(t_game *game);
char	*ft_one_space(char	*str, int s, int f);

//INFO dal .cub
void	player_pos(t_game *game, int flag);

// CHECK
void	check_zero_nswe(t_game *game, int r, int c);
void	valid_char(t_game *game, int r, int c, int x);
void	check_mappa(t_game *g, int r, int c);
void	check_variabili(t_game *game, int i);
void	check_rgb(char **tmp1, int i, int j);
;
#endif
