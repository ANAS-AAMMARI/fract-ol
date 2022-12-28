CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f 

NAME = fractol
HEADER = fractol.h

SRCS =	utils.c     		\
		utils1.c    		\
		utils2.c    		\
		fractol.c   		\
		tools.c				\


SRCS_OBJS = ${SRCS:%.c=%.o}


all: ${NAME}

${NAME}:${SRCS_OBJS}
	${CC} ${CFLAGS} $(MLX) $^ -o fractol

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(SRCS_OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all