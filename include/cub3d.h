#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <sys/time.h>
# include "libft/libft.h"
# include "../minilibx-linux/mlx.h"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEGIHT 64
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RT 65363
# define LT 65361

//DA CANCELLARE(UNTEXTURED)
typedef struct s_data
{
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
	int		x;
	int		y;
	int		size;
	double	wall_x;
	int		side;
	void	*wall_n;
	void	*wall_s;
	void	*wall_e;
	void	*wall_w;
	char	*stored_t[4];
}			t_tex;

typedef struct s_graphic
{
	void	*mlx_pointer;
	void	*mlx_window;
	//int		size_tile;
	double	old_time;
	double	time;
	char	*fps;
}			t_graphic;

typedef struct s_coords
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
	t_data		data;
	double		move_speed;
	double		rot_speed;
	char		**map;
	char		**cub_file;
}			t_game;
//char	**map é un puntatore all'allocazione di cub_file (guarda funzione init)

//GAME

void		init(char *s, t_game *game);
void		player_info(t_game *game);
void		set_keys(t_game *game);
int			key_press(int key, t_game *game);

//RAYCAST
void		start_raycast(t_game *game);
void		init_raycast(t_game *game);
void		set_pixel(t_game *game);
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_game *game, int x, int y, int color);

void		init_ray_info(t_game *game);
void		init_graphic_info(t_game *game);
void		raycast(t_game *game, int *x);
void		set_step_and_dist(t_game *game);
void		perform_dda(t_game *game);
void		set_wall_height(t_game *game);
void		render_wall(t_game	*game, int x);

//GRAPHIC
void		create_window(t_game *game);
int			close_window(t_game *game);
void		fps_counter(t_game *game);
void		floor_ceiling_render(t_game *game, int x);

//UTILS
void		print_matrix(char **mtr);
char		*ft_strjoin_free(char *s1, char *s2);
int			ft_count_line(char *str, char c);
void		free_matrix(char **matrix);
void		init_struct(t_game *game);
uint64_t	get_time(void);
void		print_matrix(char **mtr);
char		*ft_strjoin_free(char *s1, char *s2);
int			ft_count_line(char *str, char c);
void		free_matrix(char **matrix);
void		init_struct(t_game *game);
char		*ft_one_space(char	*str, int s, int f);
void		init_images(t_game *game);

//INFO dal .cub
void		player_pos(t_game *game, int flag);

// CHECK
void		check_zero_nswe(t_game *game, int r, int c);
void		valid_char(t_game *game, int r, int c, int x);
void		check_mappa(t_game *g, int r, int c);
void		check_variabili(t_game *game, int i);
void		check_rgb(t_game *game, char **tmp1, int i, int j);
void		check_extention(char *s);
void		check_validity(t_game *game, char *str, int i);

// KEYBIND
void		move_fw(t_game *game);
void		move_bw(t_game *game);
void		move_r(t_game *game);
void		move_l(t_game *game);
void		rot_l(t_game *game);
void		rot_r(t_game *game);
int			key_press(int key, t_game *game);
void		set_keys(t_game *game);

// FREE
void		exit_free(t_game *game, int error);

#endif
