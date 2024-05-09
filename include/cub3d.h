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

typedef struct	s_graphic
{
	void	*mlx_pointer;
	void	*mlx_window;
	//int		size_tile;
}			t_graphic;

typedef struct	s_coords
{
	double	x;
	double	y;
}			t_coords;

typedef struct s_player
{
	t_coords	pos;
	t_coords	dir;
	t_coords	cam_plane;
}			t_player;

typedef struct s_ray
{
	double		cameraX;
	t_coords	dir;
	t_coords	sideDist;
	t_coords	deltaDist;
	int			mapX;
	int			mapY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
}			t_ray;

typedef struct s_game
{
	t_tex		tex;
	t_graphic	graphic;
	t_player	player;
	t_ray		ray;
	char		**map; //allocata
}			t_game;


void	init(char *s, t_game *game);
void	player_info(t_game *game);

//RAYCAST
void	start_raycast(t_game *game);
void	init_raycast(t_game *game);

//GRAPHIC
void	create_window(t_game *game);

//UTILS
void	print_matrix(char **mtr);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_count_line(char *str, char c);
void	free_matrix(char **matrix);
void	init_struct(t_game *game);

#endif
