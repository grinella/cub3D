#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <sys/time.h>
# include "libft/libft.h"
# include "../minilibx-linux/mlx.h"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RT 65363
# define LT 65361

//DA CANCELLARE(UNTEXTURED)
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	double	old_time;
	double	time;
	char	*fps;
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
	double		camera_x;
	t_coords	dir;
	t_coords	side_dist;
	t_coords	delta_dist;
	int			map_x;
	int			map_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}			t_ray;

typedef struct s_game
{
	t_tex		tex;
	t_graphic	graphic;
	t_player	player;
	t_ray		ray;
	t_data		data;//DA CANCELLARE(UNTEXTURED)
	char		**map; //allocata
	double		move_speed;
	double		rot_speed;
}			t_game;

//GAME
void	init(char *s, t_game *game);
void	player_info(t_game *game);
void	set_keys(t_game *game);
int		key_press(int key, t_game *game);

//RAYCAST
void	start_raycast(t_game *game);
void	init_raycast(t_game *game);
void	set_pixel(t_game *game);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);

//GRAPHIC
void	create_window(t_game *game);
int		close_window(t_game *game);
void	fps_counter(t_game *game);

//UTILS
void		print_matrix(char **mtr);
char		*ft_strjoin_free(char *s1, char *s2);
int			ft_count_line(char *str, char c);
void		free_matrix(char **matrix);
void		init_struct(t_game *game);
uint64_t	get_time(void);

#endif
