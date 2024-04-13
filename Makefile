NAME 		=	cub3D

LIBFT		=	/include/libft/libft.a

CC			=	gcc -g
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC			=	\
					cub3d.c

OBJ 		= 	$(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
		make -C libft all bonus
		$(CC) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	make -C include/libft clean
	$(RM) $(OBJ)

fclean : clean
	make -C include/libft fclean
	$(RM) $(NAME)

re : fclean all