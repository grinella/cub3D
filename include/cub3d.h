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

void	init(char *s, t_tex *tex);

#endif
